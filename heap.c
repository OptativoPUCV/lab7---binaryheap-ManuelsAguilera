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

void vieww_array(Heap *h) {
  int i;
  printf("\t[");
  for (i = 0; i < h->size; i++) {
    printf("%d ", h->heapArray[i].priority);
  }
  printf("]\n");
}

void swap(heapElem *arr, int a, int b) // recibe la posicion de ambos
{
  heapElem aux = arr[a];
  arr[a] = arr[b];
  arr[b] = aux;
}
void heapify_d(Heap *H,
               int index) // compara con hijos hasta // que el heap sea valido
{
  int left, right;
  left = (2 * index) + 1;
  right = (2 * index) + 2;

	if (left > H->size || right > H->size)

  if (H->heapArray[index].priority > H->heapArray[left].priority)
  {
	  swap(H->heapArray,left,index);
	  heapify_d(H,left);	
  }
	else if (H->heapArray[index].priority > H->heapArray[right].priority)
	{
		swap(H->heapArray,left,index);
		heapify_d(H,right);
	}
	else 
		return;
}

void heapify_u(Heap *H, int index) //  compara con el padre hasta
{                     
	// que el heap sea valido
	
  int parent = (index - 1) / 2;
  if (H->heapArray[parent].priority >= H->heapArray[index].priority)
    return;
  else {
    swap(H->heapArray, parent, index);
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

	  pq->capac *= 2;
    pq->capac++;
    array = (heapElem *)realloc(array, sizeof(heapElem)* pq->capac);
    
	  vieww_array(pq);
  }
	
  heapElem new;
  new.data = data;
  new.priority = priority;
	
  array[pq->size - 1] = new;

	
  heapify_u(pq, pq->size - 1);
}

void heap_pop(Heap *pq) {
  if (pq->size == 0)
    return;
  swap(pq->heapArray, 0, pq->size - 1);
	pq->size--;
  heapify_d(pq, 0);
  
}

Heap *createHeap() {
  Heap *new = malloc(sizeof(Heap));
  new->capac = 3; // "Considere capac inicial 3"
  new->size = 0;
  new->heapArray = malloc(sizeof(heapElem) * new->capac);
  return new;
}
