#include <bits/stdc++.h>
using namespace std;

struct Treasure
{
    int x, y, gold;
};

// Hàm so sánh để sắp xếp các kho báu
bool compare(Treasure a, Treasure b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int main()
{
    int n;
    cin >> n;
    vector<Treasure> treasures(n);

    for (int i = 0; i < n; i++)
    {
        cin >> treasures[i].x >> treasures[i].y >> treasures[i].gold;
    }

    // Sắp xếp các kho báu theo tọa độ (x, y)
    sort(treasures.begin(), treasures.end(), compare);

    // Mảng dp để lưu trữ số lượng vàng tối đa tại mỗi kho báu
    vector<int> dp(n);

    int maxGold = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = treasures[i].gold;
        for (int j = 0; j < i; j++)
        {
            if (treasures[j].x <= treasures[i].x && treasures[j].y <= treasures[i].y)
            {
                dp[i] = max(dp[i], dp[j] + treasures[i].gold);
            }
        }
        maxGold = max(maxGold, dp[i]);
    }

    cout << maxGold << endl;

    return 0;
}
