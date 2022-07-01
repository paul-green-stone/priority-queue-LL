#include <stdio.h>
#include <stdlib.h>

#include "PQ-type.h"

#define IS_EMPTY(_queue) (_queue->size == 0)

extern PQItem* PQItemDelete(PQItem* _item);

extern PQ* PQCreate(void);

extern int PQInsert(PQ* const _queue, void* const _data, size_t _priority);

extern void PQPrint(PQ* const _queue, void (*print_fptr)(PQItem* const));

extern PQItem* PQPop(PQ* _queue);
