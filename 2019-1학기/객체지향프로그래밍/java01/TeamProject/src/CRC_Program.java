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
	
	// ������ ���� ������Ʈ
	JTextField data_inputTF, poly_inputTF;
	JLabel inputLabel;
	JTextField result_outputTF;
	JButton errDisplayBtn;
	JRadioButton toCRC_Radio, fromCRC_Radio;
	JButton operateBtn, exitBtn;

	enum errorStatus {on, off}; // ���� ���� ǥ�õ��� ����
	enum processOptions {toCRC, fromCRC}; // ���� ������ ó�� �ɼ�
	processOptions selectedOption = processOptions.toCRC; // ���õ� ó�� �ɼ�
	// selectedOption : addActionListeners() �ȿ� �ִ� toCRC_Radio, fromCRC_Radio�� ItemListener�� ���� ������.
	
	public BodyFrame() {
		// Ÿ��Ʋ ����
		// super("CRC üũ ���α׷� - �ǿ���,�赿��,������");
		setTitle("CRC üũ ���α׷� - �ǿ���,�赿��,������");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		bodyPane = getContentPane();
		bodyPane.setLayout(new GridLayout(3,3));

		createComponents();
		addEventListners();
		
		// �׸��� ���̾ƿ��� ��ġ (���� �߿�)
		// 1��
		add(data_inputTF);
		add(poly_inputTF);
		add(inputLabel);
		// 2��
		add(toCRC_Radio);
		add(fromCRC_Radio);
		add(operateBtn);
		// 3��
		add(errDisplayBtn);
		add(result_outputTF);
		add(exitBtn);
		
		setErrorStatus(errorStatus.off); // ���� ǥ�õ� ���� �ʱ�ȭ
		
		setSize(360*2,48*3);
		setVisible(true);
	}
	
	// ������Ʈ ����
	void createComponents() {
		//// ������Ʈ ���� //
		// �Է°� ���õ� ������Ʈ
		data_inputTF = new JTextField(""); // �����͸� �Է��� TextField
		poly_inputTF = new JTextField(""); // ���׽��� �Է��� TextField 
		
		inputLabel = new JLabel(" : [��ȯ�� ������] [CRC�߻��ڵ�] �Է�");
		
		// ��°� ���õ� ������Ʈ
		result_outputTF = new JTextField("����� ��µ� ���̿���"); // ��°���� ���� TextField
		errDisplayBtn = new JButton("No Err"); // CRC���� �߻����� ǥ�� (�������� ǥ��)
		
		// ó���� ���õ� ������Ʈ
		toCRC_Radio = new JRadioButton("CRC�� ��ȯ", true); // CRC�� ��ȯ (Default selected)
		fromCRC_Radio = new JRadioButton("CRC�ڵ� �ؼ�"); // CRC�� �ؼ�
		
		ButtonGroup group = new ButtonGroup(); // Radio ��ư ����
			group.add(toCRC_Radio);
			group.add(fromCRC_Radio);
		
		operateBtn = new JButton("ó�� �մϴ�~~");
		
		// ��Ÿ  
		exitBtn = new JButton("����!");
	}

	// ���ڿ��� �Էµ� �������� ������ ��ȯ
	static int parseBinString(String binString) {
		int lastElem = binString.length() - 1;
		int x = 0; // ��ȯ�� ��
		int temp;
		for (int i = lastElem; i >= 0; i--) {
			if (binString.charAt(i) == '0') // �˻��� �ڸ��� ��Ʈ�� 0�̸� �Ѿ
				continue;
			
			// �ش� �ڸ����� ������ ������ 2�� n���� ���ϰ�, x�� ����.
			temp = 1;
			for (int exp = 0; exp < lastElem-i; exp++)
				temp *= 2;
			x += temp;
		}
		return x;
	}

	// ��ư���� ���� ���� //
	void addEventListners() {
		// ���� ��ư ����
		exitBtn.addActionListener(new ActionListener() { // �͸� Ŭ���� ���
			public void actionPerformed(ActionEvent evt) {
				System.exit(0); // ���α׷� ����
			}
		});
		// ó�� ��ư ����
		operateBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent evt) {
				setErrorStatus(errorStatus.off); // Reset Error Status
				
				// 1. �ùٸ� �Է����� �ľ�
				if (!isFormedRight()) {
					result_outputTF.setText("[!] �߸��� �Է� ����.");
					setErrorStatus(errorStatus.on);
					return;
				}
				
				// 2. ���õ� ó�� �ɼ��� �������� �ľ� �� ó��
				CRC crc = submitForm();
				switch (selectedOption) { // selectedOption�� addEventListeners()�� ���� ��ư ���ý� ���ۿ��� ������.
										  // (���� ��ư�� ���� ������ �ɼ��� ����Ǿ�����)
				// CRC �ؼ� ���ý�
				case fromCRC:
					if (CRC_Generator.hasError(crc)) { // ���� �˻�
						// ���� ����
						result_outputTF.setText("CRC�ڵ忡�� ������ ����Ǿ����ϴ�.");
						setErrorStatus(errorStatus.on);
					} else {
						// ���� ����
						int data = CRC_Generator.fromCRC(crc);
						result_outputTF.setText(CRC_Generator.bin2String(data));
					}
					break;
				
				// CRC�� ��ȯ ���ý�
				case toCRC: 
					crc = CRC_Generator.toCRC(crc.value, crc.polynomial); // crc.value���� data�� �������.
					result_outputTF.setText(CRC_Generator.bin2String(crc.value));
					break;
					
				// ����ó��
				default:
					result_outputTF.setText("[!] ���� ��ư ���� ����.");
					setErrorStatus(errorStatus.on);
					break;
				}
			}
		});

		// ���� ��ư ���ý� ����
		toCRC_Radio.addItemListener(new ItemListener() {
			public void itemStateChanged(ItemEvent evt) {
				inputLabel.setText(" : [��ȯ�� ������] [CRC�߻��ڵ�]");
				selectedOption = processOptions.toCRC;
			}
		});
		fromCRC_Radio.addItemListener(new ItemListener() {
			public void itemStateChanged(ItemEvent evt) {
				inputLabel.setText(" : [�ؼ��� CRC�ڵ�] [���� CRC�߻��ڵ�]");
				selectedOption = processOptions.fromCRC;
			}
		});
	}
	
	// �ʼ� �Է��׸� ���� Ȯ��
	boolean isFormedRight() {
		String [] inputTexts = {
				data_inputTF.getText(),
				poly_inputTF.getText()};
		
		// data �Է��� �ùٸ��� �˻�
		if (parseBinString(inputTexts[0]) == -1)
			return false;
		
		return true;
	}
	
	// ����ǥ�õ� ���� ����
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
		/// a. ������ �ҷ����� (���ڿ� --> ������ ��ȯ)
		int data = parseBinString(data_inputTF.getText());
		/// b. ���׽��� �Է����� �ľ�, ������ ��ȯ
		int poly;
		String polyString = poly_inputTF.getText();
		if (polyString.contains("x")) { // ���� x�� ���ٸ� ���׽��� ���·� �ԷµǾ������� ����. KOH�� ���� parsePolynomial() �̿�.
			poly = CRC_Generator.parsePolynomial(polyString);
			poly_inputTF.setText(CRC_Generator.bin2String(poly, false, false));
		}
		else
			poly = parseBinString(polyString);
		
		return new CRC(data, poly);
	}
}
