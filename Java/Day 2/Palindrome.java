import java.util.Scanner;

public class Palindrome {

    public static void main(String[] args) {

        Scanner aa = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String string = aa.next();

        String reversedString = "";
        for (int i = string.length() - 1; i >= 0; i--) {

            reversedString += string.charAt(i);
        }

        System.out.println("The reversed string is: " + reversedString);

        if (string.compareTo(reversedString) == 0) {

            System.out.println("Palindrome");
        }

        else {

            System.out.println("Ni Palindroma");
        }
    }
}