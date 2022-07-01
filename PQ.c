#include "PQ.h"

PQItem* PQItemCreate(void* const _data, size_t _priority) {
    PQItem* item = NULL;

    if ((item = (PQItem*) malloc(sizeof(PQItem))) != NULL) {
        item->next = NULL;

        item->priority = _priority;
        item->data = _data;
    }

    return item;
}

int auxiliaryPQInsert(PQItem* _src, PQItem* _dest) {
    if (_dest->next == NULL)
        _dest->next = _src;
    else if (_src->priority > _dest->next->priority) {
        _src->next = _dest->next;
        _dest->next = _src;
    }
    else
        return auxiliaryPQInsert(_src, _dest->next);

    return EXIT_SUCCESS;
}

void PQItemPrint(PQItem* _item, void (*print_fptr)(PQItem* const _item)) {
    if (_item != NULL) {
        printf("(P: %2llu; Data: ", _item->priority);
        print_fptr(_item);
        printf(")\n");
    }

    return ;
}

/* ---------------------------------------------------------------- */

extern PQItem* PQItemDelete(PQItem* _item) {
    if (_item != NULL) {
        free(_item->data);
        free(_item);

        _item = NULL;
    }

    return _item;
}

PQ* PQCreate(void) {
    PQ* queue = NULL;

    if ((queue = (PQ*) malloc(sizeof(PQ))) != NULL) {
        queue->highest = NULL;

        queue->size = 0;
    }

    return queue;
}


int PQInsert(PQ* _queue, void* const _data, size_t _priority) {
    PQItem* item = NULL;

    if (_queue != NULL) {
        if ((item = PQItemCreate(_data, _priority)) != NULL) {
            if (_queue->size == 0) {
                _queue->highest = item;
            }
            else if (item->priority > _queue->highest->priority) {
                item->next = _queue->highest;
                _queue->highest = item;
            }
            else
                auxiliaryPQInsert(item, _queue->highest);
        }

        _queue->size++;
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}

extern void PQPrint(PQ* const _queue, void (*print_fptr)(PQItem* const _item)) {
    PQItem* item = NULL;

    if (_queue != NULL) {
        if (_queue->size > 0) {
            for (item = _queue->highest; item != NULL; item = item->next)
                PQItemPrint(item, print_fptr);

            printf("\n");
        }
    }

    return ;
}

extern PQItem* PQPop(PQ* const _queue) {
    PQItem* item = NULL;

    if (_queue != NULL) {
        if (_queue->size > 0) {
            item = _queue->highest;
            _queue->highest = _queue->highest->next;
            _queue->size--;
        }
    }

    return item;
}
