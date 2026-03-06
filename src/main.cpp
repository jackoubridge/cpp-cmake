#include "main.h"

int main()
{
    std::thread t1 (sayHello, 1);
    std::thread t2 (sayHello, 2);
    t1.join();
    t2.join();

    return 0;
}

void sayHello(int num)
{
    while(true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "Hello " << num << std::endl;
    }
}
