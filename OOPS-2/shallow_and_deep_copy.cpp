class Student{
  private:
    int age;
    char* name;
  public:
    Student(){

    }

    Student(int age,char* name){
      this->age=age;
    //  this->name=name; // this is shallow copy , we shouldnt do this because it leads to errors
      // instead we should make another array of chars and store the name there

      // Deep Copy(which we should do usually)
      this->name=new char[strlen(name)+1];
      strcpy(this->name,name);
    }

    void display(){
      cout<<this->name<<" "<<this->age;
    }

};
