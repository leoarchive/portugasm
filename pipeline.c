/*
 *  Portugasm
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
#include <stdlib.h>
#include <string.h>

#define BUILD_FILE "build"

typedef struct portugasm PtAsm_t;

typedef struct content_tks ContTks_t;

struct content_tks
{
    char *tk;
    ContTks_t *n;
};

/*
 * PTASM TOKEN LIST
 */
struct portugasm
{
    ContTks_t *tks;
    ContTks_t *i;
};

typedef struct tokens Tokens_t;

#define NTKS (sizeof (TK) / sizeof (Tokens_t))

struct tokens
{
    char *asm_tk;
    char *pt_tk;
};

static Tokens_t TK[] =
{
    { "SECTION","SECAO" },
    { ".data",".dados" },
    { "SECTION .data","SECAO_DE_DADOS" },
    { ".bss",".blcinc" },
    { "SECTION .bss","SECAO_INICIAL" },
    { ".text",".texto" },
    { "SECTION .text","SECAO_DE_TEXTO" },
    { "main","principal" },
    { "main:","principal:" },
    /*
     * TYPES
     */
    { "DB","1BYTE" },
    { "DW","2BYTE" },
    { "DD","4BYTE" },
    { "DQ","8BYTE" },
    { "DT","10BYTE" },
    /*
     * INSTRUCTIONS
     */
    { "ADD","ADICIONAR" },
    { "MOV","MOVER" },
    { "SUB","SUBTRAIR" },
    { "DIV","DIVIDIR" },
    { "MUL","MULTIPLICAR" },
    { "RET","RETORNAR" },
};

PtAsm_t *
create ()
{
    PtAsm_t *ptasm = malloc(sizeof(PtAsm_t));
    ptasm->tks = malloc(sizeof(ContTks_t));
    ptasm->tks->n = NULL;
    ptasm->tks->tk = NULL;
    ptasm->i = ptasm->tks;
    return ptasm;
}

void
get_content_tk (PtAsm_t **ptasm, char *tk)
{
    ContTks_t *n = malloc(sizeof(ContTks_t));
    n->n = NULL;
    n->tk = malloc(sizeof(tk));
    strcpy(n->tk, tk);
    (*ptasm)->tks->n = n;
    (*ptasm)->tks = n;
}

void
lex (PtAsm_t **ptasm, FILE *pt)
{
    char bff[255];
    char *tk;

    while (fgets(bff, 255, pt))
        {
            tk = strtok(bff, " ");

            while (tk)
                {

                    if (tk[strlen(tk) - 1] == '\n')
                        {
                            tk[strlen(tk) - 1] = '\0';
                            get_content_tk (&(*ptasm), tk);
                            get_content_tk (&(*ptasm), "\n");
                        }
                    else
                        {
                            get_content_tk (&(*ptasm), tk);
                        }

                    tk = strtok(NULL, " ");
                }

            if(ferror(pt)) exit (EXIT_FAILURE);
        }
}

void
set_source_file (ContTks_t *in, FILE *src)
{
    if (!in) return;
    if (in->tk && strcmp(in->tk, "\n") == 0)
        {
            fprintf(src, "%s", in->tk);
        }
    else if (in->tk && strcmp(in->tk,"\0"))
        {
            Tokens_t tk;
            size_t i;
            for (i = 0; i < NTKS; ++i)
                {
                    tk = TK[i];
                    if (strcmp(in->tk, tk.pt_tk) == 0) break;
                }

            fprintf(src, "%s ", i < NTKS ? tk.asm_tk : in->tk);
        }

    set_source_file (in->n, src);
}

int
main (int argc, char **argv)
{
    FILE *pt = fopen(argv[1],"r");
    if (!pt) exit (EXIT_FAILURE);

    char cmd_build_file[
     strlen("mkdir -p ") + strlen(BUILD_FILE)];

    strcpy(cmd_build_file, "mkdir -p ");
    strcat(cmd_build_file, BUILD_FILE);
    system(cmd_build_file);

    char build_file[
     strlen(BUILD_FILE) + strlen(argv[1]) + 1];

    strcpy(build_file, BUILD_FILE);
    strcat(build_file, "/");
    strcat(build_file, argv[1]);

    FILE *src = fopen(build_file,"w");
    if (!src) exit (EXIT_FAILURE);

    PtAsm_t *ptasm = create();

    lex(&ptasm, pt);

    set_source_file (ptasm->i, src);

    fclose (src);
    fclose (pt);

    return 0;
}
