/*
Rui Alexandre Tapadinhas - 2018283200
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

int problem_A (vector<int> testcase) {
    int size_temp2 = testcase.size();

    sort(testcase.begin(), testcase.end());
    for (auto k = 0; k < size_temp2; k++) {
        for (auto i = k+1; (i < size_temp2); i++) {
            for (auto j = size_temp2-1; (j >= i+1); j--) {
                //cout << "inds: k=" << k << " i=" << i << " j=" << j << "\n";
                if (testcase[k] + testcase[i] + testcase[j] == 0){
                    if (testcase[k]>0 || testcase[i]>0 || testcase[j]>0) {
                        if (testcase[k]<0 || testcase[i]<0 || testcase[j]<0) {
                            //cout << testcase[k] << " " << testcase[i] << " " << testcase[j] << "\n";
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return -1;
}