/*
 * Jeremy Leclerc
 * jnl570
 * 11246740
 * CMPT214 Assignment 4 
 */

#ifndef SECONDS_H
#define SECONDS_H

#include <string.h>  //strlen
#include <ctype.h>   //isdigit
#include <stdlib.h> //atoi

typedef uint32_t num_seconds_t; //type used for seconds

#include "time_spec.h" //TRUE, FALSE
#include "time_calc.h" //typedef bool

#define NUM_SECONDS_T_OVERFLOW 3155760000 //overflow for seconds

/*
 * returns TRUE if time is a legal seconds number, returns FALSE otherwise.
 * uses: 
 *   NUM_SECONDS_T_OVERFLOW 3155760000
 */ 
bool is_legal_seconds( char* time);

/*
 * converts timeString to a number of seconds as num_seconds_t type.
 * timeString is a number of seconds
 */
num_seconds_t string_to_seconds( char * timeString);

#endif //SECONDS_H