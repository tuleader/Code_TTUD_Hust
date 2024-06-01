#include<bits/stdc++.h>

using namespace std;

// Kết quả bài toán
int result = 0;

/**
 * Hàm giải bài toán
 * k: Năm thành lập
 * n: Số lượng số bí ẩn
 * a: Mảng chứa số bí ẩn
 * visited: Mảng đánh dấu số đã được chọn hay chưa
 * count: Số phần tử của tổ hợp các phần tử thỏa mãn
 * present: Số lượng phần tử thỏa mãn của tổ hợp tại thời điểm hiện tại
 * sum: Tổng của tổ hợp hiện tại
 * pass: Vị trí xét bắt đầu từ phần tử có chỉ số pass
*/
void solve(int k, int n, int a[], int visited[], int count, int present, int sum, int pass) {
    if (present == count + 1 && sum >= k) {
        result++;
        return;
    }

    // Xét từ phần tử có chỉ số pass tránh trường hợp lặp tổ hợp: Ví dụ lặp 1 4 và 4 1
    for (int i = pass + 1; i <= n; i++) {
        if (visited[i] == 1) {
            continue;
        } else {
            // Nếu phần tử chưa được nằm trong tổ hợp, đánh dấu
            visited[i] = 1;
            // Tiếp tục tìm phần tử hợp lệ tiếp theo của tổ hợp
            solve(k, n, a, visited, count, present + 1, sum + a[i], i);
            // Trả đánh dấu về 0
            visited[i] = 0;
        }
    }
}

// Lấy ra max -> solve có sum -> sum + (max * (count - present)) < k => cắt tỉa

// Cho 1 tập số tự nhiên a, 1 số k. Tính số tập con của a sao cho tổng các phần tử 
// của tập con lớn hơn hoặc bằng k

int main() {
    int n;
    cin >> n;

    int a[n+1] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int k;
    cin >> k;

    int visited[n+1] = {0};

    // Vòng lặp để xác định số lượng phần tử của tổ hợp: 1, 2, 3,...., n
    for (int i = 1; i <= n; i++) {
        solve(k, n, a, visited, i, 1, 0, 0);
        // Để cho an toàn, sau mỗi lần như vậy đánh dấu toàn bộ mảng về 0
        memset(visited, 0, sizeof(visited));
    }

    cout << result;
}