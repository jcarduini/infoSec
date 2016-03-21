#include<fstream> 	// std::istream
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
  {
    criptografadas.push_back(mensagem);
    //criptografadas = (char**) malloc(1);		// aloca uma posição da matriz
    //criptografadas[i]= new char[mensagem.size()+1];	// aloca as posições da primeira mensagem
    //std::copy(mensagem.begin(), mensagem.end(),criptografadas[i]);
    //criptografadas[mensagem.size()]='\0';
    i++;
  }
  File.close();
  std::cout<<"Tamanho do i: "<<i<<"\n";
  imprime_matriz(i-1);
}

/**
void remove_matriz(int linhas, int colunas){
  int i;
  for (i = 0; i < linhas; i++)
    delete [] criptografadas[i];
  delete [] criptografadas;
}
**/
int main(int argc, char** argv)
{
  std::cout<<"Nome do arquivo: "<<argv[1]<<'\n';
  cria_matriz(argv[1]);
  
  return 0;
}    