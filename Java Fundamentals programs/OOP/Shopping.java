package com.company.inheritance;

class User{
	String name;
	String email;
	int cart;
	
	User(String name,String email,int cart){
		this.name=name;
		this.email=email;
		this.cart=cart;
	}
	
	void discount() {
		System.out.println("Discount provided-");
	}
	
	void loyalty() {
		System.out.println("Loyalty provided-");
	}
	
	void info() {
		System.out.println("Cart has "+cart+" items.");
	}
}

class GuestUser extends User{
	GuestUser(String name,String email,int cart){
		super(name,email,cart);
	}
	
	void info() {
		System.out.println("As a guest user,"+name+" get no discount and loyalty points provided.");
	}
}

class RegisteredUser extends User{
	int discount;
	int loyaltyp;
	public RegisteredUser(String name,String email,int cart,int discount,int loyaltyp){
		super(name,email,cart);
		this.discount=discount;
		this.loyaltyp=loyaltyp;
	}
	
	@Override
	void discount() {
		System.out.println("Discount provided-"+discount);
	}
	
	@Override
	void loyalty() {
		System.out.println("Loyalty points provided-"+loyaltyp);
	}
	
	void info() {
		System.out.println("For RegistereUser, "+name+" got Discount - "+discount+"%, Loyalty points provided-"+loyaltyp);
	}
}

public class shoppingsys {
public static void main(String[] args) {
	RegisteredUser reg=new RegisteredUser("Shiv","shiv1@gmail.com",11,21,7);
	reg.info();
	GuestUser guest=new GuestUser("Ram","ram11@gmail.com",10);
	guest.info();
}
}
