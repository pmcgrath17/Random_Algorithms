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

	int array [] = {2, 20, 1, 7, 8, 9, 12};
	Vector vector(array, 7);
	vector.print_vector();

	vector.free_vector();
}


void heap_sort(Vector vector){
// need to percolate and then switch

/*
	for(int i = vector.size; i > 0; --i){
		int temp = vector.at(i);
		vector.data[i] = vector.data[0];
		vector.data[0] = temp;
		percolate(vector, i);
	}
*/

}

void percolate(Vector vector, int last_index){


}


Vector::Vector(int array[], int size){

	this->size = size;
	this->capacity = size*2;
	this->data = new int[capacity];
	for(int i = 0; i < size; ++i){
		this->data[i] = array[i];
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
