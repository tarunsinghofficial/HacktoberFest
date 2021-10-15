import java.util.EmptyStackException;

public class ThreeStacksInOneArray {
    private int[] dataArray;
    private int size, topOne, topTwo, baseThree, topThree;

    public ThreeStacksInOneArray(int size) {
        if (size < 3) {
            throw new IllegalStateException("Size < 3 is not permisssable");
        }
        dataArray = new int[size];
        this.size = size;
        topOne = -1;
        topTwo = size;
        baseThree = size / 2;
        topThree = baseThree;
    }

    public void push(int stackId, int data) {
        if (stackId == 1) {
            if (topOne + 1 == baseThree) {
                if (stack3IsRightShiftable()) {
                    shiftStack3ToRight();
                    dataArray[++topOne] = data;
                } else {
                    throw new StackOverflowException("Stack one has reached limit");
                }
            } else {
                dataArray[++topOne] = data;
            }
        } else if (stackId == 2) {
            if (topTwo - 1 == topThree) {
                if (stack3IsLeftShiftable()) {
                    shiftStack3ToLeft();
                    dataArray[--topTwo] = data;
                } else {
                    throw new StackOverflowException("Stack two has reached limit");
                }

            } else {
                dataArray[--topTwo] = data;
            }
        } else if (stackId == 3) {
            if (topTwo - 1 == topThree) {
                if (stack3IsLeftShiftable()) {
                    shiftStack3ToLeft();
                    dataArray[++topThree]=data;
                } else {
                    throw new StackOverflowException("Stack three has reaced limit");
                }
            } else {
                dataArray[++topThree] = data;
            }
        } else {
            return;
        }

    }

    public int pop(int stackId) {
        if (stackId == 1) {
            if (topOne == -1)
                throw new EmptyStackException("First Stack Is Empty");
            int toPop = dataArray[topOne];
            dataArray[topOne--] = null;
            return toPop;
        } else if (stackId == 2) {
            if (topTwo == this.size)
                throw new EmptyStackException("Second Stack Is Empty");
            int toPop = dataArray[topTwo];
            dataArray[topTwo++] = null;
            return toPop;
        } else if (stackId == 3) {
            if (topThree == this.size && dataArray[topThree] == null)
                throw new EmptyStackException("third Stack Is Empty");
            int toPop = dataArray[topThree];
            if (topThree > baseThree)
                dataArray[topThree--] = null;
            if (topThree == baseThree)
                dataArray[topThree] = null;
            return toPop;
        } else {
            return null;
        }
    }

    public int top(int stackId) {
        if (stackId == 1) {
            if (topOne == -1)
                throw new EmptyStackException("First Stack Is Empty");
            return dataArray[topOne];
        } else if (stackId == 2) {
            if (topTwo == this.size)
                throw new EmptyStackException("Second Stack Is Empty");
            return dataArray[topTwo];
        } else if (stackId == 3) {
            if (topThree == baseThree && dataArray[baseThree] == null)
                throw new EmptyStackException("Third Stack Is Empty");
            return dataArray[topTwo];
        } else {
            return null;
        }
    }

    public boolean isEmpty(int stackId) {
        if (stackId == 1) {
            return topOne == -1;
        } else if (stackId == 2) {
            return topTwo == this.size;
        } else if (stackId == 3) {
            return (topThree == baseThree) && (dataArray[baseThree] == null);
        } else {
            return true;
        }
    }

    private void shiftStack3ToLeft(){
        for(int i=baseThree-1;i<=topThree-1;i++){
            dataArray[i]=dataArray[i+1];
        }
        dataArray[topThree--]=null;
        baseThree--;
    }

    private boolean stack3IsLeftShiftable(){
        if(topOne+1<baseThree){
            return true;
        }
        return false;
    }

    private void shiftStack3ToRight(){
        for(int i=topThree+1;i>=topThree+1;i--){
            dataArray[i]=dataArray[i-1];
        }
        dataArray[baseThree++]=null;
        topThree++;
    }

    private boolean stack3IsRightShiftable(){
        if(topThree+1<topTwo){
            return true;
        }

        return false;
    }

}