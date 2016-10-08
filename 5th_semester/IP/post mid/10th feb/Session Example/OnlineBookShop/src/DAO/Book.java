package DAO;

public class Book {

	String title;
	String author;
	float price;
	int quantity;
	public void setTitle(String t) {
		title = t;
	}
	public String getTitle() {
		return title;
	}
	public String getAuthor() {
		return author;
	}
	public void setAuthor(String a) {
    	author = a;
  	}
  
  	public void setPrice(float p) {
    	price = p;
  	}
  	public float getPrice() {
  		return price;
  	}
  	public void setQuantity(int q) {
    	quantity = q;
  	}
  	public int getQuantity() {
    	return quantity;
  	}
}
