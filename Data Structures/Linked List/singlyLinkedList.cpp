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

    ~Node(){

        int val = this -> data;

        if(this -> next !=NULL) {
            this -> next = NULL;
            delete next;
        }
        cout << "Deleted Node : " << val << endl;
    }
};

void insertAtHead(Node* &head , Node* &tail , int d) {

    if(head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
        Node* temp = new Node(d);
        temp -> next = head;
        head = temp;
    }
}

void insertAtTail(Node* &head , Node* &tail , int d) {

    if(tail == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
        Node* temp = new Node(d);
        tail -> next = temp;
        tail = temp;
    }
}

void insertAtPosition(Node* &head , Node* &tail , int position , int d) {

    if(position == 1){
        insertAtHead(head,tail,d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next == NULL) {
        insertAtTail(head,tail,d);
        return;
    }
    
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void print(Node* &head) {
    Node* temp = head;

    if(head == NULL) {
        cout << "List is Empty" << endl;
    }

    while(temp != NULL) {

        cout << temp -> data << " " ;
        temp = temp -> next;
    }cout << endl;
}

void deleteAtPosition(Node* &head , Node* &tail , int position) {

    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        delete temp;
    }
    else {
        
        int cnt = 1;
        
        Node* curr = head;
        Node* prev = NULL;

        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        if(curr -> next == NULL) {
            tail = prev;
        }

        //curr is now pointing the node which we want to delete
        prev -> next = curr -> next;
        delete curr;
    }

}

int getLength(Node* &head) { 

    if(head == NULL) {
        cout << "List is empty" << endl;
    }

    Node* temp = head;
    int cnt = 0;

    while(temp != NULL) {
        temp = temp -> next;
        cnt++;
    }

    return cnt;

}

int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail,10);
    print(head);

    insertAtPosition(head,tail,2,15);
    print(head);

    insertAtHead(head,tail,5);
    print(head);

    insertAtTail(head,tail,20);
    print(head);

    insertAtTail(head,tail,25);
    print(head);

    cout << "Length of Linked List : "<< getLength(head) << endl;

    deleteAtPosition(head,tail,1);
    print(head);
    cout <<"head : "<< head -> data << endl;
    cout <<"tail : "<< tail -> data << endl;

    deleteAtPosition(head,tail,4);
    print(head);
    cout <<"head : "<< head -> data << endl;
    cout <<"tail : "<< tail -> data << endl;

    deleteAtPosition(head,tail,2);
    print(head);
    cout <<"head : "<< head -> data << endl;
    cout <<"tail : "<< tail -> data << endl;

    cout << "Length of Linked List : "<< getLength(head) << endl;
    return 0;
}