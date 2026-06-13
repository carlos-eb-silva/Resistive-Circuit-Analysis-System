#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

double V_total, I_total, R_total; // variaveis globais para armazenar os valores totais de tensão, corrente e resistência.

void An_S(){
    
    int num_resistores;
    
    cout << "\nVocê selecionou a opção de Circuito em Série." << endl;
    cout << "Por favor, insira o número de resistores no circuito em série: ";
    cin >> num_resistores;
    cout << "Agora, insira os valores de resistência (em ohms) para cada resistor:" << endl;
    
    vector<double>R(num_resistores); // Adicionando vetor para guardar valores deles. 

    cout << "Digite a tensão total (em volts) aplicada ao circuito: ";
    cin >> V_total;
    
    R_total = 0; // Reinicia a resistência total para cada análise
    for (int i = 0; i < num_resistores; i++) {
        cout << "Resistor " << (i + 1) << ": ";
        cin >> R[i];
        R_total += R[i]; // Em série, a resistência total é a soma das resistências individuais
    }
    if (R_total == 0)
    {
        cout << "A resistência total do circuito em série é zero, o que não é possível. Por favor, verifique os valores inseridos." << endl;
        return; // Encerra a função para evitar divisão por zero
    }
    else
    {
        I_total = V_total / R_total; // A corrente total é a tensão total dividida pela resistência total
        cout << "\nA resistência total do circuito em série é: " << R_total << " ohms" << endl;
        
        if (I_total >= 1 || I_total == 0) // Corrente em amperes.
        {
            cout << "A corrente total do circuito em série é: " << I_total << " amperes" << endl;
        }
        else if (I_total < 1 && I_total > 0) // corrente em miliamperes.
        {
            cout << "A corrente total do circuito em série é: " << I_total * 1000 << " miliamperes" << endl;
        }
        else // corrente em microamperes.
        {
            cout << "A corrente total do circuito em série é: " << I_total * 1000000 << " microamperes" << endl;
        }

    cout << "\nDeseja saber a corrente e tensão em cada resistor? (s/n): ";
    char resposta;
    cin >> resposta;

    if (resposta == 's' || resposta == 'S')
    {
    cout << "\nCorrente e tensão em cada resistor:" << endl;
    for (int i = 0; i < num_resistores; i++) {
        double V_resistor = I_total * R[i]; // A tensão em cada resistor é a corrente total multiplicada pela resistência do resistor
        cout << "Resistor " << (i + 1) << ": Corrente = " << V_resistor / R[i]<< " A, Tensão = " << V_resistor << " V" << endl;
    }
} else
{
    cout << "Voltando ao menu principal..." << endl;
}
}

}

void An_P(){
            cout << "Você selecionou a opção de Circuito em Paralelo." << endl;
         
            // Lógica para análise de circuito em paralelo
}
void An_M(){
    cout << "Você selecionou a opção de Circuito Misto." << endl;
            // Lógica para análise de circuito misto
}
int main(){
    int options;
    cout << "Bem vindo ao Programa de Análise de Circuitos Resistivos!" << endl;

    do {

        cout << "Por favor, selecione uma opção:" << endl;
        cout << "(1) Análise de Circuito em Seroe" << endl;
        cout << "(2) Análise de Circuito em Série" << endl;
        cout << "(3) Análise de Circuito Misto" << endl;
        cout << "(4) Encerrar o Programa" << endl;
        cin >> options;

        switch (options) {
            case 1:
                An_P();
                break;
            case 2:
                An_S();
                break;
            case 3:
                An_M();
                break;
            case 4:
                cout << "Encerrando o programa. Obrigado por usar!" << endl;
                break;
            default:
                cout << "Opção inválida. Por favor, tente novamente." << endl;
                break;
        }
    } while (options != 4); // Loop para manter o programa rodando até que o usuário escolha encerrar


    return 0;
}