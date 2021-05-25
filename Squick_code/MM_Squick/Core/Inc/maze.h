/*
 * maze.h
 *
 *  Created on: 25 maj 2021
 *      Author: Piotr
 */

#ifndef INC_MAZE_H_
#define INC_MAZE_H_

#include "stm32f4xx_hal.h"
#include <stdio.h>
#define INC_MAZE_H_




#define MAZE_LENGTH_BLOCK_NUMBER 16
#define MAZE_WIDTH_BLOCK_NUMBER 16

#define MAZE_LENGTH MAZE_LENGTH_BLOCK_NUMBER-1
#define MAZE_WIDTH MAZE_WIDTH_BLOCK_NUMBER-1


// Final destination = center of the maze
#define GOAL_IN_MAZE_CENTER
#ifdef GOAL_IN_MAZE_CENTER
	#define GOAL_LEFT_DOWN_CORNER_X MAZE_WIDTH/2 - 1;
	#define GOAL_LEFT_DOWN_CORNER_Y MAZE_HEIGHT/2 - 1;

#else
// Another final destination for tests
	#define GOAL_LEFT_DOWN_CORNER_X MAZE_WIDTH - 1;
	#define GOAL_LEFT_DOWN_CORNER_Y MAZE_HEIGHT - 1;

#endif




// POSITION struct
typedef struct Position
{
	uint8_t x;
	uint8_t y;
}Position;


// WALLS orientation
typedef enum
{
	NoWall = 0,
	North=128,
	South=8,
	East=2,
	West=32
}Wall;


// MAZE struct
typedef struct Maze
{
	uint8_t Wall[MAZE_WIDTH][MAZE_LENGTH];
	uint8_t Cost[MAZE_WIDTH][MAZE_LENGTH];
}Maze;



void Maze_Init(Maze *_Maze); // init
void Maze_FloodFill(Maze *_Maze); // floodfill algorithm
void Maze_AddWall(Maze *_Maze, Position *_Position, Wall _Wall );
void Maze_ResetWalls(Maze *_Maze);
void Maze_ResetCosts(Maze *_Maze);
uint8_t Maze_is_Wall(Maze *_Maze, Position *_Position, Wall _Wall );
Wall Maze_isEdge(uint8_t _x, uint8_t _y);


#endif /* INC_MAZE_H_ */
