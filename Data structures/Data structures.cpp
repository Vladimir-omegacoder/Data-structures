#pragma once
#include <iostream>
#include <vector>
#include "MyVector.h"





int main()
{

	std::vector<int> a{2, 5, -2, -10, 32, 94, 12, 13, -7, -17};
	a.push_back(1);
	a.push_back(2);
	std::cout << "capacity: " << a.capacity() << '\t' << "size: " << a.size() << '\n';
	std::cout << a[5] << '\n';

}


