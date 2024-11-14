#include<iostream>
using namespace std;

class node {
    
    public : 
        int data;
        node* left;
        node* right;

        node(int d) {
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }
};

node* buildBinaryTree(node* root) {

    int data;
    cout << " Enter Data : ";
    cin >> data;
    root = new node(data);

    if(data == -1) {
        return NULL;
    }

    cout << "Enter Left Child for : " << root -> data << endl;
    root -> left = buildBinaryTree(root->left);

    cout << "Enter Right Child for : " << root -> data << endl;
    root -> right = buildBinaryTree(root->right);

    return root;
}

void inorder(node* &root , int &count) {

    if(root == NULL) {
        return;
    }

    inorder(root->left,count);
    if(root -> left == NULL && root -> right == NULL) {
        count++;
    }
    inorder(root->right,count);
}

int noOfLeafNodes(node* &root) {
     int count = 0;
     inorder(root , count);
     return count;
}

int main() {

    node* root = NULL;
    
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildBinaryTree(root);

    cout << "\nNumber Of Leaf Nodes in Binary Tree is : " << noOfLeafNodes(root) << endl; 

    return 0;
}