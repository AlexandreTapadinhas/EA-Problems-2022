/*
Rui Alexandre Tapadinhas - 2018283200
Mooshak - aceite sub 733
*/

/*
g++ -std=c++17 -Wall -Wextra -O2 C.cpp -lm
*/

#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// headers
void populate_mat(vector<vector<int>>& mat, int n_lines, int n_cols, int default_value);
void populate_deg_vector(vector<int>& vec, int size);
void populate_visit_vector(vector<bool>& visit, int size);
void print_adjacency_matrix(vector<vector<int>>& mat, int size);
void exC(int v, int c, int num_nodes, int max_moves);

// vars
vector<vector<int>> links;
vector<bool> visit;
vector<int> deg;
int best;

int main () {
    int n, m, k;
    //cout << best << endl;
    
    int n1, n2, link_cost;

    while(cin >> n >> m >> k) {
        // initiates matrix with defalut value -1
        populate_mat(links, n, n, -1);
        populate_deg_vector(deg, n);
        populate_visit_vector(visit, n);
        best = numeric_limits<int>::max();
        // stores links between nodes in an adjancency matrix
        for (int l = 0; l < m; l++) {
            cin >> n1 >> n2 >> link_cost;
            //cout << n1 << " " << n2 << " " << link_cost << endl;
            links[n1-1][n2-1] = link_cost;
            links[n2-1][n1-1] = link_cost;
        }

        visit[0] = true;
        exC(0, 0, n, k);
        if (best != numeric_limits<int>::max()) {
            cout << best << endl;
        }
        else {
            cout << "NO WAY!" << endl;
        }
        //print_adjacency_matrix(links, n);
        links.clear();
        deg.clear();
        visit.clear();
    }
    
    return 0;
}

void populate_mat(vector<vector<int>>& mat, int n_lines, int n_cols, int default_value) {
    for (int l = 0; l < n_lines; l++) {
        vector<int> temp;
        for (int c = 0; c < n_cols; c++) {
            temp.push_back(default_value);
        }
        mat.push_back(temp);
    }
}

void populate_deg_vector(vector<int>& vec, int size) {
    for (int c = 0; c < size; c++) {
        vec.push_back(0);
    }
}

void populate_visit_vector(vector<bool>& visit, int size) {
    for (int c = 0; c < size; c++) {
        visit.push_back(false);
    }
}

void print_adjacency_matrix(vector<vector<int>>& mat, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << mat[i][j];
            if (j != size-1)
                cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void exC(int v, int c, int num_nodes, int max_moves) {
    if (c >= best)
        return;
    if (v == num_nodes-1) {
        best = c;
        return;
    }
    
    // print deg and visit vectors
    /*cout << "DEG:" << endl;
    for (int i = 0; i < num_nodes; i++) {
        cout << deg[i] << " ";
    }
    cout << "\nVISIT:" << endl;
    for (int i = 0; i < num_nodes; i++) {
        cout << visit[i] << " ";
    }
    cout << endl;*/

    for (int i = 0; i < num_nodes; i++) {
        if (visit[i] == true && deg[i]<max_moves) {
            for (int j = 0; j < num_nodes; j++) {
                if (visit[j] == false && links[i][j]>=0) {
                    visit[j] = true;
                    deg[i]+=1;
                    deg[j]+=1;
                    exC(v+1, c+links[i][j], num_nodes, max_moves);
                    visit[j] = false;
                    deg[i]-=1;
                    deg[j]-=1;
                }
            }
        }
    }
}