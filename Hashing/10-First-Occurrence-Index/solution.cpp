#include <bits/stdc++.h>
using namespace std;

void firstOccurrenceIndex(vector<int>& arr) {

    unordered_map<int, int> idx_mp;

    for (int i = 0; i < arr.size(); i++) {

        if (idx_mp.find(arr[i]) != idx_mp.end()) {
            continue;
        }

        idx_mp[arr[i]] = i;

        cout << arr[i] << " --> " << i << endl;
    }
}

int main() {
    vector<int> n = {4, 7, 2, 7, 9, 4, 2};

    firstOccurrenceIndex(n);

    return 0;
}