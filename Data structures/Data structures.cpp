#pragma once
#include <iostream>
#include <vector>
#include "MyVector.h"





int main() 
{

	mds::MyVector<int> a{1, 5, 4, -2};
	
	std::cout << a.Min() << '\n';

}


