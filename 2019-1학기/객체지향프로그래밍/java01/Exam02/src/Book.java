
public class Book {
	String title;
	String author;
	void show() {
		System.out.println(title + " " + author);
	}
	public Book() {
		this("�Ű�����0");
		System.out.println(this.title+", "+this.author+",Book()������ ȣ��� ");
	}
	public Book(String title) {
		this(title, "���ڹ̻�");
		System.out.println(this.title+", "+this.author+",Book(1)������ ȣ��� ");
	}
	public Book(String title, String author) {
		this.title = title; this.author = author;
		System.out.println(this.title+", "+this.author+",Book(2)������ ȣ��� ");
	}
	public static void main(String[] args) {
		Book littlePrince = new Book("�����", "�������丮");
		Book loveStory = new Book("������");
		Book emptyBook = new Book();
		loveStory.show();
	}

}
