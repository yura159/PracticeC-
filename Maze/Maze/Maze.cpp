#include "Maze.h"
#include "MCell.h"

Maze::Maze(const int n, const int m)
{
	m_field = new MCell[n * m];
	this->n = n;
	this->m = m;
	for (int i = 0; i < n * m; i++)
		m_field[i] = MCell();
}

Maze::~Maze()
{
	delete[] m_field;
}

const MCell& Maze::cell(int i, int j) const
{
	return m_field[i * n + j];
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2)
{
	int i = min(i1, i2);
	int j = min(j1, j2);
	MCell* point = &m_field[i * n + j];
	return point->down() || point->right();
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
	return Connection(i1, j1, i2, j2, true);
}

char Maze::getSymbol(bool up, bool down, bool left, bool right)
{
	if (up) {
		if (down) {
			if (left)
				return right ? 197 : 180;
			else
				return right ? 195 : 179;
		}
		else {
			if (left)
				return right ? 193 : 217;
			else
				return right ? 192 : 1;
		}
	}
	else {
		if (down) {
			if (left)
				return right ? 194 : 191;
			else
				return right ? 218 : 1;
		}
		else {
			if (left)
				return right ? 196 : 1;
			else
				return 1;
		}
	}
	return 1;
}

bool Maze::Connection(int i1, int j1, int i2, int j2, bool connetion)
{
	int i = min(i1, j1);
	int j = min(j1, j2);
	if (i1 == i2)
		m_field[i * n + j].m_right = connetion;
	else
		m_field[i * n + j].m_down = connetion;
	return true;
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2)
{
	return Connection(i1, j1, i2, j2, false);
}

void Maze::printMaze()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			bool dirLeft, dirRight, dirDown, dirUp;
			dirRight = m_field[i * n + j].right();
			dirDown = m_field[i * n + j].down();
			dirUp = i - 1 >= 0 ? m_field[(i - 1) * n + j].down() : false;
			dirLeft = j - 1 >= 0 ? m_field[i * n + j - 1].right() : false;
			char sym = getSymbol(dirUp, dirDown, dirLeft, dirRight);
			cout << sym;
		}
		cout << endl;
	}
}
