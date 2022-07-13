package src;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.regex.*;

import src.Lexceptions.LexSyntaxError;

/***
 * Lexical analyzer
 */
public class SyntaxAnalyzer {
    String evalString; // String to be evaluated
    Queue<String> lineQueue;
    Pattern pattern;
    Matcher matcher;
    String[] exprArr;

    public SyntaxAnalyzer(String expr){
        this.evalString = expr;
        exprArr = evalString.split("\n");
        lineQueue = new LinkedList<>(Arrays.asList(exprArr));
        for(String output:exprArr){
            System.out.println(output);
        }
        keywordCheck(exprArr);
    }


    /**
     * Checks for keywords: var, input and output. When a semicolon
     * is detected, the method will skip to the next line of the string
     * @param statementArray String[]
     * @return True if the whole code does not have syntax errors. False if the code have syntax errors
     * @throws LexSyntaxError 
     */
    private boolean keywordCheck(String[] statementArray) throws LexSyntaxError{
        int line = 1;
        try {
            while (!lineQueue.isEmpty()){
                if (lineQueue.element().startsWith("var") || lineQueue.element().startsWith("input") || lineQueue.element().startsWith("output")){
                    if(lineQueue.element().endsWith(";")){
                        lineQueue.remove();
                        line++;
                    } else {
                        //Check if the word is an available identifier
                        System.out.println("huh");
                    }
                    
                } else {
                    throw new LexSyntaxError(line);
                } 
            } 
        } catc(LexSyntaxError e){
            
        }      
        return true;
    }
}
