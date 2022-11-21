import java.util.Scanner;

class Teste_Pessoa
{
	public static void main(String[] args)
	{
		Scanner Entrada = new Scanner(System.in);
		Agenda a;

		System.out.println("Digite o numero de pessoas na agenda:");
		a = new Agenda(Entrada.nextInt());
		System.out.println("Ha " + a.qnt_conhecidos() + " conhecidos em sua agenda");
		System.out.println("Ha " + a.qnt_amigos() + " amigos em sua agenda");
		a.addInformacoes();
		a.imprimeAniversario();
		a.imprimeEmails();
	}
}

class Pessoa
{
	protected String nome;
	protected int idade;

	public String obter_info()
	{
		return "";
	}

	public void definir_info(String s) {}

	public Pessoa()
	{
		this.nome = "indefinido";
		this.idade = 0;
	}

	public Pessoa(String n, int i)
	{
		this.nome = n;
		this.idade = i;
	}

	public String obter_nome()
	{
		return this.nome;
	}

	public int obter_idade()
	{
		return this.idade;
	}

	public void definir_nome(String n)
	{
		this.nome = n;
	}

	public void definir_idade(int i)
	{
		this.idade = i;
	}
}

class Amigo extends Pessoa
{
	private String data_de_aniversario;

	public Amigo()
	{
		this.data_de_aniversario = "indefinido";
	}

	@Override
	public String obter_info()
	{
		return this.data_de_aniversario;
	}

	@Override
	public void definir_info(String s)
	{
		this.data_de_aniversario = s;
	}

}

class Conhecido extends Pessoa
{
	private String email;

	public Conhecido()
	{
		this.email = "indefinido";
	}

	@Override
	public String obter_info()
	{
		return this.email;
	}

	@Override
	public void definir_info(String s)
	{
		this.email = s;
	}

}

class Agenda
{
	private int total_amigos;
	private int total_conhecidos;
	private Pessoa[] Agendadas;

	public Agenda(int pessoas)
	{
		int p;

		this.total_amigos	= 0;
		this.total_conhecidos	= 0;
		this.Agendadas		= new Pessoa[pessoas];
		
		for(p = 0; p < pessoas; p++)
		{
			if((1 + (int)(Math.random() * 2)) == 1)
				this.total_amigos++;
			else
				this.total_conhecidos++;
		}

		p = 0;

		while(p < this.total_amigos)
			this.Agendadas[p++] = new Amigo();

		while(p < this.Agendadas.length)
			this.Agendadas[p++] = new Conhecido();
	}

	public int qnt_amigos()
	{
		return this.total_amigos;
	}

	public int qnt_conhecidos()
	{
		return this.total_conhecidos;
	}

	public Pessoa[] obter_pessoas()
	{
		return this.Agendadas;
	}

	public void addInformacoes()
	{
		int a, c;
		Scanner Entrada = new Scanner(System.in);

		for(a = 0; a < this.total_amigos; a++)
		{
			System.out.println("________________________________");
			System.out.println("INFORMACOES DO AMIGO " + a);
			System.out.println("Digite seu nome:");
			this.Agendadas[a].definir_nome(Entrada.next());
			System.out.println("Digite sua idade:");
			this.Agendadas[a].definir_idade(Entrada.nextInt());
			System.out.println("Digite sua data de aniversario (dd/mm/yyyy):");
			this.Agendadas[a].definir_info(Entrada.next());
			System.out.println("________________________________");
		}

		for(c = a; c < this.Agendadas.length; c++)
		{
			System.out.println("________________________________");
			System.out.println("INFORMACOES DO CONHECIDO " + c);
			System.out.println("Digite seu nome:");
			this.Agendadas[c].definir_nome(Entrada.next());
			System.out.println("Digite sua idade:");
			this.Agendadas[c].definir_idade(Entrada.nextInt());
			System.out.println("Digite seu email:");
			this.Agendadas[c].definir_info(Entrada.next());
			System.out.println("________________________________");
		}
	}

	public void imprimeAniversario()
	{
		int a;

		System.out.println("________________________________");
		System.out.println("ANIVERSARIOS NA AGENDA:");

		for(a = 0; a < this.total_amigos; a++)
			System.out.println(this.Agendadas[a].obter_info());

		System.out.println("________________________________");
	}

	public void imprimeEmails()
	{
		int c;

		System.out.println("________________________________");
		System.out.println("EMAILS NA AGENDA:");

		for(c = this.total_amigos; c < this.Agendadas.length; c++)
			System.out.println(this.Agendadas[c].obter_info());

		System.out.println("________________________________");
	}
}
