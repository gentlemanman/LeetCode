#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
public:
    int minDistance(string word1, string word2){
        int m=word1.size(), n=word2.size();
        if(m==0) return n;
        if(n==0) return m;
        vector<vector<int> > dp(m+1, vector<int>(n+1));
        for(int i=0; i<=m; ++i){
            for(int j=0; j<=n; ++j){
                if(j == 0)
                    dp[i][j]=i;
                else if(i == 0)
                    dp[i][j]=j;
                else
                    dp[i][j] = min(dp[i-1][j-1] + (word1[i-1]==word2[j-1]?0:1), min(dp[i-1][j]+1,dp[i][j-1]+1));
            }
        }
        return dp[m][n];
    }
};
int main(){
    Solution s;
    cout<<s.minDistance("11","123")<<endl;
    return 0;
}
