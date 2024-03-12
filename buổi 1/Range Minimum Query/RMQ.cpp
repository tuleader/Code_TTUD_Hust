#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int value = 0;
    
    int n;
    scanf("%d",&n);
    
    int arr[2*n];
    for(int i = n;i<2*n;i++){
            scanf("%d",&arr[i]);
    }
    for(int i=n-1;i>0;i--){
            arr[i]=min(arr[i<<1],arr[i<<1|1]);
    }
    int q,l,r,sum = 0;
    scanf("%d",&q);
    for(int i = 0;i<q;i++){
            scanf ("%d%d",&l,&r);
            l+=n;
            r+=n+1;
            int gtnn = 10e6+1;
            if (l == r){
                  sum += arr[l];
                  continue;
            }
            while (l<r){
                  if(l&1){
                          gtnn = min (gtnn, arr[l]);
                          l++;
                  }
                  if(r&1){
                          r--;
                          gtnn = min (gtnn, arr[r]);
                  }
                  l>>=1;
                  r>>=1;
            }
            sum+=gtnn;
}
printf("%d\n",sum);
}