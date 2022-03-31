/*
Rui Alexandre Tapadinhas - 2018283200
Mooshak - aceite sub 1387
*/

/*
g++ -std=c++17 -Wall -Wextra -O2 F.cpp -lm
*/

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

// headers

int exF (vector<int> &objs, int num_meters);

int main () {
    int testcase, num_objs, num_meters, aux;
    cin >> testcase;
    while (testcase) {
        cin >> num_objs >> num_meters;
        vector<int> objs;
        for (int ob = 0; ob < num_objs; ob++) {
            cin >> aux;
            objs.push_back(aux);
        }
        cout << exF(objs, num_meters) << endl;
        testcase--;
    }
    return 0;
}

int exF (vector<int> &objs, int num_meters) { // guards
    int g = 0;
    sort(objs.begin(), objs.end());
    int last = INT_MIN;
    for (int p:objs) {
        if (p > last) {
            g++;
            last = p + 2 * num_meters;
        }
    }
    return g;
}