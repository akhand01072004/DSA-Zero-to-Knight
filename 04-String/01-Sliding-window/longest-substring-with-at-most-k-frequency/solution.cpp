#include <bits/stdc++.h>
using namespace std;

int longestSubstringAtMostKFrequency(
    const string& s,
    int k
) {
    if (k <= 0 || s.empty()) {
        return 0;
    }

    int n = s.size();
    int left = 0;
    int maxLength = 0;

    unordered_map<char, int> freq;

    for (int right = 0; right < n; right++) {

        freq[s[right]]++;

        while (freq[s[right]] > k) {
            freq[s[left]]--;
            left++;
        }

        maxLength = max(
            maxLength,
            right - left + 1
        );
    }

    return maxLength;
}

int main() {

    string s = "aabacbebebe";
    int k = 2;

    cout << longestSubstringAtMostKFrequency(s, k)
         << endl;

    return 0;
}