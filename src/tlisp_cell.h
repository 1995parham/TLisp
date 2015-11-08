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

#define tlisp_list(...) _tlisp_list((struct tlisp_cell *[]){__VA_ARGS__, NULL})

struct tlisp_cell {
	struct tlisp_cell *car;
	struct tlisp_cell *cdr;

	int is_atom;
	int value;
};

struct tlisp_cell *_tlisp_list(struct tlisp_cell **cs);

struct tlisp_cell *tlisp_cons(struct tlisp_cell *c1, struct tlisp_cell *c2);

struct tlisp_cell *tlisp_atom(int value);

void tlisp_car(const struct tlisp_cell *c);

void tlisp_cdr(const struct tlisp_cell *c);

#endif
