#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include "../LibAI/Puzzle.h"
#include "TileState.h"

using namespace TileProblem;

/* The tile problem:

   An mxn grid contains tiles with the numbers 1..(mxn)-1 through ‘8’ on them.
   Initially these tiles are in a random order. One space is left blank. The
   goal is to arrange the tiles in the correct order.

   -Any tile that is adjacent or diagonal to the blank space can slide into it
   -Two non-blank tiles can be swapped as per the chess "horse move" */

static int getInt(std::string prompt, int min, int max)
{
	// Get int from user and validate input
	std::string input;
	int i;

	while (true)
	{
		std::cout << prompt;
		std::cin >> input;
		std::stringstream ss(input);
		ss >> i;

		if (ss.fail() || i < min || i > max)
			std::cout << "Invalid input. ";
		else
			return i;
	}
}

int main()
{
	int boardMode = getInt("What are the dimensions of the board?\n"
						   "1) 2x4\n"
						   "2) 3x3\n"
						   "3) 2x5\n", 1, 3);
	short width, height;
	if (boardMode == 1)
	{
		width = 4;
		height = 2;
	}
	else if (boardMode == 2)
	{
		width = height = 3;
	}
	else
	{
		width = 5;
		height = 2;
	}

	/*for (int i = 0; i < numPeople; ++i)
	{
		std::stringstream ss;
		ss << "How many time units does person " << i << " take to cross the bridge? ";
		peopleTimes.push_back(getInt(ss.str()));
		ss.clear();
	}
	std::cout << std::endl;*/

	TileState* initial = new TileState(width, height, SHUFFLED);
	TileState* goal = new TileState(width, height, SOLVED);

	AI::Puzzle tilePuzzle(initial, goal, AI::BREADTH_FIRST);
	tilePuzzle.solve();
	return 0;
}