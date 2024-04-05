import java.util.Scanner;

public class Cooter {

    public static void main(String[] args) {

        Scanner aa = new Scanner(System.in);

        int upc = 0, lpc = 0, spc = 0, dgn = 0;

        System.out.print("Enter a string: ");
        String string = aa.nextLine();

        for (int i = string.length() - 1; i >= 0; i--) {

            char cc = string.charAt(i);

            int dd = (int) (cc);

            if (dd == 32) {
                spc++;
            } else if (dd >= 48 && dd <= 57) {
                dgn++;
            } else if (dd >= 97 && dd <= 122) {
                lpc++;
            } else if (dd >= 65 && dd <= 90) {
                upc++;
            }
        }

        System.out.println("Uppercases - " + upc + "\nLowercase - " + lpc + "\nSpacing - " + spc + "\nDigits - " + dgn);
    }
}
