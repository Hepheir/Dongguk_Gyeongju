// package kr.ac.dongguk.web;

import java.util.Scanner;
import java.io.*;

class Password {

    static String input; // 0~9로 이루어진 번호 문자열

    public static void main(String[] args) {

        // input = getValidInput("test_file.txt");
        input = getValidInput();

        String password = parsePassword(input);

        System.out.println(password);
    }


    // 불러올 파일이 따로 없을 경우, 콘솔에서 입력 받는다.
    static String getValidInput() {
        String userInput;
        Scanner sc = new Scanner(System.in);
            
        userInput = sc.nextLine();

        // 입력된 값이 유효한지 검사.
        if (checkValidInput(userInput) == false) {
            System.out.println("Invalid Input");
            return "";
        }

        sc.close();
        return userInput;
    }

    // 파일 경로가 주어지면, 해당 경로의 파일을 읽어온다.
    // 위의 getValidInput()와 동일한 기능.
    static String getValidInput(String path) {
        String userInput = "";

        try {
            File file = new File(path);

            Scanner sc = new Scanner(file);
            
            userInput = sc.nextLine();

            // 입력된 값이 유효한지 검사.
            if (checkValidInput(userInput) == false) {
                System.out.println("Invalid Input");
                return "";
            }

            sc.close();
        }
        catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    
        return userInput;
    }

    // 입력된 문자열이 0~9사이의 번호 문자로만 이루어졌는지 검사.
    static boolean checkValidInput(String password) {
        int i;
        int c;

        for (i = 0; i < password.length(); i++) {
            c = Character.getNumericValue(password.charAt(i));
            
            // 0~9 이외의 번호 문자 발견시 바로 false를 반환.
            if (c < 0 || c > 9)
                return false;
        }
        
        return true;
    }

    // 비밀번호 해독기.
    static String parsePassword(String userInput) {
        int i;

        // `i < userInput.length() - 1`인 이유는 userInput의 i번과 i + 1번의 문자를 비교해야 하기 때문.
        // 인덱스 범위를 벗어나지 않도록 하면서 동시에 필요한 부분만 비교.
        for (i = 0; i < userInput.length() - 1; i++) {
            // 서로 인접한 번호 쌍을 찾은 경우
            if (userInput.charAt(i) == userInput.charAt(i + 1))
            {
                userInput = userInput.substring(0, i) + userInput.substring(i + 2, userInput.length());
                // 문자열에서 소거된 후, 소거된 문자와 인접했던 문자들을 다시 비교하기 위해 피벗을 뒤로 1칸 옮김.
                // for문의 증감식을 고려하여 i -= 2를 하였음.
                i -= 2;
            }
        }

        return userInput;
    }
}