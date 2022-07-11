package proglang_finals.Lexer;

import java.util.*;

public class Lexer {
    static final String DIGITS = "0123456789";
    static final String CHARACTERS = "abcdefghijklmnopqrstuvwxyz";
    private String fn;
    private String text;
    public Position pos;
    private char current_char;
    private Position pos_start;
    private Tokens tok = new Tokens();
    char charArr[];
    String tokens;
    String multChar;
    
    
    public Lexer(String fn, String text){
        //Convert String text to char array.
        charArr = text.toCharArray();
        this.fn = fn;
        this.text = text;
        this.pos = new Position(-1, 0, -1, fn, text); //Default from -1 
        this.current_char = ' ';
        this.advance();
    }    
    /***
     * 
     * @return
     * Returns true when the current position index is less than the length of the char array and
     * Returns false when current position index is equal to the length of the char array
     */
    public boolean advance(){
        this.pos.advance(this.current_char);
        if (this.pos.idx < charArr.length){
            this.current_char = this.charArr[this.pos.idx];
            return true;
        } else if (this.pos.idx == charArr.length){ //Has completed 1 run?
            return false;
        }

        //this.current_char = this.charArr[this.pos.idx];
        // this.current_char = this.text[this.pos.idx] if this.pos.idx < len(this.text) else null;
        return false;
    }

    public List<String> make_tokens(){
        List<String> token = new ArrayList<String>();
        token.clear();
        try {
            while (this.pos.idx != charArr.length){
                    if(this.current_char == '\t' || this.current_char == ' '){
                        //DO NOT CHANGE THIS OR ELSE THE PROGRAM WILL BREAK WHEN YOU ENTER SPACES
                    }else if(DIGITS.contains(Character.toString(this.current_char))){
                        token.add(make_numbers() + ":"+this.current_char);
                    }else if(CHARACTERS.contains(Character.toString(this.current_char))){
                        token.add(make_characters() + ":" + this.current_char);
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
                    }else if(this.current_char == ';'){
                        token.add(Tokens.TT_SEMICOLON);
                    }else if(this.current_char == '%'){
                        token.add(Tokens.TT_MODULO);
                    }else{
                        pos_start = pos.copy();
                        char char_ = this.current_char;
                        //this.advance();
                        throw new IllegalCharError(pos_start, this.pos, ""+ char_ +"");
                    }
                boolean a = this.advance();
                if (a) {
                    //System.out.println(token);
                    continue;
                } else if (a == false){
                    System.out.println(token);
                    break;
                }

            }
        } catch (IllegalCharError e) {
            System.out.println("Error! You've entered an illegal Character.");
            return token;
        } catch (ArrayIndexOutOfBoundsException e){
            System.out.println("Array Index Out of Bounds.");
            System.exit(0);
        }
        return token;
    }
    /***
     * 
     * @return
     * Returns the numerical datatype of the current character in the char array
     */
    public String make_numbers(){
        char num_str = ' ';
        int dot_count = 0;

        while(this.current_char != '\t' && DIGITS.contains(Character.toString(this.current_char + '.'))){
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
    /***
     *
     * @return
     * Returns the data type of the current character in the char array
     */
    public String make_characters(){
        char char_str = ' ';
        int dot_count = 0;
        while(this.current_char != ' ' && CHARACTERS.contains(Character.toString(this.current_char + '.'))){
            if (this.current_char == '.'){
                if(dot_count == 1) break;
                dot_count += 1;
                char_str += '.';
            } else {
                char_str += this.current_char;
                this.advance();
            }
        }

        if(dot_count == 0){
            return tok.toStr(Tokens.TT_CHAR, char_str);
        }else{
            return "what";
        }
    }
}
