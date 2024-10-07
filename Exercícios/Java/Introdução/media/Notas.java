package media;

import java.util.Scanner;

public class Notas{
    public static void main(String[] args){

        Scanner entrada = new Scanner(System.in);
        float  nota1, nota2, nota3, media;

        System.out.println("Digite as 3 notas do Aluno:");
        nota1 = entrada.nextFloat();
        nota2 = entrada.nextFloat();
        nota3 = entrada.nextFloat();
        media = (nota1 + nota2 + nota3) / 3;

        System.out.println("O valor da media é "+ media);

    }
}