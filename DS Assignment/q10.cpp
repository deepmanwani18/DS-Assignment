#include<bits/stdc++.h>
using namespace std;
   
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
   
struct node *newNode(int item) 
{ 
    struct node *temp = (struct node *)malloc(sizeof(struct node)); 
    temp -> key = item; 
    temp -> left = temp -> right = NULL; 
    return temp; 
} 

static int c = 0;
   
void inorder(struct node *root, int a, int b) 
{
    if (root != NULL) 
    { 
        inorder(root -> right, a, b); 
        if (c <= a)
            cout << "Samosa : "; 
        else if (c > a && c <= a + b)
            cout << "Gulab Jamun : ";
        else
            return;
        cout << root -> key << endl;
        c++;
        inorder(root -> left, a, b);
    } 
} 
   
struct node* insert(struct node* node, int key) 
{ 
    if (node == NULL) 
        return newNode(key); 
  
    if (key < node->key) 
        node -> left  = insert(node -> left, key); 
    
    else if (key > node->key) 
        node -> right = insert(node -> right, key);    
  
    return node; 
} 
   
int main() 
{ 
    int arr[] = {98, 26, 84, 72, 83, 94, 90, 78, 91, 99, 66, 82, 86, 55, 43, 60, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    struct node *root = NULL; 
    root = insert(root, arr[0]);
    for(int i = 1; i < n; i++)
    {
        insert(root, arr[i]);
    } 
    inorder(root, log(n), sqrt(n)); 
   
    return 0; 
}