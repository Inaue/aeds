class Variaveis_e_Fluxo {
	public static void main(String[] args) {
		int a = 0, b = 1, c = a + b;
		int x = 13;

		System.out.println("____________________________________________________________");
		System.out.println("Exercicio 6:");
		System.out.println(a);

		while (c <= 100)
		{
			System.out.println(c);
			a = b;
			b = c;
			c = a + b;
		}

		System.out.println(c);

		System.out.println("____________________________________________________________");
		System.out.println("Exercicio 7:");
		System.out.println("Valor inicial de x: " + x);

		while (x != 1)
		{
			if((x % 2) == 0)
				x /= 2;
			else
				x = (3 * x) + 1;
			
			System.out.print(x + " -> ");
		}
		
		System.out.print('\n');
		System.out.println("____________________________________________________________");
		System.out.println("Exercicio 8:");

		x = 9;

		for (a = 0; a <= x; a++)
		{
			for (b = 1; b <= a; b++)
				System.out.print(a * b + " ");

			System.out.print('\n');
		}
		
		System.out.println("____________________________________________________________");
		System.out.println("Exercicio 9:");
		a = 0;
		b = 1;

		while (a <= 100)
		{
			System.out.println(a);
			b = a + b;
			a = b - a;
		}

		System.out.println(a);
	}
}
