#include <stdio.h>

#define MAX 100

int A[MAX];
int n = 0;

/* Khởi tạo cây */
void initTree() {
    for (int i = 0; i < MAX; i++)
        A[i] = 0;
    n = 0;
}

/* Kiểm tra cây rỗng */
int isEmpty() {
    return n == 0;
}

/* Thêm nút */
void addNode(int pos, int value) {
    if (pos >= MAX) {
        printf("Vuot qua kich thuoc cay!\n");
        return;
    }
    A[pos] = value;
    if (pos > n) n = pos;
}

/* Duyệt NLR */
void preOrder(int i) {
    if (i <= n && A[i] != 0) {
        printf("%d ", A[i]);
        preOrder(2 * i);
        preOrder(2 * i + 1);
    }
}

/* Duyệt LNR */
void inOrder(int i) {
    if (i <= n && A[i] != 0) {
        inOrder(2 * i);
        printf("%d ", A[i]);
        inOrder(2 * i + 1);
    }
}

/* Duyệt LRN */
void postOrder(int i) {
    if (i <= n && A[i] != 0) {
        postOrder(2 * i);
        postOrder(2 * i + 1);
        printf("%d ", A[i]);
    }
}

int main() {
    initTree();

    /* Nhập cây theo hình vẽ */
    addNode(1, 100);
    addNode(2, 5);
    addNode(3, 10);

    printf("Duyet truoc (NLR): ");
    preOrder(1);

    printf("\nDuyet giua (LNR): ");
    inOrder(1);

    printf("\nDuyet sau (LRN): ");
    postOrder(1);

    return 0;
}
