import java.util.Scanner;

public class Arrey {
    public static void main(String[] args) {
        Scanner aa = new Scanner(System.in);

        System.out.println("Enter the length of the first array ");
        int length1 = aa.nextInt();

        System.out.println("Enter the first array: ");

        int[] a = new int[length1];

        for (int i = 0; i < length1; i++) {

            a[i] = aa.nextInt();
        }

        a = arraysort(a);

        System.out.println("Enter the length of the second array ");
        int length2 = aa.nextInt();

        System.out.println("Enter the second array: ");

        int[] b = new int[length2];

        for (int i = 0; i < length2; i++) {

            b[i] = aa.nextInt();
        }

        b = arraysort(b);

        int[] c = new int[(length2 + length1)];

        for (int i = 0; i < length1; i++) {

            c[i] = a[i];
        }

        for (int i = 0; i < length2; i++) {

            c[length1 + i] = b[i];
        }

        c = arraysort(c);

        printArray(a);
        printArray(b);
        printArray(c);
    }

    public static int[] arraysort(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        return arr;
    }

    public static void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

}
