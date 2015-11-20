# TLisp
## Introduction to Lisp
Lisp (historically, LISP) is a family of computer programming languages with
a long history and a distinctive, fully parenthesized Polish prefix notation.
Originally specified in 1958, Lisp is the second-oldest high-level programming
language in widespread use today; only Fortran is older (by one year).
## TLisp, Why ?, When ?
TLisp is a simple and dummy C library try to simulate LISP calculation core
just for FUN :)
## TLisp capabilities
1. Create list
```c
struct tlisp_cell *lst = tlisp_list(
		tlisp_atom(10), tlisp_atom(20), tlisp_atom(30)
		);
```
2. Create con cells
```c
struct tlisp_cell *tlisp_cons(struct tlisp_cell *c1, struct tlisp_cell *c2);
```
3. Create atoms
```c
struct tlisp_cell *tlisp_atom(uint64_t value);
```
4. Reference counting based memory management
```c
void tlisp_free(struct tlisp_cell *c);
void tlisp_chain_free(struct tlisp_cell *c);
```
## Contribute
If you have time .... fork and code ... :)
## Copyright
GPLv2 :)