import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.nextLine().trim();
        if(S.isEmpty())
        {
            System.out.print(0);
            sc.close();
            return;
        }
        int count = 1;
        for(int i = 0; i<S.length(); i++){
            if(S.charAt(i) == ' ')
                count++;
        }
        System.out.print(count);
    }
}