/*
* Autor  : Thalyson Alexandre R. de Sousa
* Versão : 00.01
*/
#include "header_math.h"


int main()
{
    FILE *score;
    char nome_jogador[30], *local;
    char resposta;

    jogar_novamente: //goto

    msgEntrada();
    listar_recordes(score);
    Game matematica(dificuldade());

    cout << "Seus pontos: "  << matematica.get_pontos() << endl;
    salvar: //goto
    cout << "\n\nSalvar pontuacao (s)im (n)ão: ";
    resposta = toupper(getche()); cout << "\n\n";
    
    if (resposta == 'S')
    {
        digitar_nome: //goto
        cout << "\n\nDigite seu nome: ";
        fflush(stdin); gets(nome_jogador);
        Jogador jogador(nome_jogador);

        if ((verifica(score, nome_jogador)) == true)
        {
            cout << "\n\nScore já existente com esse nome, deseja sobrescrever? (S)im (N)ão: ";
            resposta = toupper(getche());
            if (resposta == 'S')
                recorde(score, jogador.get_nome(), matematica.get_pontos());
            else
                goto digitar_nome;
        }
        else
            recorde(score, jogador.get_nome(), matematica.get_pontos());
    }
    else if (resposta == 'N')
        system("");
    else
        goto salvar;

    if (sair_game() == false)
    {
        system("cls");
        goto jogar_novamente;
    }
    return 0;
}
