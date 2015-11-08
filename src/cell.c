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
#include "cell.h"
#include <stdlib.h>
#include <stdio.h>

struct cell *cons(struct cell *c1, struct cell *c2)
{
	struct cell *new;

	new = (struct cell *) malloc(sizeof(struct cell));
	new->car = c1;
	new->cdr = c2;
	new->is_atom = 0;
	return new;
}

void cdr(const struct cell *c)
{
	if (!c->cdr) {
		return;
	} else if (c->cdr->is_atom) {
		printf("%d", c->cdr->value);
	} else {
		printf("(");
		car(c->cdr);
		printf(", ");
		cdr(c->cdr);
		printf(")");
	}
}

struct cell *atom(int value)
{
	struct cell *new;

	new = (struct cell *) malloc(sizeof(struct cell));
	new->value = value;
	new->cdr = NULL;
	new->car = NULL;
	new->is_atom = 1;
	return new;
}

void car(const struct cell *c)
{
	if (!c->car) {
		return;
	} else if (c->car->is_atom) {
		printf("%d", c->car->value);
	} else {
		printf("(");
		car(c->car);
		printf(", ");
		cdr(c->car);
		printf(")");
	}
}
