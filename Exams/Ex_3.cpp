#include<bits/stdc++.h>

using namespace std;

long long matrix[1001][1001];
long long result = INT_MAX;
int checks = 0;

// Kiểm tra ô tiếp theo muốn đi có thể đi được hay không
int check(int n, int m, int i, int j) {
    if (matrix[i][j] == 0 || i > n || j > m) {
        return 0;
    }

    return 1;
}

void solve(int n, int m, int i, int j, long long matrix[1001][1001], int sum) {
    if (i == n && j == m) {
        sum = sum + matrix[i][j];
        if (sum < result) {
            result = sum;
            checks = 1;
            return;
        }
    }

    for (int index = i; index <= i + 1; index++) {
        for (int jndex = j; jndex <=  j + 1; jndex++) {
            if (index == i && jndex == j) {
                continue;
            }

            if (check(n, m, index, jndex) == 1) {
                if (sum + matrix[i][j] > result) {
                    continue;
                }
                solve(n, m, index, jndex, matrix, sum + matrix[i][j]);
            }
        }
    }
}

int main() {
    long long n, m;
    cin >> n >> m;

    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= m; j++) {
            cin >> matrix[i][j];
        }
    }

    solve(n, m, 1, 1, matrix, 0);

    if (checks == 0) {
        cout << -1;
    } else {
        cout << result;
    }
}