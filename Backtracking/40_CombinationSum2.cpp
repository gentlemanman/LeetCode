#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>& candidates, int target, int start, vector<int> &tmp, vector<vector<int>>& ans){
    if(target < 0) return;
    else if(target == 0){
        ans.push_back(tmp);
        return;
    }
    else{
        for(int i = start; i < candidates.size(); ++i){
            if(i > start && candidates[i] == candidates[i - 1]) continue;
            tmp.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, tmp, ans);
            tmp.pop_back();
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
    vector<vector<int>> ans;
    if(candidates.empty()) return ans;
    sort(candidates.begin(), candidates.end());
    vector<int> tmp;
    dfs(candidates, target, 0, tmp, ans);
    return ans;
}

int main(){
    vector<int> candidates = {1, 1, 2};
    vector<vector<int>> ans = combinationSum2(candidates, 3);
    cout<<ans.size()<<endl;
    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].size(); ++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
