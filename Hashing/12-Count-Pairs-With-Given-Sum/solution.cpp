#include <bits/stdc++.h>
using namespace std;

int countPairsWithGivenSum(vector<int>& arr, int target) {

    unordered_map<int, int> freq;
    int occurrence = 0;

    for (int x : arr) {

        int needed = target - x;

        occurrence += freq[needed];

        freq[x]++;
    }

    return occurrence;
}

int main() {

    vector<int> n = {1, 5, 7, -1, 5};

    cout << countPairsWithGivenSum(n, 6);

    return 0;
}