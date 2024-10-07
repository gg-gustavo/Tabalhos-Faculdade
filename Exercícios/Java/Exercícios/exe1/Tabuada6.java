package exe1;

public class Tabuada6 {

    public static void main(String[] args){

        System.out.println("Tabuada do 6");

        int n, cont, resultado;
        n = 6; 
        cont = 0;
        resultado = 0;

        while (cont <= 10) {
        resultado = n * cont;
        System.out.println(n+" x "+cont+" = "+resultado);
        cont++;
        
        }
    }
}