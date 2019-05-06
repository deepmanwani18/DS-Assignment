#include <bits/stdc++.h>
using namespace std;
  
class Queue
{ 
    stack <int> s1, s2; 
    
    public:
    void enQueue(int x) 
    { 
        s1.push(x); 
    } 
  
    int deQueue() 
    { 
        if (s1.empty() && s2.empty())
        { 
            cout << "Queue is empty"; 
            exit(0); 
        } 
        if (s2.empty())
        { 
            while (!s1.empty()) { 
                s2.push(s1.top()); 
                s1.pop(); 
            } 
        }   
        int x = s2.top(); 
        s2.pop(); 
        return x; 
    } 
}; 
  
int main() 
{ 
    Queue q; 
    while(true)
	{
		cout << "Press 1 to enQueue \nPress 2 to deQueue 2 \nPress 3 to exit \n";
		int choice, x;
		cin >> choice;
		if (choice == 3)
			break;
		switch(choice)
		{
			case 1: cout << "Enter the element" << endl;
					cin >> x;
					q.enQueue(x);
					break;
			case 2: cout << q.deQueue() << endl;
					break;
			default : cout << "Invalid input" << endl;
		}
	}
    return 0; 
}