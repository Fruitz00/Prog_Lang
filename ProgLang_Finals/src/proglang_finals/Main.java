package proglang_finals;

import java.util.Scanner;
import proglang_finals.Lexer.*;

public class Main{
    //Constants
    static final int[] DIGITS = {0,1,2,3,4,5,6,7,8,9};
    static final String TT_INT = "INT";
    static final String TT_FLOAT = "FLOAT";
    static final char TT_PLUS = '+';
    static final String TT_MINUS = "MINUS";
    static final String TT_DIV = "DIV";
    static final String TT_LPAREN = "LPAREN";
    static final String TT_RPAREN = "RPAREN";
    static final String TT_SEMICOLON = "SEMICOLON";
    static final String TT_MODULO = "MODULO";

    public static void main(String[]args){
        
        Scanner in = new Scanner(System.in);
        System.out.print("basic > ");
        String input = in.nextLine();
        Run run = new Run("<stdin>",input);
        
    }
}