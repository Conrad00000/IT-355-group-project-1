#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    /*Compliant code*/
    std::vector<int> srcVector = {2, 4, 6, 8, 10};
    std::vector<int> destVector(5);

    //The destination vector holds enough space to copy source vector into it. Otherwise buffer overflow or null terminated strings
    std::vector<int> destVector(5); 

    std::cout << "srcVector size: " << srcVector.size() << std::endl;
    std::cout << "srcVector elements: ";

    for(int i = 0; i < srcVector.size(); i++)
    {
        std::cout << srcVector[i] << " ";
    }

    std::cout << "\ndestVector size: " << destVector.size() << std::endl; 
    std::cout << "destVector after copying: "; 
    std::copy(srcVector.begin(), srcVector.end(), destVector.begin());

    for(int i = 0; i < destVector.size(); i++)
    {
        std::cout << destVector[i] << " ";
    }

    return 0;
}
