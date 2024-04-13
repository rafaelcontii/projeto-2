#include "tarefas.h"
#include <stdio.h>

int main() {
  funcao fs[] = {criar, deletar, listar, salvar, carregar};

  Tarefa tarefas[TOTAL];
  int pos;
  ERROS erro = fs[4](tarefas, &pos);
  if (erro != OK)
    pos = 0;

  int opcao;
  do {
    printf("\nMenu principal\n");
    printf("1 - Criar tarefa\n");
    printf("2 - Deletar tarefa\n");
    printf("3 - Listar tarefas\n");
    printf("Salvar Tarefas\n");
    printf("4-Exportar Tarefas\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");

    scanf("%d", &opcao);
    opcao--;
    if (opcao > 5)
      printf("Opcao invalida\n");
    else if (opcao >= 0 && opcao <= 5)
      fs[opcao](tarefas, &pos);
    else if (opcao == 5) {
      erro = gerenciarArquivo(tarefas, &pos, "tarefas.bin", 1);
      if (erro != OK)
        printf("Erro ao salvar as tarefas\n");
    } else
      printf("Sair.\n");

  } while (opcao >= 0 && opcao <= 5);

  return 0;
}
