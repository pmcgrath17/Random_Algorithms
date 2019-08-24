public class Algorithms{

	public int [] quick_sort(int [] array, int array_begin, int array_end){

		if(array_begin >= array_end)
			return;

		int increment = array_begin;
		int decrement = array_end;
		int middle = (array_begin + array_end)/2;
		int middle_value = array[middle];

		while(increment <= decrement){

			if(array[increment] > middle_value && array[decement] < middle_value){

				int temp;
				temp = array[increment];
				array[increment] = array[decrement];
				array[decrement] = temp;			
				increment++;
				decrement--;

			}
			
			else if(array[increment] >= middle_value){

				decrement--;

			}
			
			else if(array[decrment] <= array[middle]){

				increment++;
			}

			else{

				increment++;
				decrement--;

			}	

		}

		quick_sort(array, array_begin, decrement);
		quick_sort(array, increment, array_end);

	}

	public static void main (String[] args){

		Algorithms example = new Algorithms();
		int [] value = example.sample([5,4,3,2,1], 0, 5);
		for(int i = 0; i < value.length; i++){

			System.out.println(value[i]);

		}

	}


}
