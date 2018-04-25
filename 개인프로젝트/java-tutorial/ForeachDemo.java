import org.opentutorials.javatutorials.method;

class ForeachDemo
{
    public static void printMembers(String[] args)
    {
        for (String e : args)
        {
            System.out.println(e + "Àº(´Â) ¸ÔÁ×±Í¶§°ö ¸â¹öÀÔ´Ï´Ù.");
        }
    }

    public static void main(String[] args)
    {
        String[] members = {"±èµ¿ÁÖ", "±è¼Ò¸®", "±èµ¿±Õ", "¹Ú¹ÎÁö", "À±À¯¸²", "Á¶´ë¿ø"};
        
        printMembers(members);
    }
}