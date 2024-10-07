#include <stdio.h>

int tempo(int hora, int minuto){
    int aux;
    aux = (hora * 60) + minuto;
    return aux;
}


int main(void){

    int h_i, m_i , h_f, m_f, horario;

    scanf("%d %d %d %d", &h_i, &m_i, &h_f, &m_f);

    horario = (tempo(h_f, m_f) - tempo(h_i, m_i));

    if(horario == 0){
        printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n");
    }else if (horario < 0){
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", (horario/60) +23, (horario%60)+60); 
    }
    else{
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", (horario/60), (horario%60));
    }

    return 0;
}