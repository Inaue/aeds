class Teste_Estatistica {
	public static void main(String[] args) {
		float[] amostra		= new float[10];
		Estatistica Resultados	= new Estatistica();

		amostra[0] = 0.30f;
		amostra[1] = 0.40f;
		amostra[2] = 0.10f;
		amostra[3] = 0.15f;
		amostra[4] = 0.10f;
		amostra[5] = 0.77f;
		amostra[6] = 0.10f;
		amostra[7] = 0.10f;
		amostra[8] = 0.77f;
		amostra[9] = 0.10f;

		System.out.println(Resultados.mediana(amostra));
	}
}

class Estatistica {
	public float moda(float[] dados) {
		return 0.0f;
	}

	public float media(float[] dados) {
		float soma = 0.0f;

		for(float d : dados)
			soma += d;

		return (soma / dados.length);
	}

	public float mediana(float[] dados) {
		float[] ordem_crescente = new float[dados.length];
		float aux;
		int i = 0, j, centro;

		for(float d : dados)
			ordem_crescente[i++] = d;

		for(i = 0; i < ordem_crescente.length; i++)
		{
			for(j = ordem_crescente.length-1; j > i; j--)
			{
				if(ordem_crescente[j] < ordem_crescente[j-1])
				{
					aux = ordem_crescente[j];
					ordem_crescente[j] = ordem_crescente[j-1];
					ordem_crescente[j-1] = aux;
				}
			}
		}

		centro = (ordem_crescente.length / 2);
		if((ordem_crescente.length % 2) == 0)
			return ((ordem_crescente[centro] + ordem_crescente[centro+1]) / 2);
		else
			return ordem_crescente[centro];
	}

}
