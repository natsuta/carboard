/******************************************************************************
** Student name: 	Sherman Wong
** Student number: 	s3656264
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "game.h"
#define MAX_LENGTH 15
void playGame()
{
	/* TODO */
    char input[MAX_LENGTH], *command;
	Cell board[BOARD_HEIGHT][BOARD_WIDTH];
	printIntro();
	readRestOfLine();
	initialiseBoard(board);
    displayBoard(board, NULL);
	printf("\n");
	while (strcmp(command, COMMAND_QUIT) != 0) {
		printf("Board loading menu\n");
		printf("At this stage of the program, only two commands are acceptable:\n");
		printf("load <g>\n");
		printf("quit\n");
		fgets(input, MAX_LENGTH, stdin);
		bufferCheck(input);
		command = strtok(input, " ");
        if (strcmp(command, COMMAND_LOAD) == 0){
            loading(command, board);
            displayBoard(board, NULL);
			printf("\n"); /* segmentation error happens if this is not done */
			enterGame(board);
			break;
		}
		else if (strcmp(command, COMMAND_QUIT) == 0){
			printf("\n");
			break;
		}
        else
			printf("Invalid input.\n\n");
	}
	return;
}

void enterGame(Cell board[BOARD_HEIGHT][BOARD_WIDTH]) {
	char input[MAX_LENGTH], *command, *overflow;
	Player player;
	Position position;
	Direction direction;
	while (strcmp(command, COMMAND_QUIT) != 0) {
		printf("Initialisation menu\n");
		printf("At this stage of the program, only three commands are acceptable:\n");
		printf("load <g>\n");
		printf("init <x>,<y>,<direction>\n");
		printf("quit\n");
		fgets(input, MAX_LENGTH, stdin);
		bufferCheck(input);
		command = strtok(input, " ,");
		if (strcmp(command, COMMAND_LOAD) == 0){
            loading(command, board);
			displayBoard(board, NULL);
			printf("\n");
		}
		else if (strcmp(command, COMMAND_INIT) == 0){
			command = strtok(NULL, " ,");
			position.x = strtol(command, &overflow, 10);
			command = strtok(NULL, " ,");
			position.y = strtol(command, &overflow, 10);
			command = strtok(NULL, " ,");
			direction = setDirection(command);
			initialisePlayer(&player, &position, direction);
			if (placePlayer(board, position) == TRUE){
				updatePosition(&player, position);
				displayBoard(board, &player);
				printf("\n");
				inGame(board, &player, position);
				break;
			}
			else
				printf("Space blocked, try again.\n");
		}
		else if (strcmp(command, COMMAND_QUIT) == 0){
			printf("\n");
			break;
		}
		else
			printf("Invalid input.\n\n");
	};
	return;
}

void inGame(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player * player, Position position){
	char input[MAX_LENGTH], *command;
	readRestOfLine();
	while (strcmp(command, COMMAND_QUIT) != 0) {
		displayBoard(board, player);
		printf("\nIn-game menu\n");
		printf("At this stage of the program, only four commands are acceptable:\n");
		printf("forward (or f)\n");
		printf("turn_left (or l)\n");
		printf("turn_right (or r)\n");
		printf("quit\n");
		fgets(input, MAX_LENGTH, stdin);
		bufferCheck(input);
		command = strtok(input, " ,");
		if (strcmp(command, COMMAND_FORWARD) == 0 ||
			strcmp(command, COMMAND_FORWARD_SHORTCUT) == 0)
				movePlayerForward(board, player);
		else if (strcmp(command, COMMAND_TURN_LEFT) == 0 ||
				 strcmp(command, COMMAND_TURN_LEFT_SHORTCUT) == 0)
				turnDirection(player, TURN_LEFT);
		else if (strcmp(command, COMMAND_TURN_RIGHT) == 0 ||
				 strcmp(command, COMMAND_TURN_RIGHT_SHORTCUT) == 0)
				turnDirection(player, TURN_RIGHT);
		else if (strcmp(command, COMMAND_QUIT) == 0){
			printf("Total player moves: %i\n\n", player->moves);
			break;
		}
		else
			printf("Invalid input.\n\n");
	}
}

void bufferCheck(char * input){
	int i;
	for (i=0; i<strlen(input); i++){
        if(input[i] == '\n'){
            input[i] = '\0';
            break;
        }
	}
}

void loading(char * command, Cell board[BOARD_HEIGHT][BOARD_WIDTH]){
	char *overflow;
	int n;
	command = strtok(NULL, " ,");
    n = strtol(command, &overflow, 10);
    if (n == 1)
		loadBoard(board, BOARD_1);
	else if (n == 2)
		loadBoard(board, BOARD_2);
    else {
        printf("Invalid input.\n\n");
    }
}

Direction setDirection(char * command){
	Direction direction;
	if (strcmp(command, DIRECTION_NORTH) == 0)
		direction = NORTH;
	else if (strcmp(command, DIRECTION_EAST) == 0)
		direction = EAST;
	else if (strcmp(command, DIRECTION_SOUTH) == 0)
		direction = SOUTH;
	else if (strcmp(command, DIRECTION_WEST) == 0)
		direction = WEST;
	return direction;
}

void printIntro(){
	printf("You can use the following commands to play the game:\n");
    printf("load <g>\n");
    printf("   g: number of the game board to load\n");
    printf("init <x>,<y>,<direction>\n");
    printf("   x: horizontal position of the car on the board "
    		"(between 0 & 9)\n");
    printf("   y: vertical position of the car on the board "
    		"(between 0 & 9)\n");
    printf("   direction: direction of the car’s movement "
    		"(north, east, south, west)\n");
    printf("forward (or f)\n");
    printf("turn_left (or l)\n");
    printf("turn_right (or r)\n");
    printf("quit\n");
    printf("Press Enter to continue\n");
}