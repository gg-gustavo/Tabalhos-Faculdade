public class Lutador {

    // Atributos
    private String nome;
    private String nacionalidade;
    private Integer idade;
    private Float altura;
    private Float peso;
    private String categoria; // Peso Leve, Peso Médio e Peso Pesado
    private Integer vitorias;
    private Integer derrotas;
    private Integer empate;

    // Metodos Especiais

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNacionalidade() {
        return nacionalidade;
    }

    public void setNacionalidade(String nacionalidade) {
        this.nacionalidade = nacionalidade;
    }

    public Integer getIdade() {
        return idade;
    }

    public void setIdade(Integer idade) {
        this.idade = idade;
    }

    public Float getAltura() {
        return altura;
    }

    public void setAltura(Float altura) {
        this.altura = altura;
    }

    public Float getPeso() {
        return peso;
    }

    public void setPeso(Float peso) {
        this.peso = peso;
        this.setCategoria();
    }

    public String getCategoria() {
        return categoria;
    }

    public void setCategoria() {
        if (this.getPeso() < 52) {
            this.categoria = "Inválido";
        } else if (this.getPeso() <= 70.3) {
            this.categoria = "Leve";
        } else if (this.getPeso() <= 83.9) {
            this.categoria = "Médio";
        } else if (this.getPeso() <= 120.2) {
            this.categoria = "Pesado";
        } else {
            this.categoria = "Inválido";
        }
    }

    public Integer getVitorias() {
        return vitorias;
    }

    public void setVitorias(Integer vitorias) {
        this.vitorias = vitorias;
    }

    public Integer getDerrotas() {
        return derrotas;
    }

    public void setDerrotas(Integer derrotas) {
        this.derrotas = derrotas;
    }

    public Integer getEmpate() {
        return empate;
    }

    public void setEmpate(Integer empate) {
        this.empate = empate;
    }

    // Construtor

    public Lutador(String nome, String nacionalidade, Integer idade, Float altura, Float peso,
            Integer vitorias, Integer derrotas, Integer empate) {
        this.setNome(nome);
        this.setNacionalidade(nacionalidade);
        this.setIdade(idade);
        this.setAltura(altura);
        this.setPeso(peso);
        this.setVitorias(vitorias);
        this.setDerrotas(derrotas);
        this.setEmpate(empate);
    }

    // Metodos específicos

    public void apresentar() {
        System.out.println("--------APRESENTAÇÃO--------");
        System.out.println("Senhoras e Senhores! Eu vos apresento:");
        System.out.println("Lutador: " + this.getNome());
        System.out.println("Origem: " + this.getNacionalidade());
        System.out.println(this.getIdade() + " Anos");
        System.out.println(this.getAltura() + " m de Altura");
        System.out.println("Peso: " + this.getPeso()+" Kg");
        System.out.println("Categoria: " + this.getCategoria());
        System.out.println("Ganhou: " + this.getVitorias());
        System.out.println("Perdeu: " + this.getDerrotas());
        System.out.println("Empatou: " + this.getEmpate() + "\n\n");
    }

    public void status() {
        System.out.println("--------STATUS--------");
        System.out.println("Nome " + this.getNome());
        System.out.println("Origem " + this.getNacionalidade());
        System.out.println("Categoria: " + this.getCategoria());
    }

    public void ganharLuta() {
        this.setVitorias(this.getVitorias() + 1);

    }

    public void perderLuta() {
        this.setDerrotas(this.getDerrotas() + 1);
    }

    public void empatarLuta() {
        this.setEmpate(this.getEmpate() + 1);

    }

}
    