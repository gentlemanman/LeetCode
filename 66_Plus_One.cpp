#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> plusOne(vector<int>& digits){
        int len = digits.size();
        int i=len-1;
        while(i >= 0){
            int t = digits[i] + 1;
            if(t >= 10){
                digits[i] = t % 10;
                i--;
            }
            else{
                digits[i] = t; 
                break;
            }
        }
        if(i < 0){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main(){
    vector<int> v(3,3);
    Solution s;
    vector<int> res = s.plusOne(v);
    int i;
    for(i=0; i<res.size(); ++i){
        cout<<res[i]<<endl;
    }
    cout<<"i="<<i<<endl;
    return 0;
}
