#include <iostream>
using namespace std;
class Solution{
public:
    int mySqrt(int x){
        if(x==0) return 0;
        int i=0,j=x;
        while(i <= j){
            int m = (i+j)/2;
            long m2 = (long)m*m;
            if(m2 == x) return m;
            if(m2 > x) j=m-1;
            else i=m+1;
        }
        return i-1;
    }
};
int main(){
    Solution s;
    cout<<s.mySqrt(1)<<endl;
}
