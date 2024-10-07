#include <stdio.h>
#define MEDIA 12.000;

double gasto(int hora, int velo){
    return (hora*velo)/MEDIA;
}

int main(void){

    int h, v;
    scanf("%d %d", &h, &v);
    printf("%.3lf\n", gasto(h,v));

    return 0;
}