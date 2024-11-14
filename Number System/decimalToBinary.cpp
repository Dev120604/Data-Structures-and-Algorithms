// NOTE :- In Some Cases Compiler doesn't respond properly for Values = 4 , 5 , 6 and 7 so for that reason use another IDE or Online Compiler/IDE

#include<iostream>
#include<math.h>
using namespace std;

int main() {

    int decimalNum;
    cout << "Enter the Value of Decimal Number : " << endl;
    cin >> decimalNum;
    int temp = decimalNum;

    int ans = 0;
    int i = 0;

    while(decimalNum != 0) {

        int bit = decimalNum & 1;

        ans += ( bit * pow(10,i) ); // to decide the given bit's place

        decimalNum = decimalNum >> 1;
        i++;
    }

    cout << temp << " 's Binary Value is : " << ans << endl;

    return 0;
}