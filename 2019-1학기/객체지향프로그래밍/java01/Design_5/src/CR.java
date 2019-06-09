import java.util.Scanner;

class Player {
	public int choice;
	
	public void randomChoice() {
		this.choice = (int)(Math.random()*3) + 1;
	}
	
}

public class CR {
	static Scanner sc = new Scanner(System.in);
	public static final String[] text = {"에러", "가위", "바위", "보"};
	
	// 이긴사람의 배열 원소 번호를 문자열로 이어서 전송
	public static String winners(Player [] players) {
		String winnerString = "";
		int [] hist = new int[4];
		for (Player p : players) {
			hist[p.choice]++;
		}

		// 비기는 경우 : 모든 경우가 나오거나 / 한 경우만 나올 때
		if (hist[1] != 0 && hist[2] != 0 && hist[3] != 0)
			return "";
		if (hist[1] == players.length || hist[2] == players.length || hist[3] == players.length)
			return "";
		
		// 이긴 사람 찾기
		int winChoice = 0; // 이긴 사람들이 낸 것
		
		if (hist[1] == 0) // 바위와 보가 나오면
			winChoice = 3; // 보 승
		
		else if (hist[2] == 0) // 가위와 보가 나오면
			winChoice = 1; // 가위 승
		
		else // 가위와 바위가 나오면
			winChoice = 2; // 바위 승
		
		// 이긴 사람 기록하기
		for (int i = 0; i < players.length; i++)
			if (players[i].choice == winChoice)
				winnerString = winnerString+i;
		
		return winnerString;
	}
	
	public static int getChoice() {
		System.out.println("가위(1), 바위(2), 보(3) 중 하나 입력 : ");
		int choice = sc.nextInt();
		if (choice < 1 && 3 < choice)
			return getChoice();
		return choice;
	}

	public static void main(String[] args) {
		System.out.println("몇 명?");
		int users = sc.nextInt();
		// 초기화 
		// 0: 유저 / 나머지 : 컴퓨터
		Player [] players = new Player[users+1];
		for (int i = 0; i < players.length; i++)
			players[i] = new Player();
		
		while (true) {
			// 가위바위보 결정
			players[0].choice = getChoice();
			for (int i = 1; i < players.length; i++)
				players[i].randomChoice();
	
			// 결정 확인
			System.out.println("  나의 선택 : "+text[players[0].choice]);
			for (int i = 1; i < players.length; i++)
				System.out.println("  player"+i+"의 선택 : "+text[players[i].choice]);
			
			System.out.println("승자는,");
			if (winners(players) == "")
				System.out.println("없다");
			else
				System.out.println(winners(players));
		}
	}

}
