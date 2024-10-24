package controle_remoto;

import controle_remoto.interface_controle.Controlador;

public class ControleRemoto implements Controlador{
    //Atributos
    private Integer volume;
    private Boolean ligado;
    private Boolean tocando;

    //Metodos Especiais
    public ControleRemoto(){ //Contrutor
        this.volume = 50;
        this.ligado = false;
        this.tocando = false;
    }

    // Metodos Get
    public Integer getVolume(){
        return volume;
    }

    public Boolean getLigado(){
        return ligado;
    }

    public Boolean getTocando(){
        return tocando;
    }

    //Metodos Set
    public void setVolume(Integer volume) {
        this.volume = volume;
    }

    public void setLigado(Boolean ligado) {
        this.ligado = ligado;
    }

    public void setTocando(Boolean tocando) {
        this.tocando = tocando;
    }
  
    //Sobrescrevendo os Metodos Abstratos

    @Override
    public void ligar() {
        this.setLigado(true);
    }

    @Override
    public void desligar() {
        this.setLigado(false);
    }

    @Override
    public void abrirMenu() {
        Integer i;
        System.out.println();
        System.out.println("-----Menu-----");
        System.out.println("Está ligado? "+this.getLigado());
        System.out.print("Volume: "+this.getVolume());
        for(i = 0; i < getVolume(); i+=10){ //pula em 10 espaços            
            System.out.print(" | ");
        }
        System.out.println("\nEstá tocando: "+this.getTocando());
        System.out.println();
    }

    @Override
    public void fecharMenu() {
        System.out.println("Fechando o Menu");
    }

    @Override
    public void maisVolume() {
        if ((this.getLigado() == true) || this.getVolume() > 0){
            this.setVolume(this.getVolume() +1);
        }

    }

    @Override
    public void menosVolume() {
        if (this.getLigado() == true || this.getVolume() > 0){
            this.setVolume(this.getVolume() -1);
        }
    }

    @Override
    public void ligarMudo() {
        if (this.getLigado() == true && this.getVolume() > 0){
            this.setVolume(0);
        }
    }

    @Override
    public void desligarMudo() {
        if (this.getLigado() == true && this.getVolume() == 0){
            this.setVolume(50);
        }
    }

    @Override
    public void play() {
        if (this.getLigado() == true && !(this.getTocando() == true)){
            this.setTocando(true);
        }

    }

    @Override
    public void pause() {
        if (this.getLigado() == true && this. getTocando() == true){
            this.setTocando(false);
        }

    }

}
