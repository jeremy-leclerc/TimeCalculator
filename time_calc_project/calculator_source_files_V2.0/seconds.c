/*
 * Jeremy Leclerc
 * jnl570
 * 11246740
 * CMPT214 Assignment 4 
 */


#include "seconds.h"

bool is_legal_seconds( char *time ){
	unsigned int string_len = strlen(time);

	//if string is too long
	if(string_len > 10){
		return FALSE;
	}

	//if string is not digit
	for (unsigned int i = 0; i < string_len; ++i){
		if(!(isdigit(time[i]))){
			return FALSE;
		}
	}

	//if string >= 4,000,000,000 (check for overflow)
	if (string_len == 10 && ((time[0] - '0') >= 4)){
		return FALSE;
	}

	num_seconds_t seconds = string_to_seconds(time);
	if(seconds >= NUM_SECONDS_T_OVERFLOW){
		return FALSE;
	}
	return TRUE;
}

num_seconds_t string_to_seconds( char *timeString ){
	num_seconds_t seconds = (num_seconds_t)atoi(timeString);
	return seconds;
}