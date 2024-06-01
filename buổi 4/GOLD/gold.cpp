#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, L1, L2;
    cin >> n >> L1 >> L2;

    // mang luu khoi luong vang
    vector<long long int> arr(n);

    // mang luu khoi luong vang lon nhat
    vector<long long int> dp(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = arr[i];
        for(int j=L1;j<=L2;j++)
        {
            if(i>=j && dp[i]<dp[i-j]+arr[i])
            {
                dp[i]=dp[i-j]+arr[i];
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
