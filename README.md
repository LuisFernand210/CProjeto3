# CProjeto3

Este é um programa em C para gerenciar uma lista de contatos. Ele permite adicionar, listar e excluir contatos, além de salvar e carregar a agenda de um arquivo binário.

# Funcionalidades

1. **Adicionar contatos**: Permite adicionar até 255 contatos em cada lista (pessoal ou de trabalho), fornecendo nome, sobrenome, email e telefone. O telefone deve ser único.
2. **Listar contatos**: Mostra todos os contatos salvos na agenda, separados por categoria (pessoal ou de trabalho).
3. **Deletar contato**: Remove um contato escolhido com base no número de telefone, na lista pessoal ou de trabalho.
4. **Salvar agenda**: Salva as listas de contatos (pessoal e de trabalho) em um arquivo binário.
5. **Carregar agenda**: Carrega as listas de contatos (pessoal e de trabalho) de um arquivo binário.
6. **Alterar contato**: Permite alterar os dados de um contato selecionado por email, em uma lista específica (pessoal ou de trabalho).

## Compilação e Execução

Para compilar o programa, utilize o seguinte comando: gcc main.c agenda.c -o agenda
Para executar o programa, basta rodar o executável gerado com o comando: ./agenda
Siga as instruções no menu para usar as funcionalidades da agenda.

# Autor

Desenvolvido por Luís Fernando Souza Gonçalves
