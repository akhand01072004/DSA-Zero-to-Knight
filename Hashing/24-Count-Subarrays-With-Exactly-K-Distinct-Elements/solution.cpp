#include <bits/stdc++.h>
using namespace std;

long long countAtMostKDistinct(
    const vector<int>& arr,
    int k
) {
    if (k <= 0) {
        return 0;
    }

    unordered_map<int, int> freq;

    int left = 0;
    long long count = 0;

    for (int right = 0; right < arr.size(); right++) {

        // Add current element
        freq[arr[right]]++;

        // Shrink window if distinct count exceeds k
        while (freq.size() > k) {

            freq[arr[left]]--;

            if (freq[arr[left]] == 0) {
                freq.erase(arr[left]);
            }

            left++;
        }

        // Number of valid subarrays ending at right
        count += right - left + 1;
    }

    return count;
}

long long countSubarraysWithExactlyKDistinct(
    const vector<int>& arr,
    int k
) {
    return countAtMostKDistinct(arr, k)
         - countAtMostKDistinct(arr, k - 1);
}

int main() {

    vector<int> arr = {1, 2, 1, 2, 3};
    int k = 2;

    cout << countSubarraysWithExactlyKDistinct(arr, k)
         << endl;

    return 0;
}