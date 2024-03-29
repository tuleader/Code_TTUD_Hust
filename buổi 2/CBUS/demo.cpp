#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100
int N;                // so khach
int Q;                // so cho tren bus cho hanh khach
int X[2 * MAX_N + 1]; // bieu dien phuong an lo trinh X[1], X[2], . . . X[2N]
int q;                // so khach thuc su dang co tren xe ung voi phuong an bo phan hien tai
bool appear[2 * MAX_N + 1];
bool check(int v, int k)
{
    if (appear[v])
        return false;
    if (v <= N)
    { // v is pickup
        if (q >= Q)
            return false;
    }
    else
    { // v > N means drop-off
        if (!appear[v - N])
            return false;
    }
    return true;
}
void solution()
{
    for (int i = 1; i <= 2 * N; i++)
        cout << X[i] << " ";
    cout << endl;
}
void TRY(int k)
{ // thu gia tri cho X[k]
    for (int v = 1; v <= 2 * N; v++)
    {
        if (check(v, k))
        {
            X[k] = v;
            appear[v] = true;
            if (v <= N)
                q++;
            else
                q--; // update q incrementally
            if (k == 2 * N)
                solution();
            else
                TRY(k + 1);
            appear[v] = false;
            if (v <= N)
                q--;
            else
                q++; // recover status q
        }
    }
}
int main()
{
    N = 3;
    Q = 2;
    q = 0;
    for (int v = 1; v <= 2 * N; v++)
        appear[v] = false;
    TRY(1);
}