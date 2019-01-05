
#include "gtest/gtest.h"
#include "asl.hpp"

using namespace ASL;

TEST(asltest, nonempty)
{
    std::string mykey = generate_random_key();
    EXPECT_NE(0, mykey.size());
}