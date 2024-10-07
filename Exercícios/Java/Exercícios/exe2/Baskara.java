package exe2;

public class Baskara {
    public static void main(String[] args) {
    
    double a, b, c, x1, x2, delta;

    a = 1;
    b = 1;
    c = -6;  
        
    System.out.println("Bem vindo ao programa que calcula: x² + x - 6 = 0");

    delta = b*b - 4*a*c;

    System.out.println(delta);

        if (delta < 0){
            System.out.println("Não existem raízes reais");
        }
        if (delta > 0) {
            x1 = (-b + Math.pow(delta, 0.5)) / 2*a;
            x2 = (-b - Math.pow(delta, 0.5)) / 2*a;

            System.out.println("As raízes são: "+x1+", e "+x2);
        }
    
    } 
    

}