#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumZero(const vector<int>& arr) {
    unordered_map<int, int> firstIndex;

    int prefixSum = 0;
    int maxLength = 0;

    // Prefix sum 0 exists before the array starts
    firstIndex[0] = -1;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        if (firstIndex.find(prefixSum) != firstIndex.end()) {
            int length = i - firstIndex[prefixSum];
            maxLength = max(maxLength, length);
        } else {
            // Store only the first occurrence
            firstIndex[prefixSum] = i;
        }
    }

    return maxLength;
}

int main() {
    vector<int> arr = {1, 2, -3, 3, -3};

    cout << longestSubarrayWithSumZero(arr);

    return 0;
}