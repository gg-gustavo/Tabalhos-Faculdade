package exe3;
import java.util.Scanner;

class Nome {
    public static void main(String[] args){

        Scanner entrada = new Scanner(System.in);
        String nome, time, bairro;

        System.out.println("Qual o seu nome?");
        nome = entrada.nextLine();
        System.out.println("Qual o seu time?");
        time = entrada.nextLine();
        System.out.println("Qual o seu bairro?");
        bairro = entrada.nextLine();

        System.out.println("Seu nome é "+ nome +", Seu time é "+ time +", Seu bairro é "+ bairro);
    }
    
}