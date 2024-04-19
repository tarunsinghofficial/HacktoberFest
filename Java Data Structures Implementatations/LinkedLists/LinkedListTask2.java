package LinkedLists;
class Student{
	String rollNumber,name;
	public Student(String rollNumber, String name){
		this.rollNumber=rollNumber;
		this.name=name;
	}
}

class LinkedListTask2{
	Node start;
	private class Node{
		private Student std;
		private Node next;
		public Node(Student std){
			this.std=std;
		}
		public Node(Student std,Node next){
			this.std=std;
			this.next=next;
		}
	}

/////////////Method to print all students' records in LinkedList
	public void printList(){
		if(start==null)
			throw new IllegalStateException("Student LinkedList is empty!");
		Node p=start;
		System.out.print("[");
		while(p!=null){
			System.out.print("("+p.std.rollNumber+","+p.std.name+"),");
			p=p.next;
		}
		System.out.println("\b]");
	}



/////////////Method to insert a student record in LinkedList
	public Node insert(Student std){
		if(start==null){
			start= new Node(std,start);
			return start;
		}
		Node p= start;
		while (p.next!=null) {
			p=p.next;
		}
		p.next= new Node(std,p.next);
		return start;
	}



/////////////Method to delete an Student record from LinkedList
	public Node delete(Student s){
		if(start==null)
			return start;
		if(start.std.rollNumber.equals(s.rollNumber) && start.std.name.equals(s.name)){
				start= start.next;
				return start;
		}
		Node p=start;
		while(p.next!=null){
			if(p.next.std.rollNumber.equals(s.rollNumber) && p.next.std.name.equals(s.name)){
				p.next=p.next.next;
				break;
			}
			p=p.next;
	    }
	    return start;
	}

	public static void main(String[] args) {
		LinkedListTask2 studentRecords= new LinkedListTask2();
		Student zohaib=new Student("19sw42","Zohaib");
		Student amrat=new Student("19sw43","Amrat");
		Student ahmad=new Student("19sw44","Syed Ahmad Shah");
		Student uzair=new Student("19sw45","M.Uzair");
		Student arsam=new Student("19sw46","Arsam");

		studentRecords.insert(zohaib);
		studentRecords.insert(amrat);
		studentRecords.insert(ahmad);
		studentRecords.insert(uzair);
		studentRecords.insert(arsam);

		System.out.println("Students' Records: ");		
		studentRecords.printList();
		studentRecords.delete(amrat);
		System.out.println("\nAfter Deleting Amrat's Record From Students' Records: ");
		studentRecords.printList();
	
	}


}