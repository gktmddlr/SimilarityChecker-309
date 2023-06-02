
#include <string>
#include <vector>

using namespace std;

constexpr int MAX_LENGTH_SCORE = 60;
constexpr int MIN_LENGTH_SCORE = 0;
constexpr int MAX_ALPHA_SCORE = 40;
constexpr int MIN_ALPHA_SCORE = 0;

class SimilarChecker
{
public:

	int getLengthScore(const string& str1, const string& str2)
	{
		if (isMaxLengthScore(str1, str2)) return MAX_LENGTH_SCORE;
		if (isMinLengthScore(str1, str2)) return MIN_LENGTH_SCORE;
		return getPartialLengthScore(str1, str2);
	}

	int getAlphaScore(const string& str1, const string& str2)
	{
		vector<bool> alpha_str1 = getAlphabetCheckVector(str1);
		vector<bool> alpha_str2 = getAlphabetCheckVector(str2);
		int total_cnt = getAlphabetTotalCount(alpha_str1, alpha_str2);
		int same_cnt = getAlphabetSameCount(alpha_str1, alpha_str2);
		return static_cast<double>(same_cnt) / total_cnt * 40;
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

	vector<bool> getAlphabetCheckVector(const string& str1)
	{
		vector<bool> result(26, false);
		for(auto ch : str1)
		{
			result.at(ch - 'A') = true;
		}
		return result;
	}

	int getAlphabetTotalCount(vector<bool>& alpha_str1, vector<bool>& alpha_str2)
	{
		int result = 0;
		for(int i = 0; i < alpha_str1.size(); i++)
		{
			if(alpha_str1[i] || alpha_str2[i])
			{
				result++;
			}
		}
		return result;
	}

	int getAlphabetSameCount(vector<bool>& alpha_str1, vector<bool>& alpha_str2)
	{
		int result = 0;
		for (int i = 0; i < alpha_str1.size(); i++)
		{
			if (alpha_str1[i] && alpha_str2[i])
			{
				result++;
			}
		}
		return result;
	}
};