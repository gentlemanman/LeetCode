//
// Created by Administrator on 2019/1/16.
//

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> &nums, int level, vector<int> tmp, set<vector<int>>& ans){
    if(level <= nums.size()){
        ans.insert(tmp);
    } else return;

    for(int i = level; i < nums.size(); ++i){
        tmp.push_back(nums[i]);
        dfs(nums, i + 1, tmp, ans);
        tmp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    set<vector<int>> ans;
    vector<int> tmp;
    vector<vector<int>> res;
    if(nums.empty()){
        res.push_back(tmp);
        return res;
    }
    dfs(nums, 0, tmp, ans);
    res = vector<vector<int>>(ans.begin(), ans.end());
    return res;
}

int main(){
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = subsetsWithDup(nums);
    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].size(); ++j){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}
