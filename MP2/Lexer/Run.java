package MP2.Lexer;

import java.util.ArrayList;
import java.util.List;

public class Run {
    Lexer lexer;
    List<String> token;
    List<String> error;
    //tokens
    //error
    public Run(String fn, String text){
        lexer = new Lexer(fn, text);
        this.token = lexer.make_tokens();
        //this.error = lexer.make_tokens();
    }

    public List<String> ret(){
        List<String> ret_ = new ArrayList<String>(this.error);
        ret_.addAll(this.error); 
        return ret_;
    }
}
