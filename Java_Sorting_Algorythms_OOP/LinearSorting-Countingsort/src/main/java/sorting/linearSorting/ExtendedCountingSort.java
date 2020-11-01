package sorting.linearSorting;

import sorting.AbstractSorting;

/**
 * Classe que implementa do Counting Sort vista em sala. Desta vez este
 * algoritmo deve satisfazer os seguitnes requisitos: - Alocar o tamanho minimo
 * possivel para o array de contadores (C) - Ser capaz de ordenar arrays
 * contendo numeros negativos
 */
public class ExtendedCountingSort extends AbstractSorting<Integer> {

	// NOTA: 9.7

	@Override
  	public void sort(Integer[] array, int leftIndex, int rightIndex) {
  		if (array != null && leftIndex < rightIndex && leftIndex >= 0 && rightIndex < array.length && array.length != 0) {
  			Integer max = array[leftIndex];
  			Integer min = array[leftIndex];
  		
  			for(int i = leftIndex + 1; i <= rightIndex; i++) {
  				if(max < array[i]) {
  					max = array[i];
  				}
  				
  				if(min > array[i]) {
  					min = array[i];
  				}
  			}
  			
  			int[] countingArray = new int[(max - min) + 1];
  			
  			for(int i = leftIndex; i <= rightIndex; i++) {
  				countingArray[array[i] - min]++;
  			}
  		
  			int indexArray = leftIndex;
  		
  			for(int i = 0; i < countingArray.length; i++) {
  			
  				while(countingArray[i] != 0) {
  					array[indexArray] = i + min;
  					indexArray++;
  					countingArray[i]--;
  				}
  			
  			}
  		}
  	}

}
