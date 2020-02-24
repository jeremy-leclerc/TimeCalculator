/*
 * Jeremy Leclerc
 * jnl570
 * 11246740
 * CMPT214 Assignment 4 
 */




#ifndef TIME_ARG_H
#define TIME_ARG_H

#include <stdlib.h> //malloc

#include "time_spec.h"
#include "seconds.h"

#define SECONDS_IN_YEAR 31557600
#define SECONDS_IN_MONTH 2629800
#define SECONDS_IN_DAY	86400
#define SECONDS_IN_HOUR 3600
#define SECONDS_IN_MINUTE 60

/*
 * converts numSeconds into a time_spec_t struct.
 */
struct time_spec_t* seconds_to_time_spec( num_seconds_t numSeconds);

/*
 * returns number of seconds from time_spec_t struct
 * uses:
 * 	SECONDS_IN_YEAR 31557600
 * 	SECONDS_IN_MONTH 2629800
 * 	SECONDS_IN_DAY	86400
 * 	SECONDS_IN_HOUR 3600
 * 	SECONDS_IN_MINUTE 60
 */
num_seconds_t time_spec_to_seconds( struct time_spec_t *);

/*
 * returns TRUE if the in_str can be converted to a number of seconds.
 * If TRUE set the memory location pointed at by *seconds_p to the result.
 */
bool get_time_arg( char *in_str, num_seconds_t *seconds_p );

#endif //TIME_ARG_H