package sorting.linearSorting;

import sorting.AbstractSorting;

/**
 * Classe que implementa a estratégia de Counting Sort vista em sala. Procure
 * evitar desperdicio de memoria alocando o array de contadores com o tamanho
 * sendo o máximo inteiro presente no array a ser ordenado.
 * 
 */
public class CountingSort extends AbstractSorting<Integer> {

	// NOTA: 9.7	

	@Override
  	public void sort(Integer[] array, int leftIndex, int rightIndex) {
  		if (array != null && leftIndex < rightIndex && leftIndex >= 0 && rightIndex < array.length && array.length != 0) {
  			Integer max = array[leftIndex];
  		
  			for(int i = leftIndex + 1; i <= rightIndex; i++) {
  				if(max < array[i]) {
  					max = array[i];
  				}
  			}
  			
  			int[] countingArray = new int[max + 1];
  			
  			for(int i = leftIndex; i <= rightIndex; i++) {
  				countingArray[array[i]]++;
  			}
  		
  			int indexArray = leftIndex;
  		
  			for(int i = 0; i < countingArray.length; i++) {
  			
  				while(countingArray[i] != 0) {
  					array[indexArray] = i;
  					indexArray++;
  					countingArray[i]--;
  				}
  			
  			}
  		}
  		
  	}

}
