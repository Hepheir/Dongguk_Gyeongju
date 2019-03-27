public class GooGoo {

	public static void main(String[] args) {
		int i, j;
		
		for (i=1; i<=9; i++) {
			for (j=1; j<=9; j++)
				// System.out.print(j + "X" + i + "=" + (i*j) + "\t");
				System.out.printf("%dX%d=%d\t", j, i, (i*j));
			System.out.println();
		}
	}
}
