package src.Lexceptions;

public class LexSyntaxError extends RuntimeException{
    public LexSyntaxError(int line){
        System.out.println("Syntax error at line: " + line);
    }
}
