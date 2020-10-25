// LANGUAGE: Java 
// ENV: Java 8 
// AUTHOR: Noopur Agarwal
// GITHUB: https://github.com/noopurAg

import java.util.*;
class KthLargestNumber {
    public int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums);
        return nums[nums.length-k];
    }
    
    public int findKthLargestwithoutSort(int[] nums, int k){
      PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int num : nums)pq.add(num);
        for(int i=0;i<nums.length-k;i++)pq.poll();
        
        return pq.peek();
    }

    public static void main(String []args){
        int nums[] = {3,2,1,5,6,4};
        KthLargestNumber knum= new KthLargestNumber();
        int k=2; //find the kth largest element
        int number = knum.findKthLargest(nums,k);
        System.out.println("Kth largest number with k " + k+" is "+ number);
        k=3;
        number = knum.findKthLargestwithoutSort(nums,k);
        System.out.println("Kth largest number without sorting, with k " + k+" is "+ number);
    }
    
}