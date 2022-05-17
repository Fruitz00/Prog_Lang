package MP2.Lexer;
import java.text.Normalizer.Form;

public class Tokens {
    static final int[] DIGITS = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    static final String TT_INT = "INT";
    static final String TT_FLOAT = "FLOAT";
    static final String TT_PLUS = "PLUS";
    static final String TT_MINUS = "MINUS";
    static final String TT_MUL = "MUL";
    static final String TT_DIV = "DIV";
    static final String TT_LPAREN = "LPAREN";
    static final String TT_RPAREN = "RPAREN";


    public String toStr(String type_, int value) {
            if (value == 0) {
                return String.format("%s", String.valueOf(type_) + String.valueOf(value));
            }
            return String.format("%s", String.valueOf(type_));
        }
    }

