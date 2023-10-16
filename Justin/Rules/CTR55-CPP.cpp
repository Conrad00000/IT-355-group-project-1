#include <iostream> 
#include <algorithm>
#include <vector>

int main()
{
    /* compliant code */
    std::vector<int> myVector{1, 3, 5, 7};
    const std::vector<int>::size_type size = 20;

    //min makes sure we won't step out of bounds of the container
    for(auto i = myVector.begin(), e = i + std::min(size, myVector.size()); i != e; i++)
    {
        std::cout << "No buffer overflows here!!" << std::endl;
    }
    
    return 0;
}