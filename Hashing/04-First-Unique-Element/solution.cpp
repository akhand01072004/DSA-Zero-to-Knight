#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> num = {4, 5, 1, 2, 1, 4, 5, 2, 9};

    unordered_map<int, int> freq;

    // Step 1: Count frequency
    for(int x : num) {
        freq[x]++;
    }

    // Step 2: Preserve original order
    for(int x : num) {
        if(freq[x] == 1) {
            cout << x;
            return 0;
        }
    }

    cout << "No unique element";

    return 0;
}