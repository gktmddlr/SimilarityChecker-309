
#include <string>

using namespace std;

constexpr int MAX_LENGTH_SCORE = 60;
constexpr int MIN_LENGTH_SCORE = 0;

class SimilarChecker
{
public:
	int getLengthScore(const string& str1, const string& str2)
	{
		if(str1.length() == str2.length())
		{
			return MAX_LENGTH_SCORE;
		}
		if(str1.length() > str2.length())
		{
			if(str1.length() >= str2.length() * 2)
			{
				return MIN_LENGTH_SCORE;
			}
		}
		if(str2.length() > str1.length())
		{
			if (str2.length() >= str1.length() * 2)
			{
				return MIN_LENGTH_SCORE;
			}
		}
	}
};