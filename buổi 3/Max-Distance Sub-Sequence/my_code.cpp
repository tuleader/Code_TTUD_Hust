#include<bits/stdc++.h>
using namespace std;

// ham kiem tra xem co dat duoc vao voi khoang cach toi thieu la mid khong
bool check(int mid, int arr[],int n,int c)
{
    int cows = 1, last = arr[0];
    for(int i=1; i<n;i++)
    {
        if(arr[i]-last>=mid)
        {
            cows++;
            if(cows==c) return true;
            last = arr[i];
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,c;
        cin >> n >> c;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        sort(arr,arr+n);
        int l = 0, r = arr[n-1] - arr[0] + 1;
        while(r-l >1)
        {
            // tim kiem nhi phan
            int mid = (l+r)/2;
            if(check(mid,arr,n,c))
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        cout << l << endl;
    }
    return 0;
}