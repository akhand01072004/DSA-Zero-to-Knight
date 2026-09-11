#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> num = {4, 5, 1, 2, 1, 4, 5, 2, 9};
    unordered_set<int> st;
    for (int n : num ){
        st.insert(n);
    }
    cout<<st.size();
        
}