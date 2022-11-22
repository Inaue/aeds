class Teste_Area
{
	public static void main(String[] args)
	{
		AreaCalculavel[] Areas_de_Exemplo = new AreaCalculavel[3];
		int a;

		Quadrado q	= new Quadrado();
		Retangulo r	= new Retangulo();
		Circulo c	= new Circulo();

		Areas_de_Exemplo[0] = q;
		Areas_de_Exemplo[1] = r;
		Areas_de_Exemplo[2] = c;

		q.definir_lado(1.5);
		r.definir_lados(3, 4);
		c.definir_raio(8.7);

		for(a = 0; a <  Areas_de_Exemplo.length; a++)
			System.out.println("Area " + a + " mede " + Areas_de_Exemplo[a].calcula_area());
	}
}

interface AreaCalculavel
{
	double calcula_area();
}

class Quadrado implements AreaCalculavel
{
	public double lado;

	public void definir_lado(double lado)
	{
		this.lado = lado;
	}

	@Override
	public double calcula_area()
	{
		return (this.lado * this.lado);
	}
}

class Retangulo implements AreaCalculavel
{
	public double lado1;
	public double lado2;

	public void definir_lados(double l1, double l2)
	{
		this.lado1 = l1;
		this.lado2 = l2;
	}

	@Override
	public double calcula_area()
	{
		return (this.lado1 * this.lado2);
	}
}

class Circulo implements AreaCalculavel
{
	public double raio;

	public void definir_raio(double raio)
	{
		this.raio = raio;
	}

	@Override
	public double calcula_area()
	{
		return (this.raio * this.raio * Math.PI);
	}
}
