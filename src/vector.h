#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stdint.h>

typedef struct {
	uint64_t length;
	uint64_t capacity;
	int *data;
} Vector;

Vector *v_create(uint64_t length);

void v_resize(Vector *v, uint64_t length);

void v_push(Vector *v, int n);

bool v_pop(Vector *v, int *n);

void v_free(Vector *v);

#endif // !VECTOR_H
