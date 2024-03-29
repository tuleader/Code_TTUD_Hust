#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> maze, d;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void readMaze(int n, int m) {
    int val;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> val;
            maze[i][j] = val;
        }
}

bool isEscapePossible(int r, int c) {
    if (maze[r - 1][c - 1] == 1) {
        cout << -1 << endl;
        return false;
    }
    return true;
}

void bfs(int r, int c, int n, int m) {
    queue<pair<int, int>> qe;
    int row, col;
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
                    return;
                }
                qe.push(make_pair(newRow, newCol));
                maze[newRow][newCol] = 1;
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    maze = vector<vector<int>>(n, vector<int>(m));
    d = vector<vector<int>>(n, vector<int>(m));

    readMaze(n, m);
    if (isEscapePossible(r, c)) {
        bfs(r, c, n, m);
    }
    return 0;
}