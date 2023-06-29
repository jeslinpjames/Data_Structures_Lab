#include<iostream>

using namespace std;
class Mat {
  private: int ** a;
  int r,c;
  public: Mat() {}
  Mat(int x, int y) {
    r = x;
    c = y;
    if ((r > 0) && (c > 0)) {
      a = new int * [r];
      for (int i = 0; i < r; i++) {
        a[i] = new int[c];
      }
    }
  }
  ~Mat() {
    for (int i = 0; i < r; i++)
      delete a[i];
    delete a;
  }
  int* row_sum();
  int* column_sum();
  void accept_elements(void);
  int max(int ar[],int size);
};
int* Mat::column_sum() {
    int * S = new int [r];
    for (int i=0;i<r; i++){
        for(int j =0;j<c;j++){
            S[i]=S[i]+a[j][i];
        }
    }
    return S;  
}
int* Mat::row_sum() {
    int * S = new int [c];
    for (int i=0;i<c; i++){
        for(int j =0;j<r;j++){
            S[i]=S[i]+a[i][j];
        }
    }
    return S;  
}
void Mat::accept_elements() {
  for (int i = 0; i < r; i++) {
    cout << "Enter " << c << " elements of " << i + 1 << " row : ";
    for (int j = 0; j < c; j++) {
      cin >> a[i][j];
    }
  }
}
int Mat::max(int ar[],int size){
    int max_index =0;
    for(int i=1;i<size;i++){
        if(ar[max_index]<ar[i])
        max_index=i;
    }
    return max_index;
}
int main() {
  int r, c;
  cout << "Enter the number of rows and columns of the matrix : ";
  cin >> r >> c;
  Mat ob1(r, c);
  cout << "Enter the values of the matrix: " << endl;
  ob1.accept_elements();
  int *C_Sum = new int [c];
  int *R_Sum = new int [r];
  R_Sum = ob1.row_sum();
  C_Sum = ob1.column_sum();
  int max_column = ob1.max(C_Sum,c);
  int max_row = ob1.max(R_Sum,r);
  cout<<"The column number with maximum sum is : "<<max_column+1<<endl;
  cout<<"The row number with maximum sum is :"<<max_row+1<<endl;
  return 0;
}
// Enter the number of rows and columns of the matrix : 3 3
// Enter the values of the matrix:
// Enter 3 elements of 1 row : 9 8 7
// Enter 3 elements of 2 row : 6 5 4
// Enter 3 elements of 3 row : 3 2 1
// The column number with maximum sum is : 1
// The row number with maximum sum is :1