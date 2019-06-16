import java.util.Scanner;

class DATA {
    int number;
    int [] ary_A;
    int [] ary_B;

    public void in_size() {
        System.out.println("3 - 9 ���� ���� �Է�");
        Scanner sc = new Scanner(System.in);
        number = sc.nextInt();
        ary_A = new int[number];
        ary_B = new int[number];
    }

    public void in_ary() {
    	in_ary_1();
        System.out.println("1 - 100 ���� ���� �Է� (A�迭)");
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < number; i++) {
        	ary_A[i] = sc.nextInt();
        }
        System.out.println("1 - 100 ���� ���� �Է� (B�迭)");
        for (int i = 0; i < number; i++) {
        	ary_A[i] = sc.nextInt();
        }
        sc.close();
        System.out.println("�Է� ��");
    }
    
    public void in_ary_1() {
        System.out.println("1 - 100 ���� ���� �Է� (A�迭)");
        Scanner sc_a = new Scanner(System.in);
        for (int i = 0; i < number; i++) {
        	ary_A[i] = sc_a.nextInt();
        }
        sc_a.close();
        
        System.out.println("1 - 100 ���� ���� �Է� (B�迭)");
        Scanner sc_b = new Scanner(System.in);
        for (int i = 0; i < number; i++) {
        	ary_A[i] = sc_b.nextInt();
        }
        sc_b.close();
        System.out.println("�Է� ��");
    }
}

class ACTDATA extends DATA {
    public void out_same() {
        for (int i = 0; i < number; i++) {
            for (int j = 0; j < number; j++) {
                if (ary_A[i] == ary_B[j])
                    System.out.print(ary_A[i]);
            }
        }
    }

    public void out_cnt() {
        int sum = 0;
        for (int i = 0; i < number; i++) {
            for (int j = 0; j < number; j++) {
                if (ary_A[i] == ary_B[j])
                    sum++;
            }
        }
    }
}

public class Final {
    public static void main(String[] args) {
        ACTDATA data = new ACTDATA();
        data.in_size();
        data.in_ary();
        data.out_same();
        data.out_cnt();
    }
}