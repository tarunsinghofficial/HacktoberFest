package sorting.variationsOfBubblesort;

import sorting.AbstractSorting;
import util.Util;

/**
 * The implementation of the algorithm must be in-place!
 */
public class GnomeSort<T extends Comparable<T>> extends AbstractSorting<T> {
	
	// NOTA: 9.7 

	public void sort(T[] array, int leftIndex, int rightIndex) {
  		
  		if (!(array == null || array.length == 0 || leftIndex < 0 || rightIndex < 0 || leftIndex > rightIndex 
  				|| rightIndex > array.length - 1)) {
  			
  			//Para verificar o indice -1 tambem
  			int indice = leftIndex + 1;
  			while(indice <= rightIndex) {
  				
  				//Se o atual for maior ou igual o anterior adianta o indice.
  				if (indice <= leftIndex || array[indice].compareTo(array[indice - 1]) >= 0) {
  					indice ++;
  				}
  				
  				//Caso contrario troca os elementos e decrementa o indice
  				else {	
  					Util.swap(array, indice, indice - 1);
  					indice --;
  				}
  			}
  		}
  	}

}
