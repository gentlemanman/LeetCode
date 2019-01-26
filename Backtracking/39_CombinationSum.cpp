#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>& candidates, int target, vector<int> &tmp, vector<vector<int>> &ans, int begin){
    if(target < 0) return;
    if(target == 0){
        ans.push_back(tmp);
        return;
    }
    for(int i = begin; i < candidates.size(); ++i){
        tmp.push_back(candidates[i]);
        dfs(candidates, target - candidates[i], tmp, ans , i);
        tmp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    vector<vector<int>> ans;
    if(candidates.empty()) return ans;
    sort(candidates.begin(), candidates.end());
    vector<int> tmp;
    dfs(candidates, target, tmp, ans, 0);
    return ans;
}

int main(){
    vector<int> candidates = {1, 1, 2,};
    vector<vector<int>> ans = combinationSum(candidates, 3);
    cout<<ans.size()<<endl;
    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].size(); ++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
