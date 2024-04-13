# Projeto 2 - Correção de bugs e novas funcionalidades

Continuando o projeto anterior (https://github.com/cc2632/projeto0-2024-1), vamos corrigir alguns problemas encontrados no uso do programa e também adicionar algumas funcionalidades para deixar o programa melhor.

## Bugs para correção e melhorias

1. (1 ponto) Os valores de categoria e descrição estão com quebra de linha no final da string. Adicione o código necessário para que esta quebra de linha não seja armazenada
2. (1 ponto) O valor da prioridade não está limitado entre 1 e 10
3. (1 ponto) Os erros não foram tratados na função main
4. (1 ponto) Os tamanhos da categoria e descrição na função de criar tarefas e na descrição do struct estão com os valores definidos, mas não usam uma variável ou parâmetro para isso. Use o #define para mudar estes valores
5. (1 ponto) Altere o README.md para descriver melhor a forma como o programa funciona

## Funcionalidades para implementar

1. (2 pontos) Altere a função listar para pedir que o usuário a categoria que ele deseja listar. 
    - Se o usuário escolher uma categoria existente, imprima as tarefas encontradas;
    - Se a categoria não existir, avise que nenhuma tarefa foi encontrada;
    - Se o usuário deixar a categoria vazia, exiba todas as tarefas;
2. (2 pontos) Implemente uma forma de exportar as tarefas para um arquivo de texto simples em que cada tarefa deve aparecer em uma linha do arquivo. O usuário deve conseguir usar as mesmas opções que o item anterior e pode escolher o nome do arquivo texto que será gerado  
3.(1 pontos) Altere o programa para deixar o usuário carregar e salvar o arquivo binário com as tarefas.

## Critérios de avaliação

- Caso seja verificado plágio ou cópia de código (mesmo que seja de projetos de semestre anteriores), a nota será zerada e o projeto encaminhado para a reitoria.
- O projeto deve continuar o código que está disponível no repositório. Caso seja apresentado um novo código, o projeto será zerado.
- O código deve ser desenvolvido usando algum serviço de versionamento (github, gitlab, bitbucket, gitea,...) e a entrega deve ser apenas o link para o repositório. Entregas feitas de outra forma não serão aceitas.
- Serão avaliados apenas o funcionamento e código que está na branch main (ou master). Códigos em outras branchs não serão avaliados ou considerados para a nota.
- Apenas receberão notas os participantes do projeto que tiverem commits que foram feito merge na branch main/master.
- Códigos que não compilam no replit não serão corrigidos e o projeto receberá nota zero.
- Para cada ponto levantado acima deverá ser criada uma branch com a correção ou implementação da funcionalidade. Não serão consideradas mudanças no código feitas direto na main.
- Para este projeto a nota por item será dividida seguindo:
    - 1/4 pelo funcionamento (o programa faz o que foi pedido)
    - 1/2 pelo código apresentado (código bem escrito)
    - 1/4 pelo uso do sistema de versionamento

