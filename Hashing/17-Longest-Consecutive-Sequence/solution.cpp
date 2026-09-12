#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveSequence(const vector<int>& arr) {
    if (arr.empty()) {
        return 0;
    }

    unordered_set<int> s;

    for (int x : arr) {
        s.insert(x);
    }

    int maxLength = 0;

    for (int x : arr) {
        // x is the beginning of a sequence
        if (s.find(x - 1) == s.end()) {
            int current = x;
            int length = 1;

            while (s.find(current + 1) != s.end()) {
                current++;
                length++;
            }

            maxLength = max(maxLength, length);
        }
    }

    return maxLength;
}

int main() {
    vector<int> arr = {100, 4, 200, 1, 3, 2};

    cout << longestConsecutiveSequence(arr) << endl;

    return 0;
}