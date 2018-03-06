#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Interval{
    int start;
    int end;
    Interval() : start(0),end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution{
public:
    static bool compare(const Interval &a, const Interval &b)
    {
        return (a.start < b.start);
    }

    vector<Interval> merge(vector<Interval>& intervals){
        vector<Interval> res;
        if(intervals.empty()) return res;
        sort(intervals.begin(), intervals.end(), compare);
        res.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); ++i)
        {
            if(res.back().end >= intervals[i].start)
                res.back().end = max(res.back().end, intervals[i].end);
            else 
                res.push_back(intervals[i]);
        }
        return res;
    }
};

int main ()
{
    Solution s;
    Interval in1(1,2);
    Interval in2(4,6);
    Interval in3(8,10);
    Interval in4(15,18);

    vector<Interval> vec;
    vec.push_back(in1);
    vec.push_back(in2);
    vec.push_back(in3);
    vec.push_back(in4);
    
    vector<Interval> v = s.merge(vec);
    for(int i=0; i<v.size(); ++i){
        Interval in = v[i];
        cout<<"["<<in.start<<","<<in.end<<"]"<<endl;
    }
    return 0;
}

