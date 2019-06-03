import java.util.Scanner;

class Player {
	public int choice;
	
	public void randomChoice() {
		this.choice = (int)(Math.random()*3) + 1;
	}
	
}

public class CR {
	static Scanner sc = new Scanner(System.in);
	public static final String[] text = {"����", "����", "����", "��"};
	
	// �̱����� �迭 ���� ��ȣ�� ���ڿ��� �̾ ����
	public static String winners(Player [] players) {
		String winnerString = "";
		int [] hist = new int[4];
		for (Player p : players) {
			hist[p.choice]++;
		}

		// ���� ��� : ��� ��찡 �����ų� / �� ��츸 ���� ��
		if (hist[1] != 0 && hist[2] != 0 && hist[3] != 0)
			return "";
		if (hist[1] == players.length || hist[2] == players.length || hist[3] == players.length)
			return "";
		
		// �̱� ��� ã��
		int winChoice = 0; // �̱� ������� �� ��
		
		if (hist[1] == 0) // ������ ���� ������
			winChoice = 3; // �� ��
		
		else if (hist[2] == 0) // ������ ���� ������
			winChoice = 1; // ���� ��
		
		else // ������ ������ ������
			winChoice = 2; // ���� ��
		
		// �̱� ��� ����ϱ�
		for (int i = 0; i < players.length; i++)
			if (players[i].choice == winChoice)
				winnerString = winnerString+i;
		
		return winnerString;
	}
	
	public static int getChoice() {
		System.out.println("����(1), ����(2), ��(3) �� �ϳ� �Է� : ");
		int choice = sc.nextInt();
		if (choice < 1 && 3 < choice)
			return getChoice();
		return choice;
	}

	public static void main(String[] args) {
		System.out.println("�� ��?");
		int users = sc.nextInt();
		// �ʱ�ȭ 
		// 0: ���� / ������ : ��ǻ��
		Player [] players = new Player[users+1];
		for (int i = 0; i < players.length; i++)
			players[i] = new Player();
		
		while (true) {
			// ���������� ����
			players[0].choice = getChoice();
			for (int i = 1; i < players.length; i++)
				players[i].randomChoice();
	
			// ���� Ȯ��
			System.out.println("  ���� ���� : "+text[players[0].choice]);
			for (int i = 1; i < players.length; i++)
				System.out.println("  player"+i+"�� ���� : "+text[players[i].choice]);
			
			System.out.println("���ڴ�,");
			if (winners(players) == "")
				System.out.println("����");
			else
				System.out.println(winners(players));
		}
	}

}
