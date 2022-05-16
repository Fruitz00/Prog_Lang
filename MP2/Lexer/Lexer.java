package MP2.Lexer;

import java.util.*;

public class Lexer {
    static final String DIGITS = "0123456789";
    private String fn;
    private String text;
    public Position pos;
    private Character current_char;
    private Position pos_start;
    char charArr[];
    char tokens[];
    
    public Lexer(String fn, String text){
        //Convert String text to char array.
        charArr = text.toCharArray();
        this.fn = fn;
        this.text = text;
        this.pos = new Position(-1, 0, -1, fn, text); //Default from -1 
        this.current_char = charArr[0]; //Pass value here. NullpointerException. Can be first elem of charArr
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



    public List<Character> make_tokens(){
        List<Character> token = new ArrayList<Character>();
        token.clear();
        try {
            while (this.current_char != null){
                if(this.current_char == '\t'){
                    this.advance();
                }else if(DIGITS.contains(Character.toString(this.current_char))){
                    //If current char matches the digits array, tokens.append(this.makenumber)
                }else if(this.current_char == '+'){
                    token.add(Tokens.TT_PLUS);
                }else if(this.current_char == '-'){
                    token.add(Tokens.TT_MINUS);
                }else if(this.current_char == '*'){
                    
                }else if(this.current_char == '/'){
                    
                }else if(this.current_char == '('){
                    
                }else if(this.current_char == ')'){
                    
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

    public void make_numbers(){

    }
}
