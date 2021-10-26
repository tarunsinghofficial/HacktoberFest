//Using Queue
import java.util.*;

class Producer extends Thread{
	private Pool p;

	Producer(Pool p){
		super("ProducerThread");
		this.p = p;
	}

	public void run(){
		for(int count = 1; count <= 10; count++){
			try{
				Thread.sleep(1000);
			}
			catch(Exception e){
				e.printStackTrace();
			}
			p.setValue(count);
		}
		System.out.println(getName() + " finished producing values.\nTerminating " + getName());
	}

}

class Consumer extends Thread{
	private Pool p;
	int value, sum = 0;

	Consumer(Pool p){
		super("ConsumerThread");
		this.p = p;
	}

	public void run(){
		for(int count = 1; count <= 10; count++){
			try{
				Thread.sleep(1000);
			}
			catch(Exception e){
				e.printStackTrace();
			}
			value = p.getValue();
			sum += value;
		}
		System.out.println(getName() + " finished retreiving values.\nTotal: " + sum + "\nTerminating " + getName());
	}
}

class Pool{
	private int sharedValue = 0;
	Queue<Integer> q = new LinkedList<>();
	private boolean writable = true;

	public synchronized void setValue(int x){
		while(writable == false){
			try{
				wait();
			}catch(Exception e){
				e.printStackTrace();
			}
		}
		System.out.println(Thread.currentThread().getName() + " setting shared value to " + x);
		writable = false;
		sharedValue = x;
		q.add(x);
		notify();
	}

	public synchronized int getValue(){
		while(writable == true){
			try{
				wait();
			}catch(Exception e){
				e.printStackTrace();
			}
		}
		System.out.println(Thread.currentThread().getName() + " retreiving shared value " + sharedValue);
		writable = true;
		notify();
		return q.remove();
	}
}

public class ProdCon{
	public static void main(String[] args){
		Pool pool = new Pool();

		Producer p = new Producer(pool);
		Consumer c = new Consumer(pool);

		p.start();
		c.start();
	}
}