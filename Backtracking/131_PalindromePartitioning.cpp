//
// Created by Administrator on 2019/1/19.
//

#include <bits/stdc++.h>
using namespace std;

bool isValid(string s){
    int i = 0;
    int j = int(s.length()) - 1;
    while(i <= j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

void dfs(string s, vector<string>& tmp, vector<vector<string>>& ans){
    if(s.empty()){
        ans.push_back(tmp);
        return;
    }
    else{
        for(int i = 1; i <= s.length(); ++i){
            if(isValid(s.substr(0, i))){
                tmp.push_back(s.substr(0, i));
                dfs(s.substr(i), tmp, ans);
                tmp.pop_back();
            }
        }
    }
}

vector<vector<string>> partition(string s){
    vector<vector<string>> ans;
    if(s.empty()) return ans;
    vector<string> tmp;
    dfs(s, tmp, ans);
    return ans;
}

int main()
{
    string s = "aab";
    // cout<<isValid(s)<<endl;
    vector<vector<string>> ans = partition(s);
    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[0].size(); ++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
