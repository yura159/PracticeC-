#ifndef MTreNode_H
#define MTreeNode_H

class MTreeNode
{
public:
	int i() const { return m_i; };
	int j() const { return m_j; };
	const MTreeNode* parent() const { return m_parent; };
	MTreeNode* child(int i) const;
	int distance() const { return m_distance; };
	int childCount() const { return m_countChildren; };
	bool addChild(int i, int j);
	MTreeNode* hasChild(int i, int j);
	static MTreeNode* beginTree(int i, int j);

private:
	int m_countChildren = 0;
	int m_i = 0, m_j = 0;
	int m_distance = 0;
	MTreeNode* m_parent;
	MTreeNode* m_children;	
	MTreeNode(){};
	MTreeNode(MTreeNode* parent);
};
#endif // !MTreNode


