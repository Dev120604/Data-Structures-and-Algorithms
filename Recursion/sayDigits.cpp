#include<iostream>
using namespace std;

void sayDigits(int n , string arr[]) {

    //base case 
    if(n == 0) {
        return ;
    }

    int digit = n % 10;
    n = n/10;

    sayDigits(n,arr);
    cout << arr[digit] << " ";

}

int main() {

    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int num;
    cout << "Enter Number : " << endl;
    cin >> num;

    sayDigits(num,arr);

    return 0;
}