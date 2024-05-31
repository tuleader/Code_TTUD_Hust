#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

// hop nhat 2 mang
int merge(int *arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int count = 0;

    // tao mang tam luu tru cac phan tu
    int L[n1], R[n2];

    // sao chep du lieu vao mang tam
    for(int i=0;i<n1;i++)
    {
        L[i] = arr[left+i];
    }

    for(int j=0;j<n2;j++)
    {
        R[j] = arr[mid+j+1];
    }

    // hop nhat 2 mang tam vao mang chinh
    int i = 0, j = 0, k = left;
    while(i<n1 && j <n2)
    {
        if(L[i]<=R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            count += n1-i;
            count %= MOD;
        }
        k++;
    }

    // sao chep cac phan tu con lai cua L va R neu co
    while(i<n1)
    {
        arr[k] = L[i];
        k++;
        i++;
    }
    while (j<n2)
    {
        arr[k] = R[j];
        k++;
        j++;
    }
    
    return count;
}

// sap xep mang
int mergeSort(int *arr, int left, int right)
{
    int totalCount = 0;

    if(left < right)
    {
        int mid = left + (right - left) / 2;

        // sap xep phan dau va phan sau cua mang
        totalCount += mergeSort(arr, left, mid);
        totalCount %= MOD;
        totalCount += mergeSort(arr,mid+1,right);
        totalCount %= MOD;

        // hop nhat 2 mang da sap xep
        totalCount += merge(arr,left,mid,right);
        totalCount %= MOD;
    }

    return totalCount;
}

int main()
{
    int n,value;
    cin >> n;

    int arr[n];

    for(int i= 0;i<n;i++)
    {
        cin >> arr[i];
    }

    value = mergeSort(arr,0,n-1);
    cout << value % MOD << endl;
    return 0;
}
