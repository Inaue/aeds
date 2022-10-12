import Porta;

class Casa {
	private String cor		= "Branco";
	private int totalDePortas	= 0;
	private Porta[] Portas_da_Casa	= new Porta[0];

	public void pintar(String c) {
		this.cor = c;
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
