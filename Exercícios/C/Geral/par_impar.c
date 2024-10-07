#include <stdio.h>
#include <stdlib.h>

int main(void){
    long int *vet, tam;
    int i;

    scanf("%ld", &tam);
    vet = (long int *) malloc(tam * sizeof(long int));

    if(vet == NULL){
        exit(1);
    }

    for(i = 0; i < tam; i++){
        scanf("%ld", &vet[i]);
    }
    for(i = 0; i < tam; i++){
        if (vet[i] == 0){
            printf("NULL\n");
        }
        else if(vet[i]%2 == 0 && vet[i] > 0){
            printf("EVEN POSITIVE\n");
        }
        else if(vet[i]%2 == 0 && vet[i] < 0){
            printf("EVEN NEGATIVE\n");
        }
        else if(vet[i]%2 != 0 && vet[i] > 0){
            printf("ODD POSITIVE\n");
        }
        else if(vet[i]%2 != 0 && vet[i] < 0){
            printf("ODD NEGATIVE\n");
        }
    }
    
    return 0;
}