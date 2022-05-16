import java.text.Normalizer.Form;

public class Tokens{

    private String token;
    private String value;


    public token(String token, String value){

        this.token = token;
        this. value = value;

    }

    public toStr(){

        if (this.value){
            return String.format("%s", String.valueOf(this.token) + String.valueOf(this.value));
        }
        return String.format("%s", String.valueOf(this.token));
    }

}
