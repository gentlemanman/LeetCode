#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    string minWindow(string s, string t){
        int ls = s.length();
        int lt = t.length();
        if(ls == 0 || lt == 0) return "";
        int start =0, cur_start = 0, cur_end = 0;
        int min_len = s.length() + 1;
        vector<int> t_freq(128, 0);
        for (int i=0; i<lt; i++){
            char ch = t[i];
            t_freq[ch]++;
        }
        int cnt = 0; // 记录总次数
        while(cur_end < ls){
            char ch = s[cur_end];
            if(t_freq[ch] > 0){
                cnt++;
            }
            t_freq[ch]--;
            cur_end++;
            if(cnt == lt){
                while(cur_start < cur_end){
                    ch = s[cur_start];
                    if(t_freq[ch] < 0){
                        t_freq[ch]++;
                        cur_start++;
                        continue;
                    }else{
                        int cur_len = cur_end - cur_start;
                        if(cur_len < min_len){
                            min_len = cur_len;
                            start = cur_start;
                        }
                        cnt--;
                        t_freq[ch]++;
                        cur_start++;
                        break;
                    }
                }
            }
        }
        if(min_len <= ls) return s.substr(start, min_len);
        else return "";
    }
};
int main(){
    Solution s;
    cout<<s.minWindow("113","3");
    return 0;
}
