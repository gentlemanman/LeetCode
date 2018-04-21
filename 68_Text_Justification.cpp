#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution{
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth){
        if(words.empty())
            return vector<string>();
        vector<string> res;
        int sz = words.size();
        vector<string> tmp;
        int sumLen = 0, count = 0;
        for(int i=0; i<sz; ++i){
            if((sumLen + words[i].length() + count) <= maxWidth){
                ++count;
                sumLen = sumLen + words[i].length();
                tmp.push_back(words[i]);
                continue;
            }
            else{
                if(1 == count){
                    string str = tmp[0];
                    while(str.length() < maxWidth)
                        str += " ";
                    res.push_back(str);
                }
                else{
                    string str = "";
                    // 需要放置额外的空格
                    int extraSpace = maxWidth - sumLen - count + 1;
                    // 每个间隔徐再增加的空格
                    int everySpace = extraSpace / (count - 1);
                    // 前几个间隔需要在放置的空格
                    int frontSpace = extraSpace % (count - 1);
                    
                    for(int k=0; k<count-1; ++k){
                        int j = 0;
                        //1+everySpace个空格
                        while(j < everySpace + 1){
                            tmp[k] += " ";
                            ++j;
                        }
                    }
                    for(int k=0; k<frontSpace; ++k){
                        str += " ";
                    }
                    for(int k=0; k<count; ++k){
                        str += tmp[k];
                    }
                    res.push_back(str);
                }
            }
            tmp.clear();
            count = 0;
            sumLen = 0;
            --i;
        }
        if(1 == count){
            string str = tmp[0];
            while(str.length() < maxWidth)
                str +=" ";
            res.push_back(str);
        }
        if(count > 1){
            string str="";
            for(int k=0;k<count-1;++k){
                str = str + tmp[k] + " ";
            }
            str += tmp[count-1];
            while(str.length() < maxWidth)
                str += " ";
            res.push_back(str);
        }
        return res;
    }
};

int main(){
    vector<string> v;
    v.push_back("1");
    v.push_back("2");
    v.push_back("3");
    v.push_back("4");
    v.push_back("5");
    Solution s;
    vector<string> r=s.fullJustify(v,3);
    for(int i=0; i<r.size(); ++i)
        cout<<r[i]<<endl;
    return 0;
}
