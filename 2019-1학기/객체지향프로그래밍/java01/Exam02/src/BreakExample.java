import java.util.Scanner;

public class BreakExample {
	public static final String EXIT_CMD = "exit";
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println(EXIT_CMD+"�� �Է��ϸ� �����մϴ�.");
		
		while(true) {
			System.out.print(">>");
			String text = scanner.nextLine();
			if (text.contentEquals(EXIT_CMD))
				break;
		}
		
		System.out.println("�����մϴ�...");
		scanner.close();
	}

}
