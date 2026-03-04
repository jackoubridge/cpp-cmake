#include "main.h"

int main()
{
	std::thread t1 (sayHello, 1);
	std::thread t2 (sayHello, 2);
	t1.join();
	t2.join();
	return 0;
}
