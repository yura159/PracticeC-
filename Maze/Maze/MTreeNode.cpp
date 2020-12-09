#include "MTreeNode.h"

using namespace std;

MTreeNode* MTreeNode::child(int i) const
{
    return i >= m_countChildren && m_children == nullptr ? nullptr : &m_children[i];
}

bool MTreeNode::addChild(int i, int j)
{
    m_countChildren++;
    MTreeNode* children = new MTreeNode[m_countChildren];
    for (int i = 0; i < m_countChildren - 1; i++)
        children[i] = m_children[i];
    auto child = new MTreeNode(this);
    child->m_i = i;
    child->m_j = j;
    child->m_distance = m_distance + 1;
    children[m_countChildren - 1] = *child;
    m_children = children;
    return true;
}

MTreeNode* MTreeNode::hasChild(int i, int j)
{
    if (m_i == i && m_j == j) return this;
    for (int index = 0; index < m_countChildren; index++)
    {
        auto ch = child(index);
        if (ch != nullptr)
        {
            ch = ch->hasChild(i, j);
            if (ch != nullptr) return ch;
        };
    }
    return nullptr;
}
 
 MTreeNode* MTreeNode::beginTree(int i, int j)
{
    auto node = new MTreeNode(nullptr);
    node->m_i = i;
    node->m_j = j;
    return node;
}

MTreeNode::MTreeNode(MTreeNode* parent)
{
    m_parent = parent;
}
