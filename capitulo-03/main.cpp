#include "posfixa.cpp"

using namespace std;


void questao01(){

    // Crie um programa que exiba a forma posfixa e o resultado de uma expressão infixa
    // com inteiro de um digito, digitada pelo usuário.

    string infixa;
    std::cin >> infixa;

    string posfixa = fromInfixStringToPosfix(infixa);

    std::cout << "Posfixa: " << posfixa << std::endl;
    float result = evaluatePosfix(posfixa);

    std::cout << "Resultado: " << result << std::endl;

}


int main()
{
    // string infixa = "(2*50+8/4)";
    // string posfix = fromInfixStringToPosfix(infixa);
    
    // std::cout << "Posfixa: " << posfix << std::endl;
    
    // std::cout << "Resultado: " << evaluatePosfix(posfix) << std::endl;
    questao01();
    
    return 0;
    
}
