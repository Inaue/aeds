class TrianguloPascal {
	public static void main(String[] args) {
		int i, j, n = 17;
		int[][] triangulo = new int[n][n];
		
		for(int[] linha : triangulo)
			linha[0] = 1;

		for(i = 1; i < n; i++)
		{
			for(j = 1; j <= i; j++)
				triangulo[i][j] = triangulo[i-1][j-1] + triangulo[i-1][j];
		}

		System.out.println("Estas sao as " + n + " primeiras linhas do triangulo de pascal:");

		for(int[] linha : triangulo)
		{
			for(int celula : linha)
			{
				if(celula == 0)
					break;

				System.out.print(celula + "\t");
			}

			System.out.print('\n');
		}
	}
}
