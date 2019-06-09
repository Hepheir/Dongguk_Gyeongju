class GameDef {
	public static final int ROCK = 0;
	public static final int CISSOR = 1;
	public static final int PAPER = 2;	
}

class User {
	boolean isActive = true; // 현재 턴 수에 참가하고 있는가.
	int choice = 0;
	
	public void makeChoice() {
		// TODO 사용자로 부터 입력
		this.choice = 0;
	}
}

class CPU extends User {
	@Override
	public void makeChoice() {
		this.choice = (int)(Math.random() * 3);
	}
}

public class GameFlow {
	GameFlow() {
		// TODO
		System.out.println("hi");
	}
}
