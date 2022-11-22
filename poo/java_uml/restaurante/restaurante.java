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
	Mesa[] Mesas_Atender;

	public Restaurante(String nome, String endereco, Mesa[] Mesas_Existentes)
	{
		this.nome		= nome;
		this.endereco		= endereco;
		this.Mesas_Atender	= Mesas_Existentes;
	}

	public String obter_nome()
	{
		return this.nome;
	}

	public String obter_endereco()
	{
		return this.endereco;
	}

	public Mesa[] obter_mesas()
	{
		return this.Mesas_Atender;
	}
	
	public void definir_nome(String novo_nome)
	{
		this.nome = novo_nome;
	}

	public void definir_endereco(String novo_endereco)
	{
		this.endereco = novo_endereco;
	}

	public void definir_mesas(Mesa[] Novas_Mesas)
	{
		this.Mesas_Atender = Novas_Mesas;
	}

}

class Mesa
{
	private int numeroMesa;
	private String data;
	private boolean reserva;
	private Comanda Cmd;

	Mesa(int num_mesas, String data, boolean reserva, Comanda Comanda_Inicial)
	{
		this.numeroMesa	= num_mesas;
		this.data	= data;
		this.reserva	= reserva;
		this.Cmd	= Comanda_Inicial;
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

	public Comanda obter_comanda()
	{
		return this.Cmd;
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

	public void definir_comanda(Comanda Nova_Comanda)
	{
		this.Cmd = Nova_Comanda;
	}

	public boolean reservar(String data_reservada)
	{
		boolean ja_reservada = this.reserva;

		if(ja_reservada)
			return false;
		else
		{
			this.reserva	= true;
			this.data	= data_reservada;
			
			return true;
		}
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
	private String[] consumo;
	private double valor;
	private Cliente[] Clientes_da_Mesa;
	
	public double obter_valor()
	{
		return this.valor;
	}

	public String[] obter_consumo()
	{
		return this.consumo;
	}

	public Cliente[] obter_clientes()
	{
		return this.Clientes_da_Mesa;
	}

	public void definir_consumo(String[] consumo_cliente)
	{
		this.consumo = consumo_cliente;
	}

	public void definir_valor(double valor_pagar)
	{
		this.valor = valor_pagar;
	}

	public void definir_clientes(Cliente[] Clientes_Definir)
	{
		this.Clientes_da_Mesa = Clientes_Definir;
	}

	public void listar_consumo()
	{
		for(String c : this.consumo)
			System.out.println(c);
	}

	public double calcular10porcento()
	{
		return (this.valor / 10);
	}

	public double dividirConta()
	{
		return (this.valor / Clientes_da_Mesa.length);
	}
}
