#include <stdio.h>
#include <string.h>
#include "tarefas.h"

ERROS criar(Tarefa tarefas[], int *pos){
    if(*pos >= TOTAL)
        return MAX_TAREFA;

    printf("Entre com a prioridade: ");
    scanf("%d", &tarefas[*pos].prioridade);
    clearBuffer();
  printf("Digite a categoria desejada : ");
  fgets(tarefas[*pos].categoria, CHAR_CATEGORIA, stdin);
  tarefas[*pos].categoria[strcspn(tarefas[*pos].categoria, "\n")] = '\0';

  printf("Digite a descricao desejada: ");
  fgets(tarefas[*pos].descricao, CHAR_DESCRICAO, stdin);
  tarefas[*pos].descricao[strcspn(tarefas[*pos].descricao, "\n")] = '\0';

  *pos = *pos + 1;

  return OK;
}


ERROS deletar(Tarefa tarefas[], int *pos){
    // teste se existem tarefas
    if(*pos == 0)
        return SEM_TAREFAS;

    // verifica se a tarefa escolhida existe
    int pos_deletar;
    printf("Entre com a posicao da tarefa a ser deletada: ");
    scanf("%d", &pos_deletar);
    pos_deletar--; // garantir posicao certa no array
    if(pos_deletar >= *pos || pos_deletar < 0)
        return NAO_ENCONTRADO;

    for(int i = pos_deletar; i < *pos; i++){
        tarefas[i].prioridade = tarefas[i+1].prioridade;
        strcpy(tarefas[i].categoria, tarefas[i+1].categoria);
        strcpy(tarefas[i].descricao,  tarefas[i+1].descricao);
    }

    *pos = *pos - 1;

    return OK;
}

ERROS listar(Tarefa tarefas[], int *pos) {
  if (*pos == 0) {
    printf("Nenhuma tarefa encontrada.\n");
    return SEM_TAREFAS;
  }

  char categoriaDesejada[CHAR_CATEGORIA];
  clearBuffer();
  printf("Digite a categoria que deseja listar(ou deixe em branco para exibir "
         "todas as categorias): ");
  fgets(categoriaDesejada, CHAR_CATEGORIA, stdin);
  categoriaDesejada[strcspn(categoriaDesejada, "\n")] = '\0';

  int encontradas = 0;
  for (int i = 0; i < *pos; i++) {
    if (categoriaDesejada[0] == '\0' ||
        strstr(tarefas[i].categoria, categoriaDesejada) != NULL) {
      printf("Pos: %d\t", i + 1);
      printf("PrioridaDe: %d\t", tarefas[i].prioridade);
      printf("CategoRia: %s\t", tarefas[i].categoria);
      printf("DescrIcao: %s\n", tarefas[i].descricao);
      encontradas++;
    }
  }

  if (encontradas == 0) {
    if (categoriaDesejada[0] == '\0') {
      printf("Nenhuma tarefa encontrada.\n");
    } else {
      printf(
          "Nenhuma tarefa encontrada dentro da categoria selecionada \"%s\".\n",
          categoriaDesejada);
    }
    return NAO_ENCONTRADO;
  }

  return OK;
}


ERROS salvar(Tarefa tarefas[], int *pos){
    FILE *f = fopen("tarefas.bin", "wb");
    if(f == NULL)
        return ABRIR;

    int qtd = fwrite(tarefas, TOTAL, sizeof(Tarefa), f);
    if(qtd == 0)
        return ESCREVER;

    qtd = fwrite(pos, 1, sizeof(int), f);
    if(qtd == 0)
        return ESCREVER;

    if(fclose(f))
        return FECHAR;

    return OK;
}

ERROS carregar(Tarefa tarefas[], int *pos){
    FILE *f = fopen("tarefas.bin", "rb");
    if(f == NULL)
        return ABRIR;

    int qtd = fread(tarefas, TOTAL, sizeof(Tarefa), f);
    if(qtd == 0)
        return LER;

    qtd = fread(pos, 1, sizeof(int), f);
    if(qtd == 0)
        return LER;

    if(fclose(f))
        return FECHAR;

    return OK;

}
ERROS Arquivo(Tarefa tarefas[], int *pos, char *nomeArquivo,
                       int operacao) {
  FILE *f;
  ERROS erro = OK;

  if (operacao == 1) {
    f = fopen(nomeArquivo, "wb");
    if (f == NULL)
      return ABRIR;

    int qtd = fwrite(tarefas, *pos, sizeof(Tarefa), f);
    if (qtd == 0)
      erro = ESCREVER;
  } else if (operacao == 2) {
    f = fopen(nomeArquivo, "rb");
    if (f == NULL)
      return ABRIR;

    int qtd = fread(tarefas, TOTAL, sizeof(Tarefa), f);
    if (qtd == 0)
      erro = LER;

    *pos = qtd / sizeof(Tarefa);
  } else {
    return OPERACAO_INVALIDA;
  }

  if (fclose(f))
    return FECHAR;

  return erro;
}



ERROS binario(Tarefa tarefas[], int *pos) {
  char nomeArquivo[100];
  printf("Digite o nome do arquivo que deseja exportar as tarefas: ");
  scanf("%s", nomeArquivo);

  FILE *arquivo = fopen(nomeArquivo, "w");
  if (arquivo == NULL) {
    return ABRIR;
  }

  for (int i = 0; i < *pos; i++) {
    fprintf(arquivo, "Prioridade: %d\tCategoria: %s\tDescricao: %s\n",
            tarefas[i].prioridade, tarefas[i].categoria, tarefas[i].descricao);
  }

  fclose(arquivo);
  return OK;
}

void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
