import java.util.Scanner;

class Book_1 {
	String title, author;
	public Book_1(String title, String author) {
		this.title = title;
		this.author = author;
	}
}
public class BookArray {

	public static void main(String[] args) {
		Book_1 [] book = new Book_1[2];
		
		Scanner scanner = new Scanner(System.in);
		for(int i=0; i<book.length; i++) {
			System.out.print("����>>");
			String title = scanner.nextLine();
			System.out.print("����>>");
			String author = scanner.nextLine();
			book[i] = new Book_1(title, author);
		}
		
		for(int i=0; i<book.length; i++)
			System.out.print("(" + book[i].title + ", " + book[i].author + ")");
		
		scanner.close();
	}

}
