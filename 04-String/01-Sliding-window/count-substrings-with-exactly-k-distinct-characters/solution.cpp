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

        freq[s[right]]++;

        while (freq.size() > k) {

            freq[s[left]]--;

            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }

            left++;
        }

        count += right - left + 1;
    }

    return count;
}

long long countSubstringsExactlyKDistinct(
    const string& s,
    int k
) {
    if (k <= 0 || s.empty()) {
        return 0;
    }

    return countSubstringsAtMostKDistinct(s, k)
         - countSubstringsAtMostKDistinct(s, k - 1);
}

int main() {
    string s = "pqpqs";
    int k = 2;

    cout << countSubstringsExactlyKDistinct(s, k);

    return 0;
}