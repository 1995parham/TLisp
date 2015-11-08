/*
 * In The Name Of God
 * ========================================
 * [] File Name : cell.c
 *
 * [] Creation Date : 09-11-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#include "tlisp_cell.h"
#include <stdlib.h>
#include <stdio.h>

struct tlisp_cell *tlisp_cons(struct tlisp_cell *c1, struct tlisp_cell *c2)
{
	struct tlisp_cell *new;

	new = (struct tlisp_cell *) malloc(sizeof(struct tlisp_cell));
	new->car = c1;
	new->cdr = c2;
	new->is_atom = 0;
	return new;
}

void tlisp_cdr(const struct tlisp_cell *c)
{
	if (!c->cdr) {
		return;
	} else if (c->cdr->is_atom) {
		printf("%d", c->cdr->value);
	} else {
		printf("(");
		tlisp_car(c->cdr);
		printf(", ");
		tlisp_cdr(c->cdr);
		printf(")");
	}
}

struct tlisp_cell *tlisp_atom(int value)
{
	struct tlisp_cell *new;

	new = (struct tlisp_cell *) malloc(sizeof(struct tlisp_cell));
	new->value = value;
	new->cdr = NULL;
	new->car = NULL;
	new->is_atom = 1;
	return new;
}

void tlisp_car(const struct tlisp_cell *c)
{
	if (!c->car) {
		return;
	} else if (c->car->is_atom) {
		printf("%d", c->car->value);
	} else {
		printf("(");
		tlisp_car(c->car);
		printf(", ");
		tlisp_cdr(c->car);
		printf(")");
	}
}

struct tlisp_cell *_tlisp_list(struct tlisp_cell **cs)
{
	struct tlisp_cell *base, *it;

	base = (struct tlisp_cell *) malloc(sizeof(struct tlisp_cell));
	it = base;
	while (*cs != NULL) {
		it->car = *cs;
		it->is_atom = 0;
		if (*(cs + 1)) {
			it->cdr = (struct tlisp_cell *) malloc(
				sizeof(struct tlisp_cell));
			it = it->cdr;
		} else {
			it->cdr = NULL;
		}
		cs++;
	}

	return base;
}
