#include <gtest/gtest.h>                // including the library
  
int factorial(int n)
{
    if (n < 0) return -1;   // invalid case
    int prod = 1;
    while (n != 0)
    {
        prod *= n--;
    }
    return prod;
}

TEST(FactorialTest, ZeroTest)  // for factorial of Zero
{
    EXPECT_EQ(1, factorial(0));
}
TEST(FactorialTest, PosTest)   // for factorial of Positive Numbers
{
    EXPECT_EQ(120, factorial(5));
    EXPECT_EQ(1, factorial(1));
    EXPECT_EQ(6, factorial(3));
}
TEST(FactorialTest, NegTest)  // for factorial of Negative Numbers
{
    EXPECT_EQ(-1, factorial(-5));
    EXPECT_EQ(-1, factorial(-1));
    EXPECT_EQ(-1, factorial(-10));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv); // initializing it
    return RUN_ALL_TESTS();               // this will run all your tests
}  
