#ifndef HEADER_MATH_H_INCLUDED
#define HEADER_MATH_H_INCLUDED

#include <iostream>
#include <locale.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

using namespace std;


class Jogador
{
    protected:
        char *nome;
        long int record;

    public:
        Jogador(char *);
        ~Jogador();
        char *get_nome();
};

class Game
{
    protected:
        double operando1;
        double operando2;
        long int pontos;
        char operador;

    public:
        Game(char);
        long int get_pontos();
};

bool verifica(FILE *, char *);
void msgEntrada();
char dificuldade();
void recorde(FILE *, char *, long int);
bool sair_game();
void listar_recordes(FILE *);

#endif // HEADER_MATH_H_INCLUDED
