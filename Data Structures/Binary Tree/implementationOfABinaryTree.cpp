#include<iostream>
#include<queue>
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
    cout << "Enter Data : ";
    cin >> data;
    root = new node(data);

    if(data == -1) {
        return NULL;
    }

    cout << "Enter the Value of Left Child for Node : " << data << endl;
    root -> left = buildBinaryTree(root->left);

    cout << "Enter the Value of Right Child for Node : " << data << endl;
    root -> right = buildBinaryTree(root->right);

    return root;
}

void levelOrderTraversal(node* root) {

    queue<node*> q; //stores addresses of the nodes/elements
    q.push(root);

    while(!q.empty()) {
        
        node* temp = q.front();
        cout << temp -> data <<" ";
        q.pop();

        if(temp -> left) { //if root's left child is not a NULL value then push it into queue
            q.push(temp->left);
        }
        if(temp->right) { //if root's right child is not a NULL value then push it into queue
            q.push(temp->right);
        }
    }
}

void levelOrdertraversalWithSeparator(node* root) {

    //here we are using NULL Value as a Seprator
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {

        node* temp = q.front();
        /* Now here we can't write temp -> data beacause of in some cases temp may be pointing to
           NULL value so in that case it becomes NULL -> data which leads to Segmentation Fault. */
        q.pop();

        if(temp == NULL) { // all the elements of that level are traversed so for next level tap enter.
            cout << endl;

            if(!q.empty()) { // may be some child of previous level are left in the queue.
                q.push(NULL);
            }
        }
        else {
            cout << temp -> data << " ";

            if(temp -> left) {
                q.push(temp -> left);
            }
            if(temp -> right) {
                q.push(temp->right);
            }
        }
    }
}

void inorder(node* root) {

    if(root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root -> data << " ";
    inorder(root->right);
}

void preorder(node* root) {

    if(root == NULL) {
        return;
    }

    cout << root -> data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) {

    if(root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root -> data << " ";
}

void buildFromLevelOrder(node* &root) { // root must be passed throgh referance variable.

    int data;
    cout << "Enter Data : ";
    cin >> data;
    root = new node(data);

    queue<node*> q;
    q.push(root);

    while(!q.empty()) {

        node* temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter Left child's Value for Node : " << temp -> data << endl; 
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter Right child's Value for Node : " << temp -> data << endl;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main() {

    node* root = NULL;

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // root = buildBinaryTree(root);

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelOrder(root);

    cout << endl;
    cout << "Printing Level Order Traversal : " << endl;
    levelOrderTraversal(root);

    cout << endl;
    cout << "Printing Level Order Traversal with Separator : " << endl;
    levelOrdertraversalWithSeparator(root);

    cout << "Printing Inorder : " << endl;
    inorder(root);

    cout << endl;
    cout << "Printing Preorder : " << endl;
    preorder(root);

    cout << endl;
    cout << "Printing Postorder : "<< endl;
    postorder(root);

    return 0;
}