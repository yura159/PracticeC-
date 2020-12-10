#include "SLList.h"
#include "iostream"

using namespace std;

void printSLList(const SLList* list)
{
	auto elem = (SLList*)list;
	while (elem->hasNext())
	{
		cout << elem->getData() << " ";
		elem = elem->next();
	}
	cout << endl;
}

bool FindElement(int data, SLList* list)
{
	auto current = list;
	while (current->hasNext())
	{
		if (data == current->getData())
			return true;
		current = current->next();
	}
	if (data == current->getData()) return true;
	return false;
}

SLList* DeleteEqualData(SLList* list)
{
	auto resultList = SLList::beginList(list->getData());
	auto current = resultList;
	int data;
	while (list->hasNext())
	{
		list = list->next();
		data = list->getData();
		if (FindElement(data, resultList)) continue;
		current = current->addElement(data);
	}
	return resultList;
}

void FindElementN(SLList* list, int n)
{
	int count = 0;
	auto current = list;
	while (current->hasNext())
	{
		count++;
		current = current->next();
	}
	if (count < n)
	{
		cout << "Error, lenght list < N";
		return;
	}
	current = list;
	while (n != count)
	{
		count--;
		current = current->next();
	}

	cout << current->getData() << endl;
}

int main()
{
	auto firstElement = SLList::beginList(rand() % 6);
	auto element = firstElement;
	for (int i = 0; i < 9; i++)
	{
		element->addElement(rand() % 6);
		element = element->next();
	}
	printSLList(firstElement);
	auto newList = DeleteEqualData(firstElement);
	printSLList(newList);
	for (int i = 0; i < 9; i++)
	{
		FindElementN(firstElement, i + 1);
	}
}