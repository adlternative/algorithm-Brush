//
// Created by adl on 2020/11/2.
//

#include<bits/stdc++.h>

using namespace std;
class Solution {
    set<int>s;
    set<int>s2;
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        s.insert(nums1.begin(),nums1.end());
        for (int i = 0; i != nums2.size(); ++i) {
            if(s.find(nums2[i])!=s.end()){
                s2.insert(nums2[i]);
            }
        }
        v.assign(s2.begin(),s2.end());
        return v;
    }
};
int main(int argc,char*argv[])
{
    return 0;
}