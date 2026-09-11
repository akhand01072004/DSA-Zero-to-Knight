#include<bits/stdc++.h>
using namespace std;

int firstRepeatingElement(vector<int>& arr){

    unordered_set<int> st;

    for(int x : arr){
        if(st.find(x) != st.end()){
            return x;
        }
        st.insert(x);
    }
    
    return -1;
}

int main(){
    vector<int> n = {7, 3, 5, 3, 7};
    cout<<firstRepeatingElement(n);
    



}