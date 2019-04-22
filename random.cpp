#include<iostream>
#include<ctime>
#include<stdlib.h>

using namespace std;

struct link {

  int value;
  struct link * next;
  struct link * prev;

};

void addLink(struct link* bsent, int val){

  struct link * new_link = new struct link;

  new_link->value = val;
  bsent->prev->next = new_link;
  new_link->prev = bsent->prev;
  bsent->prev = new_link;
  new_link->next = 0;

}

bool getSum(int *array, int length, int sum){

  int end = length - 1;
  int begin = 0;

  while(begin != end){
    if(array[begin] + array[end] < sum){
      begin++;
    }

    else if(array[begin] + array[end] > sum){

      end--;

    }

    if(sum == array[begin] + array[end])
      return true;

  }

  return false;

}

void sort_array(int * array, int begin, int end){

  if(begin >= end)
    return;

  int pivot = (begin + end) / 2;
  int bindex = begin;
  int eindex = end;

  while(bindex <= eindex){

    if(array[bindex] >= array[pivot] && array[eindex] <= array[pivot]){

      int temp = array[bindex];
      array[bindex] = array[eindex];
      array[eindex] = temp;

      bindex++;
      eindex--;

    }

    else if(array[bindex] >= array[pivot]){

      eindex--;

    }

    else if(array[eindex] <= array[pivot]){

      bindex++;

    }

    else{
      bindex++;
      eindex++;
    }

  }

  sort_array(array, begin, eindex);
  sort_array(array, bindex, end);

}

int main() {

  int length = 10;
  int *array = new int[length];

  srand(time(NULL));

  for(int i = 0; i < length; i++){

    array[i] = (rand() % 10);
    cout << array[i] << ", ";

  }

  cout << endl;

  sort_array(array, 0, length - 1);

  cout << "Sorted Array! :" << endl;

  for(int i = 0; i < length; i++){

    cout << array[i] << ", ";

  }

  cout << "\n" << endl;

  cout << getSum(array, length, 10) << endl;
  /*
  struct link *sent1 = new link;
  struct link *sent2 = new link;

  sent1->next = sent2;
  sent1->prev = 0;
  sent2->prev = sent1;
  sent2->next = 0;
  */

}
