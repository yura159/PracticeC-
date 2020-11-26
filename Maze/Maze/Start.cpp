#include "Maze.h"

int main()
{
	Maze maze = Maze(5, 5);

	for (int i = 0; i < maze.N(); i++)
	{
		for (int j = 0; j < maze.M(); j++)
		{
			if (i == j && i < maze.N() - 1)
				maze.makeConnection(i, j, i, j + 1);
			if (i == j - 1)
				maze.makeConnection(i, j, i + 1, j);
		}
	}
	maze.printMaze();
}