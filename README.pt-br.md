# MyCLib

[Read in English](README.md) | [中文版](README.zh-cn.md)

## Aviso Importante

> **Este projeto é apenas para fins de aprendizado.**
>
> O **código backend** (todas as implementações em C em `src/`) foi escrito **manualmente sem assistência de IA**, como parte da minha jornada para entender profundamente como C funciona nos bastidores.
>
> A **interface** (camada de frontend para visualização e interação com o backend) foi criada usando agentes de IA. Seu único propósito é fornecer uma melhor experiência visual para demonstrar a funcionalidade do backend - ela **não** é o foco deste projeto.

---

**Objetivo:** Mostrar meus conhecimentos da linguagem C e suas características.

Esse projeto mostra um conjunto das minhas próprias implementações de bibliotecas e algoritmos, buscando entender como as coisas funcionam por baixo dos panos.

## Como rodar

Você pode compilar o projeto usando `gcc`:

```bash
gcc main.c -I./include -o main.out
./main.out
```

## Funções

### String Utils

*   **my_strlen**: Retorna o tamanho de uma string usando aritmética de ponteiros.
*   **my_tolower**: Converte uma string para minúsculas (retorna uma nova string alocada).
*   **my_toupper**: Converte uma string para maiúsculas (retorna uma nova string alocada).
*   **my_strcmp**: Compara duas strings lexicograficamente. Retorna `0` se iguais, `1` se str1 é maior, `-1` se str2 é maior.
*   **my_strcmp_percent**: Calcula similaridade entre strings usando o algoritmo de distância de Levenshtein. Retorna uma porcentagem (0-100).

### Math Utils

*   **min**: Retorna o mínimo de três inteiros (usado por `my_strcmp_percent` para programação dinâmica).
