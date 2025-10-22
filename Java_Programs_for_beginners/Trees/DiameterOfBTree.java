
import java.io.*;
import java.util.*;

public class DiameterOfBTree {
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

  public static int height(Node node) {
    if (node == null) {
      return -1;
    }

    int lh = height(node.left);
    int rh = height(node.right);

    int th = Math.max(lh, rh) + 1;
    return th;
  }
  static int diaOfTree;
  public static int diameter1(Node node) {
    // write your code here
    if(node==null){
        return -1;
    }
    
    int lh=diameter1(node.left);
    int rh=diameter1(node.right);
    
    int diaOfNode=lh+rh+2;
    if(diaOfNode>diaOfTree){
        diaOfTree=diaOfNode;
    }
    
    return Math.max(lh,rh)+1;
    
  }
  public static int diameter2(Node node){
     if(node==null){
         return 0;
     }   
      int ldia=diameter2(node.left);
      int rdia=diameter2(node.right);
      
      
      int lh=height(node.left);
      int rh=height(node.right);
      int diaofNode=lh+rh+2;
      
      return Math.max(diaofNode,Math.max(ldia,rdia));
      
  }
  public static class DiaPair{
      int ht,dia;
      DiaPair(int ht,int dia){
          this.ht=ht;
          this.dia=dia;
      }
  }
  public static DiaPair diameter3(Node node){
      if(node==null){
          return new DiaPair(-1,0);
          }
        DiaPair lpair=diameter3(node.left);
        DiaPair rpair=diameter3(node.right);
        
        int ht=Math.max(lpair.ht,rpair.ht)+1;
        int diaOfNode=lpair.ht+rpair.ht+2;
        int diaofTree=Math.max(Math.max(lpair.dia,rpair.dia),diaOfNode);
        
        return new DiaPair(ht,diaofTree);
        
        
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

    Node root = construct(arr);

    //  diaOfTree = 0;
    //  diameter1(root);
    // System.out.println(diaOfTree);
    
    // System.out.println(diameter2(root));
    DiaPair res=diameter3(root);
    System.out.println(res.dia);

  }

}