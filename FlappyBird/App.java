import javax.swing.*;

public class App {

    public static void main(String[] args) throws Exception{
        int largura = 360;
        int altura = 640;

        JFrame frame = new JFrame("Flappy Bird");
        frame.setVisible(true);
        frame.setSize(largura, altura); // dimensoes da imagem
        frame.setLocationRelativeTo(null); // abrir a janela centralizada
        frame.setResizable(false);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // fechar a janela no X

        FlappyBird flappyBird = new FlappyBird();
        frame.add(flappyBird);
        frame.pack();
        flappyBird.requestFocus();    
        frame.setVisible(true);

        

    } 
}