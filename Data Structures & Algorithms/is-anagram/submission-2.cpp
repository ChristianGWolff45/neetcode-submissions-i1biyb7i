class Solution {
public:
    bool isAnagram(string s, string t) {
	int diff = 0;
	if (s.size() != t.size())
	{
		return false;
	}
	int arr[26] = {};
	for (int i = 0; i < s.size(); i++)
	{
		if (++arr[s[i] - 'a'] == 1)
		{
			diff++;
		}
		else if (arr[s[i] - 'a'] == 0)
		{
			diff--;
		}
		if (--arr[t[i] - 'a'] == -1)
		{
			diff++;
		}
		else if (arr[t[i] - 'a'] == 0)
		{
			diff--;
		}
	}
	return diff == 0;
}
};
