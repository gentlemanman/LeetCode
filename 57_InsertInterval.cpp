#include <iostream>
#include <vector>

using namespace std;

struct Interval{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution{
public:
    vector<Interval> insert( vector<Interval>& intervals, Interval newInterval){
        vector<Interval> res;
        if(intervals.empty()) {
            res.push_back(newInterval);
            return res;
        }
        int len = intervals.size();
        bool flag = false;
        for (int i=0; i<len; ++i){
            Interval tmp(intervals[i].start, intervals[i].end);
            if(tmp.end < newInterval.start){
                res.push_back(tmp);
            }
            else if( tmp.start > newInterval.end){
                if(!flag){
                    res.push_back(newInterval);
                    flag = true;
                }
                res.push_back(tmp);
            }
            else{
                newInterval.start = min( intervals[i].start, newInterval.start);
                newInterval.end = max( intervals[i].end, newInterval.end);
            }
        }
        if(!flag)
            res.push_back(newInterval);
        return res;
    }
};

int main()
{
    Interval in1(1,2);
    Interval in2(3,5);
    Interval in3(6,7);
    Interval in4(8,10);
    Interval in5(12,16);
    Interval n(4,9);

    vector<Interval> v;
    v.push_back(in1);
    v.push_back(in2);
    v.push_back(in3);
    v.push_back(in4);
    v.push_back(in5);

    Solution s;

    vector<Interval> r = s.insert(v,n);
    for(int i=0; i<r.size(); ++i){
        cout<<"["<<r[i].start<<","<<r[i].end<<"]"<<endl;
    }
    return 0;
}

