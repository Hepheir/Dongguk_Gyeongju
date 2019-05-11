class Score {
	public static void main(String[] args) {
		double [][] chart = new double[10][5];
		
		System.out.println("====\t성적\t====");
		System.out.println("이름\t국어\t영어\t수학\t총점\t평균");
		
		for (int std = 0; std < 10; std++) {
			// Generate random score
			for (int sbj = 0; sbj < 3; sbj++)
				chart[std][sbj] = (int)(Math.random()*101);
			
			// Get sum
			chart[std][3] = 0;
			for (int sbj = 0; sbj < 3; sbj++)
				chart[std][3] += chart[std][sbj];
			
			// Get avg
			chart[std][4] = chart[std][3] / 3;

			// Print
			System.out.printf("%c\t", std + 'A');
			for (int sbj = 0; sbj < 4; sbj++)
				System.out.printf("%3.0f\t", chart[std][sbj]);
			System.out.printf("%.2f\n", chart[std][4]);
		}
	}
}