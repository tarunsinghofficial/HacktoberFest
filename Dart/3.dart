// make a class named bank
class Bank {
  String? name;
  String? address;
  int? balance;
  int? amount;

  // make a constructor
  Bank(String name, String address, int balance) {
    this.name = name;
    this.address = address;
    this.balance = balance;
  }

  // make a method named deposit
  deposit(amount) {
    balance = (balance! + amount) as int?;
  }

  // make a method named withdraw
  withdraw(amount) {
    balance = (balance! - amount) as int?;
  }
}

void main(List<String> args) {
  // create an object for class
  // ignore: unused_local_variable
  Bank bank = new Bank('SBI', 'BTM', 100000);

  // call the methods
  bank.deposit(10000);
  bank.withdraw(20000);

  print(bank.balance);
}
