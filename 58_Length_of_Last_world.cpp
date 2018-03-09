#include <iostream>

using namespace std;

class Solution{
public:
    int lengthOfLastWord(string s){
        int n = s.length();
        int len = 0;
        bool flag = false;
        for ( int i=n-1; i >=0; --i)
        {
            if ( s[i] !=' '){
                len++;
                flag=true;
            }
            else{
                if(!flag)
                    continue;
                else 
                    break;
            }
        }
        return len;
    }
};

int main()
{
    string str= "a a  ";
    Solution solution;
    cout<<solution.lengthOfLastWord(str)<<endl;
    return 0;
}

