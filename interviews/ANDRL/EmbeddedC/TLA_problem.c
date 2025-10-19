#include <stdint.h>

/// Compute throttle setpoint from TLA with internal rate limiting.
/// - tla: pointer to throttle lever angle in degrees
/// Returns: new power percent (0..100)
static float throttle_setpoint_calculate(const float *tla)
{
    static float prev_power = 0.0f;       // internal state for rate limiting
    float target;
    float power;

    /* 1) Map TLA -> target % power */
    if (*tla < 20.0f) {
        target = 0.0f;                // Cutoff
    }
    else if (*tla <= 30.0f) {
        target = 20.0f;               // Idle
    }
    else if (*tla < 70.0f) {
        target = (*tla) * 2.0f - 40.0f;  // Linear interpolation
    }
    else {
        target = 100.0f;              // Max
    }

    /* 2) Rate limit: max 100%/s, called at 10 Hz => 10% per call.
          Skip rate limiting if going to/from cutoff (0%) */
    const float max_delta_per_call = 10.0f; // percent

    if (prev_power == 0.0f || target == 0.0f) {
        // Immediate change when entering/leaving cutoff
        power = target;
    } else {
        float delta = target - prev_power;
        if (delta > max_delta_per_call) {
            power = prev_power + max_delta_per_call;
        } else if (delta < -max_delta_per_call) {
            power = prev_power - max_delta_per_call;
        } else {
            power = target;
        }
    }

    /* 3) Clamp output to [0, 100] */
    if (power < 0.0f) power = 0.0f;
    if (power > 100.0f) power = 100.0f;

    /* 4) Update internal state for next call */
    prev_power = power;

    return power;
}
