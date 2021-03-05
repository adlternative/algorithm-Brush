//
// Created by adl on 2020/8/1.
//
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    static map<pair<long long,long long>,long long> mm;
    long long n, q;
    cin >> n >> q;

    for (long long p = 0; p != q; ++p) {
        long long flag, i, j, k;
        cin >> flag;
        if (flag == 1) {
            cin >> i >> j >> k;
            if (k ==0){
                mm.erase({i, j});
            }else

            mm.insert(make_pair(make_pair(i, j), k));
        } else if (flag == 2) {
            cin >> i >> j;
            map<pair<long long,long long>,long long>::iterator iter =mm.find({i, j});
            if (iter!=mm.end()){
                cout <<iter->second<< endl;
            }
        }
    }
    return 0;
}