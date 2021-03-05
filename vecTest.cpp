//
// Created by adl on 2020/9/6.
//

#include<bits/stdc++.h>

using namespace std;

int main(int argc,char*argv[])
{
    vector<int>v;
    list<int>l{1,2,3};
    v.insert(v.begin(),l.begin(),l.end());
    for (const auto &item:v) {
        cout << item<<endl;
    }
    return 0;
}