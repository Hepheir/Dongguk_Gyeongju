package sdaf;
import java.io.*;

public class Pwcontroller {  //비밀번호 대상
   static int[] v_arrPw = {4,1,0,0,1,1,2,3,8,0,9,9,0,8,4,4};  //최종 비밀번호
   static int[] v_arrPwTemp;
   File password_File = new File("prog_1_sample_input.txt"); 
   public static void main(String[] args) {   //최종 결과 값
      String v_strTxt  = "";  //컴마
      String v_strComm = ",";
      //중복제거 대상이 될 배열(v_arrPw)을 파라미터로 넘긴다.
      //v_arrPw의 길이는 10보다 크거나 같고 100보다 작거나 같다.
      getPw(v_arrPw);
      //중복 제거된 배열을 console에 print하기 위함
      for(int k=0; k<v_arrPwTemp.length; k++)
      {
         v_strTxt += v_arrPwTemp[k];
         if(k<v_arrPwTemp.length-1)
         {
            v_strTxt += v_strComm;
         }
      }  
      System.out.println("{"+v_strTxt+"}");  
   }
   public static void getPw(int[] v_arrPw)
   {
      int v_nCnt = 0;  //최초 입력받은 배열만큼 루프를 돌린다.
      for(int j=0; j<v_arrPw.length-1; j++)
      {
         //배열의 값이 10보다 작을 경우
         if(v_arrPw[j] < 10)
         {
            //현재 배열과 다음 배열의 숫자가 같을 경우
            if(v_arrPw[j] == v_arrPw[j+1])
            { 
               //현재 배열과 다음 배열의 값이 같으면 둘다 10으로 치환한다.
               //아래 로직에서 10인 데이터는 제거하기 위함
               v_arrPw[j]   = 10;
               v_arrPw[j+1] = 10;
               //현재 배열과 다음 배열의 값이 같을 경우 증가
               v_nCnt++;
            }
         }
      }  //현재 배열과 다음 배열의 값이 같은 게 없으면 루프 종료
      if(v_nCnt == 0)
      {
         return;
      }
      else
      {
         int v_arrCnt = 0;  //기존 배열 -2의 크기를 가진 배열을 생성
         v_arrPwTemp = new int[v_arrPw.length-2];  //10으로 치환한 배열을 루프돌린다.
         for(int n : v_arrPw)
         {  //배열의 값이 10보다 작은 것만 새로 생성한 배열에 담는다.
            if(n < 10)
            {
               v_arrPwTemp[v_arrCnt] = n;
               v_arrCnt++;
            }
         }  //새로 생성한 배열에서 중복 값을 다시 제거한다.
         getPw(v_arrPwTemp);
      }
   }
}