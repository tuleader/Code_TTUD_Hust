#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

// Hàm merge dùng để hợp nhất hai mảng đã được sắp xếp thành một mảng mới
int merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int count = 0;
    // Tạo mảng tạm để lưu trữ các phần tử
    vector<int> L(n1), R(n2);

    // Sao chép dữ liệu vào mảng tạm
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Hợp nhất hai mảng tạm vào mảng chính arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {   
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            count += n1 - i;
            count %= MOD;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của L và R (nếu có)
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    return count;
}

// Hàm mergeSort sắp xếp mảng arr từ vị trí left đến right
int mergeSort(vector<int> &arr, int left, int right)
{
    int totalCount = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Sắp xếp phần đầu và phần sau của mảng
        totalCount += mergeSort(arr, left, mid);
        totalCount %= MOD;

        totalCount += mergeSort(arr, mid + 1, right);
        totalCount %= MOD;
        // Hợp nhất hai mảng đã sắp xếp
        totalCount += merge(arr, left, mid, right);
        totalCount %= MOD;
    }
    return totalCount;
}

int main()
{
    int n, key;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    key = mergeSort(arr, 0, n - 1);
    cout << key % MOD;
    return 0;
}
