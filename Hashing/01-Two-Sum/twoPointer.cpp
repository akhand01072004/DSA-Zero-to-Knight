#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> arr = {2, 7, 8, 9, 11, 16};
    int target = 13;

    int n = arr.size();
    int i=0;
    int j = n-1;

    while(i < j){
        if ( arr[i] + arr[j] == target){
            cout << "{ " << i << " , " << j << " }" << endl;
            break;
        }
        else if( arr[i] + arr[j] > target ) j--;
        else i++;
    }
}