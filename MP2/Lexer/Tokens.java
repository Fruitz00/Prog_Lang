package MP2.Lexer;
import java.text.Normalizer.Form;

public class Tokens {
    static final int[] DIGITS = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    static final String TT_INT = "INT";
    static final String TT_FLOAT = "FLOAT";
    static final char TT_PLUS = '+';
    static final char TT_MINUS = '-';
    static final String TT_DIV = "DIV";
    static final String TT_LPAREN = "LPAREN";
    static final String TT_RPAREN = "RPAREN";

    private String type_;
    private int value;

    public Tokens(String type_, int value){
            this.type_ = type_;
            this.value = value;
    }


    public String toStr() {
            if (this.value == 0) {
                return String.format("%s", String.valueOf(this.type_) + String.valueOf(this.value));
            }
            return String.format("%s", String.valueOf(this.type_));
        }
    }

