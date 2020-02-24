/*
 * Jeremy Leclerc
 * jnl570
 * 11246740
 * CMPT214 Assignment 4 
 */

#include "time_spec.h"

bool is_legal_time_spec( char *in_str ) {
	char extra[BUFFER_SIZE+1];   // buffer for any characters following the
                                //  seconds field
	unsigned year, month, day, hour, minute, second;
                                // use full-sized unsigned variables as the 
                                //  locations for the converted values.  This 
                                //  allows for checks for overflow 
	int num_fields;

    // check that input argument is a valid pointer
	if( NULL == in_str ) {return( FALSE );}

    // try to scan the input.  Look for 6 unsigned numeric fields,
    // followed by a string consisting of "extra input".
	num_fields=sscanf( in_str, "%uy%un%ud%uh%um%us" BUFFER_SIZE_FMT, 
						&year, &month, &day, &hour, &minute, &second, 
						extra );

    // if there was something other than 6 unsigned numeric fields
    // we have an error
	if( FIELDS_IN_TIME_SPEC != num_fields ) {return( FALSE );}

    // check each of the input fields against their limits.  Return FALSE
    // if any limit reached.
	if( LIMIT_TS_YE <= year ) {return( FALSE );}
	if( LIMIT_TS_MO <= month ) {return( FALSE );}
	if( LIMIT_TS_DA <= day ) {return( FALSE );}
	if( LIMIT_TS_HO <= hour ) {return( FALSE );}
	if( LIMIT_TS_MI <= minute ) {return( FALSE );}
	if( LIMIT_TS_SE <= second ) {return( FALSE );}

    // Otherwise, the input string appears to be a value time spec
 	return( TRUE );
}

struct time_spec_t* string_to_time_spec( char* time_spec ){
	//Allocate memory for struct
	struct time_spec_t* time_spec_struct = malloc(sizeof(struct time_spec_t)); 

	//Get information for struct
	int years = get_years(time_spec);
	int months = get_months(time_spec);
	int days = get_days(time_spec);
	int hours = get_hours(time_spec);
	int minutes = get_minutes(time_spec);
	int seconds = get_seconds(time_spec);

	//Allocate data to the struct
	time_spec_struct->year = years;
	time_spec_struct->month = months; 
	time_spec_struct->day = days;
	time_spec_struct->hour = hours;
	time_spec_struct->minute = minutes;
	time_spec_struct->second = seconds;

	return time_spec_struct;
}

int get_years(char* time_spec){
	char numbers[] = {'\0', '\0', '\0'};

	int i = 0;
	while(isdigit(time_spec[i])){
		numbers[i] = time_spec[i];
		i++;
	}
	num_seconds_t yearss = atoi(numbers);
	return yearss;
}

int get_months(char* time_spec){
	int i = 0;
	while(time_spec[i] != 'y'){
		i++;
	}
	i++;
	while(time_spec[i] == ' '){
		i++;
	}

	int j = 0;
	char numbers[] = {'\0', '\0'};
	while(isdigit(time_spec[i])){
		numbers[j] = time_spec[i];
		i++;
		j++;
	}
	int months = atoi(numbers);
	return months;
}

int get_days(char* time_spec){
	int i = 0;
	while(time_spec[i] != 'n'){
		i++;
	}
	i++;
	while(time_spec[i] == ' '){
		i++;
	}
	int j = 0;
	char numbers[] = {'\0', '\0'};
	while(isdigit(time_spec[i])){
		numbers[j] = time_spec[i];
		i++;
		j++;
	}
	int days = atoi(numbers);
	return days;
}

int get_hours(char* time_spec){
	int i = 0;
	while(time_spec[i] != 'd'){
		i++;
	}
	i++;
	while(time_spec[i] == ' '){
		i++;
	}
	int j = 0;
	char numbers[] = {'\0', '\0'};
	while(isdigit(time_spec[i])){
		numbers[j] = time_spec[i];
		i++;
		j++;
	}
	int hours = atoi(numbers);
	return hours;
}

int get_minutes(char* time_spec){
	int i = 0;
	while(time_spec[i] != 'h'){
		i++;
	}
	i++;
	while(time_spec[i] == ' '){
		i++;
	}
	int j = 0;
	char numbers[] = {'\0', '\0'};
	while(isdigit(time_spec[i])){
		numbers[j] = time_spec[i];
		i++;
		j++;
	}
	int minutes = atoi(numbers);
	return minutes;
}

int get_seconds(char* time_spec){
	int i = 0;
	while(time_spec[i] != 'm'){
		i++;
	}
	i++;
	while(time_spec[i] == ' '){
		i++;
	}
	int j = 0;
	char numbers[] = {'\0', '\0'};
	while(isdigit(time_spec[i])){
		numbers[j] = time_spec[i];
		i++;
		j++;
	}
	int seconds = atoi(numbers);
	return seconds;
}

void print_time_spec( struct time_spec_t *time_spec ){
	printf("%dy %dn %dd %dh %dm %ds\n", 
									time_spec->year, time_spec->month, 
									time_spec->day, time_spec->hour, 
									time_spec->minute, time_spec->second);
}



