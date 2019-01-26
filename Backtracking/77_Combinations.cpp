#include <bits/stdc++.h>
using namespace std;

void dfs(int n, int k, int level, vector<int>& tmp, vector<vector<int>>& ans){
    if(tmp.size() == k){
        ans.push_back(tmp);
        return;
    }
    else{
        for(int i = level; i <= n; ++i){
            tmp.push_back(i);
            dfs(n, k, i + 1, tmp, ans);
            tmp.pop_back();
        }
    }
}

vector<vector<int>> combine(int n, int k){
    vector<vector<int>> ans;
    if(n < 1) return ans;
    vector<int> tmp;
    dfs(n, k, 1, tmp, ans);
    return ans;
}

int main(){
    vector<vector<int>> ans = combine(4, 2);
    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].size(); ++j){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}
