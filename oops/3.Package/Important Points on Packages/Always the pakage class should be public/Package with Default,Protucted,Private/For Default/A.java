import Default.DefaultModefier;

class A{
public static void main(String []args){
DefaultModefier dm = new DefaultModefier();
}
}

/**
D:\USER_D\desktop\some file\java\oops\3.Package\Important Points on Packages\Always the pakage class should be public\Package with Default,Protucted,Private>javac A.java
A.java:1: error: DefaultModefier is not public in Default; cannot be accessed from outside package
import Default.DefaultModefier;
              ^
A.java:5: error: cannot access DefaultModefier
DefaultModefier dm = new DefaultModefier();
^
  bad source file: .\DefaultModefier.java
    file does not contain class DefaultModefier
    Please remove or make sure it appears in the correct subdirectory of the sourcepath.
2 errors

*/