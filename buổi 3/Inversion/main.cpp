// #include<bits/stdc++.h>
// using namespace std;

// int n;
// int a[100005];
// int load = 0;

// void input(){
//     cin >> n;
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//     }
// }

// void solve(){
//     for(int i = 1; i <= n; i++){
//         for(int j = i + 1; j <= n; j++){
//             if(a[i] > a[j]){
//                 load++;
//             }
//         }
//     }
//     cout << load;
// }

// int main(){
//     input();
//     solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int temp[100005];
int load = 0;
int const MOD = 1e9 + 7;

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

void mergeParts(int *arr, int l, int mid, int r)
{
    int i = l, j = mid + 1;
    int k = 0;

    while (i <= mid && j <= r)
    {
        int nextValue;

        if (arr[i] < arr[j])
            nextValue = arr[i++];
        else
        {
            nextValue = arr[j++];
            load += mid - i + 1;
        }

        temp[k++] = nextValue;
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];

    for (int i = 0; i < k; i++)
        arr[l + i] = temp[i];
}

void mergeSort(int *arr, int l, int r)
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    mergeParts(arr, l, mid, r);
}

int main()
{
    input();
    mergeSort(a,1,n);
    cout << load;
    return 0;
}
