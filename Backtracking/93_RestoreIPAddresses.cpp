//
// Created by Administrator on 2019/1/16.
//

#include <bits/stdc++.h>
using namespace std;

bool isValid(string s){
    if(s.empty() || s.length() > 3 || (s.length() > 1 && s[0] == '0')) return false;
    int t = atoi(s.c_str());
    return t <= 255 && t >= 0;
}

void  dfs(string s, int k, string tmp, vector<string>& ans){
    if(k == 0){
        if(s.empty()) ans.push_back(tmp);
    }
    else{
        for(int i = 1; i <= 3; ++i){
            if(s.length() >= i && isValid(s.substr(0, i))){
                if(k == 1) dfs(s.substr(i), k - 1, tmp + s.substr(0, i), ans);
                else dfs(s.substr(i), k - 1, tmp + s.substr(0, i) + ".", ans);

            }
        }
    }

}

vector<string> restoreIpAddresses(string s){
    vector<string> ans;
    dfs(s, 4, "", ans);
    return ans;
}

int main()
{
    string s = "25525511135";
    vector<string> ans = restoreIpAddresses(s);
    for(int i = 0; i < ans.size(); ++i){
        //cout<<ans[i]<<endl;
    };
    string a = s.substr(2);
    cout<<a<<endl;
    return 0;
}