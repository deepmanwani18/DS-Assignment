#include <bits/stdc++.h>
using namespace std;

class ClearableStack
{
	stack <int> s;	

public:
	void push(int x)
	{
		s.push(x);
	}
	void pop()
	{
		s.pop();
	}
	void clearstack()
	{
		while(!s.empty())
			s.pop();
	}
};

int main()
{
	ClearableStack cs;
	cs.push(1);
	cs.push(2);
	cs.push(3);
	cs.clearstack();
	return 0;
}