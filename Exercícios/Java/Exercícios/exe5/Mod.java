package exe5;

import java.util.Scanner;

public class Mod {

    public static void main(String[] args){

        Scanner entrada = new Scanner(System.in);

        int a;

        a = entrada.nextInt();

        if (a%2 == 0) {
            System.out.println("O número é par");
        }
        else if (a%2 != 0){
            System.out.println("O número é ímpar");

        }
    }
}