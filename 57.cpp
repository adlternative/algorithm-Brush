#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int begin, end;
    vector<vector<int>> ret;
    int flag = 0;

    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        int tempbegin = begin = newInterval[0];
        int tempend = end = newInterval[1];

        if (intervals.empty()) {
            ret.push_back(newInterval);
            return ret;
        }
        for (const auto &item:intervals) {
            if (item[1] < begin) {
                ret.push_back(item);
            } else if (item[0] > end) {
                if (flag == 0) {
                    flag = 1;
                    ret.push_back(vector<int>{tempbegin,tempend});
                }
                ret.push_back(item);
            } else {
                tempbegin = min(tempbegin, item[0]);
                tempend = max(tempend, item[1]);
            }
        }
        if (flag == 0) {
            flag = 1;
            ret.push_back(vector<int>{tempbegin,tempend});
        }
        return ret;
    }
};

int main(int argc,char*argv[])
{
    return 0;
}