class Solution{
public:
    bool search(vector<int> &A, int target){
        int low = 0, high = A.size() - 1, size = A.size(), mid = 0;
        if(size <= 0){
            return 0;
        }
        while(low <= high){
            mid = low + (high - low) / 2;
            if(A[mid] == target){
                return 1;
            }
            if(A[mid] > A[low]){
                if(A[low] <= target && target < A[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else if(A[mid] < A[low]){
                if(A[mid] < target && target <= A[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            else{
                low++;
            }
        }
        return 0;
    }
};