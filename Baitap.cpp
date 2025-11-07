#include <stdio.h>

int main() {
    int a, b;
    printf("Nhap hai so: ");
    scanf("%d %d", &a, &b);  // ? thêm &

    int tong = a + b;
    printf("Tong = %d\n", tong);

    return 0;
}

