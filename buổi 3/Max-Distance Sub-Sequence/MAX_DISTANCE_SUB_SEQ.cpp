#include <bits/stdc++.h>
using namespace std;

bool check(int mid, int x[], int n, int c)
{
    int cows = 1, last = x[0];
    for (int i = 1; i < n; i++)
    {
        if (x[i] - last >= mid)
        {
            if (++cows == c)
                return true;
            last = x[i];
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        int x[n];
        for (int i = 0; i < n; i++)
            cin >> x[i];
        sort(x, x + n);
        int l = 0, r = x[n - 1] - x[0] + 1;
        while (r - l > 1)
        {
            int mid = (l + r) / 2;
            if (check(mid, x, n, c))
                l = mid;
            else
                r = mid;
        }
        cout << l << "\n";
    }
    return 0;
}
