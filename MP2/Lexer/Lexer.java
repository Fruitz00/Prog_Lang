package MP2.Lexer;

import java.util.*;

public class Lexer {
    static final String DIGITS = "0123456789";
    private String fn;
    private String text;
    private Position pos;
    private Character current_char;
    private Position pos_start;
    
    Lexer(String fn, String text){
        this.fn = fn;
        this.text = text;
        this.pos = new Position(-1, 0, -1, fn, text);
        this.current_char = null;
        this.advance();
    }    

    public void advance(){
        this.pos.advance(this.current_char);
        // this.current_char = this.text[this.pos.idx] if this.pos.idx < len(this.text) else null;
    }

    public void make_tokens(){
        List<Character> token = new ArrayList<Character>();    

        while (this.current_char != null){
            if (this.current_char == '\t'){
                this.advance();
            }else if(this.current_char == '\t'){

            }else if(DIGITS.contains(Character.toString(this.current_char))){
                
            }else if(this.current_char == '+'){

            }else if(this.current_char == '-'){
                
            }else if(this.current_char == '*'){
                
            }else if(this.current_char == '/'){
                
            }else if(this.current_char == '('){
                
            }else if(this.current_char == ')'){
                
            }else{
                pos_start = pos.copy();
                char char_ = this.current_char;
                this.advance();
                return token, IllegalCharError(pos_start, this.pos, ""+ char_ +"")
            }
        }
    }

    public void make_numbers(){
        
    }
}
