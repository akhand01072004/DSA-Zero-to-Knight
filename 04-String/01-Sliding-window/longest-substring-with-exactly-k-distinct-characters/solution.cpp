#include <bits/stdc++.h>
using namespace std;

int longestSubstringExactlyKDistinct(
    const string& s,
    int k
) {
    if (k <= 0 || s.empty()) {
        return 0;
    }

    unordered_map<char, int> freq;

    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < s.size(); right++) {

        // Add the current character
        freq[s[right]]++;

        // Shrink the window if distinct characters exceed k
        while (freq.size() > k) {

            freq[s[left]]--;

            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }

            left++;
        }

        // Update answer only for exactly k distinct characters
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

    string s = "aabacbebebe";
    int k = 2;

    cout << longestSubstringExactlyKDistinct(s, k)
         << endl;

    return 0;
}