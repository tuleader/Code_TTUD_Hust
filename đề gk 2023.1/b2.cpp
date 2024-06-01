#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; // Số lượng số tự nhiên
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i]; // Đọc các số tự nhiên
    }

    int S; // Năm thành lập công ty
    cin >> S;

    vector<int> dp(40001, 0); // 40001 là một giá trị lớn đủ để chứa tổng có thể
    dp[0] = 1;                // Có một cách để có tổng là 0 (không lấy số nào)

    // Cập nhật dp cho mỗi số
    for (int num : nums)
    {
        for (int j = 40000; j >= num; --j)
        {
            dp[j] += dp[j - num];
        }
    }

    // Tính tổng số cách để có tổng lớn hơn hoặc bằng S
    int count = 0;
    for (int i = S; i <= 40000; ++i)
    {
        count += dp[i];
    }

    cout << count << endl; // In ra kết quả
    return 0;
}
