#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

void v_print(Vector *v) {
	printf("length: %d, capacity: %d\n", (int)v->length, (int)v->capacity);
	printf("[");
	for (int i = 0; i < v->length; i++) {
		printf("%d", v->data[i]);

		if (i != v->length - 1) {
			printf(", ");
		}
	}
	printf("]\n");
}

int main(int argc, char *argv[]) {
	Vector *v = v_create(0);

	for (int i = 0; i < 6; i++) {
		v_push(v, i);
		v_print(v);
	}

	for (int i = 0; i < 7; i++) {
		int n = 0;
		bool popped = v_pop(v, &n);

		if (!popped) {
			printf("Failed to pop, vector is empty!\n");
		}

		printf("Number: %d\n", n);
		v_print(v);
	}

	v_resize(v, 69);
	v_print(v);

	v_resize(v, 0);
	v_print(v);

	v_free(v);

	return EXIT_SUCCESS;
}
