#include "SLList.h"

SLList* SLList::next()
{
	return m_nextElem;
}

bool SLList::hasNext() const
{
	return m_nextElem != nullptr;
}

SLList* SLList::beginList(int data)
{
	return new SLList(data);
}

SLList* SLList::addElement(int data)
{
	if (hasNext())
		return nullptr;
	auto x = new SLList(data);
	m_nextElem = x;
	return m_nextElem;
}

void SLList::removeNext()
{
	if (!hasNext()) return;
	auto nextElem = next();
	while (nextElem->hasNext())
	{
		auto elem = nextElem->next();
		delete nextElem;
		nextElem = elem;
	}
	delete nextElem;
}

SLList::SLList(int data) : m_data(data), m_nextElem(nullptr){}