#ifndef MCell_H
#define MCell_H
class Maze;

class MCell
{
public:
	friend Maze;
	const bool right() { return m_right; };
	const bool down() { return m_down; };
private:
	MCell() {};
	bool m_down = false;
	bool m_right = false;
};

#endif // !MCell_H