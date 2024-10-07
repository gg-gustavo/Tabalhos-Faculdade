package exe4;

import java.util.Scanner;

public class PositivoNegativo {

    public static void main(String[] args){

        Scanner entrada = new Scanner(System.in);

        int a;

        a = entrada.nextInt();

        if (a < 0){
            System.out.println("Negativo");
        }
        else if (a > 0){
            System.out.println("Positivo");
        }
    }
}