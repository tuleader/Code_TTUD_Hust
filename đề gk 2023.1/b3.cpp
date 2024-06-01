#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, INT_MAX));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    // Kiểm tra ô đầu tiên và cuối cùng có thể đi qua không
    if (a[1][1] == 0 || a[n][m] == 0) {
        cout << -1 << endl;
        return 0;
    }

    dp[1][1] = a[1][1];  // Chi phí ban đầu để đến ô đầu tiên

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == 1 && j == 1) continue;  // Bỏ qua ô đầu tiên vì đã xét
            if (a[i][j] != 0) {
                long long cost = a[i][j];
                if (i > 1) dp[i][j] = min(dp[i][j], dp[i-1][j] + cost);  // Di chuyển từ trên xuống
                if (j > 1) dp[i][j] = min(dp[i][j], dp[i][j-1] + cost);  // Di chuyển từ trái sang phải
                if (i > 1 && j > 1) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + cost);  // Di chuyển chéo
            }
        }
    }

    // Nếu chi phí đến ô cuối cùng là vô cùng, có nghĩa là không thể đến được
    if (dp[n][m] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << dp[n][m] << endl;  // In ra chi phí tối thiểu
    }

    return 0;
}
