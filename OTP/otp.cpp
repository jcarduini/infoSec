#include<fstream> 	// std::istream
#include<sstream>	//std::stringstream
#include<iostream>	//std::cout
#include<vector> 	//std::vector
#include<stdlib.h> 	//malloc

std::vector<std::string> criptografadas;

void imprime_matriz(int nElem){
  int i, j;
  for (i = 0; i < nElem; i++)
      std::cout<<criptografadas[i][i]<<'\n';
    
 }

void cria_matriz(const char* nomeArquivo){
  std::cout<<"Nome do arquivo"<<nomeArquivo<<'\n';
 
  std::ifstream File(nomeArquivo); 
  int i = 0;
  std::string mensagem;
  while(getline(File,mensagem))
    criptografadas.push_back(mensagem);
    
  File.close();
  std::cout<<"Tamanho do i: "<<i<<"\n";
  imprime_matriz(i-1);
}


void ASCII2hex(){
  char i;
  std::cin >> i;
  std::stringstream hex;
  hex << std::hex <<i;
  std::cout<<"numero em hex: "<<hex<<"\n";
}

int main(int argc, char** argv)
{
//  std::cout<<"Nome do arquivo: "<<argv[1]<<'\n';
  //cria_matriz(argv[1]);
  ASCII2hex();
  return 0;
}    