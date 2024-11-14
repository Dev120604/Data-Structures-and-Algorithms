#include<iostream>
#include<unordered_map>
using namespace std;

int main() {

    unordered_map<string,int> m;

    pair<string,int> p1 = make_pair("babbar",3);
    m.insert(p1);

    pair<string,int> p2("love",2);
    m.insert(p2);

    pair<string,int> p3 = {"HelloJee",5};
    m.insert(p3);

    m["mera"] = 1;

    m["mera"] = 2;//this statement updates the old value of the key by the new value (updates the value at key) 

    //Search
    cout << m["mera"] << endl;
    cout << m.at("babbar") << endl;

    // if we try to print the value of the key which is not present then at method gives error
    // cout << m.at("unkownKey") << endl; 

    //but below statement creates a new key in map and initialize the value of it with zero
    cout << m["unknownKey"] << endl;
    //now at method don't give any error because entry corresponding the key has done by above statement
    cout << m.at("unknownKey") << endl;

    //size
    cout << m.size() << endl;

    //to check presence // present -> 1 and absent -> 0
    cout << m.count("bro") << endl;

    for(auto i : m) {
        cout << i.first << " " << i.second << endl;
    }

    //erase
    cout << m.erase("love");

    //iterator
    unordered_map<string,int> :: iterator it = m.begin();
    // auto it = m.begin();
    cout << "\nPrinting map through iterator and after one deletion" << endl;
    while(it != m.end()) {
        cout << it -> first << " " << it->second << endl;
        it++ ;
    }

    return 0;
}


