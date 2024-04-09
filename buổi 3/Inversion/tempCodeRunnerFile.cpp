#include<bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int load = 0;

void merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    int temp[right + 1];

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            load += (mid - i + 1); // Count inversions
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int p = left; p <= right; p++) {
        arr[p] = temp[p];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

void solve(){
    mergeSort(a, 1, n);
    cout << load;
}

int main(){
    input();
    solve();
    return 0;
}