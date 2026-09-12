#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithEqual0s1sand2s(
    const vector<int>& arr
) {
    map<pair<int, int>, int> firstIndex;

    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    int mxLen = 0;

    firstIndex[{0, 0}] = -1;

    for(int i = 0; i < arr.size(); i++) {

        if(arr[i] == 0) {
            count0++;
        }
        else if(arr[i] == 1) {
            count1++;
        }
        else {
            count2++;
        }

        int difference01 = count0 - count1;
        int difference12 = count1 - count2;

        pair<int, int> state = {
            difference01,
            difference12
        };

        if(firstIndex.find(state) != firstIndex.end()) {

            mxLen = max(
                mxLen,
                i - firstIndex[state]
            );

        }
        else {
            firstIndex[state] = i;
        }
    }

    return mxLen;
}

int main() {

    vector<int> n = {
        0, 1, 2, 0, 1, 2,
        1, 1, 2, 2, 0, 0
    };

    cout << longestSubarrayWithEqual0s1sand2s(n);

    return 0;
}