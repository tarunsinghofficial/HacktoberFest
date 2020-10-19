package Cipher;

public class RAILFENCE {

    private String encodeRAILFENCE(String inputText, int key){

        StringBuilder str1 = new StringBuilder();

        int usedKey = Math.min(key, inputText.length());

        String cipString = null;

        if (usedKey == 1){
            cipString = inputText;
        }else if (usedKey > 1){
            int l = 0;
            while(l <= (inputText.length()-1)){
                str1.append(inputText.charAt(l));
                l += (2*(usedKey - 1));
            }
            int a = 2*(usedKey - 2);
            int b = 2;
            for (int i = 2; i <= usedKey-1; i++){
                int loc = i - 1;
                str1.append(inputText.charAt(loc));
                while(loc <= (inputText.length()-1)){
                    loc = loc + a;
                    if (loc > inputText.length()-1){
                        break;
                    }
                    str1.append(inputText.charAt(loc));
                    loc = loc + b;
                    if (loc > inputText.length()-1){
                        break;
                    }
                    str1.append(inputText.charAt(loc));
                }
                a -= 2;
                b += 2;
            }
            l = usedKey - 1;
            while(l <= (inputText.length()-1)){
                str1.append(inputText.charAt(l));
                l += (2*(usedKey - 1));
            }

            cipString = str1.toString();
        }
        
        return cipString;
    }

    private String decodeRAILFENCE(String encode, int key){

        char[] decode = new char[encode.length()];
        StringBuilder str1 = new StringBuilder();

        int usedKey = Math.min(key, encode.length());


        if (usedKey == 1){
            return encode;
        }else if (usedKey > 1){
            int l = 0, k = 0;
            while(l <= (encode.length()-1)){

                decode[l] = encode.charAt(k);
                k++;
                l += (2*(usedKey - 1));
                if ((l > encode.length()-1) || (k > encode.length() - 1)){
                    break;
                }
            }

            int a = 2*(usedKey - 2);
            int b = 2;

            for (int i = 2; i <= usedKey-1; i++){
                int loc = i - 1;
                if ((k > encode.length()-1) || (loc > encode.length() - 1)){
                    break;
                }

                decode[loc] = encode.charAt(k);
                k++;
                loc = loc + a;
                while(loc <= (encode.length()-1)){

                    if (loc > encode.length()-1 || k > encode.length()-1){
                        break;
                    }

                    decode[loc] = encode.charAt(k);
                    loc = loc + b;
                    k++;
                    if ((loc > encode.length()-1) || (k > encode.length()-1)){
                        break;
                    }

                    decode[loc] = encode.charAt(k);
                    loc = loc + a;
                    k++;
                }
                a -= 2;
                b += 2;

            }

            l = usedKey - 1;
            while(l <= (encode.length()-1)){

                if ((k > encode.length()-1) || (l > encode.length() - 1)){
                    break;
                }

                decode[l] = encode.charAt(k);
                k++;
                l += (2*(usedKey - 1));
                if ((l > encode.length()-1) || (k > encode.length() - 1)){
                    break;
                }
            }
        }

        for (char c : decode) {
            str1.append(c);
        }

        return str1.toString();


    }

    public String encodeProcedureRAILFENCE(String inputText, int key){
        return encodeRAILFENCE(inputText, key);
    }

    public String decodeProcedureRAILFENCE(String inputText, int key){
        return decodeRAILFENCE(inputText, key);
    }

}
