
public class Book {
	String title;
	String author;
	void show() {
		System.out.println(title + " " + author);
	}
	public Book() {
		this("매개변수0");
		System.out.println(this.title+", "+this.author+",Book()생성자 호출됨 ");
	}
	public Book(String title) {
		this(title, "작자미상");
		System.out.println(this.title+", "+this.author+",Book(1)생성자 호출됨 ");
	}
	public Book(String title, String author) {
		this.title = title; this.author = author;
		System.out.println(this.title+", "+this.author+",Book(2)생성자 호출됨 ");
	}
	public static void main(String[] args) {
		Book littlePrince = new Book("어린왕자", "생렉쥐페리");
		Book loveStory = new Book("춘향전");
		Book emptyBook = new Book();
		loveStory.show();
	}

}
