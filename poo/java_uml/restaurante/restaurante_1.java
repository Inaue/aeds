class Teste_Restaurante
{
	public static void main(String[] args)
	{
		int i, num_ini_mesas	= 6;
		String[] Pedido		= new String[8];
		Cliente[] Cli_Imprimir;
		Cliente[] Novos		= new Cliente[2];
		Mesa[] Mesas_Redondas	= new Mesa[num_ini_mesas];
		Comanda[] Cmd_Rest	= new Comanda[num_ini_mesas];
		Comanda Cmd_Manipular;
		Restaurante Meu_Rest	= new Restaurante("Buchinho Cheio", "Av. Ressaca, 194", Mesas_Redondas);
		
		System.out.println("______________________________________________________");
		System.out.println("Restaurante Antigo:");
		System.out.println("Nome: " + Meu_Rest.obter_nome());
		System.out.println("Endereco: " + Meu_Rest.obter_endereco());
		
		Meu_Rest.definir_nome("Buchinho Cheio Fast Food & Delivery");
		Meu_Rest.definir_endereco("Av. P. Carlos Luz, 3001");

		System.out.println("______________________________________________________");
		System.out.println("Restaurante Novo:");
		System.out.println("Nome: " + Meu_Rest.obter_nome());
		System.out.println("Endereco: " + Meu_Rest.obter_endereco());
		System.out.println("______________________________________________________");

		for(i = 0; i < num_ini_mesas; i++)
			Mesas_Redondas[i] = new Mesa();

		for(i = 0; i < num_ini_mesas; i++)
			Cmd_Rest[i] = new Comanda();

		for(i = 0; i < Mesa.obter_total_mesas(); i++)
			Mesas_Redondas[i].definir_comanda(Cmd_Rest[i]);

		Mesas_Redondas[3].reservar("26/11/2022");
		Novos[0] = new Cliente("Virginia", "virginia@teiacoltec.org");
		Novos[1] = new Cliente();
		Novos[1].definir_nome("Rita");
		Novos[1].definir_email("rita@teiacoltec.org");
		Pedido[0] = "Salada de Alface";
		Pedido[1] = "Ariticum";
		Pedido[2] = "Picanha";
		Pedido[3] = "Linguica";
		Pedido[4] = "Frango Empanado";
		Pedido[5] = "Arroz";
		Pedido[6] = "Feijao Tropeiro";
		Pedido[7] = "Buchada de Bode";
		Cmd_Manipular = Mesas_Redondas[3].obter_comanda();
		Cmd_Manipular.definir_clientes(Novos);
		Cmd_Manipular.definir_consumo(Pedido);
		Cmd_Manipular.definir_valor(100.00);
		Cli_Imprimir = Cmd_Manipular.obter_clientes();

		for(Mesa m : Mesas_Redondas)
		{
			if(m.obter_reserva())
				System.out.println("A mesa " + m.obter_num_mesa() + " esta reservada para o dia " + m.obter_data());
			else
				System.out.println("A mesa " + m.obter_num_mesa() + " nao esta reservada.");
		}

		System.out.println("______________________________________________________");
		System.out.println("Clientes da Mesa 3:");

		for(Cliente c : Cli_Imprimir)
			System.out.println("Nome: " + c.obter_nome() + "\t|\tEmail: " + c.obter_email());

		System.out.println("Itens de Consumo:");
		Cmd_Manipular.listar_consumo();
		System.out.println("Valor Total Gasto:\tR$ " + Cmd_Manipular.obter_valor());
		Cmd_Manipular.definir_valor(Cmd_Manipular.obter_valor() - Cmd_Manipular.calcular10porcento());
		System.out.println("Com Desconto de 10%:\tR$ " + Cmd_Manipular.obter_valor());
		System.out.println("Valor Por Pessoa:\tR$ " + Cmd_Manipular.dividirConta());
		System.out.println("______________________________________________________");
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
	private static int total_mesas = 0;
	private int numeroMesa;
	private String data;
	private boolean reserva;
	private Comanda Cmd;

	public Mesa()
	{
		this.numeroMesa	= Mesa.total_mesas++;
		this.reserva	= false;
	}

	public static int obter_total_mesas()
	{
		return Mesa.total_mesas;
	}

	public int obter_num_mesa()
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

	public void definir_num_mesa(int num_mesa)
	{
		this.numeroMesa = num_mesa;
	}

	public void definir_data(String nova_data)
	{
		this.data = nova_data;
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

	Cliente() {}

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
