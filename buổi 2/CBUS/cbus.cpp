#include<bits/stdc++.h>
using namespace std;

const int MAXN = 23;

int n,k,load;
int c[MAXN][MAXN];
int x[MAXN];
int sum = 0;
int res = 1e9;
void input(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= k; j++)
            cin >> c[i][j];
}

bool check(int i, int k){

}

void TRY(int k){
    for(int i = 1; i = 2*n;i++){
        if(check(i,k)){
            x[k] = i;
            sum += c[x[k-1]][i];
            res = min(res, sum);
            sum -= c[x[2*n]][0];
        } else if(k<n){

        }
    }
}
