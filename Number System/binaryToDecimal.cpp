#include<iostream>
#include<math.h>
using namespace std;

int main() {

    int binaryNum;
    cout << "Enter Binary value in the Form of Integer : " << endl;
    cin >> binaryNum;
    int temp = binaryNum;

    int i = 0;// p;ace holder/indicator for position
    int ans = 0;

    while(binaryNum != 0) {

        int digit = binaryNum % 10;

        ans += ( digit * pow(2,i) );

        binaryNum /= 10;
        i++;
    }

    cout << temp << " 's Decimal Number is : " << ans << endl;

    return 0;
}