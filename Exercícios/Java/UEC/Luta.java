import java.util.Random;

public class Luta{
    private Lutador desfaiado;
    private Lutador desafiante;
    private Integer rouds;
    private boolean aprovada;

    public void marcarLuta(Lutador l1, Lutador l2){
        if(l1.getCategoria() == l2.getCategoria() && l1 != l2){
            this.setAprovada(true);
            this.setDesfaiado(l1);
            this.setDesafiante(l2);
        }
        else{
            setAprovada(false);
            this.setDesfaiado(null);
            this.setDesafiante(null);
        }
    }

    public void lutar(){
        if(this.isAprovada()){
            System.err.println("Desafiado");
            this.desfaiado.apresentar();
            System.err.println("Desafiante");
            this.desafiante.apresentar();
    
            Random aleatorio = new Random();
            int vencedor = aleatorio.nextInt(3); //0 1 2
    
            switch (vencedor) {
                case 0: // empate
                    System.err.println("Empatou");
                    this.desafiante.empatarLuta();
                    this.desfaiado.empatarLuta();
                    break;
                case 1: // desafiado vence
                    System.out.println("Venceu " + this.desfaiado.getNome());
                    this.desfaiado.ganharLuta();
                    this.desafiante.perderLuta();
                    break;
                case 2: // desafiante vence
                    System.out.println("Venceu " + this.desafiante.getNome());
                    this.desafiante.ganharLuta();
                    this.desfaiado.perderLuta();
                    break;
            }
        } else {
            System.err.println("A luta não pode acontecer!");
        }
    }
    

    // metodos especiais

    public Lutador getDesfaiado() {
        return desfaiado;
    }

    public void setDesfaiado(Lutador desfaiado) {
        this.desfaiado = desfaiado;
    }

    public Lutador getDesafiante() {
        return desafiante;
    }

    public void setDesafiante(Lutador desafiante) {
        this.desafiante = desafiante;
    }

    public Integer getRouds() {
        return rouds;
    }

    public void setRouds(Integer rouds) {
        this.rouds = rouds;
    }

    public boolean isAprovada() {
        return aprovada;
    }

    public void setAprovada(boolean aprovada) {
        this.aprovada = aprovada;
    }
    


}