#include<bits/stdc++.h>
using namespace std;

long long int countSubarraysWithSumZero(vector<int>& arr){

    unordered_map<int, int> freq;
    long long int countOfSubarray = 0;
    freq[0] = 1;
    int prefixSum = 0;

    for(int i = 0; i < arr.size(); i++){
        prefixSum += arr[i];

        countOfSubarray += freq[prefixSum];

        freq[prefixSum]++;

    }        

    return countOfSubarray;
}

int main(){

    vector<int> n = {1,-1,1,-1};

    cout << countSubarraysWithSumZero(n);
}