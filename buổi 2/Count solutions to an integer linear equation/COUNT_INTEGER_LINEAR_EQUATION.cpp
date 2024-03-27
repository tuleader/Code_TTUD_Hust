#include <bits/stdc++.h>
#define MAX 20
using namespace std;
int n, M;
int a[MAX];
int t[MAX];
int X[MAX];
int f;
int dem;
void initT(){
    t[1] = a[1];
    int i;
    for(i = 2; i <= n; i++) t[i] = t[i-1] + a[i];
}
void solution(){
    if(f == M){
        dem++;
    }
}
void TRY(int k){
    int v;
    for(v = 1; v <= (M-f-(t[n]-t[k]))/a[k]; v++){
        X[k] = v;
        f += a[k]*X[k];
        if(k == n){
            solution();
        }else{
            TRY(k+1);
        }
        f -= a[k]*X[k];
    }
}
void input(){
    cin >> n >> M;
    int i;
    for(i = 1; i <= n; i++)
        cin >> a[i];
}
void solve(){
    f = 0;
    initT();
    dem = 0;
    TRY(1);
    cout << dem;
}

int main(){
    input();
    solve();
    return 0;
}
