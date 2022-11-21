class Teste_Restaurante
{
	public static void main(String[] args)
	{
		//code
	}
}

class Restaurante
{
	private String nome;
	private String endereco;
	Mesa[] Mesas_Atender = new Mesa[0];

	Restaurante(String nome, String endereco)
	{
		this.nome	= nome;
		this.endereco	= endereco;
	}

	public String obter_nome()
	{
		return this.nome;
	}

	public String obter_endereco()
	{
		return this.endereco;
	}

	public void definir_nome(String novo_nome)
	{
		this.nome = novo_nome;
	}

}

class Mesa
{
	private int numeroMesa;
	private String data;
	private boolean reserva;
	Cliente[] Clintes_Sentados = new Cliente[0];

	Mesa(int num_mesas, String data, boolean reserva)
	{
		this.numeroMesa	= num_mesas;
		this.data	= data;
		this.reserva	= reserva;
	}

	public int obter_num_mesas()
	{
		return this.numeroMesa;
	}

	public String obter_data()
	{
		return this.data;
	}

	public boolean obter_reserva()
	{
		return this.reserva;
	}

	public void definir_num_mesas(int num_mesas)
	{
		this.numeroMesa = num_mesas;
	}

	public void definir_data(String nova_data)
	{
		this.data = nova_data;
	}

	public void definir_reserva(boolean reservas)
	{
		this.reserva = reservas;
	}

}

class Cliente
{
	private String nome;
	private String email;

	Cliente(String nome, String email)
	{
		this.nome	= nome;
		this.email	= email;
	}

	public String obter_nome()
	{
		return this.nome;
	}

	public String obter_email()
	{
		return this.email;
	}

	public void definir_nome(String novo_nome)
	{
		this.nome = novo_nome;
	}

	public void definir_email(String end_email)
	{
		this.email = end_email;
	}

}

class Comanda
{
	private String consumo;
	private double valor;
	
	Comanda(String consumo, double valor)
	{
		this.consumo	= consumo;
		this.valor	= valor;
	}

	public double obter_valor()
	{
		return this.valor;
	}

	public void definir_consumo(String consumo_cliente)
	{
		this.consumo = consumo_cliente;
	}

	public void definir_valor(double valor_pagar)
	{
		this.valor = valor_pagar;
	}

}
