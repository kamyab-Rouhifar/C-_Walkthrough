// This is the best way of understanding the concept of c++ referencing and encapsulation construction
//----------------------------------------------------------------------------------------------------
// Designer: Kamyab Rouhifar
#include <iostream>
#include <cstring>
 
using namespace std;
 
const int NG = 20;

//--------------------------------------
 
class Student {
 int no;
     
float grade[NG];
     
int ng;
     
string name;
 
public:
     
Student();
     
~Student();
     
void set(int, const float*, int);
     
void display() const;
     
void add();
    
int get_no();
    
string  getname();
 
};

string Student::getname()
 {
     name="Kamyab ( programmer )";
     
return name;
 }
 
void end(){
     
Student temp;
    
cout <<"*** Have a nice day ***"<<endl;
     
cout <<"creator: "<<temp.getname()<<endl;
 }

//--------------------------------------
 
//initializes the data members

//--------------------------------------
 
Student::Student() {
     
cout << "In constructor" << endl;
     
no = 0;
     
ng = 0;
 
}
  
Student::~Student() {
 
cout << "In destructor" << endl;
    
cout << no<<endl;
  }

//--------------------------------------

 void Student::set(int sn, const float* g, int ng_) {
  
   bool valid = sn > 0 && g != nullptr && ng_ >= 0;
     
if (valid)
         
for (int i = 0; i < ng_ && valid; i++)
             
valid = g[i] >= 0.0f && g[i] <= 100.0f;

     
if (valid) {
         
// accept the client's data
         
no = sn;
         
ng = ng_ < NG ? ng_ : NG;
         
for (int i = 0; i < ng; i++)
            
 grade[i] = g[i];
    
 } else {
        
 no = 0;
         
ng = 0;
     }
 }

//--------------------------------------
 
void Student::display() const {
  
   if (no > 0) {
        
 cout << no << ":\n";
       
 cout.setf(ios::fixed);
       
 cout.precision(2);
         
for (int i = 0; i < ng; i++) {
           
  cout.width(6);
           
  cout << grade[i] << endl;
       
  }
        
 cout.unsetf(ios::fixed);
     
    cout.precision(6);
   
  } 
else {
         cout << "no data available" << endl;
     }
 }
 
//--------------------------------------
 
int Student::get_no(){
     add();
     return no;
 }
 
//--------------------------------------
 
void mixup( Student s1, Student &s2){
     
cout <<s1.get_no()<<endl;
    
 cout<<s2.get_no()<<endl;
     
 }
 
//--------------------------------------
 
void  Student::add(){
    
 cout<<"add +5 to "<<no<<endl;
     
no+=5;
    
 ng = ng < NG ? ng : NG;
   
   for (int i = 0; i < ng; i++){
         
    grade[i]+=5;
   
 cout<<"result grade: "<<grade[i]<<endl;
    cout<<"Address grade: "<<&grade[i]<<endl;
   
  }
   
 }
 
//--------------------------------------
 
int main () {
     
Student harry, josee,jack;
     
float gh[] = {89.4f, 67.8f, 45.5f};
     
float gj[] = {83.4f, 77.8f, 55.5f};
     
harry.set(1234, gh, 3);
     
josee.set(1235, gj, 3);
     
cout<<"-------------"<<endl;
     
jack.display();
     
cout<<"-------------"<<endl;
     
mixup(harry,josee);
      
cout<<"*add*-------------*add*"<<endl;
     
harry.add();
      
cout<<"*add*-------------*add*"<<endl;
     
harry.display();
      
cout<<"-------------"<<endl;
     
josee.display();
     
end();
 
return 0;
}

