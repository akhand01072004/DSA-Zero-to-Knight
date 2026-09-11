
#include <bits/stdc++.h>
using namespace std;

int maximumFrequencyElement(vector<int>& arr) {

    unordered_map<int, int> freq;

    int maxFrequency = 0;
    int element = -1;

    for (int x : arr) {

        freq[x]++;

        if (freq[x] > maxFrequency) {
            maxFrequency = freq[x];
            element = x;
        }
    }

    return element;
}

int main() {

    vector<int> arr = {4, 7, 2, 7, 9, 4, 2, 7};

    cout << maximumFrequencyElement(arr);

    return 0;
}

