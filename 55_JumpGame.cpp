#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    bool canJump(vector<int>& nums){
        int n = nums.size();
        int i = 0;
        while(i<n){
            if(i==n-1) return true;
            if(nums[i]==0) return false;
            for(int j=nums[i]; j>0; j--)
            {
                i += j;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(0);
    Solution s;
    cout<<s.canJump(nums)<<endl;
    return 0;
}
