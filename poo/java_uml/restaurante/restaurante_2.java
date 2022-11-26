class Teste_Restaurante
{
	public static void main(String[] args)
	{
		int i, num_ini_mesas	= 6;
		String[] Pedido_Comida	= new String[8];
		String[] Pedido_Bebida	= new String[4];
		String[] Comida_VIP	= new String[4];
		String[] Bebida_VIP	= new String[2];
		Cliente[] Cli_Imprimir;
		Cliente[] Novos		= new Cliente[2];
		Cliente[] VIPs		= new Cliente[4];
		Mesa[] Mesas_Redondas	= new Mesa[num_ini_mesas];
		Comanda[] Comer		= new Comanda_Comida[num_ini_mesas];
		Comanda[] Beber		= new Comanda_Bebida[num_ini_mesas];
		Comanda Cmd_Manipular_1, Cmd_Manipular_2;
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
			Comer[i] = new Comanda_Comida();

		for(i = 0; i < num_ini_mesas; i++)
			Beber[i] = new Comanda_Bebida();

		for(i = 0; i < Mesa.obter_total_mesas(); i++)
			Mesas_Redondas[i].definir_comida(Comer[i]);

		for(i = 0; i < Mesa.obter_total_mesas(); i++)
			Mesas_Redondas[i].definir_bebida(Beber[i]);

		Mesas_Redondas[3].reservar("26/11/2022");
		Novos[0] = new Cliente("Rita", "rita@teiacoltec.org");
		Novos[1] = new Cliente();
		Novos[1].definir_nome("Leandro");
		Novos[1].definir_email("elmaia@teiacoltec.org");
		Pedido_Comida[0] = "Salada de Alface";
		Pedido_Comida[1] = "Ariticum";
		Pedido_Comida[2] = "Picanha";
		Pedido_Comida[3] = "Linguica";
		Pedido_Comida[4] = "Frango Empanado";
		Pedido_Comida[5] = "Arroz";
		Pedido_Comida[6] = "Feijao Tropeiro";
		Pedido_Comida[7] = "Buchada de Bode";
		Pedido_Bebida[0] = "Bonafont";
		Pedido_Bebida[1] = "Limonada";
		Pedido_Bebida[2] = "Suco de Uva";
		Pedido_Bebida[3] = "Cha Gelado";
		Cmd_Manipular_1 = Mesas_Redondas[3].obter_comida();
		Cmd_Manipular_1.definir_clientes(Novos);
		Cmd_Manipular_1.definir_consumo(Pedido_Comida);
		Cmd_Manipular_1.definir_valor(100.00);
		Cmd_Manipular_2 = Mesas_Redondas[3].obter_bebida();
		Cmd_Manipular_2.definir_clientes(Novos);
		Cmd_Manipular_2.definir_consumo(Pedido_Bebida);
		Cmd_Manipular_2.definir_valor(20.00);

		Mesas_Redondas[5].reservar("03/12/2022");
		VIPs[0] = new Cliente("Virginia", "virginia@teiacoltec.org");
		VIPs[1] = new Cliente("Lucas", "lucas@teiacoltec.org");
		VIPs[2] = new Cliente("Marcio", "marcio@teiacoltec.org");
		VIPs[3] = new Cliente();
		VIPs[3].definir_nome("Humberto");
		VIPs[3].definir_email("hh@teiacoltec.org");
		Comida_VIP[0] = "Camarao";
		Comida_VIP[1] = "Caranguejo";
		Comida_VIP[2] = "Esfirra";
		Comida_VIP[3] = "Mandioca";
		Bebida_VIP[0] = "Agua Gaseificada";
		Bebida_VIP[1] = "Suco de Maracuja";
		Cmd_Manipular_1 = Mesas_Redondas[5].obter_comida();
		Cmd_Manipular_1.definir_clientes(VIPs);
		Cmd_Manipular_1.definir_consumo(Comida_VIP);
		Cmd_Manipular_1.definir_valor(70.00);
		Cmd_Manipular_2 = Mesas_Redondas[5].obter_bebida();
		Cmd_Manipular_2.definir_clientes(VIPs);
		Cmd_Manipular_2.definir_consumo(Bebida_VIP);
		Cmd_Manipular_2.definir_valor(11.00);

		for(Mesa m : Mesas_Redondas)
		{
			if(m.obter_reserva())
				System.out.println("A mesa " + m.obter_num_mesa() + " esta reservada para o dia " + m.obter_data());
			else
				System.out.println("A mesa " + m.obter_num_mesa() + " nao esta reservada.");
		}

		Cmd_Manipular_1	= Mesas_Redondas[3].obter_comida();
		Cmd_Manipular_2	= Mesas_Redondas[3].obter_bebida();
		Cli_Imprimir	= Cmd_Manipular_1.obter_clientes();

		System.out.println("______________________________________________________");
		System.out.println("Clientes da Mesa 3:");

		for(Cliente c : Cli_Imprimir)
			System.out.println("Nome: " + c.obter_nome() + "\t|\tEmail: " + c.obter_email());

		System.out.println("______________________________________________________");
		System.out.println("Itens de Consumo:");
		Cmd_Manipular_1.listar_consumo();
		Cmd_Manipular_2.listar_consumo();
		System.out.println("______________________________________________________");
		System.out.println("Valor Total Gasto\t: R$ " + (Cmd_Manipular_1.obter_valor() + Cmd_Manipular_2.obter_valor()));
		Cmd_Manipular_1.definir_valor(Cmd_Manipular_1.obter_valor() - Cmd_Manipular_1.calcular10porcento());
		Cmd_Manipular_2.definir_valor(Cmd_Manipular_2.obter_valor() - Cmd_Manipular_2.calcular10porcento());
		System.out.println("Com Desconto de 10%\t: R$ " + (Cmd_Manipular_1.obter_valor() + Cmd_Manipular_2.obter_valor()));
		System.out.println("Valor Por Pessoa\t: R$ " + (Cmd_Manipular_1.dividirConta() + Cmd_Manipular_2.dividirConta()));
		System.out.println("______________________________________________________");

		Cmd_Manipular_1	= Mesas_Redondas[5].obter_comida();
		Cmd_Manipular_2	= Mesas_Redondas[5].obter_bebida();
		Cli_Imprimir	= Cmd_Manipular_1.obter_clientes();

		System.out.println("Clientes da Mesa 5:");

		for(Cliente c : Cli_Imprimir)
			System.out.println("Nome: " + c.obter_nome() + "\t|\tEmail: " + c.obter_email());

		System.out.println("______________________________________________________");
		System.out.println("Itens de Consumo:");
		Cmd_Manipular_1.listar_consumo();
		Cmd_Manipular_2.listar_consumo();
		System.out.println("______________________________________________________");
		System.out.println("Valor Total Gasto\t: R$ " + (Cmd_Manipular_1.obter_valor() + Cmd_Manipular_2.obter_valor()));
		Cmd_Manipular_1.definir_valor(Cmd_Manipular_1.obter_valor() - Cmd_Manipular_1.calcular10porcento());
		Cmd_Manipular_2.definir_valor(Cmd_Manipular_2.obter_valor() - Cmd_Manipular_2.calcular10porcento());
		System.out.println("Com Desconto de 10%\t: R$ " + (Cmd_Manipular_1.obter_valor() + Cmd_Manipular_2.obter_valor()));
		System.out.println("Valor Por Pessoa\t: R$ " + (Cmd_Manipular_1.dividirConta() + Cmd_Manipular_2.dividirConta()));
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
	private Comanda Cmd_Comida;
	private Comanda Cmd_Bebida;

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

	public Comanda obter_comida()
	{
		return this.Cmd_Comida;
	}

	public Comanda obter_bebida()
	{
		return this.Cmd_Bebida;
	}

	public void definir_num_mesa(int num_mesa)
	{
		this.numeroMesa = num_mesa;
	}

	public void definir_data(String nova_data)
	{
		this.data = nova_data;
	}

	public void definir_comida(Comanda Nova_Comanda)
	{
		this.Cmd_Comida = Nova_Comanda;
	}

	public void definir_bebida(Comanda Nova_Comanda)
	{
		this.Cmd_Bebida = Nova_Comanda;
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

interface Lista_Produtos
{
	public double		obter_valor		();
	public String[]		obter_consumo		();
	public void		definir_consumo		(String[] consumo);
	public void		definir_valor		(double valor);
	public void		listar_consumo		();
}

abstract class Comanda implements Lista_Produtos
{
	protected double valor;
	protected String[] consumo;
	protected Cliente[] Clientes_da_Mesa;
	
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

class Comanda_Bebida extends Comanda {}

class Comanda_Comida extends Comanda {}