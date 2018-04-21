#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target){
        if(matrix.empty() || matrix[0].empty()) return false;
        int m=matrix.size(), n=matrix[0].size();
        int t = -1;
        int low=0, high=m-1, mid;
        while(low<=high){
            mid = (low+high)/2;
            if(matrix[mid][0] <= target && matrix[mid][n-1] >= target){
                t=mid;
                break;
            }else if(matrix[mid][0] < target){
                low = mid+1;
            }else{
                high =mid-1;
            }
        }
        if(t==-1) return false;
        low = 0;
        high = n-1;
        while(low<=high){
            mid = (low+high)/2;
            if(matrix[t][mid] == target){
                return true;
            }else if(matrix[t][mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return false;
    }
};
int main()
{
    //vector<vector<int> > v={{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int> > v;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v.push_back(v1);
    
    Solution s;
    std::cout<<s.searchMatrix(v,3)<<std::endl;
    return 0;
}
