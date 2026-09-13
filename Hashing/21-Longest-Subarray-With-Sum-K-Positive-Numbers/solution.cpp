#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumKPositiveNumbers(
    const vector<int>& arr,
    int k
) {
    int n = arr.size();

    int left = 0;
    int sum = 0;
    int maxLength = 0;

    for (int right = 0; right < n; right++) {
        sum += arr[right];

        while (sum > k) {
            sum -= arr[left];
            left++;
        }

        if (sum == k) {
            maxLength = max(
                maxLength,
                right - left + 1
            );
        }
    }

    return maxLength;
}

int main() {
    vector<int> arr = {
        1, 2, 2, 3, 1,
        2, 3, 1, 3, 3
    };

    cout << longestSubarrayWithSumKPositiveNumbers(arr, 5);

    return 0;
}