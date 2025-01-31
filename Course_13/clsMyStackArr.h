#pragma once

#include <iostream>
#include "clsMyQueueArr.h"
using namespace std;
template <class T>

class clsMyStackArr : public clsMyQueueArr <T>
{

public :
	
	void push(T Item)
	{
		this->_MyList.InsertAtBeginning(Item);
	}

	T Top()
	{
		return this->front();
		
	}

	T Bottom()
	{
		return this->back(); 

	}
	
};

