using System;

public class Prova
{
	public static void Main()
	{
		int id = 0, ft_mudar = 1;
		string email_user;
		InstaPet Site = new InstaPet();
		Usuario[] Usuarios_Site;
		Fotos[] Fotos_Usuario;
		Fotos teste = new Fotos("http", "nada.");

		//code
	}
}

class Fotos {
	private string url;
	private string descricao;
	
	/*public Fotos(string url, string descricao) {
		this.url	= url;
		this.descricao	= descricao;
	}

	public void definir_descricao(string descricao) {
		this.descricao	= descricao;
	}

	public void definir_url(string url) {
		this.url	= url;
	}

	public string obter_descricao() {
		return this.descricao;
	}

	public string obter_url() {
		return this.url;
	}*/
}

class Usuario {
	private string nome;
	private string email;
	//private Fotos[] Fotos_Pet = new Fotos[0];

	Usuario(string nome, string email) {
		this.nome	= nome;
		this.email	= email;
	}

	public string obter_nome() {
		return this.nome;
	}

	public string obter_email() {
		return this.email;
	}

	public void cadastra_foto(string link, string desc) {
	}

	public void altera_descricao(int n, string desc) {
	}
}

class InstaPet {
	public void cadastra_usuario(string nome, string email) {
	}
	
	public void cadastra_foto(string email, string link, string desc) {
	}

	public int qnt_pets(string email) {
		return 0;
	}

	public int qnt_usuarios() {
		return 0;
	}

	public Fotos[] listar_pets(string email) {
		return null;
	}

	public Usuario[] listar_usuarios() {
		return null;
	}

	public void altera_descricao(string email, int n, string desc) {
	}
}
