/*
 *  another programming language 
 *  Copyright (c) 2022 Leonardo Zamboni
 * 
 *  this program is free software: you can redistribute it and/or modify
 *  it under the terms of the gnu general public license as published by
 *  the free software foundation, either version 3 of the license, or
 *  (at your option) any later version.
 *  
 *  this program is distributed in the hope that it will be useful,
 *  but without any warranty; without even the implied warranty of
 *  merchantability or fitness for a particular purpose.  see the
 *  gnu general public license for more details.
 *  
 *  you should have received a copy of the gnu general public license
 *  along with this program.  if not, see <http://www.gnu.org/licenses/>.
 */ 
#include <stdio.h>
#include <string.h>

typedef struct tokens TKTable_t;

struct tokens 
{
	size_t id;
	char *asm_tk;
	char *pt_tk;
};

static TKTable_t TBTK[] = {
	{ 0,"BSWAP","TROCABYTE" },
	{ 1,"CBW","BYTEPARAPALAVRA" },
	{ 2,"CDQ","" },
	{ 3,"CDQE","" },
}

void
lex (char *str)
{
	char *tk;

	tk = strtok(str, " ");

	while (tk)
	{
		printf("\"%s\" ", tk);

		tk = strtok(NULL, " ");
	}

}


int 
main (void) 
{
	char str[100] = "isso aqui eh um teste para um futuro lexer";
	lex(str);
	return 0;
}
