import java.io.*;

public class OTP {

   public static void main(String args[]) throws Exception {

      byte[] chave = {
	(byte)0x0, // se voce achou a chave, ponha aqui
	(byte)0x0,
	(byte)0x0,
	(byte)0x0,
	(byte)0x0,		      

	(byte)0x0,
	(byte)0x0,
	(byte)0x0,
	(byte)0x0,
	(byte)0x0,

	(byte)0x0,
	(byte)0x0,
	(byte)0x0,
	(byte)0x0,
	(byte)0x0,

	(byte)0x0,
	(byte)0x0,
	(byte)0x0,
	(byte)0x0,
	(byte)0x0,

	(byte)0x0,
	(byte)0x0,
	(byte)0x0,
	(byte)0x0,
	(byte)0x0
	 };

	String[] msgs = { // se voce achou as mensagens originais, ponhas elas aqui
	"",
	"",
	"",
	"",
	"",
	"",
	""};

	for (String m: msgs) {
		byte[] mb = m.getBytes();
		for (int i = 0; i < mb.length; i++) {
			mb[i] ^= chave[i];
		}
		
		System.out.println(Util.byteArrayToHexString(mb));
	}
   }
}


class Util {

    public static void main(String args[]) throws Exception {

        String clearAscii = "meu texto comum";
        byte[] bytes = clearAscii.getBytes();
        String hexString = byteArrayToHexString(bytes);

        System.out.println(clearAscii+" = "+hexString+" = "+new String(hexStringToByteArray(hexString),"ASCII"));
    }


    public static byte[] hexStringToByteArray(String s) {
        int len = s.length();
        byte[] data = new byte[len / 2];
        for (int i = 0; i < len; i += 2) {
            data[i / 2] = (byte) ((Character.digit(s.charAt(i), 16) << 4)
                                 + Character.digit(s.charAt(i+1), 16));
        }
        return data;
    }


    final protected static char[] hexArray = "0123456789ABCDEF".toCharArray();
    public static String byteArrayToHexString(byte[] bytes) throws Exception {

        char[] hexChars = new char[bytes.length * 2];
        for ( int j = 0; j < bytes.length; j++ ) {
            int v = bytes[j] & 0xFF;
            hexChars[j * 2] = hexArray[v >>> 4];
            hexChars[j * 2 + 1] = hexArray[v & 0x0F];
        }
        return new String(hexChars);
    }

}
