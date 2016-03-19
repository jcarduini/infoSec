
import java.io.*;

public class Vigenere {

    static String encripta(String texto, String chave) throws Exception {

        byte[] bytes = texto.getBytes();

        int k = 0;
        for (int i = 0; i < bytes.length; i++) {
            bytes[i] ^= chave.charAt(k);
            k = (++k) % chave.length();
        }

        return Util.byteArrayToHexString(bytes);
    }

    static String desencripta(String textoCifrado, String chave) throws Exception {

        byte[] bytes = Util.hexStringToByteArray(textoCifrado);

        int k = 0;
        for (int i = 0; i < bytes.length; i++) {
            bytes[i] ^= chave.charAt(k);
            k = (++k) % chave.length();
        }

        return new String(bytes, "ASCII");
    }


    public static void main(String args[]) throws Exception {

        BufferedReader br = new BufferedReader(new FileReader("texto.txt"));
        String textoComum = br.readLine();
        String textoCifrado = encripta(textoComum, "");
        System.out.println(textoCifrado);
    }

}
