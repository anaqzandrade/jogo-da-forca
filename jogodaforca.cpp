////Jogo criado a partir das aulas de c++ da plataforma Alura.
////Alguns pontos foram aprimorados.
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

string palavra_secreta;
map <char, bool> chutou;
vector <char> chutes_errados;

////Cabecalho de apresentacao.
void cabecalho() {
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl
         << "Jogo da forca! Voce consegue acertar a palavra secreta?" << endl
         << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl
         << "Aviso: Voce pode dar apenas 6 chutes errados." << endl
         << endl;
}

////Leitura do arquivo para posterior sorteio da palavra secreta.
vector <string> le_arquivo() {
    cout << "Com qual tema deseja jogar? 1 - Frutas 2 - Objetos 3 - Lugares" << endl;
    int resposta;
    cin >> resposta;

    vector <string> lista;

    if (resposta == 1) {
        cout << "Voce escolheu o tema frutas." << endl;
        ifstream arquivo("frutas.txt");
        int qtd_palavras;
        arquivo >> qtd_palavras;

        for (int i = 0; i < qtd_palavras; i++) {
            string palavras;
            arquivo >> palavras;
            lista.push_back(palavras);
        }
    } else if (resposta == 2) {
        cout << "Voce escolheu o tema objetos." << endl;
        ifstream arquivo("objetos.txt");
        int qtd_palavras;
        arquivo >> qtd_palavras;

        for (int i = 0; i < qtd_palavras; i++) {
            string palavras;
            arquivo >> palavras;
            lista.push_back(palavras);
        }
    } else if (resposta == 3) {
        cout << "Voce escolheu o tema lugares." << endl;
        ifstream arquivo("lugares.txt");
        int qtd_palavras;
        arquivo >> qtd_palavras;

        for (int i = 0; i < qtd_palavras; i++) {
            string palavras;
            arquivo >> palavras;
            lista.push_back(palavras);
        }
    }
    return lista;
}

////Sorteio da palavra secreta.
void sorteio() {
    vector <string> palavras = le_arquivo();
    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();

    palavra_secreta = palavras[indice_sorteado];

}

//Verifica se o chute esta presente na palavra.
bool letra_existe(char chute) {
//C++11
    for (char letra : palavra_secreta) {
        if (chute == letra) {
            return true;
        }
    }
    return false;
}

//Verifica se todas as letras ja foram encontradas.
bool nao_acertou() {
    for (char letra : palavra_secreta) {
        if (!chutou[letra]) {
            return true;
        }
    }
    return false;
}

//Verifica se as tentativas nao esgotaram.
bool nao_enforcou() {
    return chutes_errados.size() < 6;
}

////Imprime as letras que foram chutadas e nao estao presentes na palavra secreta.
void erros() {
    cout << "Letras que nao estao na palavra secreta: ";
    for (char letra : chutes_errados) {
        cout << letra << " ";
    }
    cout << endl;
}

////Imprime a palavra sendo sempre atualizada de acordo as tentativas.
void palavra() {
    for (char letra : palavra_secreta) {
        if (chutou[letra]) {
            cout << letra << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

////Pede o chute e informa se o mesmo foi certo ou errado.
void tentativas() {
    cout << "Seu chute: ";
    char chute;
    cin >> chute;

    chutou[chute] = true;

    if (letra_existe(chute)) {
        cout << "Acertou! A letra " << chute << " faz parte da palavra secreta." << endl;
    } else {
        cout << "Errou! A letra " << chute << " nao faz parte da palavra secreta." << endl;
        chutes_errados.push_back(chute);
    }
    cout << endl;
}

int main() {
    cabecalho();
    sorteio();

    while (nao_acertou() and nao_enforcou()) {
        erros();
        palavra();
        tentativas();
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;

    if (nao_acertou()) {
        cout << "Voce perdeu! Seus chutes acabaram, tente novamente." << endl;
    } else {
        cout << "Parabens! Voce ganhou." << endl;
    }

    return 0;
}