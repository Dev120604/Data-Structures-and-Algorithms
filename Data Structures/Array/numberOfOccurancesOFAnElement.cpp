#include<iostream>
#include<vector>
using namespace std;

int firstPosition(vector<int> arr , int n , int element) {

    int start = 0;
    int end = arr.size()-1;
    int ans = -1;

    int mid = start + (end-start)/2;

    while(start <= end) {

        if(arr[mid] == element) {
            ans = mid;
            end = mid - 1;
        }

        if(arr[mid] > element) {
            end = mid - 1;
        }
        else if(arr[mid] < element) {
            start = mid + 1;
        }

        mid = start + (end-start)/2;
    }

    return ans;
}

int lastPosition(vector<int> arr , int n , int element) {

    int start = 0;
    int end = arr.size()-1;
    int ans = -1;

    int mid = start + (end-start)/2;

    while(start <= end) {

        if(arr[mid] == element) {
            ans = mid;
            start = mid + 1;
        }

        if(arr[mid] > element) {
            end = mid - 1;
        }
        else if(arr[mid] < element) {
            start = mid + 1;
        }

        mid = start + (end - start)/2;
    }

    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int> p;

    p.first = firstPosition(arr,n,k);
    p.second = lastPosition(arr,n,k);

    return p;
}

int main() {

    pair<int,int> p;

    vector<int> arr = {1,2,2,2,3,3};
    int n = 6;
    int k = 3;
    
    p = firstAndLastPosition(arr,n,k);

    cout << "Total Occurances of " << k << " is : " << (p.second - p.first + 1) << endl;

    return 0;
}