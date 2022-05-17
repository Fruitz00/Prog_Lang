package MP2.Lexer;

import java.util.*;

public class Lexer {
    static final String DIGITS = "0123456789";
    private String fn;
    private String text;
    public Position pos;
    private Character current_char;
    private Position pos_start;
    private Tokens tok = new Tokens();
    char charArr[];
    char tokens[];
    
    Lexer(String fn, String text){
        //Convert String text to char array.
        charArr = text.toCharArray();
        this.fn = fn;
        this.text = text;
        this.pos = new Position(-1, 0, -1, fn, text); //Default from -1 
        this.current_char = null;
        this.advance();
    }    

    public void advance(){
        this.pos.advance(this.current_char);
        if (this.pos.idx < charArr.length){
            this.current_char = this.charArr[this.pos.idx];
        } else {

        }

        //this.current_char = this.charArr[this.pos.idx];
        // this.current_char = this.text[this.pos.idx] if this.pos.idx < len(this.text) else null;
    }

    public List<String> make_tokens(){
        List<String> token = new ArrayList<String>();
        token.clear();
        try {
            while (this.current_char != null){
                if(this.current_char == '\t'){
                    this.advance();
                }else if(DIGITS.contains(Character.toString(this.current_char))){
                    token.add(make_numbers());
                }else if(this.current_char == '+'){
                    token.add(Tokens.TT_PLUS);
                }else if(this.current_char == '-'){
                    token.add(Tokens.TT_MINUS);
                }else if(this.current_char == '*'){
                    token.add(Tokens.TT_MUL);
                }else if(this.current_char == '/'){
                    token.add(Tokens.TT_DIV);
                }else if(this.current_char == '('){
                    token.add(Tokens.TT_LPAREN);
                }else if(this.current_char == ')'){
                    token.add(Tokens.TT_RPAREN);
                }else{
                    pos_start = pos.copy();
                    char char_ = this.current_char;
                    this.advance();
                    throw new IllegalCharError(pos_start, this.pos, ""+ char_ +"");
                }
            }
        } catch (IllegalCharError e) {
            System.out.println("error u entered illegal char noob.");
            return token;
        }
        return token;
    }

    public String make_numbers(){
        char num_str = ' ';
        int dot_count = 0;

        while(this.current_char != null && DIGITS.contains(Character.toString(this.current_char + '.'))){
            if(this.current_char == '.'){
                if(dot_count == 1) break;
                dot_count += 1;
                num_str += '.';
            }
            else{
                num_str += this.current_char;
                this.advance();
            }
        }

        if(dot_count == 0){
            return tok.toStr(Tokens.TT_INT, num_str);
        }else{
            return tok.toStr(Tokens.TT_FLOAT, num_str);
        }
    }
}
