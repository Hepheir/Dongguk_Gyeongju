import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class CRC_Program {
	public static void main(String [] args) {
		BodyFrame body = new BodyFrame();
	}
}

class BodyFrame extends JFrame {
	Container bodyPane;
	
	// 윈도우 구성 컴포넌트
	JTextField data_inputTF, poly_inputTF;
	JLabel inputLabel;
	JTextField result_outputTF;
	JButton errDisplayBtn;
	JRadioButton toCRC_Radio, fromCRC_Radio;
	JButton operateBtn, exitBtn;

	enum errorStatus {on, off}; // 에러 상태 표시등의 상태
	enum processOptions {toCRC, fromCRC}; // 선택 가능한 처리 옵션
	processOptions selectedOption = processOptions.toCRC; // 선택된 처리 옵션
	// selectedOption : addActionListeners() 안에 있는 toCRC_Radio, fromCRC_Radio의 ItemListener에 의해 결정됨.
	
	public BodyFrame() {
		// 타이틀 설정
		// super("CRC 체크 프로그램 - 권오현,김동주,김희진");
		setTitle("CRC 체크 프로그램 - 권오현,김동주,김희진");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		bodyPane = getContentPane();
		bodyPane.setLayout(new GridLayout(3,3));

		createComponents();
		addEventListners();
		
		// 그리드 레이아웃에 배치 (순서 중요)
		// 1행
		add(data_inputTF);
		add(poly_inputTF);
		add(inputLabel);
		// 2행
		add(toCRC_Radio);
		add(fromCRC_Radio);
		add(operateBtn);
		// 3행
		add(errDisplayBtn);
		add(result_outputTF);
		add(exitBtn);
		
		setErrorStatus(errorStatus.off); // 에러 표시등 상태 초기화
		
		setSize(360*2,48*3);
		setVisible(true);
	}
	
	// 컴포넌트 생성
	void createComponents() {
		//// 컴포넌트 생성 //
		// 입력과 관련된 컴포넌트
		data_inputTF = new JTextField(""); // 데이터를 입력할 TextField
		poly_inputTF = new JTextField(""); // 다항식을 입력할 TextField 
		
		inputLabel = new JLabel(" : [변환할 데이터] [CRC발생코드] 입력");
		
		// 출력과 관련된 컴포넌트
		result_outputTF = new JTextField("결과가 출력될 곳이에용"); // 출력결과가 나올 TextField
		errDisplayBtn = new JButton("No Err"); // CRC에러 발생여부 표시 (색상으로 표시)
		
		// 처리와 관련된 컴포넌트
		toCRC_Radio = new JRadioButton("CRC로 변환", true); // CRC로 변환 (Default selected)
		fromCRC_Radio = new JRadioButton("CRC코드 해석"); // CRC를 해석
		
		ButtonGroup group = new ButtonGroup(); // Radio 버튼 묶음
			group.add(toCRC_Radio);
			group.add(fromCRC_Radio);
		
		operateBtn = new JButton("처리 합니다~~");
		
		// 기타  
		exitBtn = new JButton("종료!");
	}

	// 문자열로 입력된 이진수를 정수로 변환
	static int parseBinString(String binString) {
		int lastElem = binString.length() - 1;
		int x = 0; // 반환할 수
		int temp;
		for (int i = lastElem; i >= 0; i--) {
			if (binString.charAt(i) == '0') // 검사한 자릿수 비트가 0이면 넘어감
				continue;
			
			// 해당 자릿수를 차수로 가지는 2의 n승을 구하고, x에 더함.
			temp = 1;
			for (int exp = 0; exp < lastElem-i; exp++)
				temp *= 2;
			x += temp;
		}
		return x;
	}

	// 버튼들의 동작 설정 //
	void addEventListners() {
		// 종료 버튼 동작
		exitBtn.addActionListener(new ActionListener() { // 익명 클래스 사용
			public void actionPerformed(ActionEvent evt) {
				System.exit(0); // 프로그램 종료
			}
		});
		// 처리 버튼 동작
		operateBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent evt) {
				setErrorStatus(errorStatus.off); // Reset Error Status
				
				// 1. 올바른 입력인지 파악
				if (!isFormedRight()) {
					result_outputTF.setText("[!] 잘못된 입력 있음.");
					setErrorStatus(errorStatus.on);
					return;
				}
				
				// 2. 선택된 처리 옵션이 무엇인지 파악 및 처리
				CRC crc = submitForm();
				switch (selectedOption) { // selectedOption은 addEventListeners()의 라디오 버튼 선택시 동작에서 결정됨.
										  // (라디오 버튼을 눌러 선택한 옵션이 저장되어있음)
				// CRC 해석 선택시
				case fromCRC:
					if (CRC_Generator.hasError(crc)) { // 에러 검사
						// 에러 있음
						result_outputTF.setText("CRC코드에서 에러가 검출되었습니다.");
						setErrorStatus(errorStatus.on);
					} else {
						// 에러 없음
						int data = CRC_Generator.fromCRC(crc);
						result_outputTF.setText(CRC_Generator.bin2String(data));
					}
					break;
				
				// CRC로 변환 선택시
				case toCRC: 
					crc = CRC_Generator.toCRC(crc.value, crc.polynomial); // crc.value에는 data가 들어있음.
					result_outputTF.setText(CRC_Generator.bin2String(crc.value));
					break;
					
				// 예외처리
				default:
					result_outputTF.setText("[!] 라디오 버튼 선택 에러.");
					setErrorStatus(errorStatus.on);
					break;
				}
			}
		});

		// 라디오 버튼 선택시 동작
		toCRC_Radio.addItemListener(new ItemListener() {
			public void itemStateChanged(ItemEvent evt) {
				inputLabel.setText(" : [변환할 데이터] [CRC발생코드]");
				selectedOption = processOptions.toCRC;
			}
		});
		fromCRC_Radio.addItemListener(new ItemListener() {
			public void itemStateChanged(ItemEvent evt) {
				inputLabel.setText(" : [해석할 CRC코드] [사용된 CRC발생코드]");
				selectedOption = processOptions.fromCRC;
			}
		});
	}
	
	// 필수 입력항목 누락 확인
	boolean isFormedRight() {
		String [] inputTexts = {
				data_inputTF.getText(),
				poly_inputTF.getText()};
		
		// data 입력이 올바른지 검사
		if (parseBinString(inputTexts[0]) == -1)
			return false;
		
		return true;
	}
	
	// 에러표시등 상태 변경
	void setErrorStatus(errorStatus errStat) {
		if (errStat == errorStatus.on) {
			errDisplayBtn.setText("Error!");
			errDisplayBtn.setBackground(new Color(0xFF0000));
		}
		else {
			errDisplayBtn.setText("No Error");
			errDisplayBtn.setBackground(Color.GRAY);
		}
	}

	CRC submitForm() {
		/// a. 데이터 불러오기 (문자열 --> 정수로 변환)
		int data = parseBinString(data_inputTF.getText());
		/// b. 다항식의 입력형태 파악, 정수로 변환
		int poly;
		String polyString = poly_inputTF.getText();
		if (polyString.contains("x")) { // 문자 x가 들어간다면 다항식의 형태로 입력되었음으로 간주. KOH가 만든 parsePolynomial() 이용.
			poly = CRC_Generator.parsePolynomial(polyString);
			poly_inputTF.setText(CRC_Generator.bin2String(poly, false, false));
		}
		else
			poly = parseBinString(polyString);
		
		return new CRC(data, poly);
	}
}
