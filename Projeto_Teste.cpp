#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct Entrada {
       int datagrama_tam;      //Tamanho do datagrama
       int mtu_tam;            //Valor da MTU da rede
};

struct Saida {
       int fragmento_num;      //Numero do fragmento
       int id;                 //Id da operação
       int qtdade_dados;       //Area de dados
       int offset;             //Valor do Offset
       int flag;               //Flag
};

Entrada vet1[99999];           //Vetor do Struct Entrada
Saida vet2[99999];             //Vetor do Struct Saida

int x=0;                       //Variavel do while
int lim;                       //Variavel limitadora do For
int dados_enviados;            //Variavel da quantidade de dados enviados no fragmento
int valor_offset;              //Variavel do calculo de valor do offset

int main(int argc, char *argv[])
{
    srand(time(NULL));         //Função para gerar numero aleatorio
    vet2[0].id = rand()%100;   //Gerando id aleatoria
    int datagrama_size=999999; //Variavel de entrada do tamanho do datagrama pelo usuario
    int mtu_size = 0;          //Variavel de entrada do valor da MTU da rede pelo usuario
    
    //Recebendo e armazenando os valores de Entrada
          while (datagrama_size < 31 || datagrama_size > 65534)
          {
          cout << "\nDigite o tamanho do datagrama(com valor maior que 30 e menor que 65.535):"<<endl;
          cin >> datagrama_size;
          if (datagrama_size < 31 || datagrama_size > 65534) 
          { 
             cout << "Valor incorreto, redigite."<<endl; 
          }
          }
          while (mtu_size < 21)
          {
          cout << "\n\nDigite o valor do MTU da rede(maior que 20):"<<endl;
          cin >> mtu_size;
          if (mtu_size < 21) { 
             cout << "Valor incorreto, redigite."<<endl; 
          }
          }
          
    //Armazenando os valores de entrada na Struct
          vet1[0].datagrama_tam = datagrama_size - 20;
          vet2[0].qtdade_dados = mtu_size - 20;
          
    //Calculando o valor do Offset
          valor_offset = (vet2[0].qtdade_dados / 8);
          
    //Definindo quantidade de laços do For
          lim = vet1[0].datagrama_tam / vet2[0].qtdade_dados;
          if (vet1[0].datagrama_tam % vet2[0].qtdade_dados != 0)
             {
              lim = lim + 1;
              }
              
    //Laço para calcular os valores de Saida do programa e gerar a resposta
          for (x=0; x<lim; x++)
          {
              
    //Definindo o numero do fragmento
                vet2[x].fragmento_num = x + 1;
                
    //Calculando quantidade de dados enviados no fragmento, valor do flag e redefinindo valor restante de bytes
                if (vet1[x].datagrama_tam > vet2[0].qtdade_dados)
                {
                   vet2[x].flag = 0;
                   dados_enviados = vet2[0].qtdade_dados;
                   vet1[x+1].datagrama_tam = (vet1[x].datagrama_tam - vet2[0].qtdade_dados);
                   }
                   else
                   { 
                        vet2[x].flag = 1;
                        dados_enviados = vet1[x].datagrama_tam;
                        vet1[x+1].datagrama_tam = 0;
                        }
    
    //Calculando Offset
                vet2[x].offset = (valor_offset * (vet2[x].fragmento_num - 1));
    
    //Exibindo valores na tela
                cout << "\n\nDatagrama " << vet2[x].fragmento_num << endl;
                cout << "   Dados transmitidos: \t" << dados_enviados << " bytes enviados." << endl;
                cout << "   ID: \t\t\t" << vet2[0].id << endl;
                cout << "   Offset: \t\t" << vet2[x].offset << endl;
                cout << "   Flag: \t\t" << vet2[x].flag << endl << endl;
                
          }
          
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
