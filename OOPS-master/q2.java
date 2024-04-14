
/**
Enter L and R :
0.05
0.8
C       F
0.01    20.0
0.02    24.49489742783178
0.03    22.110831935702663
0.04    20.0
0.05    18.33030277982336
0.06    16.996731711975947
0.07    15.907898179514348
0.08    15.0
0.09    14.229164972072997
0.1     13.564659966250534
 */

import java.util.*;

public class q2 {
	public static void main(String[] args) {
		Scanner a = new Scanner(System.in);
		System.out.println("Enter L and R :");
		double L = a.nextDouble();
		double R = a.nextDouble();
		double X = 0.01, F, C;
		System.out.println("C\tF");
		for (int i = 1; i <=10; i++) {
			C = X * i;
			F = Math.sqrt((1 / (L * C)) - ((R * R) / (4 * C * C)));
			System.out.println(C + "\t" + F);
		}
	}
}
