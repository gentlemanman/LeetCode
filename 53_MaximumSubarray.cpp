#include <iostream>
using namespace std;
#include <cmath>
#include <vector>
class Solution{
public:
    int maxSubArray(vector<int>& nums){
        int curMax = nums[0];
        int maxSum = nums[0];
        for(int i=1; i<nums.size(); ++i){
            curMax = max(curMax+nums[i], nums[i]);
            if(curMax>maxSum)
                maxSum = curMax;
        }
        return maxSum;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);
    Solution s;
    cout<<s.maxSubArray(nums)<<endl;
    return 0;
}
