/*
Rui Alexandre Tapadinhas - 2018283200

NOT WORKING
*/

/*
g++ -std=c++17 -Wall -Wextra -O2 D.cpp -lm
*/

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

int exD (int line, int col, vector<vector<int>> &hill_matrix, vector<vector<int>> &cache);
int exD_1 (int line, int col, vector<vector<int>> &hill_matrix, vector<vector<int>> &cache);


int main () {
    int num_lines, num, res, num_testcases = 0;
    vector<vector<int>> hill_matrix;
    vector<vector<int>> cache;
    vector<int> aux_line;
    vector<int> aux_line_cache;

    cin >> num_testcases;
    cout << "num_testcases = " << num_testcases << endl;

    for (int t = 0; t < num_testcases; t++) {
        cin >> num_lines;
        cout << "num_lines = " << num_lines << endl;
        for (int l = 0; l < num_lines; l++) {
            for (int c = 0; c < l+1; c++) {
                cin >> num;
                aux_line.push_back(num);
                aux_line_cache.push_back(numeric_limits<int>::max());

                cout << num << " ";
            }
            cout << endl;
            hill_matrix.push_back(aux_line);
            cache.push_back(aux_line_cache);
        }

        res = exD_1(0, 0, hill_matrix, cache);

        cout << res << endl;

        cout << "cache:" << endl;
        for (int l = 0; l < (int)hill_matrix.size(); l++) {
            for (int c = 0; c < l+1; c++) {
                cout << cache[l][c] << " ";
            }
            cout << endl;
        }

        hill_matrix.clear();
        aux_line.clear();
    }
    return 0;
}

int exD (int line, int col, vector<vector<int>> &hill_matrix, vector<vector<int>> &cache) {
    if (cache[line][col] != numeric_limits<int>::max()) {
        cout << "cached" << endl;
        return cache[line][col];
    }
    if (line == 0 || col == 0 || col > line) {
        cache[line][col] = 0;
        return cache[line][col];
    }
    if (line == 1 && col == 1) {
        cache[line][col] = hill_matrix[line][col];
        return cache[line][col];
    }
    cache[line][col] = hill_matrix[line][col] + max(exD(line+1, col, hill_matrix, cache), exD(line+1, col+1, hill_matrix, cache));
    return cache[line][col];
}


int exD_1 (int line, int col, vector<vector<int>> &hill_matrix, vector<vector<int>> &cache) {
    if (cache[line][col] != numeric_limits<int>::max()) {
        cout << "cached" << endl;
        return cache[line][col];
    }
    if (line == (int)hill_matrix.size()) {
        cache[line][col] = hill_matrix[line][col];
        return cache[line][col];
    }
    cache[line][col] = hill_matrix[line][col] + max(exD(line+1, col, hill_matrix, cache), exD(line+1, col+1, hill_matrix, cache));
    return cache[line][col];
}