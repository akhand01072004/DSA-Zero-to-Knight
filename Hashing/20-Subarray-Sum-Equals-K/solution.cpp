#include <bits/stdc++.h>
using namespace std;

long long countSubarraysWithSumK(
    const vector<int>& arr,
    int K
) {
    unordered_map<long long, int> freq;

    long long countOfSubarrays = 0;
    long long prefixSum = 0;

    freq[0] = 1;

    for (int x : arr) {
        prefixSum += x;

        long long needed = prefixSum - K;

        countOfSubarrays += freq[needed];

        freq[prefixSum]++;
    }

    return countOfSubarrays;
}

int main() {
    vector<int> arr = {1, 2, 3};
    int K = 3;

    cout << countSubarraysWithSumK(arr, K);

    return 0;
}