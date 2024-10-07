#include <stdio.h>

    float lanches(int cod, int qnt){
        switch (cod){
            case 1:
            return qnt * 4.00;
            break;
            case 2:
            return qnt * 4.50;
            break;
            case 3:
            return qnt * 5.00;
            break;
            case 4:
            return qnt * 2.00;
            case 5:
            return qnt * 1.50;
        }

        
    }
 
int main() {

    int x, y;
    scanf("%d %d", &x, &y);
    printf("Total: R$ %.2f\n", lanches(x, y));

    return 0;
}