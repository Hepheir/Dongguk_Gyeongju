class Circle_1 {
	int radius;
	public Circle_1(int radius) {
		this.radius = radius;
	}
	public double getArea() {
		return 3.14*radius*radius;
	}
}
public class CircleArray {

	public static void main(String[] args) {
//		Circle_1 [] c;
//		c = new Circle_1[5];
		Circle_1 [] c = new Circle_1[5];
		
		for(int i=0; i<c.length; i++)
			c[i] = new Circle_1(i); 
		
		for(int i=0; i<c.length; i++)
			System.out.print((int)(c[i].getArea()) + " ");
	}
}
