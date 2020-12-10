#include "Maze.h"
#include "MTreeNode.h"

int main()
{
	Maze mase = Maze(5, 5);
	auto* tree = MTreeNode::beginTree(0, 0);
	for(int i = 0; i < mase.M(); i++)
		mase.makeConnection(i, 0, i + 1, 0);
	for (int i = 0; i < mase.M(); i++) 
	{
		mase.makeConnection(i - 1, i, i, i);
		mase.makeConnection(i, i, i, i + 1);
	}
	for (int i = 0; i < mase.M(); i++)
	{
		for (int j = i + 1; j < mase.N(); j++)
		{
			mase.makeConnection(i, j, i, j + 1);
			if (i + 1 == j)
				for (int i1 = i + 1; i1 < mase.M(); i1++)
					mase.makeConnection(i1, j, i1 + 1, j);
		}
	}
	mase.printMaze();

	for (int i = 0; i < mase.M(); i++) {
		for (int j = 0; j < mase.N(); j++) {
			if (i != 0 || j != 0) {
				if (i != 0 && mase.hasConnection(i - 1, j, i, j))
					tree->hasChild(i - 1, j)->addChild(i, j);
				else if (j != 0 && mase.hasConnection(i, j - 1, i, j))
					tree->hasChild(i, j - 1)->addChild(i, j);
			}
		}
	}

	cout << endl;

	for (int i = 0; i < mase.M(); i++)
	{
		for (int j = 0; j < mase.N(); j++)
		{
			auto child = tree->hasChild(i, j);
			if (child != nullptr)
				cout << child->distance();
			else
				cout << 0;
		}
		cout << endl;
	}
}