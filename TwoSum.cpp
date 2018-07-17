#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
//#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector <int> resault;
		map<int, int>number;
		int i;
		for (i = 0; i<nums.size(); i++)
		{
			number[nums[i]] = i;
		}
		map<int, int>::iterator p;  //迭代器
		for (i = 0; i<nums.size(); i++)
		{
			int tmp = target - nums[i];
			p = number.find(tmp);
			if (p != number.end() && p->second != i)   //灵活运用 p->first 和 p->second
			{
				resault.push_back(i);
				resault.push_back(p->second);
				return resault;
			}
		}
		throw "cannot find numbers!\n";
		return resault;
	}
};

