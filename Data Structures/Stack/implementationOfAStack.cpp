#include<iostream>
using namespace std;

class Stack {
    public : 
        int* arr;
        int size;
        int top;

        Stack(int size) {
            this -> size = size;
            top = -1;
            arr = new int[size];
        }

        void push(int element) {
            if( (size-top > 1) ) {//atleast one empty space
                top++;
                arr[top] = element;
            }
            else {
                cout << "Stack Overflow " << endl;
            }
        }

        void pop() {
            if(top >= 0) { 
                top--;
            }
            else {
                cout << "Stack underflow " << endl;
            }
        }

        int peek() {
            if(!isEmpty()) {
                return arr[top];
            }
            else {
                return -1;
            }
        }

        bool isEmpty() {
            if(top == -1) {
                return true;
            }
            else {
                return false;
            }
        }
};

int main() {

    Stack s(6);

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    while(!s.isEmpty()) {
        cout << s.peek() << endl;
        s.pop();
    }

    return 0;
}