#include<iostream>
using namespace std;

int main () {

    int n ;
    cout << " Please enter an vlaue" << endl;
    cin>> n;                                       
                                                // sqaure printing
  for (int i = 0; i <n; i++)
  {
    for (int j = 0; j < i+1; j++)
    {
        cout << "*";
            
    }
     cout << endl;

  }
  

 
}

 #include<iostream>
using namespace std;

int main () {

    int n ;
    cout << " Please enter an vlaue" << endl;
    cin>> n;

  for (int i = 0; i <n; i++)
  {
    for (int j = 0; j < n-i; j++)
    {
        cout << "*";
            
    }
     cout << endl;

  }
  

 
}