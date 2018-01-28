#include "header_math.h"


bool verifica(FILE *score, char *nome)
{
    strcpy(nome, strcat(nome, ".txt"));

    if ((score = fopen(nome, "rt")) != NULL)
    {
        fclose(score);
        return true;
    }
    else
    {
        fclose(score);
        return false;
    }
}

void msgEntrada()
{
    setlocale(LC_ALL, "Portuguese");

    cout << "Autor: Thalyson Alexandre R. de Sousa   |" << endl;
    cout << "Versão: 00.01                           |" << endl;
    cout << "Plataformas: Windows Vista/XP/7/8/8.1/10|" << endl;
    Sleep(1500);
    system("cls");
    cout << "|------------------------------------|" << endl;
    cout << "|+-x/+x-< JOGO DE MATEMÁTICA >+-x/x+-|" << endl;
    cout << "|------------------------------------|" << endl;
}

char dificuldade()
{
    char resposta;
    cout << "     Selecione a dificuldade\n\n";
    cout << "  (F)acil   (N)ormal   (D)ificil\n\n";
    cout << ">> "; resposta = toupper(getche());
    cout << "\n\n";
    return resposta;
}

void recorde(FILE *score, char *nome, long int pontos)
{
    strcpy(nome, strcat(nome, ".txt"));

    if ((score = fopen(nome, "wt")) == NULL)
        cout << "\nErro interno!" << endl;
    else
    {
        fprintf(score, "%ld", pontos);
        cout << "\n\nSalvo na pasta de exec do programa!" << endl;
    }
    fclose(score);

    FILE *recordes;

    if ((recordes = fopen("recordes.txt", "at")) == NULL)
        cout << "\nErro interno!" << endl;
    else
    {
        fprintf(recordes, "%s", nome);
        fprintf(recordes, "\n");
        fprintf(recordes, "%d", pontos);
        fprintf(recordes, "\n");
    }
    fclose(recordes);
}

bool sair_game()
{
    char resposta;

    cout << "(S)air (C)ontinuar: ";
    resposta = toupper(getche());
    if (resposta == 'S')
        exit(0);
    else if (resposta == 'C')
        return false;
    else
        return true;
}

void listar_recordes(FILE *score)
{
    char *conteudo;

    conteudo = (char *)malloc(200 * sizeof(char));

    if ((score = fopen("recordes.txt", "rb")) == NULL)
        return;
    else
    {
        cout << "    RECORDES  \n\n";
        while (fgets(conteudo, 200, score) != NULL)
            cout << conteudo;
        fclose(score);
    }
}
