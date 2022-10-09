class TestaEmpresa {
	public static void main(String[] args) {
		Empresa Minha_Empresa = new Empresa("EasyPay Ltda.", "19.778.153/0001-88");
		Data d1 = new Data((byte)9, (byte)10, (short)2022);
		Data d2 = new Data((byte)1, (byte)10, (short)2022);
		Data d3 = new Data((byte)7, (byte)10, (short)2022);
		Data d4 = new Data((byte)20, (byte)9, (short)2022);
		Data d5 = new Data((byte)1, (byte)9, (short)2022);
		Funcionario Fun_Exemplo1 = new Funcionario("Josue Jacinto de Jesus",	"Marketing",		5000.00, d1, "MG-23.844.356");
		Funcionario Fun_Exemplo3 = new Funcionario("Jenivaldo Jordao",		"Financeiro",		5000.00, d3, "MG-23.844.308");
		Funcionario Fun_Exemplo4 = new Funcionario("Jose Jeferson",		"Juridico",		2000.00, d4, "MG-23.844.222");
		Funcionario Fun_Exemplo5 = new Funcionario("Jonathas Jirolamo Junior",	"Administrativo",	15000.00, d5, "MG-23.854.080");
		Funcionario Fun_Exemplo6 = new Funcionario("Josias Jeronimo",		"Comercial",		2500.00, d2, "MG-53.104.738");
		//Funcionario Fun_Exemplo2 = new Funcionario();
		Funcionario Fun_Exemplo2 = Fun_Exemplo1;
		
		Fun_Exemplo1.mostrar();

		if(Fun_Exemplo1 == Fun_Exemplo2)
			System.out.println("Os funcionarios 1 e 2 sao identicos!");
		else
			System.out.println("Os funcionarios 1 e 2 nao sao identicos!");

		Minha_Empresa.adicionar(Fun_Exemplo1);
		Minha_Empresa.adicionar(Fun_Exemplo3);
		Minha_Empresa.adicionar(Fun_Exemplo4);
		Minha_Empresa.adicionar(Fun_Exemplo5);
		Minha_Empresa.adicionar(Fun_Exemplo6);

		Minha_Empresa.mostrar_funcionarios();
	}
}

class Funcionario {
	private String nome;
	private String departamento;
	private double salario;
	//String data_entrada	= "05/10/2022";
	private Data Data_Entrada;
	private String rg;

	Funcionario(String n, String dep, double sal, Data d_en, String r) {
		this.nome		= n;
		this.departamento	= dep;
		this.salario		= sal;
		this.Data_Entrada	= d_en;
		this.rg			= r;
	}

	public void mostrar() {
		System.out.println("_________________________________________________________________");
		System.out.println("NOME:\t\t\t" + this.nome);
		System.out.println("DEPARTAMENTO:\t\t" + this.departamento);
		System.out.println("SALARIO (R$):\t\t" + this.salario);
		//System.out.println("DATA DE ENTRADA:\t" + this.data_entrada);
		System.out.print("DATA DE ENTRADA:\t");
		this.Data_Entrada.imprimir();
		System.out.println("\nRG:\t\t\t" + this.rg);
		System.out.println("_________________________________________________________________");
	}
}

class Data {
	private byte dia	= 01;
	private byte mes	= 01;
	private short ano	= 0001;

	Data(byte d, byte m, short a) {
		this.dia = d;
		this.mes = m;
		this.ano = a;
	}

	public void definir(byte d, byte m, short a) {
		this.dia = d;
		this.mes = m;
		this.ano = a;
	}

	public void imprimir() {
		System.out.print(this.dia + "/" + this.mes + "/" + this.ano);
	}
}

class Empresa {
	private String nome;
	private String cnpj;
	private int total_funcionarios = 0;
	private Funcionario[] Func;

	Empresa(String n, String c) {
		this.nome = n;
		this.cnpj = c;
		this.Func = new Funcionario[0];
	}
	
	public void adicionar(Funcionario f) {
		Funcionario[] Novo_Espaco;
		int i;

		if(this.total_funcionarios == this.Func.length)
		{
			Novo_Espaco = new Funcionario[this.total_funcionarios+1];
			
			for(i = 0; i < this.total_funcionarios; i++)
				Novo_Espaco[i] = this.Func[i];

			this.Func = Novo_Espaco;
		}

		this.Func[this.total_funcionarios++] = f;
	}

	public void mostrar_funcionarios() {
		System.out.println("_________________________________________________________________");
		System.out.println("Funcionarios da Empresa");

		for(Funcionario f : this.Func)
			f.mostrar();
	}
}
