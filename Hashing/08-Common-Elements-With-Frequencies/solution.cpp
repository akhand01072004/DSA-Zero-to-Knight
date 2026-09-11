
#include <bits/stdc++.h>
using namespace std;

vector<int> intersectionOfArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> freq;
    vector<int> result;

    // Store frequency of elements in the first array
    for (int x : arr1) {
        freq[x]++;
    }

    // Process the second array
    for (int x : arr2) {
        if (freq[x] > 0) {
            result.push_back(x);
            freq[x]--;
        }
    }

    return result;
}

int main() {
    vector<int> arr1 = {1, 2, 2, 3, 4};
    vector<int> arr2 = {2, 2, 2, 4, 4, 5};

    vector<int> result = intersectionOfArray(arr1, arr2);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
```
