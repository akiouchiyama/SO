# Arquivo Makefile -  SO
CC=gcc
# Arquivos fonte
FONTES=projeto1.c Arquivos.c
OBJETOS=$(FONTES:.c=.o)
EXECUTAVEL=projeto

#Dependencias de Compilacao
all: $(EXECUTAVEL)

projSO: arquivo.o mergesort.o
	$(CC) -o projeto1 projeto1.c arquivo.o

arquivo.o: arquivo.c arquivo.h
	$(CC) -c arquivo.c

#Limpeza
clean:
	rm -f $(OBJETOS) $(EXECUTAVEL)