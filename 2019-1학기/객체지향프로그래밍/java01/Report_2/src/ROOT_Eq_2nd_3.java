import java.util.Scanner;

abstract class ROOT_Eq {
	double a, b, c, D;
	double x1, x2;
	
	ROOT_Eq() {}
	ROOT_Eq(double a, double b, double c) {
		this.a = a;
		this.b = b;
		this.c = c;
	}
	void determinant() {
		D = b*b - 4*a*c;
	}
	abstract void root();
	abstract void display();
}

class ROOT_Eq_Double extends ROOT_Eq {
	ROOT_Eq_Double(double a, double b, double c) {
		super(a, b, c);
	}
	
	@Override
	void root() {
		if (D < 0) {
			return;
		}
		x1 = ((-1 * b) + Math.sqrt(D))/(2*a);
		x2 = ((-1 * b) - Math.sqrt(D))/(2*a);
	}
	
	@Override
	void display() {
		System.out.printf("[%.0fx^2 + %.0fx + %.0f = 0]은 ", a, b, c);
		if (D > 0) {
			System.out.printf("두 실근을 가진다.\n");
			System.out.printf("x1 : %f\n", x1);
			System.out.printf("x2 : %f\n", x2);
		}
		else if (D == 0) {
			System.out.printf("중근을 가진다.\n");
			System.out.printf("x : %f\n", x1);
		}
		else {
			System.out.printf("허근을 가진다.\n");
		}
	}
}

public class ROOT_Eq_2nd_3 {

	public static void main(String[] args) {
		double a, b, c;
		
		Scanner tmp = new Scanner(System.in);
		System.out.print("input coeff. a(double type) = ");
		a = tmp.nextInt();
		System.out.print("input coeff. b(double type) = ");
		b = tmp.nextInt();
		System.out.print("input coeff. c(double type) = ");
		c = tmp.nextInt();

		ROOT_Eq_Double eq1 = new ROOT_Eq_Double(a,b,c);
		eq1.determinant();
		eq1.root();
		eq1.display();
		
		tmp.close();
	}
}