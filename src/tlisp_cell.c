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
	new->ref_count = 0;
	c1->ref_count++;
	c2->ref_count++;
	return new;
}

void tlisp_chain_free(struct tlisp_cell *c)
{
	if (c->ref_count > 0) {
		return;
	}
	if (!c->is_atom) {
		if (c->cdr) {
			c->cdr->ref_count--;
			tlisp_chain_free(c->cdr);
		}
		if (c->car) {
			c->car->ref_count--;
			tlisp_chain_free(c->car);
		}
	}
	free(c);
}

void tlisp_free(struct tlisp_cell *c)
{
	if (c->ref_count > 0) {
		return;
	}
	if (!c->is_atom) {
		if (c->cdr) {
			c->cdr->ref_count--;
		}
		if (c->car) {
			c->car->ref_count--;
		}
	}
	free(c);
}

void tlisp_print(const struct tlisp_cell *c)
{
	if (c->is_atom) {
		printf("%lld", c->value);
	} else {
		printf("(");
		tlisp_car_print(c);
		printf(", ");
		tlisp_cdr_print(c);
		printf(")");
	}
}

void tlisp_cdr_print(const struct tlisp_cell *c)
{
	if (!c->cdr) {
		printf("NULL");
	} else if (c->cdr->is_atom) {
		printf("%lld", c->cdr->value);
	} else {
		printf("(");
		tlisp_car_print(c->cdr);
		printf(", ");
		tlisp_cdr_print(c->cdr);
		printf(")");
	}
}

struct tlisp_cell *tlisp_atom(uint64_t value)
{
	struct tlisp_cell *new;

	new = (struct tlisp_cell *) malloc(sizeof(struct tlisp_cell));
	new->value = value;
	new->cdr = NULL;
	new->ref_count = 0;
	new->is_atom = 1;
	return new;
}

void tlisp_car_print(const struct tlisp_cell *c)
{
	if (!c->car) {
		printf("NULL");
	} else if (c->car->is_atom) {
		printf("%lld", c->car->value);
	} else {
		printf("(");
		tlisp_car_print(c->car);
		printf(", ");
		tlisp_cdr_print(c->car);
		printf(")");
	}
}

struct tlisp_cell *_tlisp_list(struct tlisp_cell **cs)
{
	struct tlisp_cell *base, *it;

	base = (struct tlisp_cell *) malloc(sizeof(struct tlisp_cell));
	it = base;
	it->ref_count = 0;
	while (*cs != NULL) {
		it->car = *cs;
		(*cs)->ref_count++;
		it->is_atom = 0;
		if (*(cs + 1)) {
			it->cdr = (struct tlisp_cell *) malloc(
				sizeof(struct tlisp_cell));
			it->cdr->ref_count = 1;
			it = it->cdr;
		} else {
			it->cdr = NULL;
		}
		cs++;
	}

	return base;
}
