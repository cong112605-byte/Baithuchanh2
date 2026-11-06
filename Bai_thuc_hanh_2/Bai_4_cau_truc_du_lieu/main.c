#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SV {
    char hoten[100];
    int ma;
    float d1, d2, d3;
};

struct Node {
    struct SV infor;
    struct Node *link;
};

struct List {
    struct Node *head;
    struct Node *tail;
};

void KhoiTao(struct List *l) {
    l->head = NULL;
    l->tail = NULL;
}

struct Node* TaoNode(struct SV x) {
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    p->infor = x;
    p->link = NULL;
    return p;
}

void ThemCuoi(struct List *l, struct SV x) {
    struct Node *p = TaoNode(x);

    if (l->head == NULL) {
        l->head = p;
        l->tail = p;
    }
    else {
        l->tail->link = p;
        l->tail = p;
    }
}

void Nhap(struct List *l, int n) {
    for (int i = 0; i < n; i++) {
        struct SV sv;

        printf("\nNhap ho ten: ");
        fgets(sv.hoten, sizeof(sv.hoten), stdin);
        sv.hoten[strcspn(sv.hoten, "\n")] = '\0';

        printf("Nhap ma sinh vien: ");
        scanf("%d", &sv.ma);

        printf("Nhap diem 1: ");
        scanf("%f", &sv.d1);

        printf("Nhap diem 2: ");
        scanf("%f", &sv.d2);

        printf("Nhap diem 3: ");
        scanf("%f", &sv.d3);

        getchar();

        ThemCuoi(l, sv);
    }
}

void Xuat(struct List l) {
    struct Node *p = l.head;

    while (p != NULL) {
        printf("\nHo ten: %s", p->infor.hoten);
        printf("\nMa sinh vien: %d", p->infor.ma);
        printf("\nDiem 1: %.2f", p->infor.d1);
        printf("\nDiem 2: %.2f", p->infor.d2);
        printf("\nDiem 3: %.2f", p->infor.d3);

        p = p->link;
    }
}

void GiaiPhong(struct List *l) {
    struct Node *p;

    while (l->head != NULL) {
        p = l->head;
        l->head = l->head->link;
        free(p);
    }

    l->tail = NULL;
}

int main() {
    struct List l;
    int n;

    KhoiTao(&l);

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar();

    Nhap(&l, n);

    printf("\nDANH SACH SINH VIEN");
    Xuat(l);

    GiaiPhong(&l);

    return 0;
}
