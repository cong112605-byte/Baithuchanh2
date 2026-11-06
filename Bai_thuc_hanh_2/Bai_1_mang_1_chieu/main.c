#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    float *p;

    scanf("%d", &n);

    p = (float*)malloc(n * sizeof(float));

    for (int i = 0; i < n; i++) {
        scanf("%f", (p + i));
    }

    for (int i = 0; i < n; i++) {
        printf("%f ", *(p + i));
    }

    free(p);

    return 0;
}