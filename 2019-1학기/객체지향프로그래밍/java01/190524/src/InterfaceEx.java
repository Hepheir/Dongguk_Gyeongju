interface PhoneInterface {
	final int TIMEOUT = 10000; // declare constant field
	//int TIMEOUT = 10000; // final ���� ���� : �׷��� public static final�� �ڵ� ������.
	void sendCall(); // abstract method
	void receiveCall(); // abstract method
	default void printLogo() { //default method
		System.out.println("**Phone**");
	}
}

class SamsungPhone implements PhoneInterface {
	@Override
	public void sendCall() {
		System.out.println("�츮������");
	}
	@Override
	public void receiveCall() {
		System.out.println("��ȭ�� �Խ��ϴ�.");
	}
	// �޼ҵ� �߰� �ۼ�
	public void flash() {
		System.out.println("��ȭ�⿡ ���� �������ϴ�.");
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
