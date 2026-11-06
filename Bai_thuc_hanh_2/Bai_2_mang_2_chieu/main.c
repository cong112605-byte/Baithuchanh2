#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    float **p;

    scanf("%d%d", &n, &m);

    p = (float**)malloc(n * sizeof(float*));

    for (int i = 0; i < n; i++) {
        p[i] = (float*)malloc(m * sizeof(float));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%f", &p[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%f ", p[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(p[i]);
    }

    free(p);

    return 0;
}