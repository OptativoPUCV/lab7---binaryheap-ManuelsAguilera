#include "heap.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
  void *data;
  int priority;
} heapElem;

typedef struct Heap {
  heapElem *heapArray;
  int size;
  int capac;
} Heap;

void heapify_u(Heap *H, int index) //  compara con el padre hasta
                                   // que el heap sea valido
{
  int parent = (index - 1) / 2;
  heapElem aux;

  if (H->heapArray[parent].priority >= H->heapArray[index].priority)
    return;
  else {
    aux = H->heapArray[parent];
    H->heapArray[parent] = H->heapArray[index];
    H->heapArray[index] = aux;
    heapify_u(H, parent);
  }
}

void *heap_top(Heap *pq) {
  if (pq->size != 0)
    return pq->heapArray[0].data;
  return NULL;
}

void heap_push(Heap *pq, void *data, int priority) {
  heapElem *array = pq->heapArray;
  pq->size++;
  if (pq->size == pq->capac) {
    array = (heapElem *)realloc(array, sizeof(heapElem) * (1 + pq->capac * 2));
    pq->capac *= 2;
    pq->capac++;
  }

	heapElem new;
	new.data=data;
	new.priority=priority;
  array[pq->size - 1] = new;
  heapify_u(pq, pq->size - 1);
}

void heap_pop(Heap *pq) {}

Heap *createHeap() {
  Heap *new = malloc(sizeof(Heap));
  new->capac = 3; // "Considere capac inicial 3"
  new->size = 0;
  new->heapArray = malloc(sizeof(heapElem) * new->capac);
  return new;
}
