#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>& nums, int level,vector<int>& tmp, vector<int> &visited, vector<vector<int>> &ans){
    if(level == nums.size()){
        ans.push_back(tmp);
        return;
    }
    for(int i = 0; i < nums.size(); ++i){
        if(visited[i] == 0){
            visited[i] = 1;
            tmp.push_back(nums[i]);
            dfs(nums, level + 1, tmp, visited, ans);
            tmp.pop_back();
            visited[i] = 0;
        }
    }
}
vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> ans;
    if(nums.empty()) return ans;
    vector<int> visited(nums.size(), 0);
    vector<int> tmp;
    dfs(nums, 0, tmp, visited, ans);
    return ans;
}
/*
//另外一种写法
void dfs(vector<int>& nums, int start, vector<vector<int>> &ans){
    if(start == nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i = start; i < nums.size(); ++i){
        swap(nums[i], nums[start]);
        dfs(nums, start + 1, ans);
        swap(nums[i], nums[start]);
    }
}
vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> ans;
    if(nums.empty()) return ans;
    dfs(nums, 0, ans);
    return ans;
}
*/

int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = permute(nums);
    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].size(); ++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}