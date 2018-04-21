#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution{
public:
    string simplifyPath(string path){
        stack<string> stack;
        for(int i=0; i < path.size();){
            // 跳过'/'
            while(i < path.size() && '/' == path[i])
                ++i;
            // 记录路径名
            string s = "";
            while(i < path.size() && path[i] != '/')
                s += path[i++];
            // 弹栈
            if(".." == s && !stack.empty())
                stack.pop();
            // 压栈
            if(s != "" && s != "." && s != "..")
                stack.push(s);
        }
        if(stack.empty())
            return "/";
        string s = "";
        while(!stack.empty()){
            s = "/" +stack.top() + s;
            stack.pop();
        }
        return s;
    }
};

int main(){
    Solution s;
    string str=s.simplifyPath("/bin/");
    cout<<str<<endl;
    return 0;
}

