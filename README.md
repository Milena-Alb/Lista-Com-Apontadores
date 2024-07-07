# Lista com Vetores - Loja de Roupas
## Descrição
Este projeto implementa uma lista utilizando vetores (arrays) para gerenciar o estoque de uma loja de roupas. As principais operações disponíveis são:

- Criar lista
- Inserir item
- No início da lista
- No final da lista
- Em uma posição específica
- Remover item
- Buscar item
- Imprimir item
- Atualizar item
- Listar itens
- Verificar o tamanho da lista
- Excluir lista

## Autores
Kaylane Nayara e Milena Leticia


## Estrutura Loja e dados

Representa um item no estoque da loja, contendo os seguintes campos:

- Id_roupa: Identificador do item (inteiro)
- Qt_estoque: Quantidade em estoque (inteiro)
- Preco: Preço do item (float)
- Tamanho: Tamanho do item (string, 2 caracteres)
- Tipo: Tipo de roupa (string, 15 caracteres)
- Cor: Cor do item (string, 10 caracteres)
- Descricao: Descrição do item (string, 50 caracteres)

## Estrutura Lista
Representa a lista de itens, contendo os seguintes campos:

- id: Identificador da lista (inteiro)
- itens: Ponteiro para o vetor de itens (Loja)

## Funções

- **Lista* criarLista()**

  Cria e inicializa uma nova lista.

- **int inserirItem()**

  Insere um novo item no final da lista.

- **int removerItem()**

  Remove um item da lista com base no seu identificador.

- **int buscarItem()**

  Busca um item na lista com base no seu identificador.

- **void imprimirItens()**

  Imprime todos os itens presentes na lista.

- **int atualizarLista()**

  Atualiza um item na lista com base no seu identificador.

- **int inserirItemInicio()**

  Insere um novo item no início da lista.

- **int inserirItemID()**

  Insere um novo item em uma posição específica da lista.

- **int listarItens()**
   
  Lista todos os itens presentes na lista.

- **void tamanho()**

  Mostra o tamanho atual da lista.

- **Lista* excluirLista()**

  Exclui a lista e libera a memória alocada.

## Contribuição
Contribuições são bem-vindas! Por favor, faça um fork do repositório e envie um pull request com suas alterações.

## Notas
Este projeto foi desenvolvido para fins de aprendizado e demonstração de manipulação de listas com vetores em C.
