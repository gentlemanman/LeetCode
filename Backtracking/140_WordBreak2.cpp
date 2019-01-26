//
// Created by Administrator on 2019/1/19.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<string> helper(string s, vector<string>& wordDict, unordered_map<string, vector<string>>& m){
    if(m.count(s)) return m[s];
    if(s.empty()) return {""};
    vector<string> res;
    for(string word : wordDict){
        if(s.substr(0, word.size()) != word) continue;
        vector<string> tmp = helper(s.substr(word.size()), wordDict, m);
        for(string str : tmp){
            res.push_back(word + (str.empty() ? "" : " ") + str);
        }
    }
    return m[s]=res;
}

vector<string> wordBreak(string s, vector<string>& wordDict){
    unordered_map<string, vector<string>> m;
    return helper(s, wordDict, m);
}


int main()
{
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    // cout<<isValid(s)<<endl;
    vector<string> ans = wordBreak(s, wordDict);
    for(int i = 0; i < ans.size(); ++i){
        cout<<ans[i]<<endl;
    }
    return 0;
}