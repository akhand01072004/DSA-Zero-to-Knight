
#include <bits/stdc++.h>
using namespace std;

bool checkIfTwoArraysAreEqual(
    const vector<int>& arr,
    const vector<int>& vec
) {
    if (arr.size() != vec.size()) {
        return false;
    }

    unordered_map<int, int> arrFreq;
    unordered_map<int, int> vecFreq;

    // Count frequencies of both arrays
    for (int i = 0; i < arr.size(); i++) {
        arrFreq[arr[i]]++;
        vecFreq[vec[i]]++;
    }

    // Compare frequency of every value
    for (auto p : arrFreq) {
        int value = p.first;

        if (arrFreq[value] != vecFreq[value]) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<int> arr = {1, 2, 2, 3};
    vector<int> vec = {2, 3, 2, 1};

    cout << checkIfTwoArraysAreEqual(arr, vec);

    return 0;
}