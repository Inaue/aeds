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

		System.out.println(Resultados.moda(amostra));
	}
}

class Estatistica {
	public float moda(float[] dados) {
		return 0.0f;
	}

	public float media(float[] dados) {
		return 0.0f;
	}

	public float mediana(float[] dados) {
		return 0.0f;
	}

}
