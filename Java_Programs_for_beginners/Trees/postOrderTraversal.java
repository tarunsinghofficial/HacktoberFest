
class Anchal
{


static class Node
{
	int data;
	Node left, right;
	boolean visited;
}

static void postorder( Node head)
{
	Node temp = head;
	while (temp != null &&
			temp.visited == false)
	{

		// Visited left subtree
		if (temp.left != null &&
			temp.left.visited == false)
			temp = temp.left;

		// Visited right subtree
		else if (temp.right != null &&
				temp.right.visited == false)
			temp = temp.right;

		
		else
		{
			System.out.printf("%d ", temp.data);
			temp.visited = true;
			temp = head;
		}
	}
}

static Node newNode(int data)
{
	Node node = new Node();
	node.data = data;
	node.left = null;
	node.right = null;
	node.visited = false;
	return (node);
}


public static void main(String []args)
{
	Node root = newNode(8);
	root.left = newNode(3);
	root.right = newNode(10);
	root.left.left = newNode(1);
	root.left.right = newNode(6);
	root.left.right.left = newNode(4);
	root.left.right.right = newNode(7);
	root.right.right = newNode(14);
	root.right.right.left = newNode(13);
	postorder(root);
}
