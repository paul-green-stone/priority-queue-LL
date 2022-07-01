#ifndef _PQ
#define _PQ

/* ---------------------------------------------------------------- */
/*                 27.06.2022 Paul Green Stone                      */
/* ---------------------------------------------------------------- */

typedef struct PriorityQueueItem {
    struct PriorityQueueItem* next;

    size_t priority;
    void* data;
} PQItem;

typedef struct PriorityQueue {
    struct PriorityQueueItem* highest;
    size_t size;
} PQ;

#endif
