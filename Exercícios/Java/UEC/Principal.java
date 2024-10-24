import java.util.Scanner;

public class Principal {

    public static void main(String[] args) {

        Scanner entrada = new Scanner(System.in);

        System.out.println("Bem vindo ao UEC!");
        System.out.println("Gostaria de Cadastrar Lutadores?");
        System.out.println("[0] SAIR\n[1] SIM");

        Integer menu = entrada.nextInt();
        
        if( menu == 1){
            System.out.println("Quantos Lutadores para o cadastro?");
            Integer quantidade = entrada.nextInt();
            Integer i;
            Lutador l[] = new Lutador[quantidade];
            
            String nome;
            String nacionalidade;
            Integer idade;
            Float altura;
            Float peso;
            Integer vitorias;
            Integer derrotas;
            Integer empate;
            
            for(i = 0; i < quantidade; i++){
                entrada.nextLine();
                System.out.println("Nome: ");
                nome = entrada.nextLine();
                System.out.println(nome);
                System.out.println("Nacionalidade: ");
                nacionalidade = entrada.nextLine();
                System.out.println("Idade: ");
                idade = entrada.nextInt();
                System.out.println("Altura: ");
                altura = entrada.nextFloat();
                System.out.println("Peso: ");
                peso = entrada.nextFloat();
                System.out.println("Vitórias: ");
                vitorias = entrada.nextInt();
                System.out.println("Derrotas: ");
                derrotas = entrada.nextInt();
                System.out.println("Empates: ");
                empate = entrada.nextInt();                
                l[i] = new Lutador(nome, nacionalidade, idade, altura, peso, vitorias, derrotas, empate);
            }   
        System.out.println("O que você deseja Fazer: ");
        System.out.println("Apresentar [1] ");
        System.out.println("Status [2] ");
        System.out.println("Sair[0]");
        menu = entrada.nextInt();
            if(menu == 1){
                for (i = 0; i < quantidade; i++){
                l[i].apresentar();
                }
            }
            else if(menu == 2){
                for(i = 0; i < quantidade; i++){
                    l[i].status();
                }
            }
        Luta UEC01 = new Luta();
        System.out.println("O que você deseja Fazer: ");
        System.out.println("Marcar Luta [1] ");
        System.out.println("Sair[0]");
        menu = entrada.nextInt();
            if(menu == 1){
                UEC01.marcarLuta(l[0], l[1]);

                System.out.println("O que você deseja Fazer: ");
                System.out.println("Lutar [1] ");
                System.out.println("Sair[0]");
                menu = entrada.nextInt();
                if(menu == 1){
                    UEC01.lutar();
                }
            }   
        }
    }
}