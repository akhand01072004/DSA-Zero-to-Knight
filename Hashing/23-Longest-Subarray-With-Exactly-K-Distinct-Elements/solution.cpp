#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithExactlyKDistinct(
    const vector<int>& arr,
    int k
) {
    if (k <= 0 || arr.empty()) {
        return 0;
    }

    unordered_map<int, int> freq;

    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < arr.size(); right++) {

        // Add current element to the window
        freq[arr[right]]++;

        // Shrink while the window has more than K distinct elements
        while (freq.size() > k) {

            freq[arr[left]]--;

            // Remove the element completely if its frequency becomes zero
            if (freq[arr[left]] == 0) {
                freq.erase(arr[left]);
            }

            left++;
        }

        // Update only when the window has exactly K distinct elements
        if (freq.size() == k) {
            maxLength = max(
                maxLength,
                right - left + 1
            );
        }
    }

    return maxLength;
}

int main() {
    vector<int> arr = {1, 2, 1, 2, 3};
    int k = 2;

    cout << longestSubarrayWithExactlyKDistinct(arr, k);

    return 0;
}