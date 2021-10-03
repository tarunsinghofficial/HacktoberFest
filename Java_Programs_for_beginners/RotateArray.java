public class RotateArray {

    public void rotate(int[] nums, int k) {
        //bounds check
        if (nums == null || nums.length == 0 || k == 0) {
            return;
        }
        int n = nums.length;
        //k may be larger than n
        k = k % n;
        rotateRange(0, n - k - 1, nums);
        rotateRange(n - k, n - 1, nums);
        rotateRange(0, n - 1, nums);
    }

    private void rotateRange(int start, int end, int[] array) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(array, i, j);
        }
    }

    private void swap(int[] array, int i, int j) {
        int t = array[i];
        array[i] = array[j];
        array[j] = t;
    }

}
