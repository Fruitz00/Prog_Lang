package src;


public class Main {
    public static void main(String[] args) {
        System.out.println("String input: ");
        String input = "this = 20;";
        String noSpaceInput = "var this=20;";
        String inputTwo = "var that = 40; var those = 50;";
        String expressions = "this+that;";
        String lineInput = "input this = 20;\n var that = 30;\nvar those = 40;";


        SyntaxAnalyzer analyze = new SyntaxAnalyzer(input);
    }

}

