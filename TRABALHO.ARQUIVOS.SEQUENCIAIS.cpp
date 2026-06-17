
// NOME: NATAN DE PAULO GONÇALVES TORRES

	// RA: 2511551211

		// 2 ADS / TURMA 2

			// GITHUB: Natan-Torres-cyber 

#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

struct cidades{
	int codigo;
	char nome[30];
	char UF[2];
};

struct clientes{
	int codigo;
	char nome[30];
	char endereco[30];
	char telefone[15];
	int codigo_cidade;
};

struct veiculos{
	char placa[8];
	char modelo[20];
	char marca[15];
	int ano;
	int codigo_cliente;
};

struct servicos{
	int codigo;
	char descricao[50];
	float valor_mao_de_obra;
};

struct pecas{
	int codigo;
	char descricao[50];
	int quant_estoque;
	int estoque_minimo;
	int estoque_maximo;
	float preco_unitario;
};

struct mecanicos{
	int codigo;
	char nome[30];
	char especialidade[30];
	char telefone[15];
};

struct ordem_de_servico{
	int codigo;
	char placa_veiculo[10];
	int codigo_mecanico;
	char data[10];
	int codigo_servico;
	int codigo_peca;
	int quantidade_peca;
};

// 1 -
void ler_cidades(cidades cidade[], int qtdCidades){
	for (int i = 0; i < qtdCidades; i++){
        cout << "\nCodigo da Cidade " << (i+1) << ": "<< cidade[i].codigo;
        
        cout << "\nNome: "<< cidade[i].nome;
        
        cout << "\nEstado: "<<cidade[i].UF<< endl;
	}
}

// 2 -
void ler_servicos(servicos servico[], int qtdServicos){
	for (int i = 0; i < qtdServicos; i++){
        cout << "\nCodigo do Servico " <<i+1<< ": "<< servico[i].codigo;
         
        cout << "\nDescricao: "<<servico[i].descricao;
        
        cout << "\nValor Mao de Obra: "<< servico[i].valor_mao_de_obra << endl;  
	}
}

// 3 -
void ler_pecas(pecas peca[], int contPeca){
	for (int i = 0; i < contPeca; i++){
        cout << "\nCodigo da Peca " << (i+1) << ": "<<peca[i].codigo; 
		    
        cout << "\nDescricao: "<<peca[i].descricao;
        
        cout << "\nQuantidade em Estoque: "<<peca[i].quant_estoque;
 
        cout << "\nEstoque Minimo: "<<peca[i].estoque_minimo;

        cout << "\nEstoque Maximo: "<<peca[i].estoque_maximo;
   
        cout << "\nPreco Unitario: "<<peca[i].preco_unitario<< endl;
    
	}
}

// Escreva uma funcao para permitir a inclusao de novos registros na tabela de Clientes.
// O programa devera garantir que o codigo do cliente a ser inserido não existe na tabela de Clientes.
// Quando o usuario digitar o codigo da cidade, o programa devera buscar este codigo na tabela de Cidades e exibir o nome da cidade e UF.

// 4 - 
void inc_clientes(clientes cliente[], int qtdCliente, int &contCliente, cidades cidade[], int qtdCidades){ 
	
	if(qtdCidades == 0){
		cout<<"\n*** Nao ha cidades encontradas. Cadastre uma cidade antes para permitir a inclusao de um cliente! ***"<< endl;
		return;
	}
	
	for (int i = 0; i < qtdCliente; i++){
			
		clientes novoCliente;
		int validacao = 0, cod_encontrado = 0;
		
		cout << "\nINCLUSAO DO CLIENTE " << i+1 << ": ";
		
		do{
			cout << "\nCodigo do Cliente: ";
			cin >> cod_encontrado;
			
			int j = 0, f = contCliente - 1;
			int achou = 0;
			
			if (contCliente > 0){
				int m = (j + f) / 2;
				
				for (; f >= j && cod_encontrado != cliente[m].codigo; m = (j + f) / 2){
					if (cod_encontrado > cliente[m].codigo)
						j = m + 1;
					else
						f = m - 1;
				}
				
				if (f >= j && cod_encontrado == cliente[m].codigo)
					achou = 1;
			}
			
			if (achou == 1){
				cout << "\nEsse codigo ja existe. Tente novamente.";
				validacao = 0;
			}
			else{
				novoCliente.codigo = cod_encontrado;
				validacao = 1;
			}
			
		} while (validacao == 0);
		
		cin.ignore();
		
		cout << "Nome do Cliente: ";
		cin.getline(novoCliente.nome, 30);
		
		cout << "Endereco do Cliente: ";
		cin.getline(novoCliente.endereco, 30);
		
		cout << "Telefone do Cliente: ";
		cin.getline(novoCliente.telefone, 15);
		
		cout << "Codigo da Cidade do Cliente: ";
		cin >> novoCliente.codigo_cidade;
		
		
		int inicio = 0, fim = qtdCidades - 1;
		int cidadeEncontrada = 0;
		
		if (qtdCidades > 0){
			int meio = (inicio + fim) / 2;
			
			for (; fim >= inicio && novoCliente.codigo_cidade != cidade[meio].codigo; meio = (inicio + fim) / 2){
				if (novoCliente.codigo_cidade > cidade[meio].codigo)
					inicio = meio + 1;
				else
					fim = meio - 1;
			}
			
			if (fim >= inicio && novoCliente.codigo_cidade == cidade[meio].codigo){
				cout << "\nCidade: " << cidade[meio].nome;
				cout << "\nEstado: " << cidade[meio].UF;
				cidadeEncontrada = 1;
			}
			else{
				cidadeEncontrada = 0;
			}
		}
		
		if (cidadeEncontrada == 1){
			int aux;
			
			for (aux = contCliente; aux > 0 && cliente[aux - 1].codigo > novoCliente.codigo; aux--){
				cliente[aux] = cliente[aux - 1];
			}
			
			cliente[aux].codigo = novoCliente.codigo;

			strcpy(cliente[aux].nome, novoCliente.nome);

			strcpy(cliente[aux].endereco, novoCliente.endereco);

			strcpy(cliente[aux].telefone, novoCliente.telefone);

			cliente[aux].codigo_cidade = novoCliente.codigo_cidade;
			
			contCliente++;
			
			cout << "\nCliente cadastrado com sucesso!"<< endl;
		}
		else{
			cout << "\nCidade nao encontrada. Cliente nao cadastrado.";
		}
	}
}

// Escreva uma funcao para permitir a inclusao de novos registros na tabela de Veiculos.
// O programa devera garantir que a placa do veiculo a ser inserido nao existe na tabela de Veiculos.
// Quando o usuario digitar o codigo do cliente, o programa devera buscar este codigo na tabela de Clientes e exibir o nome do cliente.

// 5 -
void inc_veiculos(veiculos veiculo[], int qtdVeiculo, int &contVeiculo, clientes cliente[], int qntCliente, int contCliente){
	
	if(contCliente == 0){
		cout<<"\n*** Nao ha clientes encontrados. Cadastre um cliente antes para permitir a inclusao de um veiculo! ***"<< endl;
		return;
	}
	
	for (int i = 0; i < qtdVeiculo; i++){
		
		veiculos novoVeiculo;
		int validacao = 0;
		char placa_encontrada[8];
		
		cout << "\nINCLUSAO DO VEICULO " << i+1 << " ";
		
		do{
			cout << "\nPlaca do Veiculo: ";
			cin >> placa_encontrada;	
			
			int j = 0, f = contVeiculo - 1;
			int achou = 0;
			
			if (contVeiculo > 0){
				int m = (j + f) / 2;
				
				for (; f >= j && strcmp(placa_encontrada, veiculo[m].placa) != 0; m = (j + f) / 2){
					if (strcmp(placa_encontrada, veiculo[m].placa) > 0)
						j = m + 1;
					else
						f = m - 1;
				}
				
				if (f >= j && strcmp(placa_encontrada, veiculo[m].placa) == 0)
					achou = 1;
			}
			
			if (achou == 1){
				cout << "\nEsse codigo ja existe. Tente novamente."<< endl;
				validacao = 0;
			}
			else{
				strcpy(novoVeiculo.placa, placa_encontrada);
				validacao = 1;
			}
			
		} while (validacao == 0);
		
		
		
		cin.ignore();
		
		cout << "Modelo do Veiculo: ";
		cin.getline(novoVeiculo.modelo, 20);
		
		cout << "Marca do Veiculo: ";
		cin.getline(novoVeiculo.marca, 15);
		
		cout << "Ano do Veiculo: ";
		cin >> novoVeiculo.ano;
		
		cout << "Codigo do Cliente do Veiculo: ";
		cin >> novoVeiculo.codigo_cliente;
		
		
		int inicio = 0, fim = qntCliente - 1;
		int clienteEncontrado = 0;
		
		if (qntCliente > 0){
			int meio = (inicio + fim) / 2;
			
			for (; fim >= inicio && novoVeiculo.codigo_cliente != cliente[meio].codigo; meio = (inicio + fim) / 2){
				if (novoVeiculo.codigo_cliente > cliente[meio].codigo)
					inicio = meio + 1;
				else
					fim = meio - 1;
			}
			
			if (fim >= inicio && novoVeiculo.codigo_cliente == cliente[meio].codigo){
				cout << "\nCliente: " << cliente[meio].nome;
				clienteEncontrado = 1;
			}
		}
		
		if (clienteEncontrado == 1){
			int aux;
			
			for (aux = contVeiculo; aux > 0 && strcmp(veiculo[aux - 1].placa, novoVeiculo.placa) > 0; aux--){
				veiculo[aux] = veiculo[aux - 1];
			}
			
			strcpy(veiculo[aux].placa, novoVeiculo.placa);

			strcpy(veiculo[aux].modelo, novoVeiculo.modelo);

			strcpy(veiculo[aux].marca, novoVeiculo.marca);

			veiculo[aux].ano = novoVeiculo.ano;

			veiculo[aux].codigo_cliente = novoVeiculo.codigo_cliente;
			
			contVeiculo++;
			
			cout << "\nVeiculo cadastrado com sucesso!"<< endl;
		}
		else{
			cout << "\nCliente nao encontrado. Veiculo nao cadastrado."<< endl;
		}
	}
}

// 6 -
void inc_mecanicos(mecanicos mecanico[], int qtdMecanico, int &contMecanico){
	
	for(int i = 0; i < qtdMecanico; i++){
		
		mecanicos novoMecanico;
		int validacao = 0, cod_digitado = 0;
	
		cout<<"\nINCLUSAO DO MECANICO "<<i+1<<": "<< endl;
		
		do{
			cout<<"Codigo do Mecanico: ";
			cin>>cod_digitado;
			
			int j = 0, f = contMecanico - 1;
			int achou = 0;
			
			if(contMecanico > 0){
				int m = (j + f) / 2;
				for(; f >= j && cod_digitado != mecanico[m].codigo; m =  (j + f) / 2){
					if(cod_digitado > mecanico[m].codigo){
						j = m + 1;
					}
					else{
						f = m - 1;
					}
				}
				 if(f >= j && cod_digitado == mecanico[m].codigo){
					achou = 1;
				}
			}
			if(achou == 1){	
				cout<<"Esse codigo ja existe. Tente Novamente."<< endl;
				validacao = 0;
				}
			else{
				novoMecanico.codigo = cod_digitado;
				validacao = 1;	
				}
			}
		while (validacao == 0);	
		
		cin.ignore();
				
		cout << "Nome: ";
		cin.getline(novoMecanico.nome, 30);		
			
		cout << "Especialidade: ";
		cin.getline(novoMecanico.especialidade, 30);
				
		cout << "Telefone: ";
		cin.getline(novoMecanico.telefone, 15);
		
		int aux;
		
		for (aux = contMecanico; aux > 0 && mecanico[aux - 1].codigo > novoMecanico.codigo; aux--){
			mecanico[aux] = mecanico[aux - 1];
		}
			
		mecanico[aux].codigo = novoMecanico.codigo;			
		strcpy(mecanico[aux].nome, novoMecanico.nome);			
		strcpy(mecanico[aux].especialidade, novoMecanico.especialidade);			
		strcpy(mecanico[aux].telefone, novoMecanico.telefone);
		
		contMecanico++;
		
		cout<<"\nMecanico Cadastrado com Sucesso."<< endl;						
		}
	}
	
// 7 -
void abrir_ordem_servico(ordem_de_servico ordem_servico[], int qtdOrdens, int &contOrdens, veiculos veiculo[], int qtdVeiculo, int contVeiculo, pecas peca[], int contPeca,
mecanicos mecanico[], int contMecanico, servicos servico[], int contServico, clientes cliente[], int contCliente){
	for(int i = 0; i < qtdOrdens; i++){
		
		if(contServico == 0){
			cout<<"\nVoce ainda nao possui dados de nenhum servico. Registre um servico para ser possivel abrir uma ordem de servico."<< endl;
			return;
		}
		
		if(contPeca == 0){
			cout<<"\nVoce ainda nao possui dados de nenhuma peca. Registre uma peca para ser possivel abrir uma ordem de servico."<< endl;
			return;
		}
		
		if(contCliente == 0){
			cout<<"\nVoce ainda nao possui dados de nenhum cliente. Registre um cliente para ser possivel abrir uma ordem de servico."<< endl;
			return;
		}
		
		if(contVeiculo == 0){
			cout<<"\nVoce ainda nao possui dados de nenhum veiculo. Registre um veiculo para ser possivel abrir uma ordem de servico."<< endl;
			return;
		}
		
		if(contMecanico == 0){
			cout<<"\nVoce ainda nao possui dados de nenhum mecanico. Registre um mecanico para ser possivel abrir uma ordem de servico."<< endl;
			return;
		}
		
		ordem_de_servico novaOrdem;
		int aux = contOrdens;
		int validacao = 0;
		
		cout<<"Abertura da OS Nº "<<i+1<<": "<< endl;
		
		do{
			int achou = 0;
			
			cout<<"Codigo da OS: ";
			cin>>novaOrdem.codigo;
		
			int inicio = 0, fim = contOrdens - 1;
			int meio = (inicio + fim) / 2;
			for(; fim >= inicio && novaOrdem.codigo != ordem_servico[meio].codigo; meio = (inicio + fim) / 2){
				if (novaOrdem.codigo > ordem_servico[meio].codigo){
					inicio = meio + 1;
				}
				else{
					fim = meio - 1;
				}	
			}
			
			if(fim >= inicio && novaOrdem.codigo == ordem_servico[meio].codigo){
					achou = 1;
				}
				
			if(achou == 1){
				cout<<"Esse codigo ja existe. Tente um codigo novo!"<< endl;
				validacao = 0;
			}
			else{
				validacao = 1;
			}
			
		} while(validacao == 0);
		
		cout<<"Placa do Veiculo: ";
		cin>>novaOrdem.placa_veiculo;
		
		int inicio = 0, fim = contVeiculo - 1;
		int meio = (inicio + fim) / 2;
			
		for (; fim >= inicio && strcmp(novaOrdem.placa_veiculo, veiculo[meio].placa) != 0; meio = (inicio + fim) / 2){
			if (strcmp(novaOrdem.placa_veiculo, veiculo[meio].placa) > 0)
				inicio = meio + 1;
			else
				fim = meio - 1;
		}
		
			
		if (fim >= inicio && strcmp(novaOrdem.placa_veiculo, veiculo[meio].placa) == 0){
			cout << "Modelo do Veiculo: " << veiculo[meio].modelo;
			for(int x = 0; x < contVeiculo; x++){
				if(veiculo[meio].codigo_cliente == cliente[x].codigo){
					cout<<"\nNome do Cliente: " << cliente[x].nome;
				}
			}	
		}
		else{
			cout<<"\nVeiculo Nao Encontrado."<< endl;
			return;
		}
		
		inicio = 0; fim = contMecanico - 1;
		meio = (inicio + fim) / 2;
		cout<<"\nCodigo do Mecanico: ";
		cin>>novaOrdem.codigo_mecanico;
		for (; fim >= inicio && novaOrdem.codigo_mecanico != mecanico[meio].codigo; meio = (inicio + fim) / 2){
			if (novaOrdem.codigo_mecanico > mecanico[meio].codigo)
				inicio = meio + 1;
			else
				fim = meio - 1;
		}
			
		if (fim >= inicio && novaOrdem.codigo_mecanico == mecanico[meio].codigo){
			cout << "Nome do Mecanico: " << mecanico[meio].nome;
			cout <<	" || Especialidade do Mecanico: " << mecanico[meio].especialidade;
		}
		else{
			cout<<"\nMecanico Nao Encontrado."<< endl;
			return;
		}
		
		cout << "\nData Abertura OS: ";
		cin >> novaOrdem.data;
		
		inicio = 0, fim = contServico - 1;
		meio = (inicio + fim) / 2;
		
		cout << "\nCodigo do Servico: ";
		cin >>	novaOrdem.codigo_servico;
		for (; fim >= inicio && novaOrdem.codigo_servico != servico[meio].codigo; meio = (inicio + fim) / 2){
			if (novaOrdem.codigo_servico > servico[meio].codigo)
				inicio = meio + 1;
			else
				fim = meio - 1;
		}
			
		if (fim >= inicio && novaOrdem.codigo_servico == servico[meio].codigo){
			cout << "Descricao do Servico: " << servico[meio].descricao;
			cout <<	" || Valor da Mao de Obra do Servico: " << servico[meio].valor_mao_de_obra;
		}
		else{
			cout<<"\\nServico Nao Encontrado."<< endl;
			return;
		}
		
		inicio = 0, fim = contPeca - 1;
		meio = (inicio + fim) / 2;
		cout << "\nCodigo da Peca: ";
		cin >> novaOrdem.codigo_peca;
		for (; fim >= inicio && novaOrdem.codigo_peca != peca[meio].codigo; meio = (inicio + fim) / 2){
			if (novaOrdem.codigo_peca > peca[meio].codigo)
				inicio = meio + 1;
			else
				fim = meio - 1;
		}
		
		int indice_peca = -1;	
		if (fim >= inicio && novaOrdem.codigo_peca == peca[meio].codigo){
			cout << "Descricao da Peca: " << peca[meio].descricao;
			indice_peca = meio;
		}
		else{
			cout<<"\nPeca Nao Encontrada."<< endl;
			return;
		}
		
		int opcao = 0;
		int seguir = 0;
		
		do{

		    cout << "\nQuantidade de Pecas: ";
    		cin >> novaOrdem.quantidade_peca;

    		if(novaOrdem.quantidade_peca <= peca[indice_peca].quant_estoque){

        		peca[indice_peca].quant_estoque =
        		peca[indice_peca].quant_estoque - novaOrdem.quantidade_peca;

		        seguir = 1;
    		}
    		else{

        		cout << "\nERRO!";
        		cout << "\nEstoque Disponivel: "<< peca[indice_peca].quant_estoque<< endl;

        		cout << "\n1 - Informar Nova Quantidade";
        		cout << "\n2 - Cancelar OS";
        		cout << "\nOpcao: ";
        		cin >> opcao;

        		if(opcao == 2){
           		 return;
       		 }
   		 }

		}while(seguir == 0);
		
		for(aux = contOrdens; aux > 0 && ordem_servico[aux - 1].codigo > novaOrdem.codigo; aux--){
    		ordem_servico[aux] = ordem_servico[aux - 1];
		}
		
		ordem_servico[aux].codigo = novaOrdem.codigo;
		strcpy(ordem_servico[aux].placa_veiculo, novaOrdem.placa_veiculo);
		ordem_servico[aux].codigo_mecanico = novaOrdem.codigo_mecanico;
		strcpy(ordem_servico[aux].data, novaOrdem.data);
		ordem_servico[aux].codigo_servico = novaOrdem.codigo_servico;
		ordem_servico[aux].codigo_peca = novaOrdem.codigo_peca;
		ordem_servico[aux].quantidade_peca = novaOrdem.quantidade_peca;
		contOrdens++;
	}
}

// 8 - 
void consulta_pecas(pecas peca[], int qtdPeca, int contPeca){
    int cod_peca;
    int validacao = 0;

    cout << "\nPECAS DISPONIVEIS:";

    for(int i = 0; i < contPeca; i++){
        cout << "\nCodigo: " << peca[i].codigo;
        cout << " - Descricao: " << peca[i].descricao;
    }
    
    for(int y = 0; y < qtdPeca; y++){
    	do{
    	
        cout << "\n\nDigite o codigo da peca que deseja consultar: ";
        cin >> cod_peca;

        int inicio = 0, fim = contPeca - 1;
        int meio = (inicio + fim) / 2;

        for(; fim >= inicio && cod_peca != peca[meio].codigo; meio = (inicio + fim) / 2){
            if(cod_peca > peca[meio].codigo)
                inicio = meio + 1;
            else
                fim = meio - 1;
        }

        if(fim >= inicio && cod_peca == peca[meio].codigo){

            float valor_total_estoque;

            valor_total_estoque = peca[meio].quant_estoque * peca[meio].preco_unitario;

            cout << "\n\nPECA ENCONTRADA";
            cout << "\nCodigo: " << peca[meio].codigo;
            cout << "\nDescricao: " << peca[meio].descricao;
            cout << "\nQuantidade em Estoque: " << peca[meio].quant_estoque;
            cout << "\nEstoque Minimo: " << peca[meio].estoque_minimo;
            cout << "\nEstoque Maximo: " << peca[meio].estoque_maximo;
            cout << "\nPreco Unitario: " << peca[meio].preco_unitario;
            cout << "\nValor Total em Estoque: " << valor_total_estoque<< endl;

            validacao = 1;
        }
        else{
            cout << "\nPeca nao encontrada. Tente novamente.";
            validacao = 0;
        }

    	}while(validacao == 0);
	}   
}

// 9 - 
void exibir_pecas_abaixo_minimo(pecas peca[], int &contPeca){
	
	int quant_compra = 0;
	float valor_compra = 0, valor_total_compra = 0;
	
	for(int i = 0; i < contPeca; i++){
		
    	if(peca[i].quant_estoque < peca[i].estoque_minimo){
        	quant_compra = peca[i].estoque_maximo - peca[i].quant_estoque;
       		valor_compra = quant_compra * peca[i].preco_unitario;
       		
      		cout<<"\nInformacoes da Peca: ";
        	cout<<"\nCodigo: "<<peca[i].codigo;
    	    cout<<"\nDescricao: "<<peca[i].descricao;
    	    cout<<"\nQuantidade em Estoque: "<<peca[i].quant_estoque;
    	    cout<<"\nEstoque Maximo: "<<peca[i].estoque_maximo;
    	    cout<<"\nQuantidade a Comprar: "<<quant_compra;
    	    cout<<"\nValor de Reposicao de Estoque: R$"<<valor_compra<<" reais."<< endl;
    	    valor_total_compra = valor_total_compra +valor_compra;
    	    
   		}
   		else{
   			cout<<"\nNao existe pecas abaixo do estoque minimo."<< endl;
   			return;
		   }
}

	cout<<"\n\nValor Total de Gasto no Reabastecimento do Estoque Geral: R$"<<valor_total_compra<<" reais."<< endl;
	
}

// 10 - 
void arrecadacao_ordens(ordem_de_servico ordem_servicos[], int &contOrdens, servicos servico[], int contServico, pecas peca[], int contPeca){
	float total = 0;
	for(int i = 0; i < contOrdens; i++){
    	float preco = 0, valor_mao_obra = 0, valor_total_pecas = 0, valor_os = 0;
    
    	for(int x = 0; x < contPeca; x++){        
        	if(ordem_servicos[i].codigo_peca == peca[x].codigo){
            	preco = peca[x].preco_unitario;
        	}
    	}
    
    	for(int y = 0; y < contServico; y++){
        	if(ordem_servicos[i].codigo_servico == servico[y].codigo){
            	valor_mao_obra = servico[y].valor_mao_de_obra;
        	}
    	}
   
    	valor_total_pecas = preco * ordem_servicos[i].quantidade_peca;
    	valor_os = valor_mao_obra + valor_total_pecas;
    	total = total + valor_os;
}

	cout<<"\nValor Total Arrecadado: "<<total<< endl;

}

int main(){
	
	cidades cidade[10];
	clientes cliente[10];
	veiculos veiculo[10];
	servicos servico[10];
	pecas peca[10];
	mecanicos mecanico[10];
	ordem_de_servico ordem_servicos[10];
	
	int qtdCidades = 0,  qtdCliente = 0,  qtdVeiculo = 0,  qtdServicos = 0,  qtdPeca = 0,  qtdMecanico = 0,  qtdOrdens = 0;
	int contCliente = 0, contVeiculo = 0, contMecanico = 0, contOrdens = 0, contPeca = 0, contServico = 0;
	
	//IMPLEMENTANDO DADOS PARA FUNÇÃO DE LER CIDADES
	cidade[0].codigo = 1;
    strcpy(cidade[0].nome, "Assis");
    strcpy(cidade[0].UF, "SP");

    cidade[1].codigo = 2;
    strcpy(cidade[1].nome, "Marilia");
    strcpy(cidade[1].UF, "SP");

    cidade[2].codigo = 3;
    strcpy(cidade[2].nome, "Bauru");
    strcpy(cidade[2].UF, "SP");
    qtdCidades = 3;
     
	
	//IMPLEMENTANDO DADOS PARA FUNÇÃO DE LER SERVICOS
	servico[0].codigo = 1;
	strcpy(servico[0].descricao, "Troca de Oleo");
	servico[0].valor_mao_de_obra = 100.00;
	
	servico[1].codigo = 2;
	strcpy(servico[1].descricao, "Troca de Filtro");
	servico[1].valor_mao_de_obra = 50.00;
	
	servico[2].codigo = 3;
	strcpy(servico[2].descricao, "Troca de Radiador");
	servico[2].valor_mao_de_obra = 200.00;
	qtdServicos = 3;
	contServico = 3;
	
	//IMPLEMENTANDO DADOS PARA FUNÇÃO DE LER PECAS
	peca[0].codigo = 1;
	strcpy(peca[0].descricao, "Pneu");
	peca[0].quant_estoque = 14;
	peca[0].estoque_minimo = 15;
	peca[0].estoque_maximo = 50;
	peca[0].preco_unitario = 300.00;
	
	peca[1].codigo = 2;
	strcpy(peca[1].descricao, "Bateria");
	peca[1].quant_estoque = 10;
	peca[1].estoque_minimo = 15;
	peca[1].estoque_maximo = 35;
	peca[1].preco_unitario = 500.00;
	
	peca[2].codigo = 3;
	strcpy(peca[2].descricao, "Radiador");
	peca[2].quant_estoque = 3;
	peca[2].estoque_minimo = 7;
	peca[2].estoque_maximo = 20;
	peca[2].preco_unitario = 250.00;
	contPeca = 3;
	
	int opcao = 0;
	cout<<"=============================="<< endl;
	cout<<"            MENU  " << endl;
	cout<<"       OFICINA MECANICA"<< endl;
	cout<<"=============================="<< endl;
	
	do{
		
	cout<<"\n1. Ler Cidades";
	cout<<"\n2. Ler Servicos";
	cout<<"\n3. Ler Pecas";
	cout<<"\n4. Inclusao de Clientes";
	cout<<"\n5. Inclusao de Veiculos";
	cout<<"\n6. Inclusao de Mecanicos";
	cout<<"\n7. Abertura de Ordem de Servico";
	cout<<"\n8. Consultar Peca";
	cout<<"\n9. Exibir Pecas Abaixo do Estoque Minimo";
	cout<<"\n10. Valor Arrecadado com Todas Ordens de Servico";
	cout<<"\n0. Sair"<< endl;
	
	cout<<"\nDigite a opcao desejada: ";
	cin>>opcao;
	
		switch(opcao){
			case 0:
    			cout << "\nEncerrando Programa..";
			break;
			
			
			case 1:
				cout<<"\n - Leitura dos Dados das Cidades: "<< endl;
				ler_cidades(cidade, qtdCidades);
			break;
		
		
			case 2:
				cout<<"\n - Leitura dos Dados dos Servicos: "<< endl;
				ler_servicos(servico, qtdServicos);
			break;	
		
		
			case 3:
				cout<<"\n - Leitura dos Dados das Pecas: "<< endl;
				ler_pecas(peca, contPeca);
			break;	
		
		
			case 4:
				cout<<" - Quantos Registros de Clientes Voce Deseja Incluir? ";
				cin>>qtdCliente;
				inc_clientes(cliente, qtdCliente, contCliente, cidade, qtdCidades);
			break;
			
		
			case 5:
				cout<<" - Quantos Registros de Veiculos Voce Deseja Incluir? ";
				cin>>qtdVeiculo;
				inc_veiculos(veiculo, qtdVeiculo, contVeiculo, cliente, qtdCliente, contCliente);
			break;
		
		
			case 6:
				cout<<" - Quantos Registros de Mecanicos Voce Deseja Incluir? ";
				cin>>qtdMecanico;
				inc_mecanicos(mecanico, qtdMecanico, contMecanico);
			break;
				
				
			case 7:
				cout<<" - Quantas Ordens de Servico Voce Deseja Abrir? ";
				cin>>qtdOrdens;
				abrir_ordem_servico(ordem_servicos, qtdOrdens, contOrdens, veiculo, qtdVeiculo, contVeiculo, peca, contPeca,
				mecanico, contMecanico, servico, contServico, cliente, contCliente);
			break;	
			
		
			case 8:
				cout<<" - Quantas Pecas Voce Deseja Consultar? ";
				cin>>qtdPeca;
				consulta_pecas(peca, qtdPeca, contPeca);
			break;	
			
		
			case 9:
				cout<<" - Relatorio de Pecas Abaixo do Estoque Minimo ";
				exibir_pecas_abaixo_minimo(peca, contPeca);
			break;
				
		
			case 10:
				cout<<" - Valor Total Arrecadado Com Todas as Ordens de Servicos: ";
				arrecadacao_ordens(ordem_servicos, contOrdens, servico, contServico, peca, contPeca);
			break;
			
			default:
				cout<<"Opcao Invalida."<< endl;	
		}
	}
	while(opcao != 0);
	
	return 0;
}

