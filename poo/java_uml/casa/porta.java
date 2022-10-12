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
