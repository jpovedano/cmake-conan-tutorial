
#include "gtest/gtest.h"
#include "asl.hpp"

using namespace ASL;

// int main()
// {
//     std::string mykey = random_key();
//     std::cout << "Generated string: " << mykey << std::endl;
//     if (mykey.size() == 0) {
//         return -1;
//     }
// }
TEST(asltest, nonempty)
{
    std::string mykey = random_key();
    EXPECT_NE(0, mykey.size());
}