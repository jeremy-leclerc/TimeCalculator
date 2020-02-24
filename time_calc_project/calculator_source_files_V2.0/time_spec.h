/*
 * Jeremy Leclerc
 * jnl570
 * 11246740
 * CMPT214 Assignment 4 
 */

#ifndef TIME_SPEC_H
#define TIME_SPEC_H

#include <stdio.h> //printf, fprintf 
#include <stdlib.h> //atoi
#include <ctype.h> //isdigit
#include <string.h> //strlen

#include "time_calc.h"
#include "seconds.h"

#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 100
#define BUFFER_SIZE_FMT  "%100s" // Format for a field of size BUFFER_SIZE
#define FIELDS_IN_TIME_SPEC 6
// limits on values in the fields of a time spec (TS)
#define LIMIT_TS_YE 100
#define LIMIT_TS_MO 12
#define LIMIT_TS_DA 31
#define LIMIT_TS_HO 24
#define LIMIT_TS_MI 60
#define LIMIT_TS_SE 60

#define TIME_SPEC_T
struct time_spec_t {
	uint8_t year; 
	uint8_t month; 
	uint8_t day; 
	uint8_t hour; 
	uint8_t minute;
	uint8_t second; };



// is_legal_time_spec:
//   determine whether the string pointed to by in_str represents a legal
//   "time spec"; that is, it is a string of the form
//      n1y n2n n3d n4h n5m n6s
//   where n1 < LIMT_TS_YE, n2 < LIMIT_TS_MO, n3 < LIMIT_TS_DA, 
//   n4 < LIMIT_TS_HO, n5 < LIMIT_TS_MI, n6 < LIMIT_TS_SE and each
//   of the fields may or may not be surrounded by white space.  
//   Output an error message on stderr if it is not.
// In:
// Out:
//   return -- TRUE if string is a legal time spec
//          -- FALSE otherwise.  Also output error message on stderr.
bool is_legal_time_spec( char * in_str);

/*
 * returns a time_spec_t struct from the information given by time_spec(String)
 * time_spec is a time_spec as a string
 */
struct time_spec_t* string_to_time_spec( char * time_spec);

/*
 * returns number of years as an int from time_spec
 */
int get_years(char*);

/*
 * returns number of months as an int from time_spec
 */
int get_months(char*);

/*
 * returns number of days as an int from time_spec
 */
int get_days(char*);

/*
 * returns number of hours as an int from time_spec
 */
int get_hours(char*);

/*
 * returns number of minutes as an int from time_spec
 */
int get_minutes(char*);

/*
 * returns number of seconds as an int from time_spec
 */
int get_seconds(char*);

/*
 * prints the information of a time_spec_t struct as a time spec to stdout
 */
void print_time_spec( struct time_spec_t *);

#endif //TIME_SPEC_H
