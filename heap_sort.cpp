#include<iostream>
using namespace std;


struct Vector{

	Vector(int array[], int size);
	int size;
	int capacity;
	int * data;
	int at(int index);
	void print_vector();
	void free_vector();

};

void heap_sort(Vector vector);
void percolate(Vector vector, int last_index);

int main(){

	int array [] = {2, 20, 1, 7, 8, 9, 12, 6, 30};
	Vector vector(array, 9);
	vector.print_vector();
	heap_sort(vector);
	vector.print_vector();
	vector.free_vector();
}


void heap_sort(Vector vector){
// need to percolate and then switch

	for(int i = vector.size - 1; i > 0; --i){
		percolate(vector, i);
		int temp = vector.data[i];
		vector.data[i] = vector.data[0];
		vector.data[0] = temp;
		vector.print_vector();
	}

}

void percolate(Vector vector, int last_index){

	int j = 0;
	do {

		if(vector.data[j] == -10){
			return;
		}
		vector.print_vector();
		int left_child = 2*j + 1;
		int right_child = 2*j + 2;

		if(left_child <= last_index && right_child <= last_index){

			if(vector.data[left_child] > vector.data[right_child]){
				if(vector.data[j] < vector.data[left_child]){

					int temp = vector.data[j];
					vector.data[j] = vector.data[left_child];
					vector.data[left_child] = temp;
					j = left_child;

				} else {
					return;
				}

			} else {

				if(vector.data[j] < vector.data[right_child]){

					int temp = vector.data[j];
					vector.data[j] = vector.data[right_child];
					vector.data[right_child] = temp;
					j = right_child;
				} else {
					return;
				}

			}

		} else if(left_child <= last_index){

			if(vector.data[j] < vector.data[left_child]){

				int temp = vector.data[j];
				vector.data[j] = vector.data[left_child];
				vector.data[left_child] = temp;
				j = left_child;

			} else {
				return;
			}

		} else {
			return;
		}
		
	} while(j <= last_index);
}


Vector::Vector(int array[], int size){

	this->size = size;
	this->capacity = size*2;
	this->data = new int[capacity];
	for(int i = 0; i < capacity; ++i){
		if(i < size){
			this->data[i] = array[i];
		} else {
			this->data[i] = -10;
		}
	}

}

int Vector::at(int index){
	return this->data[index];
}

void Vector::print_vector(){

	for(int i = 0; i < this->size; ++i){
		cout << this->data[i] << " ";
	}
	cout << endl;

}

void Vector::free_vector(){
	delete [] this->data;
}
