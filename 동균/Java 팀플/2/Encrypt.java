/**
 * Encrypt
 *  - main : �����Լ�
 * 
 *  - parseFile : �Էµ� ����� ������ ����, �ʿ��� ���ڸ� �ɷ� ��ȯ�ϴ� �Լ�.
 *  - stringToIntArray : 8���� ���ڰ� �����ִ� ���ڿ� �� ���� ũ�Ⱑ 8�� int �迭�� �ٲٴ� �Լ�.
 *  - join : �迭�� ���ڿ��� �ٲ�. �迭�� �� ��� ���̴� �������� ����.
 *  - encryptArray : ��ȣȭ �ϴ� �Լ�. (������ ���õ� ������� ��ȣȭ)
 */

import java.util.Scanner;
import java.io.*;

class Encrypt {
    static String input;

    public static void main(String[] args) {
        String line;
        int[] arrayBlock = new int[8];
        int[] encryptedArrayBlock = new int[8];


        input = parseFile("./prog_2_sample_input.txt");

        // ���� ���
        try {
            BufferedWriter bw = new BufferedWriter(new FileWriter("./prog_2_sample_output.txt"));
            Scanner sc = new Scanner(input);

            for (int i = 1; sc.hasNextLine(); i++) {
                // �Էµ� ���Ͽ��� �� �پ� �̾ƿͼ�
                line = sc.nextLine();

                // �̾ƿ� �� ���� String���� ũ�� 8¥�� int�� �迭�� �ٲٰ�
                arrayBlock = stringToIntArray(line);

                // ������ int �迭�� ��ȣȭ �Ѵ�.
                encryptedArrayBlock = encryptArray(arrayBlock);

                // ��ȣȭ�� �迭�� �ٽ� ���ڿ��� �ٲ۴�.
                line = join(encryptedArrayBlock);


                // �� �پ� ���Ͽ� õõ�� �ۼ��� ��������.
                bw.write( String.valueOf(i) );
                bw.newLine();

                bw.write(line);
                bw.newLine();

            }

            bw.close();
            sc.close();
        }
        catch (IOException e) {
            System.err.println(e);
        }
    }

    static String parseFile(String path) {
        String userInput = "";
        
        try {
            File file = new File(path);

            Scanner sc = new Scanner(file);
            
            do
            {
                sc.nextLine(); // �� �ٸ��� ������ �� ��ȣ�� �Ÿ��� ���� ���.

                userInput += sc.nextLine() + '\n';
            }
            while ( sc.hasNextLine() );

            sc.close();
        }
        catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        return userInput;
    }

    static int[] stringToIntArray(String line) {
        int[] array = new int[8];

        Scanner sc = new Scanner(line);
        
        for (int i = 0; i < 8; i++) {
            array[i] = sc.nextInt();
        }

        sc.close();

        return array;
    }

    static String join(int[] array) {
        String str = "";

        for (int i = 0; i < array.length; i++) {
            str = str + String.valueOf(array[i]) + ' ';
        }

        return str;
    }

    static int[] encryptArray(int[] array) {
        int cycle = 1;
        int memory;

        while (true) {
            // �迭�� ���� �·� 1ĭ �̵�, ������ ���� 1 ~ 5���� ������ �°� ���ҽ�Ŵ.
            memory = array[0];

            for (int i = 0; i < 7; i++) {
                array[i] = array[i + 1];
            }

            array[7] = memory - cycle;
            cycle++;

            // ���ҵ� ���ڰ� 0���� ������ ��ȣȭ ����.
            if (array[7] < 0) {
                array[7] = 0;
                break;
            }

            // �� 5ȸ���� ���ο� ����Ŭ ����
            if (cycle > 5) {
                cycle = 1;
            }
        }
        
        return array;
    }
}