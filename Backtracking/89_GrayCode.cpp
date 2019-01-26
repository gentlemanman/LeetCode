//
// Created by Administrator on 2019/1/15.
//
#include <bits/stdc++.h>
using namespace std;

vector<int> grayCode(int n) {
    vector<int> res;
    for (int i = 0; i < pow(2,n); ++i) {
        res.push_back((i >> 1) ^ i); //右移和异或
    }
    return res;
}

int main()
{
    vector<int> ans = grayCode(2);
    for(int i = 0; i < ans.size(); ++i){
        //cout<<ans[i]<<endl;
    }
    int a = 2;
    int b = 1;
    cout<<(a ^ 1)<<endl;
    return 0;
}

