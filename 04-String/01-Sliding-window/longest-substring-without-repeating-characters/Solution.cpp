#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(const string& s) {

    int left = 0;
    int maxLength = 0;

    unordered_map<char, int> freq;

    for (int right = 0; right < s.size(); right++) {

        // Add the current character
        freq[s[right]]++;

        // Shrink the window while duplicate exists
        while (freq[s[right]] > 1) {

            freq[s[left]]--;
            left++;
        }

        // Current window has no duplicate characters
        maxLength = max(
            maxLength,
            right - left + 1
        );
    }

    return maxLength;
}

int main() {

    string str = "pwwkew";

    cout << lengthOfLongestSubstring(str) << endl;

    return 0;
}