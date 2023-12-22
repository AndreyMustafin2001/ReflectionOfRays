#include "lines.cpp"
#include <gtest/gtest.h>
#include <cmath>
TEST(F,A)
{
    std::vector<std::pair<int, int>> pairs = {{1,1},{-1,1}};
    std::vector<std::pair<int, int>> pairs1 = {{1,1},{1,1},{-1,1}};
    std::vector<std::pair<int, int>> pairs2 = {{-1,1},{1,2},{-1,4},{5,4},{-6,4},{2,4}};

    ASSERT_EQ(true,isSymmetricExists(pairs));
    ASSERT_EQ(0,straightline(pairs));
    ASSERT_EQ(false,isSymmetricExists(pairs1));
    ASSERT_EQ(false,isSymmetricExists(pairs2));
}

int main(int argc,char* argv[])
{
   testing::InitGoogleTest(&argc,argv);
   return RUN_ALL_TESTS();
}

