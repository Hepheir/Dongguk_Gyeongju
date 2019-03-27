
public class ConditionalOperator {

	public static void main(String[] args) throws java.io.IOException {
		int a, b, c, m=0, n=0;
		System.out.print("Enter three #s : ");
		a = System.in.read()-'0';
		b = System.in.read()-'0';
		c = System.in.read()-48;
		
		m = (a>b)? a:b;
		m = (m>c)? m:c;
		System.out.println("The largest # = "+m);
		
		n = a>b? (c>a? c:a):(c>b? c:b);
		System.out.println("The largest # = "+n);
	}

}
