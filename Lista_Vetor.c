/****************************************************************** 
 * Nome: Lista com vetores com o tema loja de roupas              *
 * Descricao: Implementacao de lista com uso de vetores (array).  *
 *            Esse codigo possui as principais operacoes da       *
 *            lista, como:                                        *
 *            criar lista,                                        *
 *            inserir item,                                       *
 *            remover item,                                       *
 *            buscar item,                                        *
 *            imprimir item,                                       *
 *            atualizar item,                                     *
 *            listar itens,                                       *
 *            tamanho lista,                                      *
 *            excluir lista.                                      *
 * Autor: Kaylane Nayara e Milena Leticia                         *                  
 *                                                                *
 ******************************************************************/
 
/*Include das bibliotecas usadas*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/*Definicao das constantes*/ 
#define TAM 5

/*Definicao das estruturas*/ 
typedef struct {
	int   Id_roupa    [6];
	int   Qt_estoque;
    float Preco;
    char  Tamanho     [2];
	char  Tipo       [15];
	char  Cor        [10];
	char  Descricao  [50];
} Loja;

typedef struct {
	int   id;
	Loja *itens;
} Lista;

/* Nome: criarLista
 * Parametro: Lista* 
 * Retorno: Endereco do espaco de memoria reservado pelo malloc
 * Descricao: Funcao responsavel pela criacao da lista e inicializacao
 *            do campo id e alocacao do vetor de itens.
 */
Lista* criarLista(){
	//Solicita ao computador espaço para criação da lista
	Lista *nova = (Lista*)malloc(sizeof(Lista));
	
	//Verifica se o espaço foi consedido
	if (nova == NULL){
		printf("Nao tem espaco \n");
		return NULL;
	}
	//Organiza os dados iniciais da lista
	nova->id = 0;
	nova->itens = (Loja*)malloc(TAM * sizeof(Loja));
	
	//Verifica se o espaço foi consedido
	if (nova->itens == NULL){
		printf("Nao tem espaco\n");
		free(nova); //Libera o espaço de lista 
		return NULL;
	}
	//Retorna o espaço reservado
	return nova;
}
/* Nome: inserirItem
 * Parametros: lista - ponteiro para uma estrutura Lista, que contém os itens
 *             busca - identificador do item que será buscado e atualizado na lista
 *		       Qt_estoque -  quantidade em estoque para o item
 *		       Preco -  preço para o item
 *		       Tamanho -  tamanho para o item
 *		       Tipo -  tipo para o item
 *		       Cor -  cor para o item
 *	 	       Descricao -  descrição para o item
 * Retorno: 1 se o item foi adicionado, 0 - caso contrario
 * Descricao: Funcao criada para inserir um item no final da lista
 */
int inserirItem(Lista* lista, int Qt_estoque, float Preco, char Tamanho[], char Tipo[],char Cor[], char Descricao[]){
	//Verifica se a lista foi criada
	if (lista == NULL){
		printf("A lista nao foi criada\n");
		return 0;
	}
	//Verificando se existe espaco para inserir mais um elemento na lista
	if(lista->id < TAM){
		//Inserindo o item e suas informações na lista
		lista->itens[lista->id].Id_roupa[0] = lista->id;
		lista->itens[lista->id].Qt_estoque = Qt_estoque;
		lista->itens[lista->id].Preco = Preco;
		strcpy(lista->itens[lista->id].Tamanho, Tamanho);
		strcpy(lista->itens[lista->id].Tipo,  Tipo);
		strcpy(lista->itens[lista->id].Cor, Cor);
		strcpy(lista->itens[lista->id].Descricao, Descricao);
		//Atualiza a quantidade de elementos da lista
		++(lista->id);
	}
	else{
		printf("Espaco cheio\n");
		return 0;
	}
	return 1;
	}

/* Nome: removerItem
 * Parametro: lista - ponteiro que possui o endereco lista
 *            item - elemento que sera removido da lista
 * Retorno: 1 se o item foi removido, 0 - caso contrario
 * Descricao: Funcao criada para remover um item da lista
 */	
int removerItem(Lista* lista, int item){
	int i, j;
	
	//Verifica se a lista foi criada
	if(lista == NULL){
		printf("A lista nao foi criada\n");
		return 0;
	}
	//Verifica se há itens na lista
    if (lista->id == 0){
		printf("Nao ha itens na lista\n");
		return 0;
	}
	//Percorre todos os elementos da lista
	for(i=0; i< lista->id; ++i){
		//Verificando se o elemento atual e igual ao valor que sera removido
		if(lista->itens[i].Id_roupa[0] == item){
			//Desloca os itens apos posicao do item que sera removido da lista
			for(j=i; j< lista->id -1; ++j){
				lista->itens[j] = lista->itens[j+1];
			}
			//Atualiza a quantidade de item na lista
			--lista->id;
			return 1;
		}
	}
	return 0;
}
/* Nome: buscarItem
 * Parametro: lista - ponteiro que possui o endereco lista
 *            busca - item que sera buscado na lista
 * Retorno: o indice do item encontrado, -1 caso contrario
 * Descricao: Funcao criada para buscar um item na lista
 */
int  buscarItem(Lista* lista, int busca){
    int i;
    //Verifica se a lista foi criada
	if(lista == NULL){
		printf("A lista nao foi criada\n");
		return 0;
	}
	//Percorre todos os elementos da lista
	for(i=0; i < lista->id; ++i){
		//Verifica se o item atual e igual ao valor buscado
		if(lista->itens[i].Id_roupa[0] == busca){
			printf("O item esta na lista, na posicao %d \n", i);
			return 1;
		}
	}
	printf("O item nao foi encontrado\n");
	return -1;
}

/* Nome: imprimirItens
 * Parametro: lista - ponteiro que possui o endereco lista
 * Retorno: void
 * Descricao: Funcao criada para apresentar todos itens presentes na lista
 */
void imprimirItens(Lista* lista){
	int i;
	//Verifica se a lista foi criada
	if (lista == NULL){
		printf("A lista nao foi criada\n");
		return;
	}
	//Verifica se ha itens na lista
	if (lista->id == 0){
		printf("Nao ha itens na lista\n");
		return;
	}
	
	printf("Informacoes sobre as roupas: \n");
	//Mostra cada item e suas informacoes presente na lista
	for (i=0; i< lista->id; ++i){
		printf("Peça %d:\n", i+1 );
		printf("Tipo: %s\n", lista->itens[i].Tipo);
		printf("Id: %d\n", lista->itens[i].Id_roupa[0]);
		printf("Quantidade no estoque: %d\n",lista->itens[i].Qt_estoque);
		printf("Preco: %f\n", lista->itens[i].Preco);
		printf("Tamanho: %s\n", lista->itens[i].Tamanho);
		printf("Cor: %s\n", lista->itens[i].Cor);
		printf("Descricao: %s\n", lista->itens[i].Descricao);
	}
}

/* Nome: atualizarItem
 * Parametros: lista - ponteiro para uma estrutura Lista, que contém os itens
 *             busca - identificador do item que será buscado e atualizado na lista
 *		       Qt_estoque - nova quantidade em estoque para o item
 *		       Preco - novo preço para o item
 *		       Tamanho - novo tamanho para o item
 *		       Tipo - novo tipo para o item
 *		       Cor - nova cor para o item
 *	 	       Descricao - nova descrição para o item
 * Retorno: 1 - quando o valor e atualizado e 0 - caso contrario
 * Descricao: Funcao responsavel por atualizar um item e suas informações
 *            na lista, caso o mesmo esteja na lista indicada
 */
int atualizarLista(Lista* lista, int busca, int Qt_estoque, float Preco, char Tamanho[], char Tipo[],char Cor[], char Descricao[]){
	int i;
	//Verifica se a lista foi criada
	if(lista == NULL){
		printf("A lista nao foi criada\n");
		return 0;
	}
	//Verifica se ha itens na lista
	if (lista->id == 0){
		printf("Nao ha itens na lista\n");
		return;
	}
	
	//Percorre todos os elementos da lista
	for(i=0; i < lista->id; ++i){
		//Verifica se o item atual e igual ao valor buscado
		if(lista->itens[i].Id_roupa[0] == busca){
			//Atualiza o item e suas informacoes
			lista->itens[i].Qt_estoque = Qt_estoque;
	     	lista->itens[i].Preco = Preco;
		    strcpy(lista->itens[i].Tamanho, Tamanho);
		    strcpy(lista->itens[i].Tipo, Tipo);
		    strcpy(lista->itens[i].Cor, Cor);
		    strcpy(lista->itens[i].Descricao, Descricao);
			printf("Item atualizado com sucesso!\n");
			return 1;	
		}
		
	}
	return 0;
}

/* Nome: inserirItemInicio
 * Parametros: lista - ponteiro para uma estrutura Lista, que contém os itens
 *             busca - identificador do item que será buscado e atualizado na lista
 *		       Qt_estoque -  quantidade em estoque para o item
 *		       Preco -  preço para o item
 *		       Tamanho -  tamanho para o item
 *		       Tipo -  tipo para o item
 *		       Cor -  cor para o item
 *	 	       Descricao -  descrição para o item
 * Retorno: 1 se o elemento foi adicionado, 0 - caso contrario
 * Descricao: Funcao criada para inserir um item no inicio da lista
 */
int inserirItemInicio(Lista* lista, int Qt_estoque, float Preco, char Tamanho[], char Tipo[],char Cor[], char Descricao[]){
	int i;
	//Verifica se a lista foi criada
	if(lista == NULL){
		printf("A lista nao foi criada\n");
		return 0;
	}
	//Verifica se há espaco para inserir mais um item na lista
	if(lista-> id < TAM){
		//Desloca todos os itens para o final da lista
		for(i = lista->id; i>0; --i){
			lista->itens[i] = lista->itens[i-1];
		}
		//Insere o item na primeira posicao da lista
		lista->itens[0].Id_roupa[0] = 0;
		lista->itens[0].Qt_estoque = Qt_estoque;
		lista->itens[0].Preco = Preco;
		strcpy(lista->itens[0].Tamanho, Tamanho);
		strcpy(lista->itens[0].Tipo, Tipo);
		strcpy(lista->itens[0].Cor, Cor);
		strcpy(lista->itens[0].Descricao, Descricao);
		//Atualiza a quantidade de item na lista
		++(lista->id);
	}
	else{
		printf("Espaco cheio\n");
		return 0;
	}
	return 1;
}
/* Nome: inserirItemID
 * Parametros: lista - ponteiro para uma estrutura Lista, que contém os itens
 *             posicao - posicao que o item sera adicionado na lista
 *		       Qt_estoque -  quantidade em estoque para o item
 *		       Preco -  preço para o item
 *		       Tamanho -  tamanho para o item
 *		       Tipo -  tipo para o item
 *		       Cor -  cor para o item
 *	 	       Descricao -  descrição para o item
 * Retorno: 1 se o elemento foi adicionado, 0 - caso contrario
 * Descricao: Funcao criada para inserir um item na posicao indicada na lista
 */

int inserirItemID(Lista* lista, int posicao, int Qt_estoque, float Preco, char Tamanho[], char Tipo[],char Cor[], char Descricao[]){
	int i;
	//Verifica se a lista foi criada
	if(lista == NULL){
		printf("A lista nao foi criada\n");
		return 0;
	}
	//Verifica se há espaco para inserir mais um item na lista
	if(lista-> id < TAM){
		//Verifica se a posicao esta dentro do intervalo permitido
		if(posicao < lista->id){
			//Desloca todos os itens apos posicao para o final da lista
			for(i=lista->id; i > posicao; --i){
				lista->itens[i] = lista->itens[i-1];
			}
			//Insere o item na posicao indicada na lista
			lista->itens[posicao].Id_roupa[0] = posicao;
			lista->itens[posicao].Qt_estoque = Qt_estoque;
	    	lista->itens[posicao].Preco = Preco;
	    	strcpy(lista->itens[posicao].Tamanho, Tamanho);
	    	strcpy(lista->itens[posicao].Tipo, Tipo);
	    	strcpy(lista->itens[posicao].Cor, Cor);
	    	strcpy(lista->itens[posicao].Descricao, Descricao);
	    	//Atualiza a quantidade de item na lista
	    	++(lista->id);
		}
		else{
			printf("Posicao fora do intervalo permitido\n");
			return 0;
		}
	}
	else{
		printf("Espaco esgotado\n");
		return 0;
	}
	return 1;
}

/* Nome: listarItens
 * Parametro: lista - ponteiro que possui o endereco lista
 * Retorno: 1 se o elemento foi adicionado, 0 - caso contrario
 * Descricao: Funcao responsavel listagem dos itens da lista
 */
int listarItens(Lista* lista){
	int i;
	// Verifica se a lista foi criada
	if(lista == NULL){
		printf("A lista nao foi criada\n");
		return 0;
	}
	//Verifica se ha itens na lista
	if (lista->id == 0){
		printf("Nao ha itens na lista\n");
		return 0;
	}
	// Percorre todos os itens da lista e imprime suas informações
	for(i=0;i < lista->id; ++i){
		printf("Peça %d:\n", i+1 );
		printf("Tipo: %s\n", lista->itens[i].Tipo);
		printf("Id: %d\n", lista->itens[i].Id_roupa[0]);
		printf("Quantidade no estoque: %d\n",lista->itens[i].Qt_estoque);
		printf("Preco: %f\n", lista->itens[i].Preco);
		printf("Tamanho: %s\n", lista->itens[i].Tamanho);
		printf("Cor: %s\n", lista->itens[i].Cor);
		printf("Descricao: %s\n", lista->itens[i].Descricao);
        printf("\n \n");
	}
	return 0;
}

/* Nome: tamanho
 * Parametro: lista - ponteiro que possui o endereco lista
 * Retorno: void
 * Descricao: Funcao responsavel por mostrar o tamanho da lista
 */
void tamanho(Lista* lista) {
    // Verifica se a lista foi criada
    if(lista == NULL) {
        printf("A lista nao foi criada\n");
        return;
    }
    //Mostrar o tamanho da lista na tela
    printf("O tamanho da lista é: %d\n", lista->id);
    return;
}

/* Nome: excluirLista
 * Parametro: lista - ponteiro que possui o endereco lista
 * Retorno: NULL para indicar que a lista foi excluida
 * Descricao: Funcao responsavel pela exclusao da lista
 */
Lista* excluirLista(Lista* lista){
	//Verifica se a lista foi criada
	if(lista == NULL){
		printf("A lista nao foi criada\n");
		return NULL;
	}
	/*Liberando o espaco que foi reservado para o vetor itens*/
	free(lista->itens);
	
	//Libera o espaco que foi reservado para a lista
	free(lista);
	printf("A lista foi excluida \n");
	return NULL;
}

int main() {
	//Definicao das variaveis usadas
    int posicao;
    int Opcoes;
    int Qt_estoque;
    int lugar;
    int ID;
    float Preco;
    char Tamanho[2];
    char Tipo[15];
    char Cor[10];
    char Descricao[50];
    char Saida;
    bool cond = true;
    
    //Ponteiro usado para a criacao da lista
    Lista* lista;
    lista = criarLista();
    
    //Este loop mantem o programa em execucao ate que o usuario decida sair
    while (cond) { 
    	//Exibe um menu de opções ao usuario 
        while (1) {
            printf("O que voce deseja fazer?\n1)Inserir item\n2)Buscar itens\n3)Remover item\n4)Mostrar item\n5)Atualizar item\n6)Mostrar o tamanho da lista\n7)Listar itens\n8)Excluir \n");
            scanf("%d", &Opcoes);
            //A escolha do usuario e capturado em um switch que determina qual operacao ira realizar
            switch (Opcoes) {
            	//O usuario escolhe onde adicionar o item (inicio, fim ou posicao especifica)
                case 1:
                    printf("Onde deseja adicionar o item?\n1)No inicio da lista\n2)No final da lista\n3)Escolha a posicao do item\n");
                    scanf("%d", &lugar);

                    printf("Digite o tipo da peca: ");
                    scanf("%s", Tipo);
                    printf("Digite o tamanho da peca: ");
                    scanf("%s", Tamanho);
                    printf("Digite a cor da peca: ");
                    scanf("%s", Cor);
                    printf("Digite a quantidade de pecas no estoque: ");
                    scanf("%d", &Qt_estoque);
                    printf("Digite o preco da peca: ");
                    scanf("%f", &Preco);
                    printf("Descreva a peca: ");
                    scanf("%s", Descricao);

					//A escolha do usuario e capturado em um switch que determina qual operacao ira realizar
                    switch (lugar) {
                    	//Chama a funcao inserirItemInicio e coloca seus parametros
                        case 1:
                            inserirItemInicio(lista, Qt_estoque, Preco, Tamanho, Tipo, Cor, Descricao);
                            printf("O item foi adicionado com sucesso!\n");
                            break;
                        //Chama a funcao inserirItem e coloca seus parametros
                        case 2:
                            inserirItem(lista, Qt_estoque, Preco, Tamanho, Tipo, Cor, Descricao);
                            printf("O item foi adicionado com sucesso!\n");
                            break;
                        //Chama a funcao inserirItemID e coloca seus parametros
                        case 3:
                            printf("Em qual posicao voce deseja adiconar?\n");
                            scanf("%d", &posicao);
                            inserirItemID(lista, posicao, Qt_estoque, Preco, Tamanho, Tipo, Cor, Descricao);
                            printf("O item foi adicionado com sucesso!\n");
                            break;
                        //Caso a escolha nao seja valida, exibe uma mensagem
                        default:
                            printf("Opcao invalida\n");
                            break;
                    }
                    break;
                //Chama a funcao buscarItem e coloca o seu parametro
                case 2:
                    printf("Digite o ID do item: \n");
                    scanf("%d", &ID);
                    buscarItem(lista, ID);
                    break;
                //Chama a funcao removerItem e o coloca seu parametro
                case 3:
                    printf("Digite o ID do item: \n");
                    scanf("%d", &ID);
                    removerItem(lista, ID);
                    printf("O item foi removido com sucesso!\n");
                    break;
                //Chama a funcao imprimirItens e o coloca seu parametro
                case 4:
                    imprimirItens(lista);
                    break;
                //Chama a funcao atualizarLista e coloca seus parametros
                case 5:
                	//Verifica se ha itens na lista
                    if (lista->id == 0) {
                        printf("Nao ha itens na lista\n");
                    } else {
                        printf("Digite o ID da peca que sera atualizada: \n");
                        scanf("%d", &ID);

                        printf("Digite o tipo da peca: ");
                        scanf("%s", Tipo);
                        printf("Digite o tamanho da peca: ");
                        scanf("%s", Tamanho);
                        printf("Digite a cor da peca: ");
                        scanf("%s", Cor);
                        printf("Digite a quantidade de pecas no estoque: ");
                        scanf("%d", &Qt_estoque);
                        printf("Digite o preco da peca: ");
                        scanf("%f", &Preco);
                        printf("Descreva a peca: ");
                        scanf("%s", Descricao);
                        atualizarLista(lista, ID, Qt_estoque, Preco, Tamanho, Tipo, Cor, Descricao);
                    }
                    break;
                //Chama a funcao tamanho e o coloca seu parametro
                case 6:
                    tamanho(lista);
                    break;
                //Chama a funcao listarItens e o coloca seu parametro
                case 7:
                    listarItens(lista);
                    break;
                //Chama a funcao excluirLista e o coloca seu parametro
                case 8:
                    printf("Tem certeza que quer excluir a lista? (S/N): \n");
                    scanf(" %c", &Saida); 
                    //Compara a variavel com a string para excluir a lista
                    if (toupper(Saida) == 'S') {
                        excluirLista(lista);
                        break;
                    } else if (toupper(Saida) == 'N') {
                        break;
                    } else {
                        printf("Opcao invalida\n");
                        break;
                    }
                //Caso a escolha nao seja valida, exibe uma mensagem    
                default:
                    printf("Opcao invalida\n");
                    break;
            }
            break;
        }
        //Neste loop, apos cada operacao, o usuario e perguntado se deseja realizar mais alguma alteracao
        while(cond=true){
	        printf("Deseja fazer mais alguma alteracao? (S/N)\n");
	        scanf(" %c", &Saida); 
	        //Compara a variavel com a string para atribuir false a variavel e encerrar o loop
	        if (toupper(Saida) == 'S') {
	            cond = true;
	            break;
	        } else if (toupper(Saida) == 'N') {
	            cond = false;
	            break;
	        } else {
	            printf("Opcao invalida\n");
	        }
		}
    }
    return 0;
}
