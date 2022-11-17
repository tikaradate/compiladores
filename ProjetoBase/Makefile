 # -------------------------------------------------------------------
 #            Arquivo: Makefile
 # -------------------------------------------------------------------
 #              Autor: Bruno Müller Junior
 #               Data: 08/2007
 #      Atualizado em: [09/08/2020, 19h:01m]
 #
 # -------------------------------------------------------------------

$DEPURA=1

compilador: lex.yy.c compilador.tab.c compilador.o tabela_simb.o simbolo.o
	gcc lex.yy.c compilador.tab.c compilador.o tabela_simb.o simbolo.o -o compilador -lfl -L /usr/lib/x86_64-linux-gnu -ly -lc

lex.yy.c: compilador.l compilador.h
	flex compilador.l

compilador.tab.c: compilador.y compilador.h
	bison compilador.y -d -v

tabela_simb.o: tabela_simb/tabela_simb.c tabela_simb/tabela_simb.h
	gcc -c tabela_simb/tabela_simb.c -o tabela_simb.o

simbolo.o: tabela_simb/simbolo.c tabela_simb/simbolo.h
	gcc -c tabela_simb/simbolo.c -o simbolo.o

compilador.o : compilador.h compiladorF.c
	gcc -c compiladorF.c -o compilador.o

clean :
	rm -f compilador.tab.* lex.yy.c *.o compilador
