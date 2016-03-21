#include<fstream> 	// std::istream
#include<iostream>	//std::cout
#include<stdlib.h> 	//malloc

char** criptografadas;

void imprime_matriz(int elem){
  int i;
  for (i = 0; i < elem; i++)
    std::cout<<criptografadas[i];  
 }

void cria_matriz(const char* nomeArquivo){
  std::cout<<"Nome do arquivo"<<nomeArquivo<<'\n';
 
  std::ifstream File(nomeArquivo); 
  int i = 0;
  std::string mensagem;
  while(!File.eof())
  {
    getline(File,mensagem);
    criptografadas = (char**) malloc(1);		// aloca uma posição da matriz
    criptografadas[i]= new char[mensagem.size()+1];	// aloca as posições da primeira mensagem
    std::copy(mensagem.begin(), mensagem.end(),criptografadas[i]);
    criptografadas[mensagem.size()]='\0';
    std::cout<<"Elemento "<<i<<": "<<criptografadas;
    i++;
  }
  std::cout<<"Tamanho do i: "<<i<<"\n";
  //imprime_matriz(i-2);
}


void remove_matriz(int linhas, int colunas){
  int i;
  for (i = 0; i < linhas; i++)
    delete [] criptografadas[i];
  delete [] criptografadas;
}

int main(int argc, char** argv)
{
  std::cout<<"Nome do arquivo: "<<argv[1]<<'\n';
  cria_matriz(argv[1]);
  
  return 0;
}    