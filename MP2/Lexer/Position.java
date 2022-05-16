package MP2.Lexer;
public class Position {
    private int idx;
    private int ln;
    private int col;
    private String fn;
    private String ftxt;

    Position(int idx, int ln, int col, String fn, String ftxt){
        this.idx = idx;
        this.ln = ln;
        this.col = col;
        this.fn = fn;
        this.ftxt = ftxt;
    }

    public void advance(Character curr_char){

    }   
    
    public Position copy(){
        return new Position(this.idx,this.ln,this.col,this.fn,this.ftxt);
    }
}
