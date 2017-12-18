#include<iostream>
#include <map>
#include <algorithm>
#include <vector>
#include<deque>
using namespace std;

int lengthOfLongestSubstring(string s)
{
	deque<char> deq;
	if (s.size() > 0)
		deq.push_back(s[0]);
	else
		return 0;
	deque<char>::iterator d1, d2;
	int i = 1;
	int dis = 1, maxlen = 1;
	while (i < s.size())
	{		
		deq.push_back(s[i]);
		dis++;
		d1 = deq.begin();
		while (d1 != (--deq.end()) && *d1 != s[i])  //顺序不能放反了
		{			
			d1++;
		}
		if (d1 != (--deq.end()))
		{			
			d2 = deq.begin();
			d1++;
			while (d2 != d1)
			{
				d2++;
				deq.pop_front();				
				dis--;
			}
		}		
		i++;
		if (maxlen < dis)
			maxlen = dis;
	}
	return maxlen;
}

void main()
{
	int maxlen = 0;
	char s[20] = "ynyo";
	//cin >> s;
	maxlen = lengthOfLongestSubstring(s);
	cout << maxlen << endl;
}