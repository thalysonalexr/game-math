#include "header_math.h"


Game::Game(char resposta)
{
    int tentativas = 10;
    double resposta_certa;
    double compara;
    int level;

    this->pontos = 0;

    if (resposta == 'F')
        level = 10;
    else if (resposta == 'N')
        level = 100;
    else if (resposta == 'D')
        level = 1000;

    while (tentativas != 0)
    {
        srand((unsigned)time(NULL));
        int decisao = 1+(rand()%4);

        this->operando1 = 1+(rand()%level);
        this->operando2 = 1+(rand()%level);

        if (decisao == 1)
        {
            this->operador = '+';
            resposta_certa = this->operando1 + this->operando2;
        }
        else if (decisao == 2)
        {
            this->operador = '-';
            resposta_certa = this->operando1 - this->operando2;
        }
        else if (decisao == 3)
        {
            this->operador = 'x';
            resposta_certa = this->operando1 * this->operando2;
        }
        else if (decisao == 4)
        {
            this->operador = '/';
            resposta_certa = this->operando1 / this->operando2;
        }

        cout << this->operando1 << " " << this->operador << " " << this->operando2 << " = ";
        cin >> compara;

        if (compara == resposta_certa)
            pontos += 10;

        --tentativas;
    }
}


long int Game::get_pontos()
{
    return pontos;
}
