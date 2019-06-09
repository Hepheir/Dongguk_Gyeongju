interface PhoneInterface {
	final int TIMEOUT = 10000; // declare constant field
	//int TIMEOUT = 10000; // final 생략 가능 : 그래도 public static final로 자동 설정됨.
	void sendCall(); // abstract method
	void receiveCall(); // abstract method
	default void printLogo() { //default method
		System.out.println("**Phone**");
	}
}

class SamsungPhone implements PhoneInterface {
	@Override
	public void sendCall() {
		System.out.println("띠리리리링");
	}
	@Override
	public void receiveCall() {
		System.out.println("전화가 왔습니다.");
	}
	// 메소드 추가 작성
	public void flash() {
		System.out.println("전화기에 불이 켜졌습니다.");
	}
}

public class InterfaceEx {
	public static void main(String[] args) {
		SamsungPhone phone = new SamsungPhone();
		phone.printLogo();
		phone.sendCall();
		phone.receiveCall();
		phone.flash();
	}

}
