#ifndef MATRIX_H_
#define MATRIX_H_
#include <iostream>
#include <vector>
#include "xcept.h" 
using std::ostream;

template <class T>
class Matrix{
 friend ostream& operator<< (ostream& out, const Matrix<T>& rhs){
  size_t k=0;
  for(size_t i=0; i!=rhs.rows; ++i)
  {
   for(size_t j=0; j!=rhs.cols; ++j)
     out << rhs.element[k++] << " "; 
   out << std::endl;
  }
  return out;
 }
public:
 Matrix(int r=0, int =0);
 Matrix(const Matrix<T> &m);
 int Rows() const {return rows;}
 int Columns() const {return cols;}
 T& operator()(int i, int j);
 Matrix<T>& operator=(const Matrix<T> &rhs);
 Matrix<T> operator+()const; //unary +
 Matrix<T> operator+(const Matrix<T> &rhs)const;
 Matrix<T> operator-()const; //unary -
 Matrix<T> operator-(const Matrix<T> &rhs)const;
 Matrix<T> operator*(const Matrix<T> &rhs)const;
 Matrix<T>& operator+=(const Matrix<T> &rhs);
private:
 int rows, cols;
 std::vector<T> element;
};

template <class T>
Matrix<T>::Matrix(int r, int c)
:rows(r), cols(c)
{
 if(r<0 || c<0)
   throw BadInitializers();
 if((r&&!c)||(!r&&c))
   throw BadInitializers();
 element.resize(rows*cols);
}

template <class T>
Matrix<T>::Matrix(const Matrix<T> &m)
{
  rows = m.Rows();
  cols = m.Columns();
  element.resize(rows*cols);
  for(size_t i=0; i!=m.element.size(); ++i)
    element[i] = m.element[i];
}

template <class T>
T& Matrix<T>::operator()(int i, int j) 
{
  if ( (i<1 || i>rows) || (j<1 || j>cols) )
    throw OutOfBounds();
  return element[(i-1)*cols+j-1];
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T> &m)
{
  rows = m.Rows();
  cols = m.Columns();
  element.resize(rows*cols);
  element = m.element;
}

template <class T>
Matrix<T> Matrix<T>::operator+()const //unary +
{
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs)const
{
  if( (rhs.rows!=this->rows) || (rhs.cols!=this->cols) )
    throw SizeMismatch(); 
  Matrix result(rhs.rows, rhs.cols);
  for(size_t i=0; i<this->element.size(); ++i)
    result.element[i] = this->element[i] + rhs.element[i];
  return result;
}

template <class T>
Matrix<T> Matrix<T>::operator-()const
{
}

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &rhs)const
{
  if( (rhs.rows!=this->rows)||(rhs.cols!=this->cols) )
    throw SizeMismatch(); 
  Matrix result(rhs.rows, rhs.cols);
  for(size_t i=0; i<this->element.size(); ++i)
    result.element[i] = this->element[i] - rhs.element[i];
  return result;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &rhs)const
{
  if(this->cols != rhs.rows)
    throw SizeMismatch();
  Matrix result(this->rows, rhs.cols);
  for(size_t i=0; i!=this->rows; ++i)
   for(size_t j=0; j!=rhs.cols; ++j)
  {
    result(i+1,j+1)=0;
    for(size_t k=0; k!=this->cols; ++k)
      result(i+1,j+1) += this->element(i+1, k+1)*rhs.element(k+1, j+1);
  }
  return result;
}

template <class T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& rhs)
{
  if( (rhs.rows!=this->rows)||(rhs.cols!=this->cols) )
    throw SizeMismatch(); 
  for(size_t i=0; i<this->element.size(); ++i)
    this->element[i] += rhs.element[i];
  return *this;
}

#endif
