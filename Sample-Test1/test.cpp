#include "pch.h"
#include "../Project11/SimilarChecker.cpp"

class SimilarCheckerTest : public testing::Test
{
public:
	SimilarChecker checker;
};

TEST(SimilarCheckerTest, SP) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}