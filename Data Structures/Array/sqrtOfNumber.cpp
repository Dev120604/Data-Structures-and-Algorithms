#include<iostream>
using namespace std;

int sqrt(int n) {

    int start = 0;
    int end = n;
    int answer = -1;

    long long int mid = start + (end-start)/2;

    while(start <= end) {

        long long int square = mid * mid;

        if(square == n) {
            return mid;
        }

        if(square < n) {
            answer = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }

        mid = start + (end-start)/2; 
    }

    return answer;
}

double morePrecision(int n , int integer_part , int precision) {

    double factor = 1;
    double ans = integer_part;

    for(int i=0 ; i<precision ; i++) {

        factor = factor/10;

        for(double j=ans ; j*j<n ; j=j+factor) {
            ans = j;
        }
    }

    return ans;
}

int main() {

    int n;
    cout << "Enter Number : " << endl;
    cin >> n;

    int integer_part = sqrt(n);

    cout << "Square Root of " << n << " is : " << morePrecision(n,integer_part,4) << endl;

    return 0;
}