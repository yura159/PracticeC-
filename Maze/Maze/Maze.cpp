#include "Maze.h"
#include "MCell.h"

Maze::Maze(int n, int m)
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
	if (isBadPoint(i, j)) return MCell();
	return m_field[i * n + j];
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2)
{
	int i = min(i1, i2);
	int j = min(j1, j2);
	if (isBadPoint(i, j) || (i1 != i2 && j1 != j2)) return false;
	MCell* point = &m_field[i * n + j];
	return point->down() || point->right();
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
	return Connection(i1, j1, i2, j2, true);
}

bool Maze::isBadPoint(int i, int j) const
{
	return i < 0 || j < 0 || j >= m || i >= n;
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
				return right ? 192 : '0';
		}
	}
	else {
		if (down) {
			if (left)
				return right ? 194 : 191;
			else
				return right ? 218 : '0';
		}
		else {
			if (left)
				return right ? 196 : '0';
			else
				return '0';
		}
	}
}

bool Maze::Connection(int i1, int j1, int i2, int j2, bool connetion)
{
	int i = min(i1, i2);
	int j = min(j1, j2);
	if (i < 0 || j < 0 || j >= m || i >= n) return false;
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
	bool dirLeft, dirRight, dirDown, dirUp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dirRight = cell(i, j).m_right;
			dirDown = cell(i, j).m_down;
			dirUp = hasConnection(i - 1, j, i, j);
			dirLeft = hasConnection(i, j - 1, i, j);
			cout << getSymbol(dirUp, dirDown, dirLeft, dirRight);
		}
		cout << endl;
	}
}
