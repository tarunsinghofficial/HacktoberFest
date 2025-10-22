
import java.io.*;
import java.util.*;

public class NodeKLevelDown {
  public static class Node {
    int data;
    Node left;
    Node right;

    Node(int data, Node left, Node right) {
      this.data = data;
      this.left = left;
      this.right = right;
    }
  }

  public static class Pair {
    Node node;
    int state;

    Pair(Node node, int state) {
      this.node = node;
      this.state = state;
    }
  }

  public static Node construct(Integer[] arr) {
    Node root = new Node(arr[0], null, null);
    Pair rtp = new Pair(root, 1);

    Stack<Pair> st = new Stack<>();
    st.push(rtp);

    int idx = 0;
    while (st.size() > 0) {
      Pair top = st.peek();
      if (top.state == 1) {
        idx++;
        if (arr[idx] != null) {
          top.node.left = new Node(arr[idx], null, null);
          Pair lp = new Pair(top.node.left, 1);
          st.push(lp);
        } else {
          top.node.left = null;
        }

        top.state++;
      } else if (top.state == 2) {
        idx++;
        if (arr[idx] != null) {
          top.node.right = new Node(arr[idx], null, null);
          Pair rp = new Pair(top.node.right, 1);
          st.push(rp);
        } else {
          top.node.right = null;
        }

        top.state++;
      } else {
        st.pop();
      }
    }

    return root;
  }

  public static void display(Node node) {
    if (node == null) {
      return;
    }

    String str = "";
    str += node.left == null ? "." : node.left.data + "";
    str += " <- " + node.data + " -> ";
    str += node.right == null ? "." : node.right.data + "";
    System.out.println(str);

    display(node.left);
    display(node.right);
  }
  public static void printKLevelsDown(Node node, int k){
    // write your code here
    if(node==null){
        return ;
    }
    if(k==0){
        System.out.println(node.data);
        return;
    }
     printKLevelsDown(node.left,k-1);
      printKLevelsDown(node.right,k-1);
    
    
  }
    public static ArrayList<Node> nodeToRootPath(Node node, int data){
    // write your code here
    if(node==null){
        return new ArrayList<>();
    }
    
    if(node.data==data){
        ArrayList<Node> list=new ArrayList<>();
        list.add(node);
        return list;
    }
    
   ArrayList<Node> lres=nodeToRootPath(node.left,data);
    if(lres.size()>0){
        lres.add(node);
        return lres;
    }
    ArrayList<Node> rres=nodeToRootPath(node.right,data);
    if(rres.size()>0){
        rres.add(node);
        return rres;
    }
    
    return new ArrayList<>();
  }
  public static void printKNodesFar(Node node, int data, int dist) {
    // write your code here
    
    ArrayList<Node> list=nodeToRootPath(node,data);
    
    for(int idx=0;idx<list.size();idx++){
        Node curr=list.get(idx);
        
        if(idx==0) printKLevelsDown(curr,dist);
        else{
            int dac=idx;
            int rDist=dist-dac;
            
            if(rDist==0){
                System.out.println(curr.data);
            }else{
                Node prev=list.get(idx-1);
                if(curr.left==prev){
                   printKLevelsDown(curr.right,rDist-1);
                }else{
                     printKLevelsDown(curr.left,rDist-1);
                }
            }
        }
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    Integer[] arr = new Integer[n];
    String[] values = br.readLine().split(" ");
    for (int i = 0; i < n; i++) {
      if (values[i].equals("n") == false) {
        arr[i] = Integer.parseInt(values[i]);
      } else {
        arr[i] = null;
      }
    }

    int data = Integer.parseInt(br.readLine());
    int k = Integer.parseInt(br.readLine());

    Node root = construct(arr);
    printKNodesFar(root, data, k);
  }

}