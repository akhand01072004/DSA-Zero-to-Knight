#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> arr = {2, 7, 9, 11, 16};
    int target = 13;

    unordered_map<int, int> mp;

    for(int i=0; i< arr.size(); i++){
        int needed = target - arr[i]; 

        if(mp.find(needed) != mp.end()){
            cout<<"{ "<< mp[needed] <<" , "<< i;
            return 0;
        }

        mp[arr[i]] = i;
    }
}
