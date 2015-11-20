/*
 * In The Name Of God
 * ========================================
 * [] File Name : tlisp_select
 *
 * [] Creation Date : 20-11-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#include <stddef.h>
#include <stdlib.h>
#include "tlisp_select.h"
#include "tlisp_cell.h"

struct tlisp_cell *select_1(struct tlisp_cell *x, struct tlisp_cell *lst)
{
	struct tlisp_cell *ptr;

	for (ptr = lst; ptr != NULL;) {
		if (ptr->car == x) {
			return ptr->cdr;
		} else {
			ptr = ptr->cdr;
		}
	}
	return NULL;
}

struct tlisp_cell *select_2(struct tlisp_cell *x, struct tlisp_cell *lst)
{
	struct tlisp_cell *ptr;
	struct tlisp_cell *previous;

	for (ptr = lst; ptr != NULL;) {
		previous = ptr;
		if (ptr->car == x) {
			previous = ptr->cdr;
			tlisp_chain_free(ptr->car);
			tlisp_free(ptr);
			return previous;
		} else {
			ptr = ptr->cdr;
		}
		tlisp_chain_free(previous->car);
		tlisp_free(previous);
	}
	return NULL;
}
