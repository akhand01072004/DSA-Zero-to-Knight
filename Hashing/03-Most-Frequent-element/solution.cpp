#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> num = {1,1, 2, 2, 1, 4, 2, 3, 3};
    unordered_map<int, int> m;
    for (int i = 0; i < num.size(); i++)
        m[num[i]]++;

    // Printing of Unordered_MAP

    int mx = 0;
    int ele = -1;
    cout << "Element Frequency" << endl;
    for (auto i : m)
        if (i.second > mx){
            ele = i.first;
            mx = i.second;
        }

    cout<< ele;
}