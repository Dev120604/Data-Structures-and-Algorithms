#include<iostream>
using namespace std;

class Queue {
    public :
        int* arr;
        int size;
        int qfront;
        int rear;

        Queue(int s) {
            this -> size = s;
            arr = new int[s];
            qfront = 0;
            rear = 0;
        }

        void enqueue(int element) {
            if(rear == size) {
                cout << "Queue is Full" << endl;
            }
            else {
                arr[rear] = element;
                rear++;
            }
        }
        int dequeue() {
            if(qfront == rear) {
                // cout << "Queue is Empty" << endl;
                return -1;
            }
            else {
                int ans = arr[qfront];
                qfront++;
                if(qfront == rear) {
                    //this condition make sure that there is no memeory wastage happens in queue(array)
                    qfront = 0;
                    rear = 0;
                }
                return ans;
            }
        }
        int front() {
            if(qfront == rear) {
                return -1;
            }
            else {
                return arr[qfront];
            }
        }
        bool isEmpty() {
            if(qfront == rear) {
                return true;
            }
            else {
                return false;
            }
        }
};

int main() {

    Queue q(6);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    while(!q.isEmpty()) {
        cout << q.front() << " ";
        q.dequeue();
    }cout << endl;

    return 0;
}