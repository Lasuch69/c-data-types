#include <stdlib.h>

#include "vector.h"

uint64_t _po2(uint64_t n) {
	uint64_t po2 = 1;
	while (po2 < n) {
		po2 = po2 << 1;
	}

	return po2;
}

void _v_realloc(Vector *v, uint64_t capacity) {
	v->data = (int *)realloc(v->data, sizeof(int) * capacity);
	v->capacity = capacity;
}

Vector *v_create(uint64_t length) {
	uint64_t capacity = _po2(length);

	Vector *v = (Vector *)malloc(sizeof(Vector));
	v->length = length;
	v->capacity = capacity;
	v->data = (int *)malloc(sizeof(int) * capacity);

	for (int i = 0; i < length; i++) {
		v->data[i] = 0;
	}

	return v;
}

void v_resize(Vector *v, uint64_t length) {
	uint64_t new_capacity = _po2(length);
	_v_realloc(v, new_capacity);

	for (int i = v->length; i < length; i++) {
		v->data[i] = 0;
	}

	v->length = length;
}

void v_push(Vector *v, int n) {
	if (v->length == v->capacity) {
		// vector full; double on capacity
		_v_realloc(v, v->capacity << 1);
	}

	v->data[v->length] = n;
	v->length += 1;
}

bool v_pop(Vector *v, int *n) {
	if (v->length == 0) {
		return false;
	}

	*n = v->data[v->length - 1];
	v->length -= 1;

	uint64_t new_capacity = _po2(v->length);
	_v_realloc(v, new_capacity);

	return true;
}

void v_free(Vector *v) {
	free(v->data);
	free(v);
}
