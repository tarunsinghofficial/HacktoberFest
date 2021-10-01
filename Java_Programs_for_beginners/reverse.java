import java.util.Stack;

class Test {
	static Stack<Character> st = new Stack<>();
	
	static void insert_at_bottom(char x)
	{

		if(st.isEmpty())
			st.push(x);

		else
		{
			char a = st.peek();
			st.pop();
			insert_at_bottom(x);

			st.push(a);
		}
	}
	
	static void reverse()
	{
		if(st.size() > 0)
		{
			
			char x = st.peek();
			st.pop();
			reverse();
			
			insert_at_bottom(x);
		}
	}
	
	public static void main(String[] args)
	{
		
		st.push('1');
		st.push('2');
		st.push('3');
		st.push('4');
		
		System.out.println("Original Stack");
		
		System.out.println(st);
		
		reverse();
		
		System.out.println("Reversed Stack");
		
		System.out.println(st);
	}
}
