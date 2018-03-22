#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int uniquePaths(int m, int n){
        if( m<=0 || n<=0){
            return 0;
        }
        vector<int> res(n,0);
        res[0] = 1;
        for(int i=0; i<m; ++i){
            for(int j=1; j<n; ++j){
                res[j] = res[j] + res[j-1];
            }
        }
        return res[n-1];
    }
};
int main(){
    Solution s;
    cout<<s.uniquePaths(51,9)<<endl;
    return 0;
}
