/*
Rui Alexandre Tapadinhas - 2018283200
Mooshak - sub 2028
*/

/*
g++ -std=c++17 -Wall -Wextra -O2 I.cpp -lm
*/

/*
Output:
8
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>


using namespace std;

vector<vector<int>> adj_graph; //vetor de adjacencias
int num_nodes, end_node;

int djikstra(vector<vector<int>> &adj_graph, int end_node);

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (cin >> num_nodes >> end_node) {
        
        adj_graph.resize(num_nodes, vector<int> (num_nodes));
        
        
        int id;
        
        for (int i = 0; i < num_nodes; i++) {
            cin >> id;
            if (id == i+1) {
                for (int j = 0; j < num_nodes; j++) {
                    cin >> adj_graph[i][j];
                }
            }
        }

        // print adj mat
        /*cout << "adj mat" << endl;
        for (int i = 0; i < (int)adj_graph.size(); i++) {
            for (int j = 0; j < (int)adj_graph[i].size(); j++) {
                cout << adj_graph[i][j] << " ";
            }
            cout << endl;
        }*/
        
        cout << djikstra(adj_graph, end_node) << endl;
        adj_graph.clear();
    }
}

int djikstra(vector<vector<int>> &adj_graph, int end_node){
    vector<int> path;
    path.resize((int)adj_graph.size());
    queue<int> Q;
    for(int i = 1; i < (int)adj_graph.size(); i ++){
        path[i] = INT_MAX;

    }
    Q.push(0);
    path[0] = 0;
    while(!Q.empty()){
        int current = Q.front();
        Q.pop();
        for (int i = 0; i < (int)adj_graph[current].size(); i++){
            if(adj_graph[current][i] != -1 && adj_graph[current][i] != 0){
                if(path[i] > path[current] + adj_graph[current][i]){
                    path[i] = path[current] + adj_graph[current][i];
                    Q.push(i);
                }
            }
        }
    }
    return path[end_node-1];

}
