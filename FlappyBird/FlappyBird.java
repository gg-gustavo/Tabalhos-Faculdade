import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.Random;
import javax.swing.*;

public class FlappyBird extends JPanel implements ActionListener, KeyListener{ //permitir a craiçãoo de novas classes que tenham o Jpanel
    int largura = 360;
    int altura = 640;

    //Imagens
    Image fundo_img;
    Image passaro_img;
    Image tubo_cima_img;
    Image tubo_baixo_img;

    //Passaro
    int passaro_X = largura /8;
    int passaro_Y = altura /2;
    int passaro_largura = 34;
    int passaro_altura = 24;

    class Passaro{
        int x = passaro_X;
        int y = passaro_Y;
        int largura = passaro_largura;
        int altura = passaro_altura;
        Image img;

        Passaro(Image img){
            this.img = img;
        }
    }

    //Tubos
    int tubo_X = largura;
    int tubo_Y = 0;
    int tubo_largura = 64;
    int tubo_altura = 512;

    class Tubo {
        int x = tubo_X;
        int y = tubo_Y;
        int largura = tubo_largura;
        int altura = tubo_altura;
        Image img;
        boolean passou = false;

        Tubo(Image img){
            this.img = img;
        }
    }

    //Lógica de jogo
    Passaro passaro;
    int gravidade = 1;
    boolean fim_de_jogo = false;
    double pontos;

    //Movimentação
    int velocidade_X = -4; //Faz parecer o passaro voar para direita
    int velocidade_Y = 0; //Move 6 px para cima

    ArrayList<Tubo> tubos;

    Timer loop_jogo;
    Timer deposita_tubos;


    FlappyBird(){ //construtor
        setPreferredSize(new Dimension(largura, altura)); //largura vem por primeiro
        setBackground(Color.blue);
        setFocusable(true);
        addKeyListener(this);

        //Carregar as Imagens

        fundo_img = new ImageIcon(getClass().getResource("./fundo.png")).getImage();
        passaro_img = new ImageIcon(getClass().getResource("./passaro.png")).getImage();
        tubo_baixo_img = new ImageIcon(getClass().getResource("./tubo_baixo.png")).getImage();
        tubo_cima_img = new ImageIcon(getClass().getResource("./tubo_cima.png")).getImage();

        //Passaro
        passaro = new Passaro(passaro_img);

        //Tubos
        tubos = new ArrayList<Tubo>();
        Random random = new Random();

        //Timer dos tubos
        deposita_tubos = new Timer(1500, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e){
                deposita_tubos();
            }   
        });
        
        //Timer dos tubos
        deposita_tubos.start();

        //Timer do jogo
        loop_jogo = new Timer(1000/60, this);
        loop_jogo.start();


    }

    public void deposita_tubos(){

        int random_tubo_Y = (int)(tubo_Y - tubo_altura/4 - Math.random()*(tubo_altura/2));
        int abrir_espaco = altura/4;
        Tubo tubo_cima = new Tubo(tubo_cima_img);
        tubo_cima.y = random_tubo_Y;
        tubos.add(tubo_cima); //adiciona ao array de tubos
        
        Tubo tubo_baixo = new Tubo(tubo_baixo_img);
        tubo_baixo.y = tubo_cima.y + tubo_altura + abrir_espaco;
        tubos.add(tubo_baixo); //adicona ao array de tubos
    }

    // Criar as funções do jogo utilizando a lib JPanel

    public void paintComponent(Graphics g){
        super.paintComponent(g);
        draw(g);
    }

    public void draw(Graphics g){
        
        //fundo
        g.drawImage(fundo_img, 0, 0, largura, altura, null);

        //passaro
        g.drawImage(passaro.img, passaro.x, passaro.y, passaro.largura, passaro.altura, null);

        //Tubos
        for (int i = 0; i < tubos.size(); i++){
            Tubo tubo = tubos.get(i);
            g.drawImage((tubo.img), tubo.x, tubo.y, tubo.largura, tubo.altura, null);
        }

        //Pontos
        g.setColor(Color.white);
        g.setFont(new Font("Arial", Font.PLAIN, 32));
        if (fim_de_jogo){
            g.drawString("FIM DE JOGO: " + String.valueOf((int) pontos), 10, 35);
        }
        else {
            g.drawString(String.valueOf((int) pontos), 10, 35);
        }
    }

    public void movimentacao(){
        
        //passaro
        velocidade_Y = velocidade_Y + gravidade;
        passaro.y = passaro.y + velocidade_Y; // sobe 6px por segundo
        passaro.y = Math.max(passaro.y, 0); // seta o teto máximo que é 0 px

        //tubos
        for (int i = 0; i < tubos.size(); i++){
            Tubo tubo = tubos.get(i);
            tubo.x = tubo.x + velocidade_X;

            if (!tubo.passou && passaro.x > tubo.x + tubo.largura){
                tubo.passou = true;
                pontos = pontos + 0.5; //0,5 +0,5 2 tubos

            }

            if (colisao(passaro, tubo)){
                fim_de_jogo = true;
            }

        }

        if (passaro.y > altura) {
            fim_de_jogo = true;
        }

    }

    public boolean colisao(Passaro a, Tubo b){
        return a.x < b.x + b.largura &&
                a.x + a.largura> b.x &&
                a.y < b.y + b.altura &&
                a.y +a.altura > b.y;
                //logica de colisão do flappybird
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        movimentacao();
        repaint();
        if(fim_de_jogo){
            deposita_tubos.stop();
            loop_jogo.stop();
        }
    }


    // Entrada
    @Override
    public void keyPressed(KeyEvent e) {
        if(e.getKeyCode() == KeyEvent.VK_SPACE){
            velocidade_Y = -9;
            if (fim_de_jogo){
                //reseta o jogo, definimos os valores para o default
                passaro.y = passaro_Y;
                velocidade_Y = 0;
                tubos.clear();
                pontos = 0;
                fim_de_jogo = false;
                loop_jogo.start();
                deposita_tubos.start();
            }
        }
    }

    @Override
    public void keyTyped(KeyEvent e) {}


    @Override
    public void keyReleased(KeyEvent e) {}


    
}