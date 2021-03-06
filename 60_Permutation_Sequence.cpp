#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    string getPermutation(int n, int k){
        vector<int> permutation(n, 1);
        for(int i=1; i<=n; ++i){
            permutation[i] = permutation[i-1] * i;
        }
        vector<char> digits = {'1','2','3','4','5','6','7','8','9'};
        string res;
        int num = n-1;
        while(num){
            int t = (k-1) / permutation[num--];
            k = k - t*permutation[num+1];
            res.push_back(digits[t]);
            digits.erase(digits.begin()+t);
        }
        res.push_back(digits[k-1]);
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.getPermutation(3,1)<<endl;
    return 0;
}
