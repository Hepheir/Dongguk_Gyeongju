import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Enumeration;

class Text {
	public static final String WINDOW_TITLE = "Title Screen";
	
	public static final String SINGLE_PLAY_BUTTON = "Single Play";
	public static final String MULTI_PLAY_BUTTON = "Multi Play";
	public static final String EXIT_BUTTON = "Exit";

	public static final String DIALOG_TITLE = "number of AI Players";
	public static final String START_BUTTON = "Start!";
	
}

public class TitleScreen extends JFrame {
	public TitleScreen() {
		setTitle(Text.WINDOW_TITLE);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container contentPane = getContentPane();
		contentPane.setLayout(new FlowLayout());

		// 버튼 생성 (싱글플레이 | 멀티플레이 | 종료)
		JButton[] jBtns = new JButton[3];
		jBtns[0] = new JButton(Text.SINGLE_PLAY_BUTTON);
		jBtns[1] = new JButton(Text.MULTI_PLAY_BUTTON);
		jBtns[2] = new JButton(Text.EXIT_BUTTON);
		
		OnClick onClick = new OnClick();
		for (JButton btn : jBtns) {
			btn.addActionListener(onClick);
			contentPane.add(btn);
		}
		
		setSize(300, 300);
		setVisible(true);
	}

	// 싱글플레이 선택시, 컴퓨터 참가자 수 결정
	void setSinglePlayerGame() {
		// 다이얼로그 생성
		TitleScreen that = this;
		class TitleDialog extends JDialog {
			public TitleDialog() {
				super(that, Text.DIALOG_TITLE, true);
				setLayout(new FlowLayout());
				
				// 라디오 버튼 생성 (컴퓨터 플레이어 수 선택)
				JRadioButton[] radioBtns = new JRadioButton[4];
				ButtonGroup btnGroup = new ButtonGroup();
				for (int i = 0; i < radioBtns.length; i++) {
					radioBtns[i] = new JRadioButton(String.valueOf(i+1));
					btnGroup.add(radioBtns[i]);
					add(radioBtns[i]);
				}
				
				// 시작 버튼 생성
				JButton startBtn = new JButton(Text.START_BUTTON);
				startBtn.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent evt) { // https://killsia.tistory.com/entry/%EC%9E%90%EB%B0%94%EC%8A%A4%EC%9C%99-JRadioButton-%EB%9D%BC%EB%94%94%EC%98%A4-%EB%B2%84%ED%8A%BC
						// 라디오 버튼으로부터 선택된 숫자 가져오기
						Enumeration<AbstractButton> enums = btnGroup.getElements();
						int CPs = 1;
						while (enums.hasMoreElements()) {
							JRadioButton jb = (JRadioButton) enums.nextElement();
							if (jb.isSelected())
								CPs = Integer.parseInt(jb.getText());
						}
						System.out.println("Game Start! with "+CPs+" Players.");
						setVisible(false);
					}
				});
				
				//
				add(startBtn);
				setSize(200, 100);
			}
		}
		
		TitleDialog td = new TitleDialog();
		td.setVisible(true);
	}

	// 메인 윈도우 (싱글플레이어 | 멀티플레이어 | 종료) 버튼 선택시 액션 결정
	private class OnClick implements ActionListener {
		public void actionPerformed(ActionEvent evt) {
			JButton btn = (JButton) evt.getSource(); // 다운 캐스팅
			String innerText = btn.getText();
			
			if (innerText.equals(Text.SINGLE_PLAY_BUTTON)) {
				System.out.println("Single Player mode!");
				setSinglePlayerGame();
			}
			else if (innerText.equals(Text.MULTI_PLAY_BUTTON)) {
				System.out.println("Multi Player mode!");
			}
			else if (innerText.equals(Text.EXIT_BUTTON)) {
				System.exit(0);
			}
		}
	}
	
	public static void main(String [] args) {
		new TitleScreen();
	}
}