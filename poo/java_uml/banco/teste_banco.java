class Teste_Banco {
	public static void main(String[] args) {
		Conta exemplo_1		= new Conta();
		Conta exemplo_2		= new Conta();
		ContaCorrente exemplo_3	= new ContaCorrente();
		ContaPoupanca exemplo_4	= new ContaPoupanca();

//		exemplo_1.depositar(1000000.00);
//		exemplo_2.depositar(1000000.00);
//		exemplo_3.depositar(1000000.00);
//		exemplo_4.depositar(1000000.00);

//		System.out.println(exemplo_1.extrato());
//		System.out.println(exemplo_2.extrato());
//		System.out.println(exemplo_3.extrato());
//		System.out.println(exemplo_4.extrato());
	}
}

class Banco {
	private Conta[] Contas_Clientes = new Conta[0];
	
	public void adiciona(Conta c) {
		Conta[] Novo_Espaco;
		int i, total_de_contas = this.Contas_Clientes.length + 1;

		Novo_Espaco = new Conta[total_de_contas];
		
		for(i = 0; i < total_de_contas; i++)
			Novo_Espaco[i] = this.Contas_Clientes[i];

		this.Contas_Clientes = Novo_Espaco;
		this.Contas_Clientes[total_de_contas] = c;
	}

	public Conta pegaConta(int n) {
		return this.Contas_Clientes[n];
	}

	public int pegaTotalDeContas() {
		return this.Contas_Clientes.length;
	}
}

class AtualizadorDeContas {
	private double saldo_total = 0;
	private double taxa_atualizar;

	public AtualizadorDeContas(double taxa) {
		this.taxa_atualizar = taxa;
	}

	public void atualizar_conta(Conta c) {
		double saldo = c.extrato();
		System.out.println("________________________________________");
		System.out.println("Saldo inicial da conta:\t$ " + saldo);
		this.saldo_total -= saldo;
		c.atualizar(this.taxa_atualizar);
		saldo = c.extrato();
		this.saldo_total += saldo;
		System.out.println("Saldo final da conta:\t$ " + saldo);
		System.out.println("________________________________________");
	}

	public double obter_saldo_total() {
		return this.saldo_total;
	}
}

class Conta {
	protected double saldo;

	public double extrato() {
		return this.saldo;
	}

	public void depositar(double valor) {
		this.saldo += valor;
	}

	public boolean sacar(double valor) {
		boolean pode_sacar = (valor <= this.saldo);

		if(pode_sacar)
			this.saldo -= valor;

		return pode_sacar;
	}

	public void atualizar(double taxa) {
		this.saldo *= 1 + taxa;
	}
}

class ContaCorrente extends Conta {
	@Override
	public void atualizar(double taxa) {
		this.saldo *= 1 + (2 * taxa);
	}

	@Override
	public void depositar(double valor) {
		this.saldo += (valor - 0.10);
	}
}

class ContaPoupanca extends Conta {
	@Override
	public void atualizar(double taxa) {
		this.saldo *= 1 + (3 * taxa);
	}
}

