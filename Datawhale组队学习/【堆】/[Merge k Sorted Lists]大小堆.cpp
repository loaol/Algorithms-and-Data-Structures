typedef enum heap_type_e heap_type_t;
typedef struct heap_s heap_t;

enum heap_type_e {
    min_heap = 0,
    max_heap,
};

struct heap_s {
    heap_type_t     type;
    struct ListNode **values;
    int             size;
    int             index;
};

struct ListNode *heap_pop(heap_t *heap) {
    int     parent, child1, child2, next;
    struct ListNode *ret, *last;
    
    if (heap->index <= 0) {
        return NULL;
    }
    
    heap->index--;
    ret = heap->values[0];
    last = heap->values[heap->index];
    parent = 0;
    
    while (parent < heap->index) {
        child1 = parent * 2 + 1;
        child2 = parent * 2 + 2;
        
        if (child1 < heap->index && heap_compare(heap, last, heap->values[child1]) > 0) {
            if (child2 < heap->index && heap_compare(heap, heap->values[child1], heap->values[child2]) > 0) {
                next = child2;
            } else {
                next = child1;
            }
        } else if (child2 < heap->index && heap_compare(heap, last, heap->values[child2]) > 0) {
            next = child2;
        } else {
            heap->values[parent] = last;
            break;
        }
        
        heap->values[parent] = heap->values[next];
        parent = next;
    }
    
    return ret;
}

void heap_insert(heap_t *heap, struct ListNode *v) {
    int     parent, index;
    
    if (heap->index >= heap->size) {
        return;
    }
    
    index = heap->index;
    heap->index++;
    while (index > 0) {
        parent = (index - 1) / 2;
        
        if (heap_compare(heap, v, heap->values[parent]) < 0) {
            heap->values[index] = heap->values[parent];
            index = parent;
            continue;
        }
        
        break;
    }
    
    heap->values[index] = v;
    return;
}

int heap_compare(heap_t *heap, struct ListNode *v1, struct ListNode *v2) {
    if (heap->type == min_heap) {
        return v1->val - v2->val;
    } else {
        return -(v1->val - v2->val);
    }
}

heap_t *heap_create(heap_type_t type, int size) {
    heap_t      *heap;
    
    heap = calloc(1, sizeof(heap_t));
    if (heap == NULL) {
        return NULL;
    }
    
    heap->values = calloc(size, sizeof(struct ListNode*));
    if (heap->values == NULL) {
        return NULL;
    }
    
    heap->size = size;
    heap->index = 0;
    heap->type = type;
    
    return heap;
}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int             i;
    heap_t          *heap;
    struct ListNode *head, *pre, *next;;
    
    if (listsSize == 0) return NULL;
    
    heap = heap_create(min_heap, listsSize);
    if (heap == NULL) {
        return NULL;
    }
    
    for (i = 0; i < listsSize; i++) {
        if (lists[i] == NULL) { continue; }
        heap_insert(heap, lists[i]);
    }
    
    head = heap_pop(heap);
    if (head == NULL) {
        return NULL;
    }
    if (head->next != NULL) {
        heap_insert(heap, head->next);
    }
    pre = head;
    
    do {
        next = heap_pop(heap);
        
        pre->next = next;
        if (next == NULL) {
            break;
        }
         
        if (next->next != NULL) {
            heap_insert(heap, next->next);
        }
        pre = pre->next;
    } while (true);

    return head;
}
