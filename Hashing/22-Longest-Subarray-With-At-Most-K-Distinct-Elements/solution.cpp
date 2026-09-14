#include <bits/stdc++.h>
using namespace std;

int longestSubarrayAtMostKDistinct(
    const vector<int>& arr,
    int k
) {
    unordered_map<int, int> freq;

    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < arr.size(); right++) {

        // Add current element to the window
        freq[arr[right]]++;

        // Shrink window while distinct elements exceed k
        while (freq.size() > k) {

            freq[arr[left]]--;

            // Remove element completely when its frequency becomes zero
            if (freq[arr[left]] == 0) {
                freq.erase(arr[left]);
            }

            left++;
        }

        // Current window is valid
        maxLength = max(
            maxLength,
            right - left + 1
        );
    }

    return maxLength;
}

int main() {

    vector<int> arr = {1, 2, 1, 2, 3};
    int k = 2;

    cout << longestSubarrayAtMostKDistinct(arr, k);

    return 0;
}