#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int len = nums1.size() + nums2.size();
	int x = 0, y = 0;
	int i = 0;

	if (len == 0)
		return 0;
	else if (nums1.size() == 0)
	{
		vector<int> ::iterator q = nums2.begin();
		if (len % 2 == 0)
		{
			while (i != (len / 2 - 1))
			{
				i++;
				q++;
			}
			x = *q;
			y = *(++q);
			return ((double)(x + y) / 2);
		}
		else
		{
			while (i != len / 2 )
			{
				i++;
				q++;
			}
			return (double)*q;
		}
	}
	else if (nums2.size() == 0)
	{
		vector<int> ::iterator p = nums1.begin();
		if (len % 2 == 0)
		{
			while (i != (len / 2 - 1))
			{
				i++;
				p++;
			}
			x = *p;
			y = *(++p);
			return ((double)(x + y) / 2);
		}
		else
		{
			while (i != len / 2)
			{
				i++;
				p++;
			}
			return (double)*p;
		}
	}
	else
	{
		vector<int> ::iterator p = nums1.begin();
		vector<int> ::iterator q = nums2.begin();
		vector<int> ::iterator m;
		if (len % 2 == 0)  //偶数个 --------------
		{		
			for (i = 0; i < (len / 2 - 1); i++)
			{
				if (*p < *q)   //nums1小于nums2
				{
					p++;
					if (p == nums1.end())
					{
						p--;
						i++;
						while (i < (len / 2 - 1))
						{
							q++;
							i++;
						}
						x = *q;
						y = *(++q);
						return ((double)(x + y) / 2);
					}
				}
				else if(*p > *q)   //nums1大于nums2
				{
					q++;
					if (q == nums2.end())
					{
						q--;
						i++;
						while (i < (len / 2 - 1))
						{
							p++;
							i++;
						}
						x = *p;
						y = *(++p);
						return ((double)(x + y) / 2);
					}
				}
				else   //nums1等于nums2
				{
					p++; q++;
					if (p == nums1.end())
					{
						p--;
						q--;
						i++;
						while (i < (len / 2 - 1))
						{
							q++;
							i++;
						}
						x = *q;
						y = *(++q);
						return ((double)(x + y) / 2);
					}
					else if(q == nums2.end())
					{
						q--; p--;
						i++;
						while (i < (len / 2 - 1))
						{
							p++;
							i++;
						}
						x = *p;
						y = *(++p);
						return ((double)(x + y) / 2);
					}
					else
					{
						if (*p < *q)
							q--;
						else if (*p > *q)
							p--;
						else
						{
							++i;
							if (i == (len / 2 - 1))
							{
								--q;
							}
						}
					}
				}
			}
			m = q;
			m++;
			if(*p > *q)
				if((q!=--nums2.end())&& (*p > *m))
					return ((double)(*q + *(++q)) / 2);
			m = p;
			m++;
			if (*p < *q)
				if ((p!=--nums1.end())&&(*m < *q))
					return ((double)(*p + *(++p)) / 2);
			return ((double)(*p+*q)) / 2;
		}
		else   //奇数个
		{
			for (i = 0; i < len / 2; i++)
			{
				if (*p < *q)
				{
					p++;
					if (p == nums1.end())
					{
						p--;
						i++;
						while (i < len / 2)
						{
							q++;
							i++;
						}
						return (double)*q;
					}
				}
				else if(*p > *q)
				{
					q++;
					if (q == nums2.end())
					{
						q--;
						i++;
						while (i < len / 2)
						{
							p++;
							i++;
						}
						return (double)*p;
					}
				}
				else   //nums1等于nums2
				{
					p++; q++;
					if (p == nums1.end())
					{
						p--; q--;
						i++;
						while (i < len / 2)
						{
							q++;
							i++;
						}
						return (double)*q;
					}
					else if (q == nums2.end())
					{
						q--; p--;
						i++;
						while (i < len / 2)
						{
							p++;
							i++;
						}
						return (double)*p;
					}
					else
					{
						if (*p < *q)
							q--;
						else if (*p > *q)
							p--;
						else
							++i;
					}
				}
			}
			if (*p < *q)
				return (double)*p;
			else
				return (double)*q;

		}
	}
}
int main()
{
	//vector<int> b = {3};
	//vector<int> a = {1,2,4,5,7};
	vector<int> a = { 1,2};
	vector<int> b = { 1,2 };
	double mid = 0;
	mid = findMedianSortedArrays(a, b);
	cout <<"mid=" << mid << endl;
}