#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */
	//q[q -> size] = 	proc;
	if (empty(q)) {
		q -> proc[0] == proc;
		q -> size++;
		return;
	}
	int idx = 0;
	for (int i = 0; i < q -> size; i++) {
		if (q -> proc[i] -> priority > proc -> priority) {
			break;
		}
		idx++;
	}
	q -> size++;
	for (int j = q -> size - 1; j > idx; j--) {
		q -> proc[j] = q -> proc[j - 1];
	}
	q -> proc[idx] = proc;
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if (empty(q)) return;
	struct pcb_t * temp = q -> proc[0];
	for (int i = 0; i < q -> size - 1; i++) {
		q -> proc[i] = q -> proc[i + 1];
	}
	q -> proc[q -> size - 1] = NULL;
	q -> size--;
	return temp;
}

