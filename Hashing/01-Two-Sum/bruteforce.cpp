#include<bits/stdc++.h>
using namespaces std;

int main(){
    vector<int> arr = {2, 7, 8, 9, 11, 15};
    int n = arr.size();
    int target = 13;

    for(int i=0; i<n; i++){
        for(int j= i+1; j<n; j++){
            if(arr[i] + arr[j] == target){
               cout << "{ " << arr[i] << " , " << arr[j] << " }" << endl;
               break; 
            }
        }
    }
}