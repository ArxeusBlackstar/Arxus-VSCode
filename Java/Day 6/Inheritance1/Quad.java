//         MENU
// ------------------
// 1. Trapezoid
// 2. Parallelogram
// 3. Rectangle
// 4. Square
// 5. Exit
// ------------------
// Enter your choice: 1
// Enter x1, y1 : 0 0
// Enter x2, y2 : 4 0
// Enter x3, y3 : 3 2
// Enter x4, y4 : 1 2
// Area of Trapezoid : 6.0
// ------------------
// Enter your choice: 2
// Enter x1, y1 : 0 0
// Enter x2, y2 : 2 0
// Enter x3, y3 : 3 1
// Enter x4, y4 : 1 1
// Area of Parallelogram : 2.0
// ------------------
// Enter your choice: 3
// Enter x1, y1 : 0 0
// Enter x2, y2 : 3 0
// Enter x3, y3 : 3 2
// Enter x4, y4 : 0 2
// Area of Rectangle : 6.0
// ------------------
// Enter your choice: 4
// Enter x1, y1 : 0 0
// Enter x2, y2 : 2 0
// Enter x3, y3 : 2 2
// Enter x4, y4 : 0 2
// Area of Square : 4.0
// ------------------
//Enter your choice: 5    

import java.util.Scanner;

public class Quad {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.println(
                "\tMENU\n------------------\n1. Trapezoid\n2. Parallelogram\n3. Rectangle\n4. Square\n5. Exit");

        while (true) {
            System.out.print("------------------\nEnter your choice: ");
            int n = sc.nextInt();
            double[] x = new double[5];
            double[] y = new double[5];

            for (int i = 1; i <= 4; i++) {
                System.out.print("Enter x" + i + ", y" + i + " : ");
                x[i] = sc.nextDouble();
                y[i] = sc.nextDouble();
            }

            switch (n) {
                case 1:
                    Trapezoid t = new Trapezoid(x, y);
                    System.out.println("Area of Trapezoid : " + t.area());
                    break;
                case 2:
                    Parallelogram p = new Parallelogram(x, y);
                    System.out.println("Area of Parallelogram : " + p.area());
                    break;
                case 3:
                    Rectangle r = new Rectangle(x, y);
                    System.out.println("Area of Rectangle : " + r.area());
                    break;
                case 4:
                    Square s = new Square(x, y);
                    System.out.println("Area of Square : " + s.area());
                    break;
                case 5:
                    System.exit(0);
                default:
                    System.out.println("Invalid Choice!");
            }
        }
    }
}

class Quadrilateral {

    double[] x = new double[5];
    double[] y = new double[5];

    Quadrilateral(double[] x, double[] y) {
        this.x = x;
        this.y = y;
    }

    double calcDist(double x1, double y1, double x2, double y2) {
        double dX = x2 - x1;
        double dY = y2 - y1;
        double distance = Math.sqrt(dX * dX + dY * dY);
        return distance;
    }

    double perpDist(double px1, double py1, double lx1, double ly1, double lx2, double ly2) {
        double m = (ly2 - ly1) / (lx2 - lx1);
        double b = ly1 - m * lx1;
        double distance = Math.abs(m * px1 - py1 + b) / Math.sqrt(m * m + 1);
        return distance;
    }

    double area() {
        return -1;
    }
}

class Trapezoid extends Quadrilateral {
    Trapezoid(double[] x, double[] y) {
        super(x, y);
    }

    @Override
    double area() {
        return 0.5 * Math.abs(
                (x[1] * y[2] + x[2] * y[3] + x[3] * y[4] + x[4] * y[1]) -
                        (x[2] * y[1] + x[3] * y[2] + x[4] * y[3] + x[1] * y[4]));
    }

}

class Parallelogram extends Trapezoid {
    Parallelogram(double[] x, double[] y) {
        super(x, y);
    }

    @Override
    double area() {
        return calcDist(x[1], y[1], x[2], y[2]) * perpDist(x[4], y[4], x[1], y[1], x[2], y[2]);
    }
}

class Rectangle extends Parallelogram {
    Rectangle(double[] x, double[] y) {
        super(x, y);
    }

    @Override
    double area() {
        return calcDist(x[1], y[1], x[2], y[2]) * calcDist(x[2], y[2], x[3], y[3]);
    }
}

class Square extends Rectangle {
    Square(double[] x, double[] y) {
        super(x, y);
    }

    @Override
    double area() {
        return Math.pow(calcDist(x[1], y[1], x[2], y[2]), 2);
    }
}
