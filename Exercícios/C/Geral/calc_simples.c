#include <stdio.h>

int main(void){

    int pc1, pc2, cd1, cd2;
    float vl1, vl2;

    scanf("%d %d %f", &cd1, &pc1, &vl1);
    scanf("%d %d %f", &cd2, &pc2, &vl2);

    printf("VALOR A PAGAR: R$ %.2f\n", (vl1 * pc1 + vl2 * pc2));

    return 0;
}