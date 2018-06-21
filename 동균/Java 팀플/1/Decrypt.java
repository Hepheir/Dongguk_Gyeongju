/**
 * Password
 *  - main : 메인함수
 * 
 *  - getConsoleInput : 문자열을 콘솔로 부터 입력받아 반환하는 함수.
 *  - parseFile : 입력된 경로의 파일을 열어, 필요한 문자만 걸러 반환하는 함수.
 *  - checkValid : 문자열이 유효한지 확인하는 함수 (0~9)사이의 문자만 있는지 확인한다.
 *  - decryptString : 복호화 하는 함수. (중복된 두 숫자를 제거한다)
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


    // 불러올 파일이 따로 없을 경우, 콘솔에서 입력 받는다.
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

        // 입력된 값이 유효한지 검사.
        if (checkValid(userInput) == false) {
            System.out.println("Invalid Input");
            return "";
        }

        return userInput;
    }

    // 파일 해석기
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


                // 매 줄마다 첫 공백이 나오기 전 까지는 문자열의 길이가 입력되어있음.
                // 따라서 입력 받은 행에서 공백 뒤만 남기고 자름.
                for (int i = 0; i < line.length(); i++)
                    if (line.charAt(i) == ' ')
                        line = line.substring(i + 1, line.length());

                userInput += line + '\n';
            }
            while ( sc.hasNextLine() );

            sc.close();

            // 입력된 값이 유효한지 검사.
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

    // 입력된 문자열이 0~9사이의 번호 문자로만 이루어졌는지 검사.
    static boolean checkValid(String password) {
        int i;
        int c;

        for (i = 0; i < password.length(); i++) {
            c = Character.getNumericValue(password.charAt(i));
            
            // '줄 바꿈 문자, 0~9' 이외의 문자 발견시 바로 false를 반환.
            if (password.charAt(i) == '\n')
                continue;

            else if (c < 0 || c > 9)
                return false;
        }
        
        return true;
    }

    // 비밀번호 해독기.
    static String decryptString(String userInput) {
        int i = 0;

        // `i < userInput.length() - 1`인 이유는 userInput의 i번과 i + 1번의 문자를 비교해야 하기 때문.
        // 인덱스 범위를 벗어나지 않도록 하면서 동시에 필요한 부분만 비교.
        while (i < userInput.length() - 1) {
            // 서로 인접한 번호 쌍을 찾은 경우
            if (userInput.charAt(i) == userInput.charAt(i + 1))
            {
                userInput = userInput.substring(0, i) + userInput.substring(i + 2, userInput.length());
                // 문자열에서 소거된 후, 소거된 문자와 인접했던 문자들을 다시 비교하기 위해 피벗을 뒤로 1칸 옮김.
                // (단, i의 값이 0 아래로 가지 않도록 한다.)
                if (i > 0)
                    i--;
            }
            else
                i++;
        }

        return userInput;
    }
}