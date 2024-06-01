#include<bits/stdc++.h>

using namespace std;

map<int, int> dp;

int CKN(int n) {
    int k = 2;

    vector<vector<int>> C(k + 1, vector<int>(n + 1, 0));
    
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || i == j) {
                C[i][j] = 1;
            } else if (j > i) { 
                C[i][j] = (C[i - 1][j - 1] + C[i][j - 1]) % 1000000007;
            }
        }
    }
    
    return C[k][n] % 1000000007;
}

int main() {
    int n;
    cin >> n;

    int a[n+1];
    int value;
    for (int i = 1; i <= n; i++) {
        cin >> value;
        dp[value]++;
    }

    int result = 0;
    for (auto i = dp.begin(); i != dp.end(); i++) {
        if (i->second >= 2) {
            result += CKN(i->second);
        }
    }

    cout << result % 1000000007 << endl;
}