#ifndef Maze_H
#define Maze_H

#include <iostream>
#include <algorithm>

using namespace std;

class MCell;

class Maze
{
public:
	Maze(int n, int m);
	~Maze();
	const int N() { return n; };
	const int M() { return m; };
	const MCell& cell(int i, int j) const;
	bool hasConnection(int i1, int j1, int i2, int j2);
	bool makeConnection(int i1, int j1, int i2, int j2);
	bool removeConnection(int i1, int j1, int i2, int j2);
	void printMaze();

private:
	MCell* m_field = nullptr;
	int n;
	int m;
};

#endif // !Maze_H