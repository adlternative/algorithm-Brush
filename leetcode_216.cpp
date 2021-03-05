//
// Created by adl on 2020/9/11.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
//                        9        3      10
    void dfs(int cur, int n, int k, int sum) {
        if (temp.size() + (n - cur + 1) < k || temp.size() > k) { /* 0+(9-1+1)<3  */
            return;
        }
        if (temp.size() == k && accumulate(temp.begin(), temp.end(), 0) == sum) { /* */
            ans.push_back(temp);
            return;
        }
        temp.push_back(cur);
        dfs(cur + 1, n, k, sum);
        temp.pop_back();
        dfs(cur + 1, n, k, sum);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, 9, k, n);
        return ans;
    }
};


















class Solution2 {
public:
    vector<vector<int>>vv;
    vector<int>v;

    void  dfs(int cur,int range,int n ,int  k  ){
        if(v.size()+ range-cur +1 <k){
            return;
        }
        if(accumulate(v.begin(),v.end(),0)==n&&v.size()==k){
            vv.push_back(v);
            return;
        }
        if(cur >range ){
            return ;
        }
        v.push_back(cur);
        dfs(cur+1,range,n,k);
        v.pop_back();
        dfs(cur+1,range,n,k);

        return ;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1,9,n,k);
        return vv;
    }
};
int main(int argc, char *argv[]) {

    int k = 3, n = 7;
    Solution2 s;
    auto vv = s.combinationSum3(4, 54);
    for (const auto &v:vv) {
        for (const auto &item:v) {
            cout << item;
        }
        cout << endl;
    }
    return 0;
}
