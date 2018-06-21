#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    vector<vector<int>> combine(int n, int k){
        vector<vector<int>> res;
        vector<int> tmp;
        recursion(n, k, 1, tmp, res);
        return res;
    }
    void recursion(int n, int k, int l, vector<int>& tmp, vector<vector<int>>& res){
        if(tmp.size() == k) res.push_back(tmp);
        for(int i = l; i <= n; ++i){
            tmp.push_back(i);
            recursion(n, k, i+1, tmp, res);
            tmp.pop_back();
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> r = s.combine(4,2);
    for(auto &row : r)
        for(auto col : row)
            cout<<col;
    return 0;

}
