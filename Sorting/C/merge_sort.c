#include <stdio.h>

void merge(int*, int, int, int);
void mergeSort(int*, int, int);


int main() {
    int arr[100], i, lim;
    printf("Enter number of elements: ");
    scanf("%d", &lim);
    printf("Enter elements of array one by one: ");
    for(i=0; i<lim; i++) {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, lim-1);
    printf("\n\nDisplaying elements of the result array\n\n");
    for(i=0; i<lim; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

void mergeSort(int arr[], int l, int r) {
    int mid;
    if(l < r) {
        mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

void merge(int arr[], int l, int m, int r) {
    int i=l, j=m+1, k=0, res[100];
    while(i<=m && j<=r) {
        if(arr[i] < arr[j]) {
            res[k] = arr[i];
            i++;
        }
        else {
            res[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i<=m) {
        res[k] = arr[i];
        k++; i++;
    }
    while(j<=r) {
        res[k] = arr[j];
        k++; j++;
    }
    for(i=r; i>=l; i--) {
        arr[i] = res[--k];
    }
}