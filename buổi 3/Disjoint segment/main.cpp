#include<bits/stdc++.h>
using namespace std;

int n;
pair <int, int> a[100005];

void input(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
}

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second < b.second;
}

void solve(){
    sort(a + 1, a + n + 1, cmp);
    int res = 0;
    int r = a[1].second;
    for (int i = 2; i <= n; i++){
        if (a[i].first > r){
            res++;
            r = a[i].second;
        }
    }
    cout << res + 1;
}

int main(){
    input();
    solve();
    return 0;
}



