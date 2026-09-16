#include <bits/stdc++.h>
using namespace std;

int longestSubstringAtMostKDistinct(
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

        // Current window contains at most k distinct characters
        maxLength = max(
            maxLength,
            right - left + 1
        );
    }

    return maxLength;
}

int main() {

    string s = "eceba";
    int k = 2;

    cout << longestSubstringAtMostKDistinct(s, k)
         << endl;

    return 0;
}