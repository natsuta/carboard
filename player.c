/******************************************************************************
** Student name: 	Sherman Wong
** Student number: 	s3656264
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "player.h"

void initialisePlayer(Player * player, Position * position, Direction direction)
{
    /* TODO */
	player->position = *position;
	player->direction = direction;
	player->moves = 0;
}

void turnDirection(Player * player, TurnDirection turnDirection)
{
    /* TODO */
	if (turnDirection == TURN_LEFT){
		if (player->direction == NORTH){
			player->direction = WEST;
			printf("Direction changed to west\n");
		}
		else if (player->direction == EAST){
			player->direction = NORTH;
			printf("Direction changed to north\n");
		}
		else if (player->direction == SOUTH){
			player->direction = EAST;
			printf("Direction changed to east\n");
		}
		else if (player->direction == WEST){
			player->direction = SOUTH;
			printf("Direction changed to south\n");
		}
	}
    else if (turnDirection == TURN_RIGHT){
		if (player->direction == NORTH){
			player->direction = EAST;
			printf("Direction changed to east\n");
		}
		else if (player->direction == EAST){
			player->direction = SOUTH;
			printf("Direction changed to south\n");
		}
		else if (player->direction == SOUTH){
			player->direction = WEST;
			printf("Direction changed to west\n");
		}
		else if (player->direction == WEST){
			player->direction = NORTH;
			printf("Direction changed to north\n");
		}
	}
}

Position getNextForwardPosition(const Player * player)
{
    /* TODO */
    Position position;
	position = player->position;
	if (player->direction == NORTH)
		position.y--;
	else if (player->direction == EAST)
		position.x++;
	else if (player->direction == SOUTH)
		position.y++;
	else if (player->direction == WEST)
		position.x--;
    return position;
}

void updatePosition(Player * player, Position position)
{
    /* TODO */
	player->position = position;
	player->moves++;
	printf("Update position done\n");
}

void displayDirection(Direction direction)
{
    /* TODO */
	if(direction == NORTH)
		printf("|%s", DIRECTION_ARROW_OUTPUT_NORTH);
	else if(direction == EAST)
		printf("|%s", DIRECTION_ARROW_OUTPUT_EAST);
	else if(direction == SOUTH)
		printf("|%s", DIRECTION_ARROW_OUTPUT_SOUTH);
	else if(direction == WEST)
		printf("|%s", DIRECTION_ARROW_OUTPUT_WEST);
}
