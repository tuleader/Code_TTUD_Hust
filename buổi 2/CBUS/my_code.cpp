// ham input
// ham check xem khach da len xe chua
// ham Try de thu tat ca cac truong hop
// ket hop nhanh can de loai bo so truong hop khong can thiet
#include <bits/stdc++.h>
using namespace std;

int n, k;
const int MaxN = 23;
int cost[MaxN][MaxN]; // mảng lưu chi phí đi
int x[MaxN];          // mảng lưu lộ trình đi
int load;             // số hành khách đang có trên xe
int f;                // tổng chi chí hoàn thành 1 chuyến đi
int f_min = 1e9;      // chi phí hoàn thành chuyến đi với giá trị nhỏ nhất
int c_min = 1e9;      // chi giữa 2 chặng nhỏ nhất
bool visited[MaxN];

void input()
{
    cin >> n >> k;
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> cost[i][j];
            if (i != j)
                c_min = min(c_min, cost[i][j]);
        }
    }
    x[0] = 0;
    // cout << c_min;
}

bool check(int i)
{
    if (visited[i])
        return false;
    if (i > n && !visited[i - n])
        return false;
    if (i <= n && load == k)
        return false;
    return true;
}

void Try(int t)
{
    for (int i = 1; i <= 2 * n; i++)
    {
        if (check(i))
        {
            x[t] = i;
            visited[i] = true;
            f += cost[x[t - 1]][i];

            if (i <= n)
                load++;
            else
                load--;

            if (t == 2 * n)
            {
                f += cost[x[t]][0];
                f_min = min(f, f_min);
                f -= cost[x[t]][0];
            }
            else if (t < 2 * n && (f + (2 * n - t) * c_min) < f_min)
                Try(t + 1);
            // khi gọi đệ quy xong thì sẽ trả lại giá trị trước đó và thử với i tiếp theo
            if (i <= n)
                load--;
            else
                load++;

            visited[i] = false;
            f -= cost[x[t - 1]][i];
        }
    }
}

int main()
{
    input();
    Try(1);
    cout << f_min;
    return 0;
}