#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

#define N 3
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) 
	{ }
};

ListNode* create()
{
	struct ListNode *head;
	struct ListNode *p1,*p2;
	int i = 0;
	p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	cout << "--------------" << endl;
	scanf("%d", &p1->val);
	head = p1;
	p2 = p1;
	i++;
	while (i < N)
	{			
		p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
		scanf("%d", &p1->val);
		p2->next = p1;
		p2 = p1;
		i++;
	}
	p2->next = NULL;
	return head;
}
void print(ListNode* add)
{
	struct ListNode *p;
	p = add;
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	struct ListNode *add, *p,*head;
	add = (struct ListNode*)malloc(sizeof(struct ListNode));
	p = (struct ListNode*)malloc(sizeof(struct ListNode));
	int sum=0,yu=0;
	int a = 0, b = 0 ,n = 0;

	while (l1!=NULL || l2!=NULL)
	{
		if (l1 == NULL)
		{
			a = 0;
			b = l2->val;
			l2 = l2->next;
		}
		else if (l2 == NULL)
		{
			a = l1->val;
			b = 0;
			l1 = l1->next;
		}
		else
		{
			a = l1->val;
			b = l2->val;
			l1 = l1->next;
			l2 = l2->next;
		}
		
		sum = sum + a + b;
		if (sum < 10)
		{
			add->val = sum;
			sum = 0;
		}
		else
		{
			yu = sum % 10;
			add->val = yu;
			sum = 1;
		}
		p->next = add;
		p = add;
		if (n == 0)
		{
			head = add;
		}
		add = (struct ListNode*)malloc(sizeof(struct ListNode));
		n++;
	}
	if (sum == 1)
	{
		add->val = 1;
		p->next = add;
		p = add;
	}
	p->next = NULL;
	add = head;
	return add;
}

void main()
{
	struct ListNode *l1, *l2, *add;
	add = (struct ListNode*)malloc(sizeof(struct ListNode));
	l1 = create();
	l2 = create();
	//print(l1, l2);
	add = addTwoNumbers(l1,l2);
	print(add);
}