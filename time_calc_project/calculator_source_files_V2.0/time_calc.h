/*
 * Jeremy Leclerc
 * jnl570
 * 11246740
 * CMPT214 Assignment 4
 */


#ifndef TIME_CALC_H
#define TIME_CALC_H

#include <stdio.h> //fprintf()
#include <string.h> //strm()

typedef char bool; //Used as a boolean with TRUE/FALSE

#include "time_spec.h"
#include "seconds.h"
#include "time_arg.h"

/*
 * Calls function which carries out tasks: add, subt, or comp
 * time 1, time 2 are either time_specs or number of seconds
 * command: {add, subt, comp}
 */
void add_subt_comp(char* time1, char* time2, char* command);

/*
 * returns TRUE and prints the conversion (time spec/seconds) if TRUE.
 * Otherwise, return FALSE and print error message to stderr.
 * time_string is either a time_spec or a number of seconds
 */
bool convert(char* time_string);

/*
 * returns the sum of two number of seconds together
 * time1, time2 are a number of seconds
 */ 
void add(num_seconds_t time1, num_seconds_t time2);

/*
 * returns the difference of two number of seconds.
 * time1, time2 are a number of seconds
 */
void subt(num_seconds_t time1, num_seconds_t time2);

/*
 * Compares two number of seconds and print the result 
 * (greater, less, or equal) of time1 compared to time 2.
 * time1, time2 are a number of seconds
 */
void comp(num_seconds_t time1, num_seconds_t time2);

/* 
 * prints a message of how to use time_calc to stdout
 */
void usage( void );

#endif //TIME_CALC_H