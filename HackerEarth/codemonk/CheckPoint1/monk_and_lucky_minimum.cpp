#include <iostream>
using namespace std;
const int SZ = int(1e5+5);

int T, N, A[SZ];

int partition(int arr[], int l, int r) {
    int piv = arr[l];
    int j = l+1; 
    for (int i=l+1; i<=r; i++) {
        if (arr[i] <= piv) {
            swap(arr[i], arr[j++]); 
        }
    }
    swap(arr[l], arr[j-1]);
    return j-1;
}


int randomPartition(int arr[], int l, int r) {
    int randPos = l + rand() % (r-l+1);
    swap(arr[randPos] ,arr[l]);
    return partition(arr, l, r);
}

void quickSort(int arr[], int l, int r) { 
    if (l < r) {
        int pivPos = randomPartition(arr, l, r);
        quickSort(arr, l, pivPos-1);
        quickSort(arr, pivPos+1, r);
    }
}


void merge(int arr[], int mid, int l, int r) {
    int p = l, q = mid+1, sz = r-l+1, midValue = arr[mid];
    int aux[sz], k=0;
    for (int i=l; i<=r; i++) {
        if (p > mid) aux[k++] = arr[q++];
        else if (q > r) aux[k++] = arr[p++];
        else if (arr[p] < arr[q]) aux[k++] = arr[p++];
        else aux[k++] = arr[q++];
    }
    for (int i=0; i<k; i++) arr[l+i] = aux[i];
}


void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = (l + r) >> 1;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, mid, l, r);
    }
}


int main() {
    freopen("input.txt", "r", stdin);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i=0; i<N; i++) cin >> A[i];
//        quickSort(A, 0, N-1);     
        mergeSort(A, 0, N-1);
        int j = 1, cnt = 1;
        while (j < N && A[j] == A[j-1]) cnt++, j++;
        if (cnt & 1) cout << "Lucky" << endl;
        else cout << "Unlucky" << endl;
    }
    return 0;
}
