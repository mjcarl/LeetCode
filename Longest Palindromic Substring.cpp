#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

string longestPalindrome(string s)
{
	string t;
	int i,n=0,max=0;
	if (s.size() == 0)
	{
		return "";
	}
	t = "$#";
	for (i = 0; i < s.size(); i++)
	{
		t += s[i];
		t += '#';
	}
	t += '$';
	string::iterator iter = t.begin();
	string::iterator p;
	string::iterator q;
	string::iterator it;
	iter++;
	iter++;
	while (*iter != '$')
	{
		p = q = iter;
		--p; ++q;
		n = 0;
		while (*p!='$'&&*q!='$'&&*p == *q)
		{
			--p; ++q;
			++n;
		}
		if (n > max)
		{
			it = iter;
			max = n;
		}
		++iter;
	}
	string re;
	n = max;
	while (n > 0)
	{
		--it;
		--n;
	}
	while (n < (2 * max))
	{
		if (*it != '#')
			re += *it;
		++it;
		++n;
	}
	return re;
}

void main()
{
	string s = "aac";
	cout << longestPalindrome(s) << endl;
}






//ZMT
//class Solution {
//public:
//	string expandAroundCenter(string s, int l, int r) {
//		int n = s.size();
//		while (l >= 0 && r <= n - 1 && s[l] == s[r]) {
//			l--;
//			r++;
//		}
//		return s.substr(l + 1, r - l - 1);
//	}
//	string longestPalindrome(string s) {
//		int len = s.size();
//		if (len == 0)
//			return "";
//		string longestStr = s.substr(0, 1);
//		int i;
//		string s1, s2;
//		for (i = 0; i<len - 1; i++) {
//			s1 = expandAroundCenter(s, i, i);
//			if (s1.size()>longestStr.size())
//				longestStr = s1;
//			s2 = expandAroundCenter(s, i, i + 1);
//			if (s2.size()>longestStr.size())
//				longestStr = s2;
//		}
//		return longestStr;
//	}
//};