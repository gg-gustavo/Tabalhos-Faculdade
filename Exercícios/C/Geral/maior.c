#include <stdio.h>

int main(void){
    int i, vet[3] = {0,0,0};
    for(i = 0; i < 3; i++){
        scanf("%d", &vet[i]);
    }
    int chave = vet[0];
    for(i = 0; i < 3; i++){
        if(chave < vet[i]){
            chave = vet[i];
        }
    }
    printf("%d eh o maior\n", chave);
    return 0;
}