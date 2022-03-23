/*
Rui Alexandre Tapadinhas - 2018283200
Mooshak - aceite sub 231
*/

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

//vars
int num_testcases, temp, res;
vector<int> testcase;
int size_temp;

void nothing () {}

int problem_A (vector<int> testcase);

int main () {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    while (cin >> num_testcases) {
        for (int i = 0; i < num_testcases; i++) {
            cin >> temp;
            testcase.push_back(temp);
            //cout << temp << "\n";
        }
        if (cin >> temp && temp == 0) {
            //cout << "leu " << temp << "\n";
            nothing(); //leu 0;
        }

        size_temp = testcase.size();
        res = problem_A(testcase);
        if (res == 1) {
            cout << "Fair\n";
        }
        else if (res == -1) {
            cout << "Rigged\n";
        }
        testcase.clear();

    }
    return 0;
}

int problem_A (vector<int> testcase) { //done using 3sum from 
    int size_temp2 = testcase.size();
    int start, end, res_temp;

    sort(testcase.begin(), testcase.end());

    for (auto k = 0; k < size_temp2-1; k++) {
        start = k+1;
        end = size_temp2-1;
        while (start < end) {
            res_temp = testcase[k] + testcase[start] + testcase[end];
            if (res_temp == 0) {
                //cout << "inds: k=" << k << " s=" << start << " e=" << end << "\n";
                return 1;
            }
            else if (res_temp > 0) {
                end--;
            }
            else { //res_temp < 0
                start++;
            }
        }
    }
    return -1;
}