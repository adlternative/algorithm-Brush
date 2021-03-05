
#include<bits/stdc++.h>

using namespace std;
long long ss[2000002];

int main() {
    long long n, m, x;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> ss[i];
    for (int i = 1; i <= m; ++i) {

        cin >> x;
        cout << ss[x] << endl;
    }
    return 0;
}/*
int main(int argc, char *argv[]) {
//    puts("?");
    long  s[200001];
//    memset(s,0,sizeof(s));
//    puts("?");
    int n, m;
    cin >> n >> m;
    for (int i = 0; i != n; ++i) {
        cin >> s[i];
    }
    for (int j = 0; j != m; ++j) {
        int check ;
        cin >> check;
        std::cout << s[check - 1] << std::endl;
    }
*//*
    int n, m;
    cin >> n >> m;
    map<long long,long long>mm;
    for (int i = 0; i != n; ++i) {
        long long num;
        cin >> num;
        mm.insert(make_pair(i, num));
    }
    for (int j = 0; j != m; ++j) {
        long long check;
        cin >> check;
        cout << mm.find(check-1)->second << endl;
    }
    return 0;
*//*
}*/