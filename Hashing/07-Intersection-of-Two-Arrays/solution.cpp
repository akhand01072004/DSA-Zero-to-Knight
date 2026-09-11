#include <bits/stdc++.h>
using namespace std;

unordered_set<int> IntersectionOfArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> res;
    unordered_set<int> us;

    for (int i = 0; i < arr1.size(); i++) {
        us.insert(arr1[i]);
    }

    for (int j = 0; j < arr2.size(); j++) {
        if (us.find(arr2[j]) != us.end()) {
            res.insert(arr2[j]);
        }
    }

    return res;
}

int main() {
    vector<int> n = {4, 1, 3, 2};
    vector<int> n1 = {2, 4};

    unordered_set<int> result = IntersectionOfArray(n, n1);

    for (int x : result) {
        cout << x << " ";
    }
}