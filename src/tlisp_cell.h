/*
 * In The Name Of God
 * ========================================
 * [] File Name : cell.h
 *
 * [] Creation Date : 08-11-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#ifndef TLISP_CELL_H
#define TLISP_CELL_H

#include <stdint.h>

#define tlisp_list(...) _tlisp_list((struct tlisp_cell *[]){__VA_ARGS__, NULL})

struct tlisp_cell {
	union {
		struct tlisp_cell *car;
		uint64_t value;
	};

	struct tlisp_cell *cdr;

	int is_atom;
	int ref_count;
};


struct tlisp_cell *_tlisp_list(struct tlisp_cell **cs);

struct tlisp_cell *tlisp_cons(struct tlisp_cell *c1, struct tlisp_cell *c2);

void tlisp_free(struct tlisp_cell *c);

void tlisp_chain_free(struct tlisp_cell *c);

struct tlisp_cell *tlisp_atom(uint64_t value);

void tlisp_car_print(const struct tlisp_cell *c);

void tlisp_cdr_print(const struct tlisp_cell *c);

void tlisp_print(const struct tlisp_cell *c);

#endif
