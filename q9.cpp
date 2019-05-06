#include<iostream> 
#include <list> 
using namespace std; 
  
class Hash 
{ 
    int BUCKET;
  
    list <int> *table; 
    public: 
    Hash(int V);
  
    void insertItem(int x); 
    
    int hashFunction(int i) 
    { 
        return ((2*i+5) % BUCKET); 
    } 
  
    void displayHash(); 
}; 
  
Hash::Hash(int b) 
{ 
    this->BUCKET = b; 
    table = new list<int>[BUCKET]; 
} 
  
void Hash::insertItem(int key) 
{ 
    int index = hashFunction(key); 
    table[index].push_back(key);  
} 
  
void Hash::displayHash() 
{ 
    for (int i = 0; i < BUCKET; i++) 
    { 
        cout << i; 
        for (auto x : table[i]) 
            cout << " --> " << x; 
        cout << endl; 
    } 
} 
  
int main() 
{ 
    int a[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5}; 
    int n = sizeof(a)/sizeof(a[0]); 
    Hash h(11);
    for (int i = 0; i < n; i++)  
    {
        h.insertItem(a[i]);   
    }
    h.displayHash(); 
    return 0; 
} 