/*
Rui Alexandre Tapadinhas - 2018283200
Mooshak - sub
*/

/*
g++ -std=c++17 -Wall -Wextra -O2 E.cpp -lm
*/

#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <vector>

using namespace std;

int exE(vector<int> pizzas, int sum);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int num_testcases;
    while (cin >> num_testcases)
    {
        vector<int> pizzas;
        pizzas.push_back(0);
        int sum = 0;
        while (num_testcases--)
        {
            int time;
            cin >> time;
            pizzas.push_back(time);
            sum += time;
        }
        cout << pizza(pizzas, sum) << endl;
    }
    return 0;
}

int pizza(vector<int> pizzas, int sum)
{
    int n = pizzas.size() + 1;
    int k = ceil(sum / 2) + 1;
    int sum2 = ceil(sum / 2) + 1;
    vector<vector<bool>> cache;
    //populate
    cache.resize(n);
    for (int l = 0; l < n; l++) {
        cache[l].resize(sum2);
    }

    for (int i = 0; i < n; i++)
        cache[i][0] = true;

    for (int j = 1; j < k; j++)
        cache[0][j] = false;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < k; j++)
        {
            cache[i][j] = cache[i - 1][j];
            if (pizzas[i] <= j)
            {
                cache[i][j] = cache[i - 1][j] || cache[i - 1][j - pizzas[i]];
            }
        }
    }

    for (int i = k; i > 0; i--)
    {
        if (cache[n - 1][i])
        {
            return abs(2 * i - sum);
        }
    }
    return 0;
}

