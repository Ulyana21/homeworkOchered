#include "iqueue.h" 
#include <iostream>


int main(void)
{
	MyQueue<char> test1;
	MyQueue<char> test2(3);
	test2.put('q');
	test2.put('w');
	test2.put('e');
	test1.put('r');
	test1.put('t');
	std::cout << test1.size() << test1.take() << test2.get(1) << std::endl;
	system("pause");
	return 0;
}