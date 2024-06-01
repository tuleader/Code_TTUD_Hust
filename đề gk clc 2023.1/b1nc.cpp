#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, count = 0, number;
    cin >> n;
    vector<int> arr(n);
    vector<int> sum(100001, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            count += sum[(arr[i] + arr[j])];
        }
    }
    cout << count;
}