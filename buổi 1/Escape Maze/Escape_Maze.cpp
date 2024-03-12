#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, r, c, val, row, col;
    cin >> n >> m >> r >> c;
    queue<pair<int, int>> qe;
    vector<vector<int>> maze(n, vector<int>(m)), d(n, vector<int>(m));

    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> val;
            maze[i][j] = val;
        }

    if (maze[r - 1][c - 1] == 1) {
        cout << -1 << endl;
        return 0;
    }
    d[r - 1][c - 1] = 0;
    maze[r-1][c-1] = 1;
    qe.push(make_pair(r - 1, c - 1));
    while (!qe.empty()) {
        row = qe.front().first;
        col = qe.front().second;
        qe.pop();
        for (int i = 0; i < 4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if (maze[newRow][newCol] != 1) {
                d[newRow][newCol] = d[row][col] + 1;
                if (newRow == 0 || newRow == n - 1 || newCol == 0 || newCol == m - 1) {
                    cout << d[newRow][newCol] + 1 << endl;
                    return 0;
                }
                qe.push(make_pair(newRow, newCol));
                maze[newRow][newCol] = 1;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}