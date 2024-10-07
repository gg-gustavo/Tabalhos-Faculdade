#include <stdio.h>

int fat_descendnete(int n, int k){
    if(k == 1){
        return n;
    }
    return n * fat_descendnete(n-1, k-1);
}

int main(void){
    int N, K;
    scanf("%d %d", &N, &K);
    printf("o valor do fariaral dado n = %d e k = %d é: %d\n", N, K, fat_descendnete(N,K));
    return 0;
}
