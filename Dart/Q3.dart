/*
  Client class with attribute name(constructor), purchase amount double,
  get and add method.

  Loyal client class attribute purchase amount, get method, 
  discount method .
*/

class Client {
  String? name;
  static double purchaseAmount = 0;

  Client(String name) {
    this.name = name;
  }

  void addPurchase(double amt) {
    purchaseAmount = purchaseAmount + amt;
    print("Yay! ${name} made a purchase of ${amt}");
  }
}

class LoyalClient extends Client {
  static double pAmount=0;
  double? discount;

  LoyalClient(String name) : super(name);

  void Purchase(double amt) {
    pAmount = pAmount + amt;
    discount = (Client.purchaseAmount * 15) / 100;
    print("\nAmount: ${amt}");
    print("Discount: ${discount}");
    print("Total: ${pAmount - discount!}");
  }
}

void main(List<String> args) {
  Client a = new Client("Parth");
  a.addPurchase(100);
  a.addPurchase(200);
  print(Client.purchaseAmount);

  LoyalClient b = new LoyalClient("Karan");
  b.Purchase(1500);
}
