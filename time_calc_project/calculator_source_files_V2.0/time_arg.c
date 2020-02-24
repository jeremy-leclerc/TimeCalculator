/*
 * Jeremy Leclerc
 * jnl570
 * 11246740
 * CMPT214 Assignment 4 
 */

#include "time_arg.h"

struct time_spec_t* seconds_to_time_spec( num_seconds_t numSeconds){
	//Allocate memory for struct
	struct time_spec_t* spec_ptr = malloc(sizeof(struct time_spec_t));  

	int years = numSeconds / SECONDS_IN_YEAR;
	int remaining_seconds = numSeconds % SECONDS_IN_YEAR;

	int months = remaining_seconds / SECONDS_IN_MONTH;
	remaining_seconds = remaining_seconds % SECONDS_IN_MONTH;

	int days = remaining_seconds / SECONDS_IN_DAY;
	remaining_seconds = remaining_seconds % SECONDS_IN_DAY;

	int hours = remaining_seconds / SECONDS_IN_HOUR;
	remaining_seconds = remaining_seconds % SECONDS_IN_HOUR;

	int minutes = remaining_seconds / SECONDS_IN_MINUTE;
	remaining_seconds = remaining_seconds % SECONDS_IN_MINUTE;

	int seconds = remaining_seconds;

	//Assign values to struct
	spec_ptr->year = years;
	spec_ptr->month = months;
	spec_ptr->day = days;
	spec_ptr->hour = hours;
	spec_ptr->minute = minutes;
	spec_ptr->second = seconds;

	return spec_ptr;
}

num_seconds_t time_spec_to_seconds( struct time_spec_t * time_spec){

	//Get numbers from struct
	num_seconds_t years = time_spec->year;
	num_seconds_t months = time_spec->month;
	num_seconds_t days = time_spec->day;
	num_seconds_t hours = time_spec->hour;
	num_seconds_t minutes = time_spec->minute;
	num_seconds_t seconds = time_spec->second;

	//Calculate total number of seconds
	num_seconds_t total_seconds = (years * SECONDS_IN_YEAR) + 
									(months * SECONDS_IN_MONTH) + 
									(days * SECONDS_IN_DAY) + 
									(hours * SECONDS_IN_HOUR) + 
									(minutes * SECONDS_IN_MINUTE) + 
									seconds;
	return  total_seconds;
}

bool get_time_arg( char *in_str, num_seconds_t *seconds_p ){
	if(is_legal_time_spec(in_str)){
		struct time_spec_t* time_spec_ptr = string_to_time_spec(in_str);
		num_seconds_t seconds = time_spec_to_seconds(time_spec_ptr);
		*seconds_p = seconds;
		return 1;
	}
	else if(is_legal_seconds(in_str)){
		num_seconds_t seconds = string_to_seconds(in_str);
		*seconds_p = seconds;
		return 1;
	}
	return 0;
}








