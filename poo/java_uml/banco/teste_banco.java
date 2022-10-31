class Teste_Banco {
	public static void main(String[] args) {
		int contas_existentes, c;
		int exemplo_referencia	= 2;
		double selic_hoje	= 0.1375;// 13.75% a.a.
		Conta exemplo_0		= new Conta();
		Conta exemplo_1		= new Conta();
		ContaCorrente exemplo_2	= new ContaCorrente();
		ContaPoupanca exemplo_3	= new ContaPoupanca();
		Conta referencia_extra;
		AtualizadorDeContas Atualizador_Exemplos = new AtualizadorDeContas(selic_hoje);
		Banco Bank_Pay = new Banco();

		exemplo_0.depositar(1000000.00);
		exemplo_1.depositar(1000000.00);
		exemplo_2.depositar(1000000.00);
		exemplo_3.depositar(1000000.00);
		exemplo_0.sacar(10.00);
		Bank_Pay.adiciona(exemplo_0);
		Bank_Pay.adiciona(exemplo_1);
		Bank_Pay.adiciona(exemplo_2);
		Bank_Pay.adiciona(exemplo_3);
		referencia_extra	= Bank_Pay.pegaConta(exemplo_referencia);
		contas_existentes	= Bank_Pay.pegaTotalDeContas();
		System.out.println("Saldo da conta " + exemplo_referencia + ": $ " + referencia_extra.extrato());
		System.out.println("________________________________________");
		System.out.println("Meu banco possui " + contas_existentes + " contas.");
		System.out.println("________________________________________");
		System.out.println("Atualizacoes:");

		for(c = 0; c < contas_existentes; c++) {
			System.out.println("Conta " + c);
			Atualizador_Exemplos.atualizar_conta(Bank_Pay.pegaConta(c));
		}

		System.out.println("________________________________________");
		System.out.println("Saldo total do banco: $ " + Atualizador_Exemplos.obter_saldo_total());
	}
}

class Banco {
	private Conta[] Contas_Clientes = new Conta[0];
	
	public void adiciona(Conta c) {
		Conta[] Novo_Espaco;
		int i, total_de_contas = this.Contas_Clientes.length;

		Novo_Espaco = new Conta[total_de_contas + 1];
		
		for(i = 0; i < total_de_contas; i++)
			Novo_Espaco[i] = this.Contas_Clientes[i];

		this.Contas_Clientes = Novo_Espaco;
		this.Contas_Clientes[total_de_contas++] = c;
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

