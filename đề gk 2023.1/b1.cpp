#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    int num, total = 0;
    // khởi tạo mảng đếm số lần xuất hiện của mỗi phần tử
    int arr[1000000] = {0};

    // nhập kết quả vào và đếm luôn
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr[num]++;
    }

    // duyệt qua từng phần tử và đếm số cặp bằng nhau
    for (int i = 0; i < 1000000; i++)
    {
        if (arr[i] != 0)
        {
            total += arr[i] * (arr[i] - 1) / 2;
            total %= MOD;
        }
    }

    cout << total;
    return 0;
}