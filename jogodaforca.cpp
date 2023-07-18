////Jogo criado a partir das aulas de c++ da plataforma Alura.
////Alguns pontos foram aprimorados.
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
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

        if(arquivo.is_open()) {
            int qtd_palavras;
            arquivo >> qtd_palavras;

            for (int i = 0; i < qtd_palavras; i++) {
                string palavras;
                arquivo >> palavras;
                lista.push_back(palavras);
            }
            arquivo.close();
            return lista;
        } else {
            cerr << "\nArquivo nao encontrado!"<<endl;
        }
    } else if (resposta == 2) {
        cout << "Voce escolheu o tema objetos." << endl;
        ifstream arquivo("objetos.txt");

        if(arquivo.is_open()) {
            int qtd_palavras;
            arquivo >> qtd_palavras;

            for (int i = 0; i < qtd_palavras; i++) {
                string palavras;
                arquivo >> palavras;
                lista.push_back(palavras);
            }
            arquivo.close();
            return lista;
        } else {
            cerr <<"\nArquivo nao encontrado! "<<endl;
        }
    } else if (resposta == 3) {
        cout << "Voce escolheu o tema lugares." << endl;
        ifstream arquivo("lugares.txt");
        
        if(arquivo.is_open()) {
            int qtd_palavras;
            arquivo >> qtd_palavras;

            for (int i = 0; i < qtd_palavras; i++) {
                string palavras;
                arquivo >> palavras;
                lista.push_back(palavras);
            }
            arquivo.close();
            return lista;
        } else {
            cerr << "\nArquivo nao encontrado!"<<endl;
        }
    }
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

vector <string> adiciona_arquivo(int escolha) {

    vector <string> lista;

    if (escolha == 1) {
        ifstream arquivo("frutas.txt");

        if(arquivo.is_open()) {
            int qtd_palavras;
            arquivo >> qtd_palavras;

            for (int i = 0; i < qtd_palavras; i++) {
                string palavras;
                arquivo >> palavras;
                lista.push_back(palavras);
            }
            arquivo.close();
            return lista;
        } else {
            cerr << "\nArquivo nao encontrado!"<<endl;
        }
    } else if (escolha == 2) {
        ifstream arquivo("objetos.txt");

        if(arquivo.is_open()) {
            int qtd_palavras;
            arquivo >> qtd_palavras;

            for (int i = 0; i < qtd_palavras; i++) {
                string palavras;
                arquivo >> palavras;
                lista.push_back(palavras);
            }
            arquivo.close();
            return lista;
        } else {
            cerr <<"\nArquivo nao encontrado! "<<endl;
        }
    } else if (escolha == 3) {
        ifstream arquivo("lugares.txt");
        
        if(arquivo.is_open()) {
            int qtd_palavras;
            arquivo >> qtd_palavras;

            for (int i = 0; i < qtd_palavras; i++) {
                string palavras;
                arquivo >> palavras;
                lista.push_back(palavras);
            }
            arquivo.close();
            return lista;
        } else {
            cerr << "\nArquivo nao encontrado!"<<endl;
        }
    }
}

void salva_arquivo(vector <string> nova_lista, int escolha) {

    if (escolha == 1) {
        ofstream arquivo("frutas.txt");
        if (arquivo.is_open()) {
            arquivo << nova_lista.size() << endl;

            for(string palavra : nova_lista) {
                arquivo << palavra << endl;
            }
            arquivo.close();
        } else {
            cerr << "Nao foi possivel abrir o arquivo para escrita!" << endl;
        }
    } else if (escolha == 2) {
        ofstream arquivo("objetos.txt");
        if (arquivo.is_open()) {
            arquivo << nova_lista.size() << endl;

            for(string palavra : nova_lista) {
                arquivo << palavra << endl;
            }
            arquivo.close();
        } else {
            cerr << "Nao foi possivel abrir o arquivo para escrita!" << endl;
        }
    } else if (escolha == 3) {
        ofstream arquivo("lugares.txt");
        if (arquivo.is_open()) {
            arquivo << nova_lista.size() << endl;

            for(string palavra : nova_lista) {
                arquivo << palavra << endl;
            }
            arquivo.close();
        } else {
            cerr << "Nao foi possivel abrir o arquivo para escrita!" << endl;
        }
    }
}

void adiciona_palavra(int escolha) {
    cout << "Digite a nova palavra, utilizando letras maiusculas" << endl;
    string nova_palavra;
    cin >> nova_palavra;

    if (escolha == 1) {
        ifstream arquivo("frutas.txt");
        vector <string> lista = adiciona_arquivo(escolha);
        lista.push_back(nova_palavra);
        salva_arquivo(lista, escolha);
    } else if (escolha == 2) {
        ifstream arquivo("objetos.txt");
        vector <string> lista = adiciona_arquivo(escolha);
        lista.push_back(nova_palavra);
        salva_arquivo(lista, escolha);
    } else if (escolha == 3) {
        ifstream arquivo("lugares.txt");
        vector <string> lista = adiciona_arquivo(escolha);
        lista.push_back(nova_palavra);
        salva_arquivo(lista, escolha);
    }
    cout << "Palavra adicionada com sucesso!" << endl;
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
        cout << "Voce deseja adicionar uma nova palavra? 1 - SIM 2 - NAO." << endl;
        int escolha;
        cin >> escolha;
        if (escolha == 1) {
            cout << "Sua palavra se encaixa em: 1 - Frutas 2 - Objetos 3 - Lugares?" << endl;
            int resposta;
            cin >> resposta;
            if (resposta == 1) {
                int escolha = 1;
                adiciona_palavra(escolha);
            } else if (resposta == 2) {
                int escolha = 2;
                adiciona_palavra(escolha);
            } else if (resposta == 3) {
                int escolha = 3;
                adiciona_palavra(escolha);
            }
        } 
    }

    return 0;
}
