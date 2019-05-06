#include <bits/stdc++.h>
using namespace std;

class DualStack
{ 
    int *arr; 
    int size; 
    int top1, top2; 
	public: 
	DualStack(int MaxSize)
	{ 
		size = MaxSize; 
		arr = new int[MaxSize]; 
		top1 = -1; 
		top2 = size; 
	} 

	bool IsFull()
	{
		if (top1 >= top2 - 1)
		{
			cout << "Stack Overflow\n"; 
			return 1;
		}
		return 0;
	}

	void push1(int x) 
	{ 
		if (!IsFull()) 
		{ 
			top1++; 
			arr[top1] = x; 
		}
		else
		{
			exit(1);
		} 
	} 

	void push2(int x) 
	{ 
		if (!IsFull()) 
		{ 
			top2--; 
			arr[top2] = x; 
		}
		else
		{
			exit(1);
		} 
	} 

	int pop1() 
	{ 
	   if (top1 >= 0 ) 
	   { 
	      int x = arr[top1]; 
	      top1--; 
	      return x; 
	   } 
	   else
	   { 
	       cout << "Stack UnderFlow"; 
	       exit(1); 
	   } 
	} 

	int pop2() 
	{ 
	   if (top2 < size) 
	   { 
	      int x = arr[top2]; 
	      top2++; 
	      return x; 
	   } 
	   else
	   { 
	       cout << "Stack UnderFlow"; 
	       exit(1); 
	   } 
	} 
};

int main(){
	int MaxSize;
	cout << "Enter the size of array" << endl;
	cin >> MaxSize;
	DualStack ds(MaxSize);
	int choice, x;
	while(true)
	{
		cout << "Press 1 to push in stack 1 \nPress 2 to push in stack 2 \nPress 3 to pop in stack 1 \nPress 4 to pop in stack 2 \nPress 5 to exit \n";
		cin >> choice;
		if (choice == 5)
			break;
		switch(choice)
		{
			case 1: cout << "Enter the element" << endl;
			cin >> x;
			ds.push1(x);
			break;
			case 2: cout << "Enter the element" << endl;
			cin >> x;
			ds.push2(x);
			break;
			case 3: ds.pop1();
			break;
			case 4: ds.pop2();
			break;
			default : cout << "Invalid input" << endl;
		}
	}
	return 0;
}