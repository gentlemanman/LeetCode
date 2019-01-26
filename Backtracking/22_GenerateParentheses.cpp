#include <bits/stdc++.h>
using namespace std;

vector<string> res;

void generate(int left, int right, string s, int n){
    if(right == n){
        res.push_back(s);
    }
    else{
        if(left < n){
            generate(left + 1, right, s + '(', n);
        }
        if(right < left){
            generate(left, right + 1, s + ')', n);
        }
    }
}

vector<string> generateParenthesis(int n){
    generate(0, 0, "", n);
    return res;
}

int main(){
    vector<string> r = generateParenthesis(3);
    for(int i = 0; i < res.size(); ++i)
        cout<<res[i]<<endl;
}


