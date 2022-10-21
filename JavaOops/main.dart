//dart interface

// Class Geek (Interface)
class Geek {
  void printdata() {
    print("Hello Geek !!");
  }
}

// Class Gfg implementing Geek
class Gfg implements Geek {
  void printdata() {
    print("Welcome to GeeksForGeeks");
  }
}

void main() {
  // Creating Object
  // of the class Gfg
  Gfg geek1 = new Gfg();

  // Calling method
  // (After Implementation )
  geek1.printdata();
}
