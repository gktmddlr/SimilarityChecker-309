
#include <string>

using namespace std;

constexpr int MAX_LENGTH_SCORE = 60;
constexpr int MIN_LENGTH_SCORE = 0;

class SimilarChecker
{
public:


	int getLengthScore(const string& str1, const string& str2)
	{
		int value;
		if (isMaxLengthScore(str1, str2)) return MAX_LENGTH_SCORE;
		if (isMinLengthScore(str1, str2)) return MIN_LENGTH_SCORE;
		return getPartialLengthScore(str1, str2);
	}
private:
	bool isMaxLengthScore(const string& str1, const string& str2)
	{
		if (str1.length() == str2.length())
		{
			return true;
		}
		return false;
	}
	bool isMinLengthScore(const string& str1, const string& str2)
	{
		auto min_len = min(str1.length(), str2.length());
		auto max_len = max(str1.length(), str2.length());

		if (max_len >= min_len * 2)
		{
			return true;
		}
		return false;
	}
	int getPartialLengthScore(const string& str1, const string& str2)
	{
		auto min_len = min(str1.length(), str2.length());
		auto max_len = max(str1.length(), str2.length());

		return (1 - (static_cast<double>(max_len - min_len) / min_len)) * 60;
	}
};