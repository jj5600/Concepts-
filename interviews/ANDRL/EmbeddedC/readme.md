Throttle Setpoint Calculation

Task: Compute the % power setting given the throttle lever angle (TLA).

Requirements:

While the TLA is less than 20 degrees, % power shall be 0% (cutoff).

While the TLA is between 20 and 30 degrees, % power shall be 20% (IDLE).

While the TLA is between 30 and 70 degrees, % power should be linearly interpolated between 20% and 100%.

While the TLA is above 70 degrees, % power shall be 100% (MAX).

The % power output should be rate limited to not be more than 100% per second.

Do not rate limit if the power is going to or from cutoff.

Note: Assume this function is called at a rate of 10 Hz.


