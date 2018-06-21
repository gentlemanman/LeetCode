#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    vector<vector<int> > subsets(vector<int>& nums){
        vector<vector<int> > res;
        vector<int> tmp;
        recursion(nums, 0, tmp, res);
        return res;
    }
    void recursion(vector<int>& nums, int l, vector<int>& tmp, vector<vector<int> >& res){
        res.push_back(tmp);
        for(int i=l; i<nums.size(); ++i){
            tmp.push_back(nums[i]);
            recursion(nums, i+1, tmp, res);
            tmp.pop_back();
        }
    }
};

int main()
{
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    Solution s;
    vector<vector<int> > r = s.subsets(num);
    for(int i=0;i<r.size();i++){
        for(int j=0;j<r[i].size();j++){
            cout<<r[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
