#include <bits/stdc++.h>
using namespace std;

// ham kiem tra xem tong co ton tai trong mang khong
bool check(const vector<int> &arr, int start, int end, int target)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return true;
        if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return false;
}

int main()
{
    int n, count = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];
            if (check(arr, j + 1, n - 1, sum))
                count++;
        }
    }
    cout << count;
}