/*
Rui Alexandre Tapadinhas - 2018283200
Mooshak - sub
*/

/*
g++ -std=c++17 -Wall -Wextra -O2 H.cpp -lm
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int exH (int num_of_trains_and_stations, vector<pair<int, int>> &pairs);
int run_pairs_array(int offset, vector<pair<int, int>> &pairs, vector<int> &type);

int main () 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int num_of_trains_and_stations, num_pairs, pair1, pair2;

    //cin >> num_of_trains_and_stations;
    while (cin >> num_of_trains_and_stations) {
        cin >> num_pairs;
        vector<pair<int, int>> pairs;
        pairs.resize(num_pairs);
        for (int ob = 0; ob < num_pairs; ob++) {
            cin >> pair1 >> pair2;
            pairs.push_back(make_pair(pair1, pair2));
        }
        if (exH(num_of_trains_and_stations, pairs) == 1) {
            cout << "NOT SURE" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

int exH (int num_of_trains_and_stations, vector<pair<int, int>> &pairs) {
    vector<int> type; // 0 -> undefined, 1 -> type1, 2 -> type2
    type.resize(num_of_trains_and_stations+1);

    type[pairs[0].first] = 1;
    type[pairs[0].second] = 2;

    pairs.erase(pairs.begin());
    if (pairs.size() > 1) {
        cout << run_pairs_array(0, pairs, type) << endl;
    }


    //cout << run_pairs_array(0, pairs, type) << endl;

    for (int i = 1; i < num_of_trains_and_stations+1; i++) {
        cout << type[i] << " ";
        if (type[i] == 0) {
            return 0; // NO
        }
    }
    return 1; // NOT SURE

}

int run_pairs_array(int offset, vector<pair<int, int>> &pairs, vector<int> &type) {
    cout << "size: " << pairs.size() << endl;
    if (type[pairs[offset].first] == 0) {
        cout << 0 << endl;
        if (type[pairs[offset].second] == 0) {
            if (pairs.size() > 1) {
                run_pairs_array(offset+1, pairs, type);
            }
        }
        else if (type[pairs[offset].second] == 1) {
            type[pairs[offset].first] = 2;
        }
        else { // type[pairs[offset].second] == 2
            type[pairs[offset].first] = 1;
        }
    }
    else if (type[pairs[offset].first] == 1) {
        cout << 1 << endl;
        if (type[pairs[offset].second] == 0 && type[pairs[offset].second] == 2) {
            type[pairs[offset].second] = 2;
        }
        else {
            return 0; // NO
        }
        pairs.erase(pairs.begin()+offset);
        if (pairs.size() > 1) {
            run_pairs_array(0, pairs, type);
        }
    }
    else { // type[pairs[offset].first] == 2
        cout << 2 << endl;
        if (type[pairs[offset].second] == 0 && type[pairs[offset].second] == 1) {
            type[pairs[offset].second] = 1;
        }
        else {
            return 0; // NO
        }
        pairs.erase(pairs.begin()+offset);
        if (pairs.size() > 1) {
            run_pairs_array(0, pairs, type);
        }
    }
    return 1;
    //pairs.erase(pairs.begin());
    /*if (pairs.size() > 1) {
        run_pairs_array(0, pairs, type);
    }*/
}