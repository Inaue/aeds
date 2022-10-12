class Teste_Casa {
	public static void main(String[] args) {
		Casa Casa_dos_Sonhos	= new Casa();
		Porta Porta_da_Frente	= new Porta();
		Porta Porta_da_Suite	= new Porta();
		Porta Porta_da_Fundos	= new Porta();

		Casa_dos_Sonhos.pintar("Verde-claro");
		Casa_dos_Sonhos.adicionarPorta(Porta_da_Frente);
		Casa_dos_Sonhos.adicionarPorta(Porta_da_Suite);
		Casa_dos_Sonhos.adicionarPorta(Porta_da_Fundos);
		Porta_da_Suite.destrancar();
		Porta_da_Suite.abrir();
		Porta_da_Fundos.destrancar();
		Porta_da_Fundos.abrir();

		System.out.println(Casa_dos_Sonhos.quantasPortasEstaoAbertas() + " das " + Casa_dos_Sonhos.totalDePortas() + " portas da casa de cor " + Casa_dos_Sonhos.obter_cor() + " estao abertas!");
	}
}

class Casa {
	private String cor		= "Branco";
	private int totalDePortas	= 0;
	private Porta[] Portas_da_Casa	= new Porta[0];

	public void pintar(String c) {
		this.cor = c;
	}

	public String obter_cor() {
		return this.cor;
	}

	public int totalDePortas() {
		return this.totalDePortas;
	}

	public int quantasPortasEstaoAbertas() {
		int abertas = 0;

		for(Porta p : this.Portas_da_Casa)
		{
			if(p.estaAberta())
				abertas++;
		}

		return abertas;
	}

	public void adicionarPorta(Porta p) {
		Porta[] Novo_Espaco;
		int i;

		if(this.totalDePortas == this.Portas_da_Casa.length)
		{
			Novo_Espaco = new Porta[this.totalDePortas+1];
			
			for(i = 0; i < this.totalDePortas; i++)
				Novo_Espaco[i] = this.Portas_da_Casa[i];

			this.Portas_da_Casa = Novo_Espaco;
		}

		this.Portas_da_Casa[this.totalDePortas++] = p;
	}
}

class Porta {
	private boolean aberta		= false;
	private boolean trancada	= true;

	public boolean estaAberta() {
		return this.aberta;
	}

	public boolean estaTrancada() {
		return this.trancada;
	}

	public boolean abrir() {
		boolean podeAbrir = !this.trancada;

		if(podeAbrir)
			this.aberta = true;

		return podeAbrir;
	}

	public boolean fechar() {
		boolean podeFechar = !this.trancada;

		if(podeFechar)
			this.aberta = false;

		return podeFechar;
	}

	public void trancar() {
		this.trancada = true;
	}

	public void destrancar() {
		this.trancada = false;
	}
}
