#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

inline void swap(int &a, int &b) //用内联函数
{
	int t;
	t = a;
	a = b;
	b = t;
}

int median3(int a[], int low, int high)   //实现三中数中值分割法/三取样切分
{
	int center = (low + high) / 2;
	if (a[low]>a[center])
		swap(a[low], a[center]);
	if (a[low]>a[high])
		swap(a[low], a[high]);
	if (a[center]>a[high])
		swap(a[center], a[high]);
	swap(a[center], a[high - 1]);
	return a[high - 1];      //返回需要移动到正确位置的枢纽元值
}
inline void compare(int a[], int low, int high)
{
	if (a[low]>a[high])
		swap(a[low], a[high]);
}
static void QuickSort(int a[], int low, int high)   //主程序,重复元素较少时
{
	int i, j;
	int pivot;

	i = low;  //警示标记点
	j = high - 1;
	if (i<j) //剩余元素至少为3个
	{
		pivot = median3(a, low, high);
		while (1)
		{
			while (a[++i]<pivot)
			{
			}
			while (a[--j]>pivot)
			{
			}
			if (i<j)
				swap(a[i], a[j]);
			else
				break;
		}
		swap(a[i], a[high - 1]);   //restore pivot
		QuickSort(a, low, i - 1);
		QuickSort(a, i + 1, high);
	}
	else if (i == j)  //只剩两个元素的排序
		compare(a, i, j + 1);
}

static void Quick3way(int a[], int low, int high)  //含有较多重复元素时，三向切分的快速排序法
{
	if (low >= high)
		return;
	int lt = low, i = low + 1, gt = high;
	int pivot = a[low];  //pivot选在最左边
	while (i <= gt)
	{
		if (a[i]<pivot)
		{
			swap(a[lt], a[i]);
			lt++; i++;
		}
		else if (a[i]>pivot)
		{
			swap(a[i], a[gt]);
			gt--;
		}
		else
			i++;
	}
	//现在 a[low..lt-1]<pivot=a[lt..gt]<a[gt+1,,high]
	Quick3way(a, low, lt - 1);
	Quick3way(a, gt + 1, high);
}
int main(void)
{
	int n = 10;
	int a[10]={5,8,2,1,7,9,0,18,4,23};
	Quick3way(a, 0, 9);
	for (int i = 0; i<10; i++)
		cout << a[i] << " ";
	cout << endl;
	int sum = 0;
	for (int i = 0; i < 10; i = i + 2)
		sum = sum + a[i];
	cout << sum << endl;
	return 0;
}