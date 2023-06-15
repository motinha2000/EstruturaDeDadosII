# ARVORE DE HUFFMAN
## ALUNOS: LEANDRO RENER BRACHO & GABRIEL MOTA SANTOS

## NESTE TRABALHO CONSTRUIMOS A ARVORE DE HUFFMAN DE UM ARQUIVO .TXT

### COMPRESS.H

Neste arquivo de cabeçalho contém a estrutura de Simbolos(folhas)
ela guarda um ponteiro de char, a frequencia dessa folha,
e dois ponteiros para outra estrutura simbolo, a esquerda e a direita.
que vai ser utilizado para construir a arvore ao final.

### MAIN.C

Aqui abrimos nosso arquivo que vem como argumento do cmd,
contamos todos caracteres nesse arquivo. 
Criamos um vetor de caracteres pra todos os caracteres do arquivo
resetamos o ponteiro do arquivo
adicionamos cada caractere do arquivo em um vetor
Criamos uma variável TAM com o total de caracters unicos nesse arquivo

### FUNÇÕES:

## elementosUnicos:
   Calcula os elementos unicos nesse arquivo usando aquele vetor com 
   todos caracteres do arquivo, usamos uma variável que conta a recorrência-1
   desse caracter no vetor c/ todos caracteres.

## iniciarStruct:
    Inicia o struct com o total de caracteres unicos(folhas)
    
## folhas:
    usa uma variável externa, para inserir no Struct de folhas
    os caracteres, e eles tem que ser únicos, adiciono um elemento
    nesse struct, vejo se ele já existe, se não existir, calculo sua frequência
    se existir vou parar a contagem e passar adicionar 
    a próxima posição vazia do struct, até que esteja cheio

## ordenar:
    ordenção básica das folhas pela sua frequência

## arvore:
    função recursiva que pega as 2 ultimas posições no struct,
    junta elas, e dependendo da frequencia adiciona a direita ou a esquerda
    ordena novamente e chama a função arvore com o tamanho total das
    folhas-1, até que reste somente 1 posição no struct folhas, e as outras
    serão guardadas a esquerda e direita dos ponteiros

## huffman:
    função que usa um loop while para printar o código de huffman dos
    caracteres, uso a função strchr para encontrar recorrencia do caracter
    a esquerda ou a direita e navego até esse nó, uso um if para quando 
    achar no nó o exato caracter com strcmp, se eu achar um recorrencia 
    dependendo a esquerda ou direita é printado 1 ou 0 respectivamente.



