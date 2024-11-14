#include<iostream>
#include<queue>
using namespace std;

class Node {

    public :
        int data;
        Node* left;
        Node* right;

        Node(int d) {
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }
};

Node* insertIntoBST(Node* root , int d) {

    if(root == NULL) {
        root = new Node(d);
        return root;
    }

    if( d > (root -> data) ) {
        root -> right = insertIntoBST(root->right,d);
    }
    if( d < (root -> data) )  { // worked well with else also
        root -> left = insertIntoBST(root->left,d);
    }

    return root;
}

void takeInput(Node* &root) {

    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root,data);
        cin >> data;
    }
}

bool searchIntoBST(Node* &root , int &value) {

    //base cases
    if(root == NULL) {
        return false;
    }
    if(root -> data == value) {
        return true;
    }

    if( (value > root->data) ) { // here we can use else if also but we consider above condition as base case for better understanding
        return searchIntoBST(root->right,value);
    }
    else {
        return searchIntoBST(root->left,value);
    }
}

bool searchIntoBSTOptimised(Node* root , int &value) { //iterative method also

    Node* temp = root;

    while( temp != NULL) {
        if(temp->data == value) {
            return true;
        }
        else if( (value > temp->data) ) {
            temp = temp -> right;
        }
        else {
            temp = temp -> left;
        }
    }
        return false;
}

Node* minValue(Node* root) {

    Node* temp = root;
    while(temp->left != NULL) {
        temp = temp -> left;
    }
    return temp;
}

Node* maxValue(Node* root) {

    Node* temp = root;
    while(temp->right != NULL) {
        temp = temp ->right;
    } 
    return temp;
}

Node* deleteFromBST(Node* &root , int value) {

    if(root == NULL) {
        return root;
    }

    if(root -> data == value) {

        // if current node has 0 child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        
        // if current node has 1 child
        // has only left child
        if(root->left != NULL && root->right == NULL) {
            Node* temp = root -> left;
            delete root;
            return temp;
        } 

        //has only right child
        if(root->right != NULL && root->left == NULL) {
            Node* temp = root -> right;
            delete root;
            return temp; 
        }

        // if current node has 2 child
        if(root->left != NULL && root->right != NULL) {
            int mini = minValue(root->right) -> data;
            root->data = mini;
            root->right = deleteFromBST(root->right,mini);
            return root;
        }
    }
    else if(value > root->data) {
        root -> right = deleteFromBST(root->right,value);
        return root;
    }
    else {
        root -> left = deleteFromBST(root->left,value);
        return root;
    }
}

void levelOrderTraversal(Node* &root) {

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        cout << temp -> data << " ";
        q.pop();

        if(temp -> left) {
            q.push(temp->left);
        }
        if(temp -> right) {
            q.push(temp->right);
        }
    }
}

int main() {

    Node* root = NULL;

    // 10 8 21 7 27 5 4 3 -1
    takeInput(root);

    cout << "\nPrinting Level Order Traversal" << endl;
    levelOrderTraversal(root);

    cout << "\nEnter Node You want to Search : " << endl ;
    int value;
    cin >> value;
    if(/*searchIntoBST(root,value)*/searchIntoBSTOptimised(root,value)) {
        cout << "Node is Present" << endl;
    }
    else {
        cout << "Node is Absent" << endl;
    }

    cout << "Minimum Value of a Node is : " << minValue(root) -> data << endl;
    cout << "Maximum Value of a Node is : " << maxValue(root) -> data << endl;

    root = deleteFromBST(root,3);

    cout << "\nPrinting Level Order Traversal after Deletion" << endl;
    levelOrderTraversal(root);

    cout << "\nMinimum Value of a Node After Deletion is : " << minValue(root) -> data << endl;
    cout << "Maximum Value of a Node After Deletion is : " << maxValue(root) -> data << endl;

    return 0;
}
