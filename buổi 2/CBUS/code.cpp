#include <bits/stdc++.h>
using namespace std;

const int MAXN = 23;
int n, k;                     // n là số điểm đón, điểm trả, k là số chỗ trên xe bus
int c[MAXN][MAXN];            // mảng lưu trữ chi phí từ điểm i đến điểm j
int x[MAXN];                  // mảng lưu trữ lộ trình của xe bus
bool visited[MAXN] = {false}; // mảng đánh dấu các điểm đã được ghé qua
int sum = 0, load = 0;        // biến trung gian để tính tổng chi phí và số khách trên xe tại mỗi thời điểm
int res = 1e9;                // biến lưu trữ kết quả cuối cùng, được khởi tạo là một giá trị lớn
int c_min = 1e9;              // biến lưu trữ chi phí nhỏ nhất từ một điểm đến một điểm khác

void input()
{
    cin >> n >> k;

    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> c[i][j];
            c_min = min(c_min, c[i][j]);
        }
    }

    x[0] = 0;
}

bool check(int i)
{
    if (visited[i])
        return false;
    if (i <= n && load == k)
        return false;
    if (i > n && !visited[i - n])
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
            // cập nhật biến trung gian visited, sum, load
            sum += c[x[t - 1]][i];
            visited[i] = true;

            if (i <= n)
            {
                load++;
            }
            else
            {
                load--;
            }
            //--------------------------------------------

            if (t == 2 * n)
            {
                sum += c[x[2 * n]][0];
                res = min(res, sum);
                sum -= c[x[2 * n]][0];
            }
            else if (t < 2 * n && sum + (2 * n - t) * c_min < res)
            { // sử dụng cắt nhánh
                Try(t + 1);
            }

            // trả lại giá trị của biến trung gian visited, sum, load
            if (i <= n)
            {
                load--;
            }
            else
            {
                load++;
            }

            visited[i] = false;
            sum -= c[x[t - 1]][i];
            //--------------------------------------------
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();

    Try(1);

    cout << res;

    return 0;
}
