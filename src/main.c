/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 08-11-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#include "tlisp_cell.h"
#include "tlisp_select.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	struct tlisp_cell *x = tlisp_atom(10);
	struct tlisp_cell *lst = tlisp_list(
		x, tlisp_atom(20), tlisp_atom(30));
	tlisp_print(lst);
	printf("\n");
	lst = select_2(x, lst);
	tlisp_print(lst);
	printf("\n");
	tlisp_chain_free(lst);
	tlisp_chain_free(x);
}
