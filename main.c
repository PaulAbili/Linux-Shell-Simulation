/*
project: 01
author:Paul Abili
email:pabili1@umbc.edu
student id:QD36016
due date: 2/28/21 11:59:59 pm
description: a simple linux shell designed to perform basic linux commands
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include "utils.h"

/*
In this project, you are going to implement a number of functions to 
create a simple linux shell interface to perform basic linux commands
*/


/*
DEFINE THE FUNCTION PROTOTYPES
user_prompt_loop()
get_user_command()
parse_command()
execute_command()
*/

int user_prompt_loop();
void get_user_command(char**);
void parse_command(char*, char***);
void execute_command(char**);

int main(int argc, char **argv){
    /*
    Write the main function that checks the number of argument passed to ensure 
    no command-line arguments are passed; if the number of argument is greater 
    than 1 then exit the shell with a message to stderr and return value of 1
    otherwise call the user_prompt_loop() function to get user input repeatedly 
    until the user enters the "exit" command.
    */

    /*
    ENTER YOUR CODE HERE
    */
	//Check to see if more than 1 argument
	//if so exit with stderr error
	//user_prompt_loop()
	if(argc > 1){
		fprintf(stderr, "Too many arguments");
	} else {
		while(user_prompt_loop() == 0){ } // do nothing!
	}

	return 0;
}

   /*
   user_prompt_loop():

   Get the user input using a loop until the user exits, prompting the user for a command.
   Gets command and sends it to a parser, then compares the first element to the two
   different commands ("/proc", and "exit"). If it's none of the commands, 
   send it to the execute_command() function. If the user decides to exit, then exit 0 or exit 
   with the user given value. 
   */

   /*user_prompt_loop()*/

int user_prompt_loop(){
    // initialize variables

    /*
    loop:
        1. prompt the user to type command by printing >>
        2. get the user input using get_user_command() function 
        3. parse the user input using parse_command() function 
        Example: 
            user input: "ls -la"
            parsed output:["ls", "-la", NULL]
        4. compare the first element of the parsed output to "/proc"and "exit"
        5. if the first element is "/proc" then you have the open the /proc file system 
           to read from it
            i) concat the full command:
                Ex: user input >>/proc /process_id_no/status
                    concated output: /proc/process_id_no/status
            ii) read from the file line by line. you may user fopen() and getline() functions
            iii) display the following information according to the user input from /proc
                a) Get the cpu information if the input is /proc/cpuinfo
                - Cpu Mhz
                - Cache size
                - Cpu cores
                - Address sizes
                b) Get the number of currently running processes from /proc/loadavg
                c) Get how many seconds your box has been up, and how many seconds it has been idle from /proc/uptime
                d) Get the following information from /proc/process_id_no/status
                - the vm size of the virtual memory allocated the vbox
                - the most memory used vmpeak
                - the process state
                - the parent pid
                - the number of threads
                - number of voluntary context switches
                - number of involuntary context switches
                e) display the list of environment variables from /proc/process_id_no/environ
                f) display the performance information if the user input is /proc/process_id_no/sched
        6. if the first element is "exit" the use the exit() function to terminate the program
        7. otherwise pass the parsed command to execute_command() function
        8. free the allocated memory using the free() function
    */

    /*
    Functions you may need:
                                //strncpy(substring, usrInput + (i - j), j);
        get_user_command(), parse_command(), execute_command(), strcmp(), strcat(), 
        strlen(), strncmp(), fopen(), fclose(), getline(), isdigit(), atoi(), fgetc(), 
        or any other useful functions
    */

    /*
    ENTER YOUR CODE HERE
    */
	// print >>
	// char* usrInput = get_user_command();
	// char[] parsed = parse_comand(usrInput);
	// if parsed[0] is exit and parsed[1] is NULL & parsed[2] doesn't exist
	// execute_command(parsed);
	int i = 0;
	int j = 0; //keeps track to the size of the array
	int k = 0;
	printf(">> ");
	char* usrInput = NULL;
	get_user_command(&usrInput); // user input

	char** parsed = (char**)malloc(sizeof(char*) * strlen(usrInput));

	for(i = 0; i < strlen(usrInput); i++){ //allocates space
		parsed[i] = malloc(sizeof(char*) * (strlen(usrInput) + 3)); 
	}

	parse_command(usrInput, &parsed);

	j = 0;
	while(strcmp(parsed[j], "\0") != 0){
		j++; // size of new array;
	}
	if(strcmp(parsed[0], "exit\0") == 0 && strcmp(parsed[1], "\0") == 0){
		//Stops loop
		for(i = 0; i < strlen(usrInput); i++){
                	free(parsed[i]); // Frees Parsed Array
                	parsed[i] = NULL;
        	}
        	free(parsed);
        	parsed = NULL;
        	free(usrInput); //Frees UserInput
        	usrInput = NULL;
		return 1;
	} else {
	        char* new_parsed[j + 1];
        	for(i = 0; i < j; i++){ //j -> j- 1
			k = 0;
			while(strcmp(parsed[i] + k, "\0") != 0){
					k++;
			}
                	new_parsed[i] = malloc(sizeof(char) * (k + 1));
			memcpy(new_parsed[i], parsed[i],(k + 1));
//			printf("Parsed:%s\n", parsed[i]);
//			printf("New Parsed:%s\n", new_parsed[i]);

	        }
		new_parsed[j] = NULL;
		execute_command(new_parsed);
		for(i = 0; i < j; i++){
			free(new_parsed[i]);
			new_parsed[i] = NULL;
		}
	}

	for(i = 0; i < strlen(usrInput); i++){
        	free(parsed[i]); // Frees Parsed Array
		parsed[i] = NULL;
        }
	free(parsed);
	parsed = NULL;
	free(usrInput); //Frees UserInput
	usrInput = NULL;
	return 0;
}


/*
get_user_command():
Take input of arbitrary size from the user and return to the user_prompt_loop()
*/

/*get_user_command()*/
void get_user_command(char** usrInput){
    /*
    Functions you may need:
        malloc(), realloc(), getline(), fgetc(), or any other similar functions
    */

    /*
    ENTER YOUR CODE HERE
    */
	size_t size = 0;
	getline(&(*usrInput), &size, stdin); //gets user input and places it into usrInput
}

/*
parse_command():
Take command grabbed from the user and parse appropriately.
Example: 
    user input: "ls -la"
    parsed output: ["ls", "-la", NULL]
Example: 
    user input: "echo     hello                     world  "
    parsed output: ["echo", "hello", "world", NULL]
*/

/*parse_command()*/
void parse_command(char* usrInput, char*** parsed){
    /*
    Functions you may need: 
        malloc(), realloc(), free(), strlen(), first_unquoted_space(), unescape()
    */

   /*
    ENTER YOUR CODE HERE
    */
	//remove spaces
	//parse string into array
	//check if first is exit or proc
	//return array

	int i = 0; // index of iteration
	int j = 0; // Size of word
	int k = 0; // index in array
	while(i < strlen(usrInput) - 1){
		if(isspace(usrInput[i]) != 0){
			if(j != 0){
				//strncpy(substring, usrInput + (i - j), j);
				//strncpy((*parsed)[k], substring); //copies parsed info to substring & adds nullptr
				memcpy((*parsed)[k], usrInput + (i - j), j);
               			(**parsed)[j + 1] = '\0';
				k++; // increments index
				j = 0; // restarts size counter
			}

		} else {
			j++;
		}
		i++;
	}

	if(j != 0){ //what if it ends without a space
		//strncpy(substring, usrInput + (i - j), j);
        	//strcpy((*parsed)[k], substring); // copies parsed info to substring & adds nullptr
		memcpy((*parsed)[k], usrInput + (i - j), j);
		(**parsed)[j] = '\0';
		k++; // increments index
        	j = 0; // restarts size counter
	}
	strcpy((*parsed)[k], "\0");
}

/*
execute_command():
Execute the parsed command if the commands are neither /proc nor exit;
fork a process and execute the parsed command inside the child process
*/

/*execute_command()*/
void execute_command(char* new_parsed[]){
    /*
    Functions you may need: 
        fork(), execvp(), waitpid(), and any other useful function
    */

    /*
    ENTER YOUR CODE HERE
    */
	//execute command
	//(somehow) use fork to create a process

	pid_t pid = fork();
	if(pid < 0){
		printf("Fork Failed\n");
	} else if(pid == 0){ // 0 means child process
		execvp(new_parsed[0], new_parsed);
	} else{
		wait(NULL);
	}


}
