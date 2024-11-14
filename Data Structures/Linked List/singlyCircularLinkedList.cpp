#include<iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node* next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }

        ~Node() {
            int value = this -> data;
            if(this -> next != NULL) {
                this -> next = NULL;
                delete next;
            }
            cout << "Deleted Node : " << value << endl;
        }
};

void insertAfterElement(Node* &tail , int element , int d) {

    if(tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        tail -> next = temp;
    }
    else {
        Node* temp = tail;//you can use curr also

        while(temp -> data != element) {
            temp = temp -> next;
        }

        //Now temp is pointing to the element

        Node* nodeToInsert = new Node(d);
        nodeToInsert -> next = temp -> next;
        temp -> next = nodeToInsert;
    }
}

void deleteElement(Node* &tail , int element) {
    if(tail == NULL) {
        cout << "List is Empty" << endl;
    }
    else {
         Node* prev = tail ;
    Node* curr = prev -> next;

    while(curr -> data != element) {
        prev = curr;
        curr = curr -> next;
    }

    //curr is pointing that element's node

    if(prev == curr) {
        //only one element is present in the linked list
        //so after deleting that element 
        tail = NULL;
    }

    if(tail == curr) {
        //if your curr element is also the element pointed by tail 
        //then before deletion of that element
        tail = prev;
    }

    prev -> next = curr ->next;
    delete curr;
    }
}

void print(Node* &tail) {
    if(tail == NULL) {
        cout<< "List is Empty "<< endl;
        return;
    }

    Node* temp = tail;

    do {
        cout << temp -> data << " ";
        temp = temp -> next;
    }while(temp != tail);
    cout << endl;
}

int getLength(Node* &tail) {
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
    }

    Node* temp = tail;
    int cnt = 0;

    do {
        cnt++;
        temp = temp -> next;
    }while(temp != tail);

    return cnt;
}

int main() {

    Node* tail = NULL;

    insertAfterElement(tail,0,10);
    print(tail);
    cout << "Length : " << getLength(tail) << endl;

    insertAfterElement(tail,10,50);
    print(tail);
    cout << "Length : " << getLength(tail) << endl;

    insertAfterElement(tail,50,70);
    print(tail);
    cout << "Length : " << getLength(tail) << endl;

    insertAfterElement(tail,70,90);
    print(tail);
    cout << "Length : " << getLength(tail) << endl;

    insertAfterElement(tail,10,30);
    print(tail);
    cout << "Length : " << getLength(tail) << endl;

    insertAfterElement(tail,90,110);
    print(tail);
    cout << "Length : " << getLength(tail) << endl;

    cout << "tail : " << tail -> data << endl;

    deleteElement(tail,110);
    print(tail);
    cout << "Length : " << getLength(tail) << endl;

    deleteElement(tail,50);
    print(tail);
    cout << "Length : " << getLength(tail) << endl;
    
    deleteElement(tail,10);
    print(tail);
    cout << "Length : " << getLength(tail) << endl;

    cout << "tail : " << tail -> data << endl;

    
    return 0;
}