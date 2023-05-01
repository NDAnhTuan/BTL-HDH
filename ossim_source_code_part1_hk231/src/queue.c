#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */
	//q[q -> size] = 	proc;
	int idx = 0;
	for (int i = 0; i < q -> size; i++) {
		if (q -> proc[i] -> prioprity > proc -> prioprity) {
			break;
		}
		idx++;
	}
	q -> size++;
	for (int j = q -> size - 1; j > idx; j--) {
		q[j] = q[j - 1];
	}
	q[idx] = proc;
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	struct pcb_t * temp = q[0];
	for (int i = 0; i < q -> size - 1; i++) {
		q[i] = q[i + 1];
	}
	q[size - 1] = NULL;
	q -> size--;
	return temp;
}

