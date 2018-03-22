#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<int> > generateMatrix(int n){
        int count = 1;
        vector<vector<int> > res;
        // initialize matrix
        for(int x=1; x<=n; x++){
            vector<int> v(n,0);
            res.push_back(v);
        }
        for(int x=0; x<n; x++){
            // 首行
            for(int j=x; j<n; j++){
                res[x][j] = count++;
            }
            // 右列
            for(int i=x+1; i<n; i++){
                res[i][n-1] = count++;
            }
            // 底行
            for(int j=n-2; j>=x; j--){
                res[n-1][j] = count++;
            }
            //左列
            for(int i=n-2; i>x; i--){
                res[i][x] = count++;
            }
            n--;
        }
        return res;
    }
};

int main(){
    int n=5;
    vector<vector<int> > res;
    Solution s;
    res = s.generateMatrix(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
