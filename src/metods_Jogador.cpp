#include "header_math.h"


Jogador::Jogador(char *nome)
{
    this->nome = new char[strlen(nome)+1];
    strcpy(this->nome, nome);
}

Jogador::~Jogador()
{
    delete[] this->nome;
}

char *Jogador::get_nome()
{
    return nome;
}
