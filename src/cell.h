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

struct cell {
	struct cell *car;
	struct cell *cdr;

	int is_atom;
	int value;
};

struct cell *cons(struct cell *c1, struct cell *c2);

struct cell *atom(int value);

void car(const struct cell *c);

void cdr(const struct cell *c);

#endif
