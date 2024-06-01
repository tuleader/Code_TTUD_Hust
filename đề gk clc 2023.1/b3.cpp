#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum = 0, halfSum;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    halfSum = sum / 2;

    // vector luu so cap co tong bang k
    vector<int> dp(halfSum + 1, 0);
    dp[0] = 1;

    // dem so cap co tong bang k
    for (int i = 0; i < n; i++)
    {
        for (int j = halfSum; j >= arr[i]; j--)
        {
            dp[j] += dp[j - arr[i]];
        }
    }

    int target = 0;
    for (int i = halfSum; i >= 0; i--)
    {
        if (dp[i])
        {
            target = i;
            break;
        }
    }

    cout << sum - 2 * target;
    return 0;
}