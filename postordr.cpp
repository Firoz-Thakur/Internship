#include <bits/stdc++.h> 
using namespace std; 
  
struct Node { 
  
    int data; 
    Node *left, *right; 
}; 
  
// Function to create a new node with the given data 
Node* newNode(int data) 
{ 
    Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
} 

void postOrderIterative(Node* root) 
{ 
    if (root == NULL) 
        return; 
  
    stack<Node *> s1, s2; 
    s1.push(root); 
    Node* node; 
  
    // Run while first stack is not empty 
    while (!s1.empty()) { 
        // Pop an item from s1 and push it to s2 
        node = s1.top(); 
        s1.pop(); 
        s2.push(node); 
  
        // Push left and right children 
        // of removed item to s1 
        if (node->left) 
            s1.push(node->left); 
        if (node->right) 
            s1.push(node->right); 
    } 
  
    // Print all elements of second stack 
    while (!s2.empty()) { 
        node = s2.top(); 
        s2.pop(); 
        cout << node->data << " "; 
    } 
} 
  
// Driver code 
int main() 
{ 
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("outp.txt", "w", stdout);
    #endif

    Node* root = NULL; 
    root = newNode(5); 
    root->left = newNode(3); 
    root->right = newNode(6); 
    root->left->left = newNode(42); 
    root->left->right = newNode(43); 
    root->right->left = newNode(11); 
    root->right->right = newNode(7); 
  
    postOrderIterative(root); 
  
    return 0; 
} 


Output : 42 43 3 11 7 6 5 
