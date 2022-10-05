class RecursosHumanos {
	public static void main(String[] args) {
		Funcionario Fun_Exemplo1 = new Funcionario();
		//Funcionario Fun_Exemplo2 = new Funcionario();
		Funcionario Fun_Exemplo2 = Fun_Exemplo1;
		
		Fun_Exemplo1.definir_data_entrada((byte)05, (byte)10, (short)2022);
		Fun_Exemplo1.mostra();

		if(Fun_Exemplo1 == Fun_Exemplo2)
			System.out.println("Os funcionarios 1 e 2 sao identicos!");
		else
			System.out.println("Os funcionarios 1 e 2 nao sao identicos!");
	}
}

class Funcionario {
	String nome		= "Josue Jacinto de Jesus";
	String departamento	= "Marketing";
	double salario		= 5000.00;
	//String data_entrada	= "05/10/2022";
	Data Data_Entrada	= new Data();
	String rg		= "MG-23.844.308";

	void mostra() {
		System.out.println("_________________________________________________________________");
		System.out.println("NOME:\t\t\t" + this.nome);
		System.out.println("DEPARTAMENTO:\t\t" + this.departamento);
		System.out.println("SALARIO (R$):\t\t" + this.salario);
		//System.out.println("DATA DE ENTRADA:\t" + this.data_entrada);
		System.out.println("DATA DE ENTRADA:\t" + this.Data_Entrada.dia + "/" + this.Data_Entrada.mes + "/" + this.Data_Entrada.ano);
		System.out.println("RG:\t\t\t" + this.rg);
		System.out.println("_________________________________________________________________");
	}

	void definir_data_entrada(byte d, byte m, short a) {
		this.Data_Entrada.dia = d;
		this.Data_Entrada.mes = m;
		this.Data_Entrada.ano = a;
	}
}

class Data {
	byte dia	= 01;
	byte mes	= 01;
	short ano	= 0001;
}
