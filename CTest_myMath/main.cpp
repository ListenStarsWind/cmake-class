#include<iostream>
#include<MyMath/math.h>
#include<cassert>

int main()
{
    assert(add(2,3) == 5);
    assert(sub(2,3) == 1);

    std::cout<<"Test OK!"<<std::endl;

    return 0;
}