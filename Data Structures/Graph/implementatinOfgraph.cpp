#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

class Graph {

    public :

        unordered_map<int,list<int>> adj;

        void addEdge(int u , int v , bool direction) {

            // if direction == 0 -> undirected
            // if direction == 1 => directed

            adj[u].push_back(v);

            if(direction == 0) {
                adj[v].push_back(u);
            }
        }

        void printAdjList() {

            for(auto i : adj) {
                cout << i.first << " -> " ;

                for(auto j : i.second) {
                    cout << j << " ";
                }
                cout << endl;
            }
        }
};

/*
vector<vector<int>> printAdjacency(int n , int m , vector<vector<int>> &edges) {
    //codestudio question
    //storing neighbours or adjacents 
    vector<int> ans[n];

    for(int i=0 ; i<m ; i++) {

        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>> adj(n);

    for(int i=0 ; i<n ; i++) {
        adj[i].push_back(i);

        //entering neighbours from ans 
        for(int j=0 ; i<ans[i].size() ; j++) {
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}
*/

int main() {

    Graph g;

    int n;
    cout << "Enter Number of Nodes : " << endl;
    cin >> n;

    int m;
    cout << "Enter Number of Edges : " << endl;
    cin >> m;

    for(int i = 0 ; i<m ; i++) {

        int u,v;
        cout << "Enter u and v : "<< endl;
        cin >> u >> v;
        
        g.addEdge(u,v,0);
    }

    g.printAdjList();

    /* this is not running properly 
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};

    vector<vector<int>> adjList = printAdjacency(3,3,edges);

    for(int i=0 ; i<3 ; i++) {
        cout << i << " -> ";
        for(int j=0 ; j<3 ; j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }*/

    return 0;
}

