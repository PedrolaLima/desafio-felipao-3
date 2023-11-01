
#include <iostream>

using namespace std;

// Criação da classe Herói
typedef struct {
    string nome;
    int idade;
    string tipo;
}heroi;

// Declaração de variáveis globais
int memb;
heroi party[10];

// Função de ataque
string atacar(string tipo){
    string ataque;
    
    if (tipo == "Ninja" or tipo == "ninja")
        ataque = "Shuriken";
    else if (tipo == "Guerreiro" or tipo == "guerreiro")
        ataque = "Espada";
    else if (tipo == "Mago" or tipo == "mago")
        ataque = "Magia";
    else if (tipo == "Monge" or tipo == "monge")
        ataque = "Artes Marciais";
    else
       return "Essa classe não pertence a equipe";
       
    return "\nO " + tipo + " atacou usando " + ataque + "!";
};

// Função de criar party
int criarParty(){
  
    do {
        cout << "Olá estranho, quantos membros estão na sua equipe? [0/10]: \n";
        cin >> memb;
        system("clear");
        } while (memb <= 0 or memb > 10);

    cout << "Excelente, agora diga quais são suas características: ";
    
    for (int i = 0; i < memb; i++){
        cout << "\n\nNome: ";
        cin >> party[i].nome;
        cout << "Idade: ";
        cin >> party[i].idade;
        do { cout << "Tipo [Guerreiro / Ninja / Mago / Monge]: ";
             cin >> party[i].tipo;
            } while (party[i].tipo != "Guerreiro" and party[i].tipo != "guerreiro" and party[i].tipo != "GUERREIRO" and
                    party[i].tipo != "Ninja" and party[i].tipo != "ninja" and party[i].tipo != "NINJA" and
                    party[i].tipo != "Mago" and party[i].tipo != "mago" and party[i].tipo != "MAGO" and
                    party[i].tipo != "Monge" and party[i].tipo != "monge" and party[i].tipo != "MONGE");
    }
    return 0;
};

// Função de start
int main()
{
    string membAtual;
    char resp;
    int menu;
    
    criarParty();
    system("clear");
    
    // Menu de ação
    cout << "    AVENTURA!\n";
    cout << "\n[1] ATACAR\n"
         << "[2] VER EQUIPE\n"
         << "[3] SAIR\n\n";
    cin >> menu;
    
    switch (menu) {
        case 1:
            do 
            {
                system("clear");
                cout << "\nAgora, decida qual o tipo do aventureiro que irá atacar o monstro: ";
                cin >> membAtual;
                for (int i = 0; i < memb; i++){
                    if (membAtual == party[i].tipo)
                    {
                        cout << atacar(membAtual);
                        i = memb;
                    }
                    else{
                        system("clear");
                    }
                }
                cout << "\nDeseja atacar novamente? [S/N]: ";
                cin >> resp;
            } 
            while (resp == 's' or resp == 'S');
            break;
            
        case 2:
            for (int i = 0; i < memb; i++){
                cout << "\n\nNome: ";
                cout << party[i].nome;
                cout << "\nIdade: ";
                cout << party[i].idade;
                cout << "\nTipo: ";
                cout << party[i].tipo;
            }
        default:
            system("exit");
    }
    return 0;
}