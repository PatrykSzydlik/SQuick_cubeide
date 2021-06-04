/*
 * maze.c
 *
 *  Created on: May 24, 2021
 *      Author: Piotr
 */
#include "maze.h"


// MAZE init
void Maze_Init(Maze *_Maze)
{
	Maze_ResetWalls(_Maze);
	Maze_ResetCosts(_Maze);
}



// Floodfill algorithm
void Maze_FloodFill(Maze *_Maze){
	// tbd
}

// Add walls
void Maze_AddWall(Maze *_Maze, Position *_Position, Wall _Wall )
{
	_Maze->Wall[_Position->x][_Position->y] += _Wall;
}



// Reset walls
void Maze_ResetWalls(Maze *_Maze)
{
	Wall TempWall = NoWall;

	// Reset walls values
	for(int x=0; x<MAZE_WIDTH; x++)
	{
		for(int y=0; y<MAZE_LENGTH; y++)
		{
			_Maze->Wall[x][y] = 0; //Reset wall information on the position (x,y)
			TempWall = Maze_isEdge(x,y); //Check if position (x,y) is on edge

			//if yes, add edge walls to the maze
				if(TempWall != NoWall)
					_Maze->Wall[x][y] += TempWall;

				TempWall = NoWall; // reset tmp
		}
	}
}



// Reset maze costs
void Maze_ResetCosts(Maze *_Maze)
{
	for(int x=0; x<MAZE_WIDTH; x++)
	{
		for(int y=0; y<MAZE_LENGTH; y++)
		{
			_Maze->Cost[x][y] = 0;
		}
	}
}



// Checking if there are walls
uint8_t Maze_is_Wall(Maze *_Maze, Position *_Position, Wall _Wall )
{
	return ((_Maze->Wall[_Position->x][_Position->y]) == _Wall);
}


// checking if there are edges
Wall Maze_isEdge(uint8_t _x, uint8_t _y)
{
	Wall TempWall = NoWall;
		if(_x == 0) TempWall += West;
		if(_x == MAZE_WIDTH) TempWall += East;
		if(_y == 0) TempWall += South;
		if(_x == MAZE_LENGTH) TempWall += North;

	return TempWall;
}

