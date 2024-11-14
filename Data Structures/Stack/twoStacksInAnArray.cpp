#include<iostream>
using namespace std;

class Stack {

    public : 

        int* arr;
        int size;
        int top1;
        int top2;

        Stack(int size) {
            this -> size = size;
            arr = new int[size];
            top1 = -1;
            top2 = size;
        }

        void push1(int element) {
            if( (top2-top1 > 1) ) { //this condition checks atleast one empty space in array is available
                top1++;
                arr[top1] = element;
            }
            else {
                cout << "Stack Overflow" << endl;
            }
        }
        void push2(int element) {
            if( (top2-top1 > 1) ) {// if(top2 < size && top2 > top1)
                top2--;
                arr[top2] = element;
            }
            else {
                cout << "Stack Overflow" << endl;
            }
        }
        int pop1() {
            if(top1 != -1) {
                int ans = arr[top1];
                top1--;
                return ans;
            }
            else {
                // cout << "Stack Underflow" << endl;
                return -1;
            }
        }
        int pop2() {
            if(top2 != size) {
                int ans = arr[top2];
                top2++;
                return ans;
            }
            else {
                // cout << "Stack Underflow" << endl;
                return -1;
            }
        }
        // void printArray() {
        //     for(int i=0; i<size;i++) {
        //         cout << *(arr+i) << " ";
        //     }cout << endl;
        // }
};

int main() {

    Stack s(10);

    int* array = s.arr;//don't take this type of risks
    int n = s.size;

    s.push1(1);
    s.push1(2);
    s.push1(3);
    s.push2(4);
    s.push2(5);
    s.push2(6);

    for(int i=0 ; i<n ;i++) {
        cout << array[i] << " ";
    }cout << endl;

    //s.printArray();

    return 0;
}