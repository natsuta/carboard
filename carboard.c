/******************************************************************************
** Student name: 	Sherman Wong
** Student number: 	s3656264
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "carboard.h"

int main()
{
    /* TODO */
	char optioninput[5], *overflow;
	long option;
	int active = 1; /* ask about boolean enum on helpers.h - non-zero needed?*/
	int instructions = 1;
	while (active != 0){
		while (instructions != 0){
			printf("Welcome to Car Board\n");
			printf("--------------------\n");
			printf("1. Play game\n");
			printf("2. Show student's information\n");
			printf("3. Quit \n\n"); /* consider return to main menu command */
			instructions = 0;
		};
		printf("Please enter your choice: ");
		fgets(optioninput, 5, stdin);
		option = strtol(optioninput, &overflow, 10);
		printf("\n");
		if (option == 1){
			instructions = 1;
			playGame();
		}
		else if (option == 2){
			showStudentInformation();
		}
		else if (option == 3){
			printf("Good bye!\n");
			active = 0;
			
		}
	};
	return EXIT_SUCCESS;
}

void showStudentInformation()
{
    /* TODO */
	printf("----------------------------------\n");
	printf("Name: %s\n", STUDENT_NAME);
	printf("No: %s\n", STUDENT_ID);
	printf("Email: %s\n", STUDENT_EMAIL);
	printf("----------------------------------\n\n");
}
