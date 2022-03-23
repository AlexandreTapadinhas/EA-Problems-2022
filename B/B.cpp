/*
Rui Alexandre Tapadinhas - 2018283200
Mooshak - aceite sub 553
*/

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

//vars
int num_testcases, temp, res;
int board [400][400];
int size_temp;

void nothing () {}

int problem_B (int x, int y, int m);

int main () {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n_knights, x, y, m, res = 0;
    cin >> n_knights;
    
    for (int i = 0; i<n_knights; i++) {
        cin >> x >> y >> m;
        res += problem_B(x, y, m);
    }
    cout << res << endl;
    return 0;
}

int problem_B (int x, int y, int m) {
    int v = 0;
    if (board[x+200][y+200] == 0) {
        v = 1;
        board[x+200][y+200] = 1;
    }
    if (m == 0) {
        return v;
    }
    else {
        return v + 
        problem_B(x+2, y+1, m-1) +
        problem_B(x+2, y-1, m-1) +
        problem_B(x-2, y+1, m-1) +
        problem_B(x-2, y-1, m-1) +
        problem_B(x+1, y+2, m-1) +
        problem_B(x+1, y-2, m-1) +
        problem_B(x-1, y+2, m-1) +
        problem_B(x-1, y-2, m-1);
    }
}