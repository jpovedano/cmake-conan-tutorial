#include <iostream>
#include "asl.hpp"

using namespace ASL;

int main()
{
    std::string mykey = random_key();
    std::cout << "Generated string: " << mykey << std::endl;
    if (mykey.size() == 0) {
        return -1;
    }
}