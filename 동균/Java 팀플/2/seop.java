//2018.06.01 담당교수 : 정환목 교수님
//
import java.io.*;

class usingFile {
    PW password = new PW();
    File data = new File("C:\\Users\\kmsbi\\Downloads\\program2_data");

    // 파일 주소 입력
    void File_read(int num) throws IOException {
        FileReader Pin = new FileReader(data);
        int ch = 0, count = 0, count_mat = 0;
        // 읽은 문자를 저장할 변수
        // 파일 내용에서 문자를 하나씩 받아서 ch에 저장
        while ((Pin.read()) != -1) {
            if (Pin.read() == '\n') count++;
            if (2 * num - 1 == count)
            PW.password[count_mat] = ch;
            ch = Pin.read() + ch * 10;
            if (Pin.read() == ' ') {
                ch = 0;
                if (count_mat < 7) count_mat++;
            };
        }
        Pin.close();
    }
}

class PW {
    static int[] password = new int[8];

    void solve() {
        while (password[password.length - 1] != 0)
        for (int i = 1; i <= 5; i++) {
            password[0] -= i;
            change();
            if (password[password.length - 1] < 0) {
                password[password.length - 1] = 0;
                break;
            }
        }
    } // 배열 password[0]의 값에다 1 ~ 5의 값을 빼고 배열을 이동시킨다.
    // password[7]의 값이 0이하면 해당 배열의 번호가 비밀번호이다.
    void change() {
        int temp;
        for (int i = 1; i < password.length; i++) {
            temp = password[i];
            password[i] = password[i - 1];
            password[i - 1] = temp;
        }
    } // 배열의 값을 한칸씩 이동하는 메소드 (단 처음 메소드는 마지막 메소드로 간다.)
    //  before : 0 - 1 - 2 - 3 - 4 - 5 - 6 - 7
    //  after  : 1 - 2 - 3 - 4 - 5 - 6 - 7 - 0
    void display(int num) {
        System.out.printf("비밀번호 %d : ", num + 1);
        for (int i = 0; i < password.length; i++) {
            System.out.printf("%4d", password[i]);
        }
        System.out.printf("\n");
    } // 값을 콘솔창에 보여준다.
}

public class Team2 {
    public static void main(String[] args) throws java.io.IOException {
        // TODO Auto-generated method stub
        usingFile number = new usingFile();

        number.File_read(0);
        number.password.solve();
        number.password.display(0);
    }
}