#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void sortedInsert(stack<int> &s,int element)
{
	if(s.empty() || ( !s.empty() && s.top() < element ))
	{
		s.push(element);
		return;
	}

	int num = s.top();
	s.pop();

	sortedInsert(s,element);

	s.push(num);
}

void sortStack(stack<int> &stack)
{
	if(stack.empty())
	{
		return;
	}

	int num = stack.top();
	stack.pop();

	sortStack(stack);

	sortedInsert(stack,num);
} 