#include "pch.h"
#include "../Project11/SimilarChecker.cpp"

class SimilarCheckerTest : public testing::Test
{
public:
	SimilarChecker checker;
};

TEST_F(SimilarCheckerTest, GetMaxLengthScore) {
  EXPECT_EQ(MAX_LENGTH_SCORE, checker.getLengthScore("ASD", "DSA"));
}

TEST_F(SimilarCheckerTest, GetMinLengthScore) {
	EXPECT_EQ(MIN_LENGTH_SCORE, checker.getLengthScore("A", "BB"));
	EXPECT_EQ(MIN_LENGTH_SCORE, checker.getLengthScore("BB", "A"));
}

TEST_F(SimilarCheckerTest, GetPartialLengthScore) {
	EXPECT_EQ(20, checker.getLengthScore("AAABB", "BAA"));
	EXPECT_EQ(20, checker.getLengthScore("BAA", "AAABB"));
	EXPECT_EQ(30, checker.getLengthScore("AA", "AAA"));
}