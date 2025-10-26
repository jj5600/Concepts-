
    Implement the atoi() ("ASCII to integer") function from <stdlib.h>

    int atoi( const char *str );

    Interprets an integer value in a character string pointed to by str.
    The implied radix is always 10.

    Discards all leading whitespace characters until the first non-whitespace
    character is found, then checks for an optional sign character, then takes
    as many characters as possible to form a valid integer number representation
    and converts them to an integer value. The integer value ends when a non-
    digit character is found. Put another way, a valid input string consists of
    the following parts:

    (optional) one or more space characters
        (optional) plus or minus sign
        numeric digits

    An invalid input string will return 0.

    If the value of the result cannot be represented, i.e. the converted
    value falls out of range of the corresponding return type, the behavior
    is undefined.

    Parameters
        str pointer to the null-terminated char string to be interpreted

    Return value
        Integer value corresponding to the contents of str on success.
        If no conversion can be performed, 0 is returned.
        
        Example:
        "1234" returns 1234
        "    sdsfsfd1234cfgdfg4545" returns 12344545
