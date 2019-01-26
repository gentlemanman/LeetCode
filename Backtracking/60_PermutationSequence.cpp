#include <bits/stdc++.h>
using namespace std;

// 此题的递归生成的顺序不对, 且存在超时的情况

string getPermutation(int n, int k){
    if(n < 0) return "";
    string ans;
    string num = "123456789";
    vector<int> f(n, 1);
    for(int i = 1; i < n; ++i) f[i] = f[i - 1] * i;
    --k;
    for(int i = n; i >=1; --i){
        int j = k / f[i - 1];
        k %= f[i - 1];
        ans.push_back(num[j]);
        num.erase(j, 1);
    }
    return ans;
}

int main(){
    string str = getPermutation(3, 6);
    cout<<str<<endl;
    return 0;
}