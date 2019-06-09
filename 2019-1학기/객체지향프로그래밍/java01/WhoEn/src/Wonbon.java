import java.util.Scanner;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

import java.util.Arrays;
class Students{
	int num_stud;
	int subjects;
	
	char[][] name;
	int[][] jumsu;
	double[] average;
	Students()
	{
		int i,j;
		for(i = 0; i < name.length;i++)
			name[i][1] = (char)(i+'A');
		for(j=0;j<jumsu[i].length-1;j++)
			jumsu[i][j] = (int)(Math.random()*101);
	}
	Students (int num_stud, int subjects)
	{
		this.num_stud = num_stud;
		this.subjects = subjects;
		
		name = new char[num_stud][2];
		jumsu = new int[num_stud][subjects+2];
		average = new double[num_stud];
		int i ,j;
		for(i = 0; i < num_stud;i++)
		{
//			name[i][0] = (char)(i+'1');
			name[i][1] = (char)(i+'A');
		}
		for(i=0;i<num_stud;i++)
		{
			for(j=0; j<subjects;j++)
				jumsu[i][j] = (int)(Math.random()*101);
		}
	}
	void total()
	{
		int i, j, sum;
		for(i =0; i<num_stud;i++) {
			sum  =0;
			for(j=0; j<subjects;j++)
				sum += jumsu[i][j];
			jumsu[i][subjects] = sum;
		}
	}
	void avg()
	{
		int i;
		for(i=0; i<num_stud;i++)
		{
			average[i] = (double)jumsu[i][subjects] / subjects;
		}
	}
	void bubble_sort()
	{
		int i, j;
		for(i = 0; i < num_stud;i++)
			for(j=0;j<num_stud-1;j++)
				if(jumsu[j][subjects] < jumsu[j+1][subjects])
					swap(j);
		rank();
	}
	void GPA(int i)
	{
			if(average[i] >= 95)
				System.out.println(" A+");
			else if(average[i] < 95 && average[i] >= 90)
				System.out.println(" A0");
			else if(average[i] < 90 && average[i] >= 85)
				System.out.println(" B+");
			else if(average[i] < 85 && average[i] >= 80)
				System.out.println(" B0");
			else if(average[i] < 80 && average[i] >= 75)
				System.out.println(" C+");
			else if(average[i] < 75 && average[i] >= 70)
				System.out.println(" C0");
			else if(average[i] < 70 && average[i] >= 65)
				System.out.println(" D+");
			else if(average[i] < 65 && average[i] >= 60)
				System.out.println(" D0");
			else
				System.out.println(" F");

	}
	void swap(int row) {
		int[] tmp_int = new int[subjects+2];
		char[] tmp_ch = new char[2];
		double tmp_dou;
		tmp_ch = name[row];
		name[row] = name[row+1];
		name[row+1] = tmp_ch;
		tmp_int = jumsu[row];
		jumsu[row] = jumsu[row+1];
		jumsu[row+1] = tmp_int;
		tmp_dou = average[row];
		average[row] = average[row+1];
		average[row+1] = tmp_dou;
	}
	void rank()
	{
		int i ;
		for(i = 0; i < jumsu.length;i++)
			jumsu[i][subjects+1] = i+1;
	}
	void display()
	{
		int i ,j;
		System.out.println("====   성적    ====\n");
		System.out.println("     국어  영어 수학 총점  석차 평균 학점 \n ");
		for(i=0;i<num_stud;i++) {
			for(j=0;j< name[i].length;j++)
				System.out.print(name[i][j]+"  ");
			for(j=0;j<jumsu[i].length;j++)
				System.out.printf("%4d",jumsu[i][j]);
			System.out.printf("%6.2f", average[i]);
			GPA(i);
		}
	}
	
}
public class Wonbon {
	public static void main(String[] args)
	{
		new Screen();
	}
}

class Screen extends JFrame {
	JTextField textInput;
	
	Screen() {
		setTitle("성적처리 프로그램 구현");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container contentPane = getContentPane();
		contentPane.setLayout(new FlowLayout());
		contentPane.setBackground(new Color(0xFFDE03));
		
		JButton [] buttons = new JButton[2];
		buttons[0] = new JButton("랜덤");
		buttons[1] = new JButton("종료");
		
		for (JButton btn : buttons) {
			btn.addActionListener(new OnClick());
			contentPane.add(btn);
		}
		
		textInput = new JTextField("여기다가 학생 수를 입력하시오.");
		contentPane.add(textInput);
		
		setSize(300, 150);
		setVisible(true);
	}
	
	class OnClick implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			JButton btn = (JButton) e.getSource();
			String text = btn.getText();
			if (text == "랜덤") {
				int num_stud;
				int subjects=3;
				
				String num_stud_string = textInput.getText();
				num_stud = Integer.parseInt(num_stud_string);
				System.out.println("입력된 학생수 : "+num_stud);
				
				Students elec = new Students(num_stud, subjects);
				elec.total();
				elec.avg();
				elec.bubble_sort();
				elec.display();
			}
			if (text == "종료") {
				System.exit(0);
			}
		}
	}
}

