#include <bits/stdc++.h>
using namespace std;

long long countSubstringsAtMostKDistinct(
    const string& s,
    int k
) {
    if (k <= 0 || s.empty()) {
        return 0;
    }

    unordered_map<char, int> freq;

    int left = 0;
    long long count = 0;

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

        // Count all valid substrings ending at right
        count += right - left + 1;
    }

    return count;
}

int main() {

    string s = "pqpqs";
    int k = 2;

    cout << countSubstringsAtMostKDistinct(
        s,
        k
    ) << endl;

    return 0;
}