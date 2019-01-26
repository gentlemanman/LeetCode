#include <bits/stdc++.h>
using namespace std;

/*void dfs(vector<int>& nums, int level, vector<int>& tmp, vector<vector<int>>& ans){
    ans.push_back(tmp);
    if(level == nums.size()){
        return;
    }
    else{
        for(int i = level; i < nums.size(); ++i){
            tmp.push_back(nums[i]);
            dfs(nums, i + 1, tmp, ans);
            tmp.pop_back();
        }
    }
}

vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int> tmp;
    dfs(nums, 0, tmp, ans);
    return ans;
}*/

//非递归写法
vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> ans(1);
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); ++i){
        int size = (int)ans.size();
        for(int j = 0; j < size; ++j){
            ans.push_back(ans[j]);
            ans.back().push_back(nums[i]);
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums);
    //cout<<ans.size()<<endl;
    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].size(); ++j){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}