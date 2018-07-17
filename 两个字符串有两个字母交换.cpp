#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

//Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.
//Input: A = "aaaaaaabc", B = "aaaaaaacb"
//Output: true

bool buddyStrings(string A, string B)    // 注意 1.x=aaaa,y=aaaa  2.x=ab,y=cd 两种情况
{
	int d = 0; int same = 0;
	if ((A.size() != B.size())||A.size()<1||B.size()<1)
		return false;
	string::iterator ita = A.begin();
	string::iterator itb = B.begin();
	map<char, int>ms;
	vector<char>ch1, ch2;
	while (ita != A.end())
	{
		if (*ita != *itb)
		{
			d++;
			ch1.push_back(*ita);
			ch2.push_back(*itb);
		}
		if (d > 2)
			return false;
		ms[*ita]++;
		++ita;
		++itb;
	}
	if (d == 2)
	{
		if (ch1[0] == ch2[1] && ch1[1] == ch2[0])
			return true;
		else
			return false;
	}
	else if (d == 0)
	{
		map<char, int>::iterator itmap = ms.begin();
		for (; itmap != ms.end(); itmap++)
			if (itmap->second > 1)
				return true;
		return false;
	}
	else
		return false;
}

int main()
{
	string a, b;
	cin >> a >> b;
	cout << buddyStrings(a,b) << endl;
	return 0;
}