#include<iostream>
using namespace std;

class Deque {
    public :
        int *arr;
        int size;
        int front;
        int rear;

        Deque(int s) {
            this -> size =s;
            arr = new int [size];
            front = -1;
            rear = -1;
        }
        bool pushRear(int element) {

            if( (front == 0 && rear == size - 1) || (front != 0 && (rear == (front - 1) % (size - 1))) ) {
                cout << "Queue is Full" << endl;
                return false;
            }
            if(front == -1) {
                front = 0;
                rear = 0;
            }
            else if(rear == size -1 && front != 0) {
                rear = 0;
            }
            else {
                rear++;
            }
            arr[rear] = element;
            return true;
        }
        bool pushFront(int element) {

            if((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1))) {
                cout << "Queue is Full" << endl;
                return false;
            }
            if(front == -1) {
                front = 0;
                rear = 0;
            }
            else if(front == 0 && rear != size - 1) {
                front = size - 1;
            }
            else {
                front --;
            }
            arr[front] = element;
            return true;
        }
        int popFront() {

            if(front == -1) {
                cout << "Queue is Empty" << endl;
                return -1;
            }
            int ans = arr[front];
            arr[front] = -1;
            if(front == rear) {
                front = rear = -1;
            }
            else if(front == size - 1) {
                front = 0;
            }
            else {
                front++;
            }
            return ans;
        }
        int popRear() {

            if(front == -1) {
                cout << "Queue is Empty" << endl;
                return -1;
            }
            int ans = arr[rear];
            arr[rear] = -1;
            if(front == rear) {
                rear = front = -1;
            }
            else if(rear == 0) {
                rear = size -1;
            }
            else {
                rear--;
            }
            return ans;
        }
        int getRear() {
            if(front == -1) {
                // cout << "Queue is Empty" << endl;
                return -1;
            }
            else {
                return arr[rear];
            }
        }
        int getFront() {
            if(front == -1) {
                cout << "Queue is Empty" << endl;
                return -1;
            }
            else {
                return arr[front];
            }
        }
        bool isEmpty() {
            if(front == -1) {
                return true;
            }
            else {
                return false;
            } 
        }
        bool isFull() {
            if((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1))) {
                return true;
            }
            else {
                return false;
            }
        }
};

int main() {

    Deque dq(6);
    dq.pushRear(1);
    dq.pushRear(2);
    dq.pushRear(3);
    dq.pushFront(4);
    dq.pushFront(5);
    dq.pushFront(6); 
    
    while(!dq.isEmpty()) {
        cout << "Pop Front : " << dq.popFront() << endl;
        cout << "Rear : " << dq.getRear() << endl;
        cout << "Front : " << dq.getFront() << endl;
        cout << "Pop Rear : " << dq.popRear() << endl;
        cout << "Rear : " << dq.getRear() << endl;
        cout << "Front : " << dq.getFront() << endl;
    }
    return 0;
}