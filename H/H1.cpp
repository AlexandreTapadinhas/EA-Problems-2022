/*
Rui Alexandre Tapadinhas - 2018283200
Mooshak - sub 1875
*/

/*
g++ -std=c++17 -Wall -Wextra -O2 H1.cpp -lm
*/

#include <iostream>
#include <vector>
#include <queue>


using namespace std;

vector<int> type;
vector<vector<int>> adj_graph; //vetor de adjacencias
int num_nodes, conns;

bool trains_stations(int v);


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (cin >> num_nodes >> conns) {
        
        adj_graph.resize(num_nodes+1);
        type.resize(num_nodes+1);
        
        for (int i = 1; i < num_nodes+1; i++) {
            type[i] = -1;
        }
        
        int node1, node2;
        
        for (int i = 0; i < conns; i++) {
            cin >> node1 >> node2;
            adj_graph[node1].push_back(node2);
            adj_graph[node2].push_back(node1);
        }
        
        bool res = true;
        for (int v = 1; v < num_nodes+1; v++) {
            if (type[v] == -1) {
                res = trains_stations(v);
            }
            if (res == false) {
                break;
            }
        }

        if (res == true) {
            cout << "NOT SURE" << endl;
        }
        else {
            cout << "NO" << endl;
        }

        adj_graph.clear();
        type.clear();
    }
}

bool trains_stations(int v) {
    queue<int> Q;
    type[v] = 1;
    Q.push(v);
    while (Q.empty() == false) {
        int node1 = Q.front(); 
        Q.pop();

        for (int node2: adj_graph[node1]) {
            if (type[node2] == -1) {
                type[node2] = 1 - type[node1];
                Q.push(node2);
            }
            else if (type[node2] == type[node1]) {
                return false;
            }
        }
    }
    return true;
}
