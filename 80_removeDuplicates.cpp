#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        if(nums.empty()) return 0;
        int n = nums.size(), k = 0, times = 1;
        for(int i=1; i<n; ++i){
            if(nums[i] != nums[k]){
                nums[++k] = nums[i];
                times = 1;
            }else if(nums[i] == nums[k]){
                if(times >= 2){
                    continue;
                }else{
                    nums[++k] = nums[i];
                    ++times;
                }
            }
        }
        nums.resize(k+1);
        return k+1;
    }
};

int main()
{
    vector<int> v = {1,1,1,2,2,3};
    Solution s;
    cout<<s.removeDuplicates(v)<<endl;
    return 0;
}
