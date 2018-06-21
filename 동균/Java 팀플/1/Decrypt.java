/**
 * Password
 *  - main : �����Լ�
 * 
 *  - getConsoleInput : ���ڿ��� �ַܼ� ���� �Է¹޾� ��ȯ�ϴ� �Լ�.
 *  - parseFile : �Էµ� ����� ������ ����, �ʿ��� ���ڸ� �ɷ� ��ȯ�ϴ� �Լ�.
 *  - checkValid : ���ڿ��� ��ȿ���� Ȯ���ϴ� �Լ� (0~9)������ ���ڸ� �ִ��� Ȯ���Ѵ�.
 *  - decryptString : ��ȣȭ �ϴ� �Լ�. (�ߺ��� �� ���ڸ� �����Ѵ�)
 */

import java.util.Scanner;
import java.io.*;

class Decrypt {

    public static void main(String[] args) {

        // String input = getConsoleInput();
        String input = parseFile("./prog_1_sample_input.txt");

        String password = decryptString(input);

        try {
            Scanner sc = new Scanner(password);
            BufferedWriter bw = new BufferedWriter(new FileWriter("./prog_1_sample_output.txt"));

            while ( sc.hasNextLine() ) {
                bw.write( sc.nextLine() );
                bw.newLine();
            }

            bw.close();
            sc.close();
        }
        catch (IOException e) {
            System.err.println(e);
        }
    }


    // �ҷ��� ������ ���� ���� ���, �ֿܼ��� �Է� �޴´�.
    static String getConsoleInput() {
        String userInput = "";
        String line;

        Scanner sc = new Scanner(System.in);
         
        do
        {
            line = sc.nextLine();
            userInput += line + '\n';
        }
        while (line.length() > 0);

        sc.close();

        // �Էµ� ���� ��ȿ���� �˻�.
        if (checkValid(userInput) == false) {
            System.out.println("Invalid Input");
            return "";
        }

        return userInput;
    }

    // ���� �ؼ���
    static String parseFile(String path)
    {
        String userInput = "";

        try {
            String line;
            File file = new File(path);

            Scanner sc = new Scanner(file);
            
            do
            {
                line = sc.nextLine();


                // �� �ٸ��� ù ������ ������ �� ������ ���ڿ��� ���̰� �ԷµǾ�����.
                // ���� �Է� ���� �࿡�� ���� �ڸ� ����� �ڸ�.
                for (int i = 0; i < line.length(); i++)
                    if (line.charAt(i) == ' ')
                        line = line.substring(i + 1, line.length());

                userInput += line + '\n';
            }
            while ( sc.hasNextLine() );

            sc.close();

            // �Էµ� ���� ��ȿ���� �˻�.
            if (checkValid(userInput) == false) {
                System.out.println("Invalid Input");
                return "";
            }
        }
        catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        return userInput;
    }

    // �Էµ� ���ڿ��� 0~9������ ��ȣ ���ڷθ� �̷�������� �˻�.
    static boolean checkValid(String password) {
        int i;
        int c;

        for (i = 0; i < password.length(); i++) {
            c = Character.getNumericValue(password.charAt(i));
            
            // '�� �ٲ� ����, 0~9' �̿��� ���� �߽߰� �ٷ� false�� ��ȯ.
            if (password.charAt(i) == '\n')
                continue;

            else if (c < 0 || c > 9)
                return false;
        }
        
        return true;
    }

    // ��й�ȣ �ص���.
    static String decryptString(String userInput) {
        int i = 0;

        // `i < userInput.length() - 1`�� ������ userInput�� i���� i + 1���� ���ڸ� ���ؾ� �ϱ� ����.
        // �ε��� ������ ����� �ʵ��� �ϸ鼭 ���ÿ� �ʿ��� �κи� ��.
        while (i < userInput.length() - 1) {
            // ���� ������ ��ȣ ���� ã�� ���
            if (userInput.charAt(i) == userInput.charAt(i + 1))
            {
                userInput = userInput.substring(0, i) + userInput.substring(i + 2, userInput.length());
                // ���ڿ����� �Ұŵ� ��, �Ұŵ� ���ڿ� �����ߴ� ���ڵ��� �ٽ� ���ϱ� ���� �ǹ��� �ڷ� 1ĭ �ű�.
                // (��, i�� ���� 0 �Ʒ��� ���� �ʵ��� �Ѵ�.)
                if (i > 0)
                    i--;
            }
            else
                i++;
        }

        return userInput;
    }
}