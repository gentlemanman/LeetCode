#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    void sortColors(vector<int>& nums){
        int n=nums.size();
        int low=0,high=n-1,i=0;
        while(i<=high){
            if(nums[i]==0) swap(nums[i++],nums[low++]);
            else if(nums[i]==2) swap(nums[i],nums[high--]);
            else i++;
        }
    }
};

int main()
{
    vector<int> v={1,2,1,2,0,0,0,1};
    Solution s; 
    s.sortColors(v);
    for(int i=0;i<v.size();++i){
        cout<<v[i];
    }
    return 0;
}
