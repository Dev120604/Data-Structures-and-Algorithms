#include<iostream>
using namespace std;

void reachHome(int src , int dest) {

    //base case
    if(src == dest) {
        cout << "Reached" << endl;
        return;
    }

    cout << "Source : " << src << "Destination : " << dest << endl;
    src++;
    reachHome(src,dest);
}

int main() {

    int src , dest;
    cout << "Enter Source and Destination : "<< endl;
    cin >> src >> dest;

    reachHome(src,dest);

    return 0;
}