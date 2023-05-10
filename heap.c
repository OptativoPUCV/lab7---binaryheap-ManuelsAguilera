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

void *heap_top(Heap *pq) { 
	if (pq->size != 0) return pq->heapArray[0].data;
	return NULL;
	
}

void heap_push(Heap *pq, void *data, int priority) {}

void heap_pop(Heap *pq) {}

Heap *createHeap() { 
	Heap *new = malloc(sizeof(Heap));
	new->capac = 3; // "Considere capac inicial 3"
	new->size=0;
	new->heapArray = malloc(sizeof(heapElem) * new->capac);
	return new; 
}
