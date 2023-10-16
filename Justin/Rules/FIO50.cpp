#include <fstream>
#include <string>

int main()
{
    std::string fileName = "Security.txt";
    std::fstream file(fileName);
    std::string inputString;

    file << "The output stream...";
    /* intervening position call removing undefined behavior */
    file.seekg(0, std::ios::beg); 
    file >> inputString;

    return 0;
}