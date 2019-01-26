#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>& nums, int level, vector<int>& tmp, vector<int>& visited, set<vector<int>>& ans){
    if(level == nums.size()){
        ans.insert(tmp);
        return;
    }
    else{
        for(int i = 0; i < nums.size(); ++i){
            if(visited[i] == 0){
                //if(i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) continue;
                visited[i] = 1;
                tmp.push_back(nums[i]);
                dfs(nums, level + 1, tmp, visited, ans);
                tmp.pop_back();
                visited[i] = 0;
            }
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums){
    vector<vector<int>> res;
    if(nums.empty()) return res;
    sort(nums.begin(), nums.end());
    set<vector<int>> ans;
    vector<int> tmp;
    vector<int> visited(nums.size(), 0);
    dfs(nums, 0, tmp, visited, ans);
    res = vector<vector<int>>(ans.begin(), ans.end());
    return res;
}

int main(){
    vector<int> nums = {1, 1, 3};
    vector<vector<int>> ans = permuteUnique(nums);
    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].size(); ++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}