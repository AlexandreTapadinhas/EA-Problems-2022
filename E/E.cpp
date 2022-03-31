/*
Rui Alexandre Tapadinhas - 2018283200
Mooshak - sub
*/

/*
g++ -std=c++17 -Wall -Wextra -O2 E.cpp -lm
*/

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <math.h>

using namespace std;

// headers

int exE(vector<int> &pizzas, int num_pizzas, int time_sum);

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int num_pizzas, aux, time_sum = 0;

    while (cin >> num_pizzas) {
        vector<int> pizzas;
        pizzas.push_back(0);
        for (int p = 0; p < num_pizzas; p++) {
            cin >> aux;
            pizzas.push_back(aux);
            time_sum += aux;
        }
        cout << exE(pizzas, num_pizzas, time_sum) << endl;
    }
    return 0;
}

int exE(vector<int> &pizzas, int num_pizzas, int time_sum) { // pizza
    vector<vector<int>> cache;
    num_pizzas++;
    int sum2 = floor(time_sum / 2) + 1;
    cache.resize(num_pizzas);
    for (int l = 0; l < num_pizzas; l++) {
        cache[l].resize(sum2);
    }

    for (int i = 0; i < num_pizzas; i++) {
        cache[i][0] = true;
    }

    for (int i = 1; i < (sum2); i++) {
        cache[0][i] = false;
    }

    for (int i = 1; i < num_pizzas; i++) {
        for (int j = 1; j < sum2; j++) {
            cache[i][j] = cache[i - 1][j];
            if (pizzas[i] <= j) {
                cache[i][j] = cache[i - 1][j] || cache[i - 1][j - pizzas[i]];
            }
        }
    }

    for (int i = sum2; i > 0; i--) {
        if (cache[num_pizzas - 1][i] == true) {
            return abs(2 * i - time_sum);
        }
    }
    return 0;
}