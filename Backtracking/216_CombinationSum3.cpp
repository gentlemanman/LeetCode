//
// Created by Administrator on 2019/1/20.
//

#include <bits/stdc++.h>
using namespace std;

void dfs(int k, int n, int level, int target, vector<int>& tmp, vector<vector<int>>& ans){
    if(target < 0){
        return;
    }
    if(target == 0 && tmp.size() == k){
        ans.push_back(tmp);
    }
    else{
        for(int i = level; i <= 9; ++i){
            if(tmp.size() < k && target > 0){
                tmp.push_back(i);
                dfs(k, n, i + 1, target - i, tmp, ans);
                tmp.pop_back();
            }
        }
    }
}

vector<vector<int>> combinationSum3(int k, int n){
    vector<vector<int>> ans;
    if(k <= 0 || n <= 0) return ans;
    vector<int> tmp;
    int target = n;
    int level = 1;
    dfs(k, n, level, target, tmp, ans);
    return ans;
}

int main(){
    vector<vector<int>> ans = combinationSum3(3, 15);
    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].size(); ++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

