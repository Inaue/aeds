class TestaEmpresa {
	public static void main(String[] args) {
		Empresa Minha_Empresa = new Empresa("EasyPay Ltda.", "19.778.153/0001-88");
		Data d1 = new Data((byte)9, (byte)10, (short)2022);
		Data d2 = new Data((byte)29, (byte)2, (short)2021);//ESTA DATA NAO VAI FUNCIONAR (data padrao = 1/1/1)
		Data d3 = new Data((byte)7, (byte)10, (short)2022);
		Data d4 = new Data((byte)20, (byte)9, (short)2022);
		Data d5 = new Data((byte)1, (byte)9, (short)2022);
		Data d6 = new Data();
		Funcionario Fun_Exemplo1 = new Funcionario("Josue Jacinto de Jesus",	"Marketing",		5000.00, d1, "MG-21.845.356");
		Funcionario Fun_Exemplo3 = new Funcionario("Jenivaldo Jordao",		"Financeiro",		5000.00, d3, "MG-84.896.381");
		Funcionario Fun_Exemplo4 = new Funcionario("Jose Jeferson",		"Juridico",		2000.00, d4, "MG-77.811.222");
		Funcionario Fun_Exemplo5 = new Funcionario("Jonathas Jirolamo Junior",	"Administrativo",	15000.00, d5, "MG-03.854.080");
		Funcionario Fun_Exemplo6 = new Funcionario("Josias Jeronimo",		"Comercial",		2500.00, d2, "MG-53.104.738");
		Funcionario Fun_Exemplo7 = new Funcionario("Julia Jaqueline Jackson");
		//Funcionario Fun_Exemplo7 = new Funcionario();
		//Funcionario Fun_Exemplo2 = new Funcionario();
		Funcionario Fun_Exemplo2 = Fun_Exemplo1;
		
		Fun_Exemplo1.mostrar();

		if(Fun_Exemplo1 == Fun_Exemplo2)
			System.out.println("Os funcionarios 1 e 2 sao identicos!");
		else
			System.out.println("Os funcionarios 1 e 2 nao sao identicos!");

		d6.definir((byte)1, (byte)9, (short)2022);
		Fun_Exemplo7.definir_departamento("Administrativo");
		Fun_Exemplo7.definir_salario(15000.00);
		Fun_Exemplo7.definir_entrada(d6);
		Fun_Exemplo7.definir_rg("MG-90.789.314");
		Minha_Empresa.adicionar(Fun_Exemplo1);
		Minha_Empresa.adicionar(Fun_Exemplo3);
		Minha_Empresa.adicionar(Fun_Exemplo4);
		Minha_Empresa.adicionar(Fun_Exemplo5);
		Minha_Empresa.adicionar(Fun_Exemplo6);
		Minha_Empresa.adicionar(Fun_Exemplo7);
		Minha_Empresa.mostrar_funcionarios();
		System.out.println("A empresa " + Minha_Empresa.obter_nome() + " possui " + Minha_Empresa.quantos_funcionarios() + " funcionarios!");
	}
}

class Funcionario {
	private static int total_funcionarios = 0;
	private int identificador;
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
		this.identificador	= ++total_funcionarios;
	}

	Funcionario(String n) {
		this.nome = n;
		this.identificador = ++total_funcionarios;
	}

	Funcionario() {
		this.identificador = ++total_funcionarios;
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
		System.out.println("IDENTIFICADOR:\t\t" + this.identificador);
		System.out.println("_________________________________________________________________");
	}

	public void definir_nome(String n)
	{
		this.nome = n;
	}

	public void definir_departamento(String d)
	{
		this.departamento = d;
	}

	public void definir_salario(double s)
	{
		this.salario = s;
	}
	
	public void definir_entrada(Data d_en)
	{
		this.Data_Entrada = d_en;
	}

	public void definir_rg(String r)
	{
		this.rg = r;
	}

	public String obter_nome()
	{
		return this.nome;
	}

	public String obter_departamento()
	{
		return this.departamento;
	}

	public double obter_salario()
	{
		return this.salario;
	}
	
	public Data obter_entrada()
	{
		return this.Data_Entrada;
	}

	public String obter_rg()
	{
		return this.rg;
	}

	public int obter_id()
	{
		return this.identificador;
	}
}

class Data {
	private byte dia	= 01;
	private byte mes	= 01;
	private short ano	= 0001;

	Data(byte d, byte m, short a) {
		this.definir(d, m, a);
	}

	Data() {}

	public boolean definir(byte d, byte m, short a) {
		boolean data_valida	= true;
		boolean bissexto	= ((a % 400) == 0) || (((a % 4) == 0) && ((a % 100) != 0));

		data_valida = data_valida && (d >= 1) && (d <= 31);	//DIA PODE EXISTIR
		data_valida = data_valida && (m >= 1) && (m <= 12);	//MES EXISTE

		data_valida = data_valida && !(	(m < 8) &&
						((m % 2) == 0) &&
						(d == 31)	);	//MESES COM SOMENTE 30 DIAS

		data_valida = data_valida && !(	(m > 8) &&(
						(m % 2) == 1) &&
						(d == 31)	);	//MESES COM SOMENTE 30 DIAS

		data_valida = data_valida && !((m == 2) && (d > 29));	//FEVEREIRO

		data_valida = data_valida && !(	!bissexto &&
						(m == 2) &&
						(d > 28)	);	//ANO NAO_BISSEXTO

		if(data_valida)
		{
			this.dia = d;
			this.mes = m;
			this.ano = a;
		}

		return data_valida;
	}

	public void imprimir() {
		System.out.print(this.dia + "/" + this.mes + "/" + this.ano);
	}

	public byte obter_dia() {
		return this.dia;
	}

	public byte obter_mes() {
		return this.mes;
	}

	public short obter_ano() {
		return this.ano;
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

	public int quantos_funcionarios() {
		return this.total_funcionarios;
	}

	public String obter_nome() {
		return this.nome;
	}

	public void mostrar_funcionarios() {
		System.out.println("_________________________________________________________________");
		System.out.println("Funcionarios da Empresa " + this.nome);

		for(Funcionario f : this.Func)
			f.mostrar();
	}
}
