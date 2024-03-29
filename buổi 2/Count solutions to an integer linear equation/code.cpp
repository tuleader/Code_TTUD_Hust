#include <bits/stdc++.h>
using namespace std;
const int MAX = 20;

int n, M, f, dem;
int a[MAX], t[MAX];
int X[MAX];

void input()
{
    cin >> n >> M;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void tongT()
{
    t[1] = a[1];
    for (int i = 2; i <= n; i++)
        t[i] += t[i - 1] + a[i];
}

void check()
{
    if (f == M)
        dem++;
}

void quayLui(int k)
{
    int y = 1;
    for (int y = 1; y <= (M - f - (t[n] - t[k])) / a[k]; y++)
    {
        X[k] = y;
        f += X[k] * a[k];
        if (k == n)
            check();
        else
            quayLui(k + 1);
        f -= X[k] * a[k];
    }
}

int main()
{
    input();
    tongT();
    f = 0, dem = 0;
    quayLui(1);
    cout << dem;
    return 0;
}