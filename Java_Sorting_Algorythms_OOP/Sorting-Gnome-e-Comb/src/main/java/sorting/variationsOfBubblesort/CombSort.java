package sorting.variationsOfBubblesort;

import sorting.AbstractSorting;
import util.Util;

/**
 * The combsort algoritm.
 */
public class CombSort<T extends Comparable<T>> extends AbstractSorting<T> {
		
	// NOTA: 9.7

	@Override
  	public void sort(T[] array, int leftIndex, int rightIndex) {
  
  		if (!(array == null || array.length == 0 || leftIndex < 0 || rightIndex < 0 || leftIndex > rightIndex
  				|| rightIndex > array.length - 1)) {
  
  			int gap = (rightIndex - leftIndex);
  			boolean trocou = true;
  			
  			//Se o gap chegar em 1 olha se na ultima passagem efetuou alguma troca caso contrario ja estara ordenado
  			while (trocou || gap != 1) {
  
  				int indice = leftIndex;
  				trocou = false;
  				gap = calculaGap(gap);
  				while (indice <= (rightIndex - gap)) {
  					if (array[indice].compareTo(array[indice + gap]) > 0) {
  						Util.swap(array, indice, (indice + gap));
  						trocou = true;
  					}
  
  					indice++;
  				}
  			}
  		}
  
  	}
  
  	private int calculaGap(int gap) {
  
  		int retorno = (int) (gap / 1.3);
  		if (retorno < 1) {
  			retorno = 1;
  		}
  
  		return retorno;
  	}

}
