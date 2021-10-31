package sorting.divideAndConquer;

import java.util.Arrays;

import sorting.AbstractSorting;
import util.Util;

/**
 * Merge sort is based on the divide-and-conquer paradigm. The algorithm
 * consists of recursively dividing the unsorted list in the middle, sorting
 * each sublist, and then merging them into one single sorted list. Notice that
 * if the list has length == 1, it is already sorted.
 */
public class MergeSort<T extends Comparable<T>> extends AbstractSorting<T> {

	private T[] tempMergArr;
  
  	@Override
  	public void sort(T[] array, int leftIndex, int rightIndex) {
  
  		if (leftIndex >= 0 && rightIndex < array.length) {
  			
  			this.tempMergArr = Arrays.copyOf(array, array.length);
  			
  			if (leftIndex < rightIndex) {
  				
  				int middle = (leftIndex + rightIndex) / 2;
  				sort(array, leftIndex, middle);
  				sort(array, middle + 1, rightIndex);
  				mergeParts(array, leftIndex, middle, rightIndex);
  			}
  		}
  	}
  
  	/**
  	 * Metodo que usa um array auxiliar, copia do array original, supondo que cada
  	 * metade ja esta ordenada, ele ira organizar todo o array comparando, posicoes
  	 * de metades distintas e colocando -as nas posicoes adequadas.
  	 * 
  	 * 
  	 * @param array
  	 *            array que ira ser organizado ao final.
  	 * @param leftIndex
  	 *            indice que a ordenacao deve comecar.
  	 * @param middle
  	 *            indice que divide as duas metades.
  	 * @param rightIndex
  	 *            indice que a ordenacao deve terminar
  	 */
  	private void mergeParts(T[] array, int leftIndex, int middle, int rightIndex) {
  
  		for (int i = leftIndex; i <= rightIndex; i++) {
  			tempMergArr[i] = array[i];
  		}
  		
  		int i = leftIndex;
  		int j = middle + 1;
  		int k = leftIndex;
  		
  		while (i <= middle && j <= rightIndex) {
  			
  			if (tempMergArr[i].compareTo(tempMergArr[j]) < 0) {
  				array[k] = tempMergArr[i];
  				i++;
  				
  			} else {
  				array[k] = tempMergArr[j];
  				j++;
  			}
  			k++;
  		}
  		while (i <= middle) {
  			array[k] = tempMergArr[i];
  			k++;
  			i++;
  		}
  
  	}

}
