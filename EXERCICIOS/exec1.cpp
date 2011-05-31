#include <cstdlib>
#include <iostream>

using namespace std;

class Conta {
      private:
              double saldo;
      public:
             Conta() { 
                     saldo = 0; 
             };
             void setSaldo(double x) {
                  saldo = saldo +x;
             };
             double getSaldo() {
                    return saldo;
             };
};

int main(int argc, char *argv[])
{
    Conta c1;
    Conta c2;
    double valorDeposito;
    
    cout << "Saldo de c1: " << c1.getSaldo() << endl;
    cout << "Saldo de c2: " << c2.getSaldo() << endl << endl;
    
    cout << "Digite quanto vc deseja creditar em c2: " <<endl;
    cin >> valorDeposito;
    c2.setSaldo(valorDeposito);
    
    cout << "Novo Saldo de c2: " << c2.getSaldo() << endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

