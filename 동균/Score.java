class Score
{
    public static void main(String[] args)
    {
        Students stud = new Students();

        stud.total();
        stud.avg();
        stud.display();
    }
}


class Students
{
    int num_stud = 10;
    int subjects = 3;

    char[] name = new char[num_stud];
    int[][] jumsu = new int[num_stud][subjects + 1];
    double[] average = new double[num_stud];

    // 생성자
    Students()
    {
        char[] _names = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

        for (int stud = 0; stud < num_stud; stud++)
        {
            name[stud] = _names[stud];

            for (int subj = 0; subj < subjects; subj++)
                jumsu[stud][subj] = _randomScore();
        }
    }

    // 0부터 100사이의 정수를 임의로 생성하는 메소드
    int _randomScore()
    {
        return (int)(Math.random() * 101);
    }

    // 총점을 구하고 저장하는 메소드
    void total()
    {
        int tot;
        for (int stud = 0; stud < num_stud; stud++)
        {
            tot = 0;
            for (int subj = 0; subj < subjects; subj++)
            {
                tot += jumsu[stud][subj];
            }
            jumsu[stud][subjects] = tot;
        }
    }

    // 평균을 구하고 저장하는 메소드
    void avg()
    {
        for (int stud = 0; stud < num_stud; stud++)
        {
            average[stud] = jumsu[stud][subjects] / 3.0;
        }
    }
    
    // 성적 전체를 출력하는 메소드
    void display()
    {
        System.out.println("==== 성적 ====");
        System.out.println("이름\t국어\t영어\t수학\t총점\t평균");

        for (int stud = 0; stud < num_stud; stud++)
        {
            // 이름
            System.out.printf(name[stud] + "\t");

            // 과목별 성적, 총점
            for (int subj = 0; subj <= subjects; subj++)
            {
                System.out.printf(jumsu[stud][subj] + "\t");
            }

            // 평균
            System.out.printf(average[stud] + "\n");
        }
    }
}