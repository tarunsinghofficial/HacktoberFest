#include <stdio.h>

#define max 100

typedef struct
{
    int n;
    int inicio;
    int vet[max];
} fila;

fila *cria_fila()
{
    fila *f = (fila *)malloc(sizeof(fila));
    f->inicio = 0;
    f->n = 0;
    return f;
}

int insere(fila *f, int v)
{
    int fim = 0;
    if (f->n < max)
    {
        fim = (f->inicio + f->n) % max;
        f->vet[fim] = v;
        f->n++;
        return 1;
    }
    return 0;
}

int retira(fila *f)
{
    int ret;
    if (f->n > 0)
    {
        ret = f->vet[f->inicio];
        f->inicio = ((f->inicio) + 1) % max;
        f->n--;
    }
    return ret;
}

int size(fila *f)
{
    return f->n;
}

int is_empty(fila *f)
{
    return f->n == 0;
}

int is_full(fila *f)
{
    return f->n == max;
}