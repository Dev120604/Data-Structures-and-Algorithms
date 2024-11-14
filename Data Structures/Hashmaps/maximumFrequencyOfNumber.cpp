#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int maximunFrequency(vector<int> &arr,int n) {
    
    unordered_map<int,int> count;

    for(int i=0 ; i<n ; i++) {
        // count[arr[i]] = count[arr[i]] + 1;
        count[arr[i]]++;
    }

    int maxi = INT32_MIN;
    int ans = -1;

    for(auto i : count) {
        if(i.second > maxi) {
            maxi = i.second;
            ans = i.first;
        }
    }
    return ans;
}

int maximumFrequency_FirstOccuring(vector<int> &arr,int n) {

    unordered_map<int,int> count;
    int maxFreq = 0;
    int maxAns = 0;

    for(int i=0 ; i<n ; i++) {
        count[arr[i]]++;
        maxFreq = max(maxFreq,count[arr[i]]);
        // maxFreq = count[arr[i]];
    }

    for(int i=0 ; i<n ; i++) {
        if(maxFreq == count[arr[i]]) {
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
}

int main() {

    vector<int> v = {23,45,14,56,14,23,14,23,56,89,23,23};
    vector<int> v1 = {23,45,14,56,14,23,14,23,56,89};
    
    cout <<"Element which has Maximum Frequency is : " << maximunFrequency(v,v.size()) << endl;

    cout <<"Element which has Maximum Frequency and occurs first is : " << maximunFrequency(v1,v1.size()) << endl;

    return 0;
}