import org.opentutorials.javatutorials.method;

class ForeachDemo
{
    public static void printMembers(String[] args)
    {
        for (String e : args)
        {
            System.out.println(e + "��(��) ���ױͶ��� ����Դϴ�.");
        }
    }

    public static void main(String[] args)
    {
        String[] members = {"�赿��", "��Ҹ�", "�赿��", "�ڹ���", "������", "�����"};
        
        printMembers(members);
    }
}