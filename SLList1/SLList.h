#ifndef SLList_H
#define SLList_H

#include <iostream>

class SLList
{
public:
	const int getData() const { return m_data; };
	void setData(int data) { m_data = data; };
	SLList* next();
	bool hasNext() const;
	static SLList* beginList(int data);
	SLList* addElement(int data);
	void removeNext();

private:
	SLList(int data);
	SLList* m_nextElem;
	int m_data;
};
#endif // !SLList_H

