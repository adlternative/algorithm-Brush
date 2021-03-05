//
// Created by adl on 2020/11/6.
//

#include<bits/stdc++.h>

using namespace std;
class Solution {
    unordered_map<int,int>m;
    unordered_map<int,vector<int>>mm;
    vector<int>ret;
public:   
    int getOneNum(int i ){
        int num =0 ;
        while(i){
            int n =i%2;
            if(n){
                num++;
            }
            i/=2;
        }
        return num;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        for (int i = 0; i != arr.size(); ++i) {
            mm[getOneNum(arr[i])].push_back(arr[i]);
        }
        for (int i = 0; i != mm.size(); ++i) {
            auto&vec=mm[i];
            sort(vec.begin(),vec.end());
            for (int j = 0; j !=vec.size(); ++j) {
                ret.push_back(vec[j]);
            }
        }
        return ret;
    }
};
int main(int argc,char*argv[])
{
    Solution  s;
    vector<int>v{0,1,2,3,4,5,6,7,8};
    auto vv=s.sortByBits(v);
    for (const auto &it:vv) {
        std::cout << it << std::endl;
    }
    return 0;
}