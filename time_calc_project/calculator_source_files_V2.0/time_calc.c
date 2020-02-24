/*
 * Jeremy Leclerc
 * jnl570
 * 11246740
 * CMPT214 Assignment 3 
 */

#include "time_calc.h"

/*
 * use: 
 *	time_calc conv time 
 *	time_calc {add,subt,comp} time1 time2
 * Program that can convert, add, subtract, or compare time spec (1y1n1d1h1m1s)
 * or seconds.
 */
int main( int argc, char *argv[]){
	//Check for conv
	if (strcmp(argv[1], "conv") == 0){
		if(argc == 3){
			convert(argv[2]);
		}
		else if(argc < 3){
			fprintf(stderr, "Error: Too few arguments.\n");
			usage();
		}
		else{
			fprintf(stderr, "Error: Too many arguments.\n");
			usage();
		}	
	}

	//Check for add/subt/comp
	else if(strcmp(argv[1], "add") == 0 ||
			strcmp(argv[1], "subt") == 0 ||
			strcmp(argv[1], "comp") == 0){
		if(argc == 4){
			//checks for add/subt/comp and executes that command
			add_subt_comp(argv[2], argv[3], argv[1]); 
		}
		else if(argc < 4){
			fprintf(stderr, "Error: Too few arguments.\n");
			usage();
		}
		else{
			fprintf(stderr, "Error: Too many arguments.\n");
			usage();
		}
	}

	//Check for help
	else if(strcmp(argv[1], "help") == 0){
		usage();
	}

	//Print usage message
	else{
		fprintf(stderr, "Error: command '%s' not recognized\n", argv[1]);
		usage();
	}
	return 0;
}

void add_subt_comp(char* time1, char* time2, char* command){
	//Convert first time to seconds
	num_seconds_t seconds1 = 0;
	if(is_legal_time_spec(time1)){
		struct time_spec_t* time_spec_ptr = string_to_time_spec(time1);
		seconds1 = time_spec_to_seconds(time_spec_ptr);
	}
	else if(is_legal_seconds(time1)){
		seconds1 = string_to_seconds(time1);
	}
	else{
		fprintf(stderr, 
			"Error arguments are not a legal time spec or seconds.\n");
		return;
	}

	//Covert second time to seconds
	num_seconds_t seconds2 = 0;
	if(is_legal_time_spec(time2)){
		struct time_spec_t* time_spec_ptr = string_to_time_spec(time2);
		seconds2 = time_spec_to_seconds(time_spec_ptr);
	}
	else if(is_legal_seconds(time2)){
		seconds2 = string_to_seconds(time2);
	}
	else{
		fprintf(stderr, 
			"Error arguments are not a legal time spec or seconds.\n" );
		return;
	}

	//Execute given command (add/subt/comp)
	if(strcmp(command, "add") == 0){
		add(seconds1, seconds2);
	}
	else if(strcmp(command, "subt") == 0 ){
		subt(seconds1, seconds2);
	}
	else if(strcmp(command, "comp") == 0){
		comp(seconds1, seconds2);
	}
	else{
		fprintf(stderr, "Error: command not recognized.\n");
	}
}

void add(num_seconds_t time1, num_seconds_t time2){
	// check for overflow of unsigned long long int at > 4,000,000,000
	if(time1 > 999999999 && time2 > 999999999){  
		unsigned int leadingDigit1 = time1/1000000000; //get leading digit
		unsigned int leadingDigit2 = time2/1000000000; // get leading digit
		// check if seconds is out of range 
		//(possible overflow of unsigned long long int)
		if((leadingDigit1 + leadingDigit2) >= 4){      
			fprintf(stderr, "Error: Time range exceeded.\n");
			return;
		}
	}
	unsigned long long  result = time1 + time2;

	//Check for valid seconds range
	if(result >= NUM_SECONDS_T_OVERFLOW){
		fprintf(stderr, "Error: Time range exceeded.\n");
		return;
	}
	num_seconds_t seconds = (num_seconds_t)result;
	struct time_spec_t* time_spec = seconds_to_time_spec(seconds);
	print_time_spec(time_spec);
	return;
}

void subt(num_seconds_t time1, num_seconds_t time2){

	//Check for valid time1, time2
	if(time1 < time2){
		fprintf(stderr, "Error: Negative time not allowed.\n");
		return;
	}
	num_seconds_t result = time1 - time2;
	struct time_spec_t* time_spec = seconds_to_time_spec(result);
	print_time_spec(time_spec);
	return;
}

void comp(num_seconds_t time1, num_seconds_t time2){
	if(time1 > time2){printf("Greater\n");}
	else if(time1 < time2){printf("Less\n");}
	else{printf("Equal\n");}
	return;
}

bool convert(char* time_string){
	if(is_legal_time_spec(time_string)){
		struct time_spec_t* time_spec_ptr = string_to_time_spec(time_string);
		num_seconds_t seconds = time_spec_to_seconds(time_spec_ptr);
		if(seconds < NUM_SECONDS_T_OVERFLOW){
			printf("%u\n", seconds);
			return TRUE;
		}
		fprintf(stderr, "Error: Time range exceeded.\n");
		return 0;
	}
	else if(is_legal_seconds(time_string)){
		num_seconds_t seconds = string_to_seconds(time_string);
		struct time_spec_t* time_spec_ptr = seconds_to_time_spec(seconds);
		print_time_spec(time_spec_ptr);
		return TRUE;

	}
	else{
		printf("Error: '%s' not a legal time string or time spec.\n", 
			time_string);
		return FALSE;
	}
}

void usage( void ) {
	puts( "Usage: time_calc help" );
	puts( " time_calc conv <time>" );
	puts( " time_calc {add,subt,comp} <time1> <time2>" );
}
