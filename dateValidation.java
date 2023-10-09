import java.util.Scanner;
import java.util.regex.*;

public class dateValidation {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String dat;
        dat = sc.nextLine();
        System.out.println(dat);

        Pattern pattern = Pattern.compile("^((0?[1-9]|[12][0-9]|3[01])\\/(0?[1-9]|1[0-2])\\/([1-2][0-9]{3}))$");
        Matcher matcher = pattern.matcher(dat);
        boolean m = matcher.matches();
        System.out.println(m);
    }
}
