class RecursosHumanos {
	public static void main(String[] args) {
		Data d1 = new Data((byte)9, (byte)10, (short)2022);
		Funcionario Fun_Exemplo1 = new Funcionario("Josue Jacinto de Jesus", "Marketing", 5000.00, d1, "MG-23.844.308");
		//Funcionario Fun_Exemplo2 = new Funcionario();
		Funcionario Fun_Exemplo2 = Fun_Exemplo1;
		
		Fun_Exemplo1.mostra();

		if(Fun_Exemplo1 == Fun_Exemplo2)
			System.out.println("Os funcionarios 1 e 2 sao identicos!");
		else
			System.out.println("Os funcionarios 1 e 2 nao sao identicos!");
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
		this.nome = n;
		this.departamento = dep;
		this.salario = sal;
		this.Data_Entrada = d_en;
		this.rg = r;
	}

	public void mostra() {
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

	public void definir_data(byte d, byte m, short a) {
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
	private Funcionario[] Func;

	Empresa() {
	
	}
	
	public void adicionar(Funcionario f) {
	
	}
}
