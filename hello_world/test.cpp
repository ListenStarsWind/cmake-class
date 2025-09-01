#include<iostream>
#include<cassert>

int main()
{
    assert(1 + 2 == 3);
    assert(1 + 2 == 4);
    std::cout << "test passed!" << std::endl;
    return 0;
}