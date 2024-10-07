package soma;
import java.util.Scanner; // Iniciando Teclado

public class Soma {
    public static void main(String[] args){

        Scanner entrada = new Scanner(System.in);
        int a, b, resultlado;

        System.out.println("Bem vindo ao programa de soma, digite o primeiro valor: ");
        a = entrada.nextInt();
        System.out.println("Digite o segundo valor: ");
        b = entrada.nextInt();

        resultlado = a + b;

        System.out.println("O resultado deu: " + resultlado);


    }

}