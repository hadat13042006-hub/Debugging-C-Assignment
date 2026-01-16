#include <stdio.h>
#include <stdlib.h>

/* Cấu trúc node */
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

/* Khởi tạo cây */
Node* initTree() {
    return NULL;
}

/* Kiểm tra cây rỗng */
int isEmpty(Node* root) {
    return root == NULL;
}

/* Tạo node mới */
Node* createNode(int value) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = value;
    p->left = NULL;
    p->right = NULL;
    return p;
}

/* Thêm con trái */
void addLeft(Node* parent, int value) {
    parent->left = createNode(value);
}

/* Thêm con phải */
void addRight(Node* parent, int value) {
    parent->right = createNode(value);
}

/* Duyệt NLR */
void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

/* Duyệt LNR */
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

/* Duyệt LRN */
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    Node* T = initTree();

    /* Tạo cây theo hình vẽ */
    T = createNode(100);
    addLeft(T, 5);
    addRight(T, 10);

    printf("Duyet truoc (NLR): ");
    preOrder(T);

    printf("\nDuyet giua (LNR): ");
    inOrder(T);

    printf("\nDuyet sau (LRN): ");
    postOrder(T);

    return 0;
}
