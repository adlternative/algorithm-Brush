//
// Created by adl on 2020/8/3.
//

#include<bits/stdc++.h>

using namespace std;
const int maxN=1e5+10;
list<int>::iterator pos[maxN];
bool erased[maxN];
int main(int argc, char *argv[]) {
    int n, k, m, x, flag;
    list<int> v;
    cin >> n;
    pos[1]=v.insert(v.begin(), 1);
    for (int i = 2; i != n + 1; ++i) {
        cin >> k >> flag;
        list<int>::iterator f=pos[k];
//        list<int>::iterator f = find(v.begin(), v.end(), k);
        pos[i]=v.insert(flag ?  ++f: f, i);
    }

//    for_each(v.begin(),v.end(),[&](int i){cout <<i<<" "; });

    cin >> m;
    for (int j = 0; j != m; ++j) {
        cin >> x;
        if(erased[x]==true){
            continue;
        }
        list<int>::iterator f =pos[x]; /*find(v.begin(), v.end(), x);*/
            v.erase(f);
            erased[x]=true;
    }
//    for_each(v.begin(),v.end(),[&](int i){cout <<i<<" "; });
    for (const auto &item:v) {
        cout << item << " ";
    }
    return 0;
}