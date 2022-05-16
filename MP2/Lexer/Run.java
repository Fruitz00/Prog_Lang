package MP2.Lexer;

public class Run {
    Lexer lexer;
    //tokens
    //error
    public Run(String fn, String text){
        lexer = new Lexer(fn, text);

    }
}
