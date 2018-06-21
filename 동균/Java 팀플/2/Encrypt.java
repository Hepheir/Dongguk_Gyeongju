/**
 * Encrypt
 *  - main : 메인함수
 * 
 *  - parseFile : 입력된 경로의 파일을 열어, 필요한 문자만 걸러 반환하는 함수.
 *  - stringToIntArray : 8개의 숫자가 적혀있는 문자열 한 줄을 크기가 8인 int 배열로 바꾸는 함수.
 *  - join : 배열을 문자열로 바꿈. 배열의 한 요소 사이는 공백으로 구분.
 *  - encryptArray : 암호화 하는 함수. (문제에 제시된 방법으로 암호화)
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

        // 파일 출력
        try {
            BufferedWriter bw = new BufferedWriter(new FileWriter("./prog_2_sample_output.txt"));
            Scanner sc = new Scanner(input);

            for (int i = 1; sc.hasNextLine(); i++) {
                // 입력된 파일에서 한 줄씩 뽑아와서
                line = sc.nextLine();

                // 뽑아온 한 줄을 String에서 크기 8짜리 int형 배열로 바꾸고
                arrayBlock = stringToIntArray(line);

                // 생성한 int 배열을 암호화 한다.
                encryptedArrayBlock = encryptArray(arrayBlock);

                // 암호화된 배열을 다시 문자열로 바꾼다.
                line = join(encryptedArrayBlock);


                // 한 줄씩 파일에 천천히 작성해 내려간다.
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
                sc.nextLine(); // 격 줄마다 나오는 행 번호를 거르기 위해 사용.

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
            // 배열의 값을 좌로 1칸 이동, 마지막 값을 1 ~ 5까지 순서에 맞게 감소시킴.
            memory = array[0];

            for (int i = 0; i < 7; i++) {
                array[i] = array[i + 1];
            }

            array[7] = memory - cycle;
            cycle++;

            // 감소된 숫자가 0보다 작으면 암호화 종료.
            if (array[7] < 0) {
                array[7] = 0;
                break;
            }

            // 매 5회마다 새로운 사이클 시작
            if (cycle > 5) {
                cycle = 1;
            }
        }
        
        return array;
    }
}