#include <bits/stdc++.h>
using namespace std;

int longestSubarrayEqualZeroOne(const vector<int>& arr) {

    unordered_map<int, int> firstIndex;

    int prefixSum = 0;
    int maxLen = 0;

    firstIndex[0] = -1;

    for(int i = 0; i < arr.size(); i++) {

        if(arr[i] == 0) {
            prefixSum -= 1;
        } else {
            prefixSum += 1;
        }

        if(firstIndex.find(prefixSum) != firstIndex.end()) {

            maxLen = max(
                maxLen,
                i - firstIndex[prefixSum]
            );

        } else {

            firstIndex[prefixSum] = i;
        }
    }

    return maxLen;
}

int main() {

    vector<int> arr = {0, 1, 1, 0};

    cout << longestSubarrayEqualZeroOne(arr);

    return 0;
}