#include<iostream>
using namespace std;

class CircularQueue {
    public:
        int *arr;
        int size;
        int front;
        int rear;

        CircularQueue(int s) {
            this -> size = s;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        bool enqueue(int element) {
            if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))) {
                cout << "Queue is Full" << endl;
                return false; 
            }
            if(front == -1) {//if the element is first element in the queue
                front = 0;
                rear = 0;
            }
            else if(rear == size-1 && front !=0) {//to maintain cyclic nature of queue
                rear = 0;
            }
            else {//normal flow
                rear++;
            }
            arr[rear] = element;
            return true;
        }
        int dequeue() {
            if(front == -1) {
                cout << "Queue is Empty" << endl;
                return -1;
            }
            int ans = arr[front];
            arr[front] = -1;
            if(front == rear) {//only one element is present in the queue
                front = -1;
                rear = -1;
            }
            else if(front == size-1 ) {//to maintain cyclic nature
                front = 0; 
            }
            else {//normal flow
                front++;
            }
            return ans;
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
            if((front == 0 && rear == size-1) || (rear == ((front -1) % (size-1)))) {
                return true;
            }
            else {
                return false;
            }
        }
};

int main() {

    CircularQueue cq(6);
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);
    cq.enqueue(6);

    while(!cq.isEmpty()) {
        cout << cq.dequeue() << " ";
    }cout << endl;
    
    return 0;
}