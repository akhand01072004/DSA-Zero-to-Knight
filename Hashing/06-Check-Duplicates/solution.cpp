#include<bits/stdc++.h>

using namespace std;

bool checkDuplicate(vector<int>& num){

    unordered_set<int> st;
    for (int n : num ){
        if(st.find(n) != st.end()){
            return true;
        }
        st.insert(n);
    }
    return false;

}

int main(){
    vector<int> num = {4, 1,2,3,6,7,8,9};
   
    cout<<checkDuplicate(num);
        
}