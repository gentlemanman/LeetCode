#include <iostream>
using namespace std;
class Solution{
public:
    int climbStairs(int n){
       if(n<=0) return 0;
       int *r = new int[n];
       r[0] = 1;
       r[1] = 2;
       for(int i=2; i<n; ++i)
           r[i] = r[i-1] + r[i-2];
       int res = r[n-1];
       delete []r;
       return res;
    }
        
};
int main(){
    Solution s;
    cout<<s.climbStairs(2)<<endl;
    return 0;
}
