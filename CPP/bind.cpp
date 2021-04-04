#include <iostream>
#include <functional>
#include <algorithm>
#include<vector>

bool divisible(int num , int den)
{
    if(num % den == 0)
        return true;
    return false;
}
int approach_2()
{
    int arr[10] = {1,20,13,4,5,6,10,28,19,15};
    return std::count_if(arr, arr + sizeof(arr)/sizeof(int) , std::bind(&divisible, std::placeholders::_1, 5));
}

int main()
{
    std::cout<<"return "<<approach_2()<<std::endl;
    return 0;
}
