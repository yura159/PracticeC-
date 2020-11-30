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
	if (i < 0 || j < 0 || j >= m || i >= n) return MCell();
	return m_field[i * n + j];
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2)
{
	int i = min(i1, i2);
	int j = min(j1, j2);
	if (i < 0 || j < 0 || j >= m || i >= n || (i1 != i2 && j1 != j2)) return false;
	MCell* point = &m_field[i * n + j];
	return point->down() || point->right();
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
	int i = min(i1, i2);
	int j = min(j1, j2);
	if (i < 0 || j < 0 || j >= m || i >= n || (i1 != i2 && j1 != j2)) return false;
	if (i1 == i2)
		m_field[i * n + j].m_right = true;
	else
		m_field[i * n + j].m_down = true;
	return true;
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2)
{
	int i = min(i1, i2);
	int j = min(j1, j2);
	if (i < 0 || j < 0 || j >= m || i >= n || (i1 != i2 && j1 != j2)) return false;
	if (i1 == i2)
		m_field[i * n + j].m_right = false;
	else
		m_field[i * n + j].m_down = false;
	return true;
}

void Maze::printMaze()
{
	bool dirLeft, dirRight, dirDown, dirUp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char symbol;
			dirRight = cell(i, j).m_right;
			dirDown = cell(i, j).m_down;
			dirUp = hasConnection(i - 1, j, i, j);
			dirLeft = hasConnection(i, j - 1, i, j);
			if (dirUp) {
				if (dirDown) {
					if (dirLeft)
						symbol = dirRight ? 197 : 180;
					else
						symbol = dirRight ? 195 : 179;
				}
				else {
					if (dirLeft)
						symbol = dirRight ? 193 : 217;
					else
						symbol = dirRight ? 192 : '0';
				}
			}
			else {
				if (dirDown) {
					if (dirLeft)
						symbol = dirRight ? 194 : 191;
					else
						symbol = dirRight ? 218 : '0';
				}
				else {
					if (dirLeft)
						symbol = dirRight ? 196 : '0';
					else
						symbol = '0';
				}
			}
			cout << symbol;
		}
		cout << endl;
	}
}
