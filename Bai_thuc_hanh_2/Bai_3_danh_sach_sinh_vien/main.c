#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SV {
    char hoten[100];
    int ma;
    float d1, d2, d3;
};

int main() {
    int n;

    printf("So SV: ");
    scanf("%d", &n);
    getchar();

    struct SV *p = (struct SV*)malloc(n * sizeof(struct SV));

    for (int i = 0; i < n; i++) {
        printf("Sinh vien thu %d\n", i + 1);

        fgets(p[i].hoten, sizeof(p[i].hoten), stdin);
        p[i].hoten[strcspn(p[i].hoten, "\n")] = '\0';

        scanf("%d", &p[i].ma);
        scanf("%f", &p[i].d1);
        scanf("%f", &p[i].d2);
        scanf("%f", &p[i].d3);

        getchar();
    }

    for (int i = 0; i < n; i++) {
        printf("Ho ten: %s\n", p[i].hoten);
        printf("Ma SV: %d\n", p[i].ma);
        printf("Diem 1: %.2f\n", p[i].d1);
        printf("Diem 2: %.2f\n", p[i].d2);
        printf("Diem 3: %.2f\n", p[i].d3);
    }

    free(p);

    return 0;
}