/** Compilar e gerar executável:
  * g++ -o executavel vigenere.cpp
  * ./executavel
 **/

#include <iostream>   //console io
#include <cstring>     //string handling
#include <algorithm>  //transform



void encrypt_vigenere(const std::string& plaintext, const std::string& key, std::string& ciphertext){
   int i, j = 0, ch;
   for(i = 0; i < plaintext.length(); i++) {
     if (plaintext[i] != ' ')
     {
      ch = (plaintext[i] + key[j]) % 26 ;
      std::cout<<"tx["<<i<<"]="<<plaintext[i]<<"+k["<<j<<"]="<<key[j]<<"="<<ch<<'\n';
      ciphertext.append(std::string(1, (char)(ch + 'A')));
     }
     else
     ciphertext.append(std::string(1, (char)(' ')));
      j = (j+1) % key.length();
  }
}

void decrypt_vigenere(const std::string& ciphertext, const std::string& key, std::string& plaintext){
   int i, j = 0, ch;
   for(i = 0; i < ciphertext.length(); i++) {
     if(plaintext[i]!= ' ')
	{
         ch = ((ciphertext[i] - 'A') + 26 -(key[j] - 'A'))%26;
	 plaintext.append(std::string(1, (char)(ch+'A')));
	}
	else
		plaintext.append(std::string(1, (char)(' ')));
	j = (j+1) % key.length();
   }
}


int main(int argc, char* argv[])
{
  std::cout << "Entre com o texto para criptografar:\n";
   char textoClaro[256] = {0};
   std::cin.getline(textoClaro,256);
   std::cout << "Texto para criptografar: " << textoClaro << std::endl;

  std::cout << "Entre com a chave:";
   char chave[256] = {0};
   std::cin.getline(chave, 256);
 
    //uppercase KEY
   std::transform(chave, chave+strlen(chave),chave, ::toupper);

   std::cout << "key chosen: " << chave << std::endl;

   std::string cipher;
   //uppercase plaintext
   std::transform(textoClaro, textoClaro+strlen(textoClaro), textoClaro, ::toupper);
   encrypt_vigenere(textoClaro,chave, cipher);

   std::string decrypted;
   decrypt_vigenere(cipher, chave, decrypted);

   std::cout << "Vigenere encrypted text: " << cipher << " decrypted: " << decrypted <<std::endl;

return 0;
}
