//Dynamic_array.cpp
// here we implement a dynamic array
class DynamicArray{
  int* data;
  int nextIndex;
  int capacity;

public:
  DynamicArray(){
    data =new int[5];
    nextIndex=0;
    capacity=5;
  }

  // making our own copy constructor for deep Copy
  DynamicArray(DynamicArray const &d){
    this->data=new int[d.capacity];
    /// copy the elements from d
    for (int i=0;i<d.nextIndex;i++){
      this->data[i]=d.data[i];
    }
    this->nextIndex=d.nextIndex;
    this->capacity=d.capacity;
  }

  // we have to do the same for the equal operator
  void operator+(DynamicArray const &d){
    this->data=new int[d.capacity];
    /// copy the elements from d
    for (int i=0;i<d.nextIndex;i++){
      this->data[i]=d.data[i];
    }
    this->nextIndex=d.nextIndex;
    this->capacity=d.capacity;
  }

  // function to add element
  void add(int element){
    if(nextIndex==capacity){
      int* newData=new int[2*capacity];
      for (int i=0;i<capacity;i++){
        newData[i]=data[i];
      }
      delete[] data;
      data=newData;
      capacity=2*capacity;
    }
    data[nextIndex]=element;
    nextIndex++;
  }

  int getElement(int i){
    if(i>capacity){
      return -1;
    }
    return data[i];
  }

  void print(){
    for (int i=0;i<nextIndex;i++){
      cout<<data[i]<<" ";
    }
    cout<<endl;
  }

};
