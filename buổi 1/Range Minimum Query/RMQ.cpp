#include <bits/stdc++.h>
using namespace std;

void readArray(int n, int arr[]) {
    for(int i = n; i < 2 * n; i++){
        scanf("%d", &arr[i]);
    }
}

void buildSegmentTree(int n, int arr[]) {
    for(int i = n - 1; i > 0; i--){
        arr[i] = min(arr[i << 1], arr[i << 1 | 1]);
    }
}

int query(int n, int arr[]) {
    int q, l, r, sum = 0;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf ("%d%d", &l, &r);
        l += n;
        r += n + 1;
        int gtnn = 10e6 + 1;
        if (l == r){
            sum += arr[l];
            continue;
        }
        while (l < r){
            if(l & 1){
                gtnn = min (gtnn, arr[l]);
                l++;
            }
            if(r & 1){
                r--;
                gtnn = min (gtnn, arr[r]);
            }
            l >>= 1;
            r >>= 1;
        }
        sum += gtnn;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    scanf("%d", &n);
    
    int arr[2 * n];
    readArray(n, arr);
    buildSegmentTree(n, arr);
    int sum = query(n, arr);
    printf("%d\n", sum);
}