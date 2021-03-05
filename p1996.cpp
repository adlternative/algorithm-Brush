#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int tot, out, now = 1;
    queue<int> q;
    cin >> tot >> out;
    for (int i = 1; i <= tot; i++)q.push(i);
    while (!q.empty())
    {
        if (now == out)
        {
            cout << q.front() << " ";
            q.pop();
            now = 1;
        }
        else
        {
            now++;
            q.push(q.front());            //排至队尾
            q.pop();
        }
    }
    return 0;
}