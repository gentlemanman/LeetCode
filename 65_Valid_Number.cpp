#include <iostream>
using namespace std;
class Solution{
public:
    bool isNumber(string s){
        int size = s.size();
        if(size == 0){
            return false;
        }
        //前导
        int start = 0;
        while(s[start] == ' '){
            ++start;
        }
        int end = size-1;
        while(s[end] == ' '){
            --end;
        }
        bool hasNum = false,hasPoint = false,hasE=false;
        for(int i=start; i<=end; ++i){
            if(s[i] == '.'){
                // 前边有.或e
                if(hasPoint || hasE){
                    return false;
                }
                hasPoint = true;
            }
            else if(s[i] == 'e'){
                //前边有e或者没数字
                if(hasE || !hasNum){
                    return false;
                }
                hasE = true;
            }
            else if(s[i] < '0' || s[i]>'9'){
                //+2
                if(i == start && (s[i] == '+' || s[i] == '-')){
                    continue;
                }
                //le-2
                else if((i != 0 && s[i-1] == 'e') && (s[i] == '+' || s[i] == '-')){
                    continue;
                }
                else{
                    return false;
                }
            }
            else{
                hasNum = true;
            }
        }
        //最后不能是e+-
        if(s[end] == 'e' || s[end] == '+' || s[end] == '-'){
            return false;
        }
        //.
        if(!hasNum && hasPoint){
            return false;
        }
        if(end == -1){
            return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    string str(" 4.4e3 ");
    cout<<s.isNumber(str)<<endl;
    return 0;
}
