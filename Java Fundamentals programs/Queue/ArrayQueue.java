
package Queue;

public class ArrayQueue implements Queue{
    
    Object a[];
    private int size;
    
    public ArrayQueue(int capacity){
        a=new Object[capacity];
    }
            
    public void enqueue(Object obj){
        if(size==a.length){
            resize();
        }
        
            a[size++]=obj;
    }
    public Object dequeue(){
        Object obj;
        if(size==0)
            throw new IllegalStateException("Queue is Empty");
        else{
            obj=a[0];
            Object aa[]=a;
            a=new Object[--size];
            System.arraycopy(aa, 1, a, 0, size);
            return obj;
        }
    }
    public Object first(){
        return a[0];
    }
    public int size(){
        return size;
    }
    public boolean isEmpty(){
        return (size==0);
    }
    public void resize(){
        Object aa[]=a;
        a=new Object[aa.length+1];
        System.arraycopy(aa, 0, a, 0, size);
    }
    public void concate(ArrayQueue aq){
        Object aa[]=a;
        a=new Object[this.size+aq.size];
        System.arraycopy(aa, 0, a, 0, size);
        int j=0;
        for(int i=size; i<this.size+aq.size; i++){
            a[i]=aq.a[j];
            j++;
        }
        size+=aq.size;
    }
    public String toString(){
        StringBuffer sb = new StringBuffer();
        for(int i=0; i<size; i++){
            sb.append(a[i]);
            sb.append(',');
        }
        String s=sb.toString();
        return s;
    }
    public void reverse(){
        Object aa[]=a;
        a=new Object[size];
        int j=0;
        for(int i=size-1; i>=0; i--,j++){
            a[j]=aa[i];
        }
        //System.arraycopy(aa, size-1, a, 0, size);
    }
  
  public static void main(String args[]){
      ArrayQueue a = new ArrayQueue(5);
      a.enqueue("a");
      a.enqueue("b");
      a.enqueue('c');
      a.enqueue('d');
      a.enqueue('e');
    //  System.out.println(a.dequeue());
     /* System.out.println(a.size());
      a.enqueue('c');
      a.enqueue('p');
      System.out.println(a.size());*/
     ArrayQueue b = new ArrayQueue(3);
     b.enqueue('u');
     b.enqueue('v');
     b.enqueue('k');
     a.concate(b);
     System.out.println(a);
     System.out.println(a.size);
      
     b.reverse();
     System.out.println(b);
     
  }  
}
