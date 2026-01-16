#include <stdio.h>

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void merge(int a[], int l, int m, int r, int n) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[50], R[50];

    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1)
        a[k++] = L[i++];

    while (j < n2)
        a[k++] = R[j++];

    printf("Sau merge [%d, %d]: ", l, r);
    printArray(a, n);
}

void mergeSort(int a[], int l, int r, int n) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m, n);
        mergeSort(a, m + 1, r, n);
        merge(a, l, m, r, n);
    }
}

int main() {
    int a[] = {5, 2, 9, 1, 7};
    int n = 5;

    printf("Mang ban dau: ");
    printArray(a, n);

    mergeSort(a, 0, n - 1, n);

    printf("Mang sau khi sap xep: ");
    printArray(a, n);

    return 0;
}
