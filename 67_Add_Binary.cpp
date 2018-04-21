#include <iostream>
using namespace std;
class Solution{
public:
    string addBinary(string a, string b){
        string c = "";
        int len_a = a.length();
        int len_b = b.length();
        int i = len_a - 1, j = len_b - 1;
        bool flag = false;
        while(i>=0 && j>=0){
            if(a[i] == '1' && b[j] =='1'){
                if(flag){
                    c.insert(c.begin(),'1');
                }
                else{
                    c.insert(c.begin(),'0');
                    flag = true;
                }
            }
            else if((a[i] == '0' && b[j] == '1')||(a[i] == '1' && b[j] == '0')){
                if(flag){
                    c.insert(c.begin(),'0');
                }
                else{
                    c.insert(c.begin(),'1');
                }
            }
            else{
                if(flag){
                    c.insert(c.begin(),'1');
                    flag = false;
                }
                else{
                    c.insert(c.begin(),'0');
                }
            }
            --i;
            --j;

        }
        while(i >= 0){
            if(flag){
                if(a[i] == '1'){
                    c.insert(c.begin(),'0');
                }
                else{
                    c.insert(c.begin(),'1');
                    flag = false;
                }
            }
            else{
                c.insert(c.begin(),a[i]);
            }
            --i;
        }
        while(j >= 0){
            if(flag){
                if(b[j] == '1'){
                    c.insert(c.begin(),'0');
                }
                else{
                    c.insert(c.begin(),'1');
                    flag = false;
                }
            }
            else{
                c.insert(c.begin(),b[j]);
            }
            --j;
        }
        if(flag){
            c.insert(c.begin(),'1');
        }
        return c;
    }
};

int main(){
    string a="11";
    string b="1";
    Solution s;
    cout<<s.addBinary(a,b)<<endl;
}
