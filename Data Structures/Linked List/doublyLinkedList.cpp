#include<iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node* prev;
        Node* next;

    Node(int data) {
        this -> data = data;
        this -> prev = NULL;
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

void insertAtHead(Node* &head , Node* &tail , int d) {

    if(head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
        Node* temp = new Node(d);
        head -> prev = temp;
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
        temp -> prev = tail;
        tail -> next = temp;
        tail = temp;
    }
}

void insertAtPosition(Node* &head , Node* &tail , int position , int d) {
    if(position == 1) {
        insertAtHead(head,tail,d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position -1) {
        temp = temp -> next;
        cnt++;
    }

    if(temp-> next == NULL) {
        insertAtTail(head,tail,d);
        return;
    }

    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

void deleteAtPosition(Node* &head , Node* &tail , int position) {
    if(position == 1) {
        Node* temp = head;
        head = temp -> next;
        head -> prev = NULL;
        delete temp;
    }
    else {

        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;

        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        if(curr -> next == NULL) {
            tail = prev;
        }

        prev -> next = curr -> next;
        delete curr;
    }
}

void print(Node* &head) {
    Node* temp = head;

    if(head == NULL) {
        cout << "List is Empty"<< endl;
    }

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }cout << endl;
}

int getLength(Node* &head) {
    Node* temp = head;
    int cnt = 0;

    if(head == NULL) {
        cout << "List is Empty" << endl;
    }

    while(temp != NULL) {
        cnt++;
        temp = temp -> next;
    }
    return cnt;
}


int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail,50);
    print(head);
    cout << "Length : "<<getLength(head)<<endl;

    insertAtHead(head,tail,40);
    print(head);
    cout << "Length : "<<getLength(head)<<endl;

    insertAtHead(head,tail,30);
    print(head);
    cout << "Length : "<<getLength(head)<<endl;

    insertAtTail(head,tail,60);
    print(head);
    cout << "Length : "<<getLength(head)<<endl;

    insertAtTail(head,tail,70);
    print(head);
    cout << "Length : "<<getLength(head)<<endl;

    insertAtTail(head,tail,80);
    print(head);
    cout << "Length : "<<getLength(head)<<endl;

    insertAtPosition(head,tail,1,20);
    print(head);
    cout << "Length : "<<getLength(head)<<endl;

    insertAtPosition(head,tail,2,25);
    print(head);
    cout << "Length : "<<getLength(head)<<endl;

    insertAtPosition(head,tail,4,35);
    print(head);
    cout << "Length : "<<getLength(head)<<endl;

    insertAtPosition(head,tail,10,90);
    print(head);
    cout << "Length : "<<getLength(head)<<endl;

    insertAtPosition(head,tail,11,100);
    print(head);
    cout << "Length : "<<getLength(head)<<endl;

    deleteAtPosition(head,tail,1);
    print(head);
    cout << "Length : "<<getLength(head)<<endl;
    cout << "head : " << head -> data << endl;
    cout << "tail : " << tail -> data << endl;

    deleteAtPosition(head,tail,5);
    print(head);
    cout << "Length : "<<getLength(head)<<endl;
    cout << "head : " << head -> data << endl;
    cout << "tail : " << tail -> data << endl;

    
    deleteAtPosition(head,tail,9);
    print(head);
    cout << "Length : "<<getLength(head)<<endl;
    cout << "head : " << head -> data << endl;
    cout << "tail : " << tail -> data << endl;

    return 0;
}