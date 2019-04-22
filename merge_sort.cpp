#include<iostream>
#include<stdlib.h>
#include<ctime>

using namespace std;

int * make_array(int length);
void print_array(int *array, int length);
void print_seg_array(int *array, int start, int end);
int * selection_sort(int *array, int length);
int * bubble_sort(int *arrray, int length);
void qsort_array(int * array, int begin, int end);
int * msort_array(int *array, int length, int start, int end);

int main(){
	srand(time(NULL));

	//Make an array of ints (size = length)
	int length = 10;
	int *array_m = make_array(length);
	int *array_q = make_array(length);
	//int *array_b = make_array(length);
	cout << endl;

	print_array(array_m, length);

	cout << endl;

	//Time for merge sort array:
	unsigned int timer = clock();
	unsigned int change_time1, change_time2;
	//qsort_array(array_m, 0 , length - 1);

	array_m = msort_array(array_m, length, 0, length - 1);

	print_array(array_m, length);

	cout << endl;

	change_time1 = clock() - timer;
	//cout << "\nMerge Sort: " << change_time1 << "\n" << endl;

	print_array(array_q, length);

	cout << endl;

	timer = clock();

	qsort_array(array_q, 0, length - 1);

	print_array(array_q, length);

	change_time2 = clock() - timer;
	//cout << "\nQuick Sort: " << change_time2 << endl;

	//Time for bubble sort array:
	//timer = clock();
	//array_b = bubble_sort(array_b, length);

	//print_array(array_b, length);

	cout << "\nMerge Sort: " << change_time1 << "\n" << endl;
  cout << "\nQuick Sort: " << change_time2 << endl;

	/*



	Here we want to:
		1) Split array up into smaller arrays (bring it to size 1)
		2) Sort smaller array
		3) Join smaller arrays together to return one sorted array
			- Be sure to use while loop with two indexers here!

	*/

	/*

		Time complexity: log(n) for partition array, O(n) for going through that array
		Total: log(nlog(n))
	*/


}

int * make_array(int length){

	int *array = new int[length];
	for(int i = 0; i < length; i++){

		array[i] = rand() % 500;


	}

	return array;

}

void print_array(int * array, int length){


	for(int i = 0; i < length; i++)
		cout << array[i] << ", ";

	cout  << endl;
}

void print_seg_array(int *array, int start, int end){

	cout << "\n" << endl;
	for(int i = start; i <= end; i++)
		cout << array[i] << ", ";

}

int * selection_sort(int *array, int length){

	int change;
	for(int i = 0; i < length; i++){
		for(int j = i + 1; j < length; j++){
			if(array[i] > array[j]){
				change = array[i];
				array[i] = array[j];
				array[j] = change;
			}
		}

	}

	return array;

}

int * buble_sort(int *array, int length){

  return array;

}

//Note: Here we are assuming begin and end are both indecies of the array
void qsort_array(int *array, int begin, int end){

	//cout << "\n" << endl;
	//print_seg_array(array, begin, end);



	/*
	This section is for visualizing the algorithm:

	cout << "Pivot: " << pivot << "\tStart: " << begin << "\tEnd: " << end << endl;
	print_array(array, 10);
	*/

	if(begin >= end)
		return;

	int pivot = array[(begin + end + 1) / 2];

	int increm = begin;
	int decrem = end;
	int pholder;

	while (increm <= decrem){

		//Here we will switch the values if an index less than the pivot index has a value greater than or equal to the pivot value
		//and the right index has a value less than the pivot value
		if(array[increm] >= pivot && array[decrem] <= pivot){

			pholder = array[increm];
			array[increm] = array[decrem];
			array[decrem] = pholder;

			increm++;
			decrem--;

		}

		else if(array[increm] >= pivot){

			decrem--;

		}

		else if(array[decrem] <= pivot){

			increm++;

		}

		else{

			increm++;
			decrem--;

		}

	}

	qsort_array(array, increm, end);
	qsort_array(array, begin, decrem);

}

/*
	This algorith needs to be modified so that it is faster than quicksort for
	larger values of length...
*/
int* msort_array(int *array, int length, int start, int end){


	int a = 0, b = 0, index = 0;

	int *new_array = new int[length];
	for(int i = start; i <= end; i++)
		new_array[index++] = array[i];

	if(length == 1)
		return new_array;

	int size_a, size_b;
	int * array1;
	int * array2;

	if(length % 2 == 1){


		//We want this to sort the first half of the array

		array1 = msort_array(new_array, length / 2 + 1, 0, length / 2);

			//int *array1 = sort_array(array, length / 2 + 1, start, start + length / 2);

		// We want this to sort the latter half of the array

		array2 = msort_array(new_array, length / 2, length / 2 + 1, length - 1);

			//int *array2 = sort_array(array, length / 2, start + length / 2 + 1, end);

		size_a = length / 2 + 1;
		size_b = length / 2;

	}

	else{

		array1 = msort_array(new_array, length / 2, 0, length / 2 - 1);
		array2 = msort_array(new_array, length / 2, length / 2, length - 1);

		size_a = length / 2;
		size_b = length / 2;

	}

	int size = size_a + size_b;
	index = 0;

	while(a + b <= size){

		if(a == size_a){
			new_array[index] = array2[b++];
		}

		else if(b == size_b){
			new_array[index] = array1[a++];
		}

		else{
			if(array1[a] < array2[b]){
				new_array[index] = array1[a++];
			}
			else
				new_array[index] = array2[b++];
		}


		index++;
	}

	delete [] array1;

	if(size_b > 1)
		delete [] array2;

	return new_array;

}
