package exam;

public class QuestionOne {
    public static void main(String[] args) {
        StringBuffer sb = new StringBuffer();
        
        for (String word: args) {
            sb.append(word.charAt(0));
        }
        
        String res = sb.toString();
        System.out.println(res);
    }
}
