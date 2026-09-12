#include<bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> arr, int k){

    unordered_map<long long, int> firstIndex;

    long long prefixsum = 0;
    int mxLen = 0;

    firstIndex[0] = -1;

    for(int i = 0; i < arr.size(); i++){

        prefixsum += arr[i];

        long long needed = prefixsum - k;

        if(firstIndex.find(needed) != firstIndex.end()){
            mxLen = max(mxLen, i - firstIndex[needed]);
        }

        if(firstIndex.find(prefixsum) == firstIndex.end()){
            firstIndex[prefixsum] = i;
        }
    }

    return mxLen;
}

int main(){

    vector<int> n = {10, 5, 2, 4, 3, 1, 9};

    cout << longestSubarrayWithSumK(n, 15);
}