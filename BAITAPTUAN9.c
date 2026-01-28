#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SinhVien {
    char hoten[50];
    char mssv[20];
    int namsinh;
    float gpa;
    struct SinhVien *next;
} SinhVien;

SinhVien* taoSinhVien(char hoten[], char mssv[], int namsinh, float gpa) {
    SinhVien *sv = (SinhVien*)malloc(sizeof(SinhVien));
    strcpy(sv->hoten, hoten);
    strcpy(sv->mssv, mssv);
    sv->namsinh = namsinh;
    sv->gpa = gpa;
    sv->next = NULL;
    return sv;
}

void themCuoi(SinhVien **head, SinhVien *sv) {
    if (*head == NULL) {
        *head = sv;
        return;
    }
    SinhVien *p = *head;
    while (p->next != NULL)
        p = p->next;
    p->next = sv;
}

void inDanhSach(SinhVien *head) {
    while (head != NULL) {
        printf("Ho ten: %s | MSSV: %s | Nam sinh: %d | GPA: %.2f\n",
               head->hoten, head->mssv, head->namsinh, head->gpa);
        head = head->next;
    }
}

int chieuDaiDanhSach(SinhVien *head) {
    int dem = 0;
    while (head != NULL) {
        dem++;
        head = head->next;
    }
    return dem;
}

int demSV_GPA_Tren_3_2(SinhVien *head) {
    int dem = 0;
    while (head != NULL) {
        if (head->gpa > 3.2)
            dem++;
        head = head->next;
    }
    return dem;
}

void sapXepTheoGPA(SinhVien *head) {
    for (SinhVien *i = head; i != NULL; i = i->next) {
        for (SinhVien *j = i->next; j != NULL; j = j->next) {
            if (i->gpa > j->gpa) {
                SinhVien temp = *i;
                *i = *j;
                *j = temp;

                SinhVien *t = i->next;
                i->next = j->next;
                j->next = t;
            }
        }
    }
}

void chenTheoThuTu(SinhVien **head, SinhVien *sv) {
    if (*head == NULL || (*head)->gpa >= sv->gpa) {
        sv->next = *head;
        *head = sv;
        return;
    }

    SinhVien *p = *head;
    while (p->next != NULL && p->next->gpa < sv->gpa)
        p = p->next;

    sv->next = p->next;
    p->next = sv;
}

int main() {
    SinhVien *ds = NULL;

    themCuoi(&ds, taoSinhVien("Nguyen Van A", "SV01", 2003, 3.5));
    themCuoi(&ds, taoSinhVien("Tran Van B", "SV02", 2002, 2.8));
    themCuoi(&ds, taoSinhVien("Le Van C", "SV03", 2004, 3.9));

    printf("Danh sach sinh vien:\n");
    inDanhSach(ds);

    printf("\nChieu dai danh sach: %d\n", chieuDaiDanhSach(ds));
    printf("So sinh vien co GPA > 3.2: %d\n", demSV_GPA_Tren_3_2(ds));

    sapXepTheoGPA(ds);
    printf("\nDanh sach sau khi sap xep tang dan theo GPA:\n");
    inDanhSach(ds);

    SinhVien *svMoi = taoSinhVien("Sinh Vien Moi", "SV04", 2003, 2.4);
    chenTheoThuTu(&ds, svMoi);

    printf("\nDanh sach sau khi chen sinh vien GPA = 2.4:\n");
    inDanhSach(ds);

    return 0;
}
