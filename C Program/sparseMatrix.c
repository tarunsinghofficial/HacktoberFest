#include <stdlib.h>
#include "matriz.h"

matriz *cria_matriz(int lin, int col, int def)
{
    int i;
    matriz *m = (matriz *)malloc(sizeof(matriz));
    m->begin = (pont *)malloc(lin * sizeof(pont));
    m->colunas = col;
    m->linhas = lin;
    m->d = def;
    for (i = 0; i < lin; i++)
        m->begin[i] = NULL;
    return m;
}

int insere(matriz *m, int lin, int col, int v)
{
    if (lin < 0 || lin >= m->linhas || col < 0 || col >= m->colunas)
        return 0;
    pont ant = NULL;
    pont atual = m->begin[lin];
    while (atual != NULL && atual->coluna < col)
    {
        ant = atual;
        atual = atual->next;
    }
    if (atual != NULL && atual->coluna == col)
    {
        if (v == m->d)
        {
            if (ant == NULL)
                m->begin[lin] = atual->next;
            else
                ant->next = atual->next;
            free(atual);
        }
        else
            atual->valor = v;
    }
    else
    {
        pont novo = (pont)malloc(sizeof(node));
        novo->coluna = col;
        novo->valor = v;
        novo->next = atual;
        if (ant == NULL)
            m->begin[lin] = novo;
        else
            ant->next = novo;
    }
    return 1;
}

int acess(matriz *m, int lin, int col)
{
    if (lin < 0 || lin >= m->linhas || col < 0 || col >= m->colunas)
        return 0;
    pont atual = m->begin[lin];
    while (atual != NULL && atual->coluna < col)
        atual = atual->next;
    if (atual != NULL && atual->coluna == col)
        return atual->valor;
    return m->d;
}