#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, L1, L2;
    cin >> n >> L1 >> L2;
    vector<long long> a(n + 1), dp(n + 1), m(n + 1);
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[0] = 0;
    m[0] = 0;
    for (long long i = 1; i <= n; i++)
    {
        dp[i] = a[i];
        if (i - L1 >= 0)
        {
            dp[i] = max(dp[i], m[i - L1] + a[i]);
        }
        m[i] = max(m[i - 1], dp[i]);
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
