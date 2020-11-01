package sorting.divideAndConquer.threeWayQuicksort;

import sorting.AbstractSorting;
import util.Util;

public class ThreeWayQuickSort<T extends Comparable<T>> extends
		AbstractSorting<T> {

	/**
	 * No algoritmo de quicksort, selecionamos um elemento como pivot,
	 * particionamos o array colocando os menores a esquerda do pivot 
	 * e os maiores a direita do pivot, e depois aplicamos a mesma estrategia 
	 * recursivamente na particao a esquerda do pivot e na particao a direita do pivot. 
	 * 
	 * Considerando um array com muitoe elementos repetidos, a estrategia do quicksort 
	 * pode ser otimizada para lidar de forma mais eficiente com isso. Essa melhoria 
	 * eh conhecida como quicksort tree way e consiste da seguinte ideia:
	 * - selecione o pivot e particione o array de forma que
	 *   * arr[l..i] contem elementos menores que o pivot
	 *   * arr[i+1..j-1] contem elementos iguais ao pivot.
	 *   * arr[j..r] contem elementos maiores do que o pivot. 
	 *   
	 * Obviamente, ao final do particionamento, existe necessidade apenas de ordenar
	 * as particoes contendo elementos menores e maiores do que o pivot. Isso eh feito
	 * recursivamente. 
	 **/
	
	private int middle;
  	
  	@Override
  	public void sort(T[] array, int leftIndex, int rightIndex) {
  		
  		this.middle = (leftIndex + rightIndex) / 2;
  		
  		if (leftIndex >= 0 && rightIndex < array.length) {
  
  			if (array.length > 1 && rightIndex - leftIndex >= 1) {
  
  				sortPivot(array, leftIndex, rightIndex);
  				int pivotIndex = move(array, leftIndex + 1, rightIndex - 1);
  
  				if (rightIndex - leftIndex > 2) {
  					sort(array, leftIndex, pivotIndex - 1);
  					sort(array, pivotIndex + 1, rightIndex);
  				} else {
  					sortThree(array, leftIndex, rightIndex);
  				}
  			}
  		}
  	}
  
  	private void sortPivot(T[] array, int leftIndex, int rightIndex) {
  
  		this.middle = (leftIndex + rightIndex) / 2;
  		
  		if (array[leftIndex].compareTo(array[middle]) > 0) {
  			Util.swap(array, leftIndex, middle);
  		}
  
  		if (array[leftIndex].compareTo(array[rightIndex]) > 0) {
  			Util.swap(array, leftIndex, rightIndex);
  		}
  
  		if (array[middle].compareTo(array[rightIndex]) > 0) {
  			Util.swap(array, middle, rightIndex);
  		}
  
  		Util.swap(array, middle, rightIndex - 1);
  	}
  
  	private void sortThree(T[] array, int leftIndex, int rightIndex) {
  
  		int size = rightIndex - leftIndex;
  		if (size > 0 && array[leftIndex].compareTo(array[rightIndex]) > 0) {
  			Util.swap(array, leftIndex, rightIndex);
  		}
  
  		if (size > 1) {
  			this.middle = (leftIndex + rightIndex) / 2;
  			
  			if (array[leftIndex].compareTo(array[middle]) > 0) {
  				Util.swap(array, leftIndex, middle);
  			}
  
  			if (array[middle].compareTo(array[rightIndex]) > 0) {
  				Util.swap(array, middle, rightIndex);
  			}
  		}
  
  	}
  
  	private int move(T[] array, int leftIndex, int rightIndex) {
  		int j = leftIndex - 1;
  		int i = leftIndex;
  		T pivot = array[rightIndex];
  
  		while (i < rightIndex && j < rightIndex) {
  			if (array[i].compareTo(pivot) < 0 && i > j) {
  				j++;
 				Util.swap(array, j, i);
 			} else {
 				i++;
 			}
 		}
 		j++;
 		while (rightIndex > j) {
 			Util.swap(array, rightIndex, rightIndex - 1);
 			rightIndex--;
 		}
 
 		return j;
 	}

}
