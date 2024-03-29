#include <bits/stdc++.h>

using namespace std;

int largestRectangleInHistogram(vector<int> histogram) {
    stack<int> s;
    int maxArea = 0;
    int area = 0;
    int i = 0;
    int size = histogram.size();

    while (i < size) {
        if (s.empty() || histogram[s.top()] <= histogram[i]) {
            s.push(i);
            i++;
        } else {
            int top = s.top();
            s.pop();
            area = histogram[top] * (s.empty() ? i : (i - s.top() - 1));
            if (area > maxArea) {
                maxArea = area;
            }
        }
    }

    while (!s.empty()) {
        int top = s.top();
        s.pop();
        area = histogram[top] * (s.empty() ? i : (i - s.top() - 1));
        if (area > maxArea) {
            maxArea = area;
        }
    }

    return maxArea;
}

void readFirstRow(int m, vector<vector<int>>& row) {
    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        row[0].push_back(val);
    }
}

void readRemainingRows(int n, int m, vector<vector<int>>& row) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val;
            cin >> val;
            if (val != 0) {
                row[i].push_back(val + row[i - 1][j]);
            } else {
                row[i].push_back(0);
            }
        }
    }
}

int main() {
    int n, m, maxArea = 0;
    cin >> n >> m;
    vector<vector<int>> row(n);
    readFirstRow(m, row);
    readRemainingRows(n, m, row);

    for (int i = 0; i < n; i++) {
        int area = largestRectangleInHistogram(row[i]);
        maxArea = max(maxArea, area);
    }
    cout << maxArea << endl;
    return 0;
}