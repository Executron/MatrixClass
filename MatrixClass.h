#include<vector>
#include<iostream>

using namespace std; 

template < int R, int C >
struct vMatrix
{

	vector<float> Elements;


	vMatrix()
	{ 
		Elements.resize(R*C);
		for (int Index = 0; Index < Elements.size(); Index++)
		{
			Elements[Index] = Index;
		}
	}
	vMatrix(std::vector<float>& input)
	{
		Elements.resize(R*C);
		//input and element size should be equal
		for (int i = 0; i < Elements.size(); i++)
		{
			Elements[i] = input[i];
		}
	}
	


	float operator[](int index)
	{
		return Elements[i];
	}
	
	vMatrix<1, C> getRow(int row)
	{
		vMatrix<1, C> k;
		for (int i = 0; i < k.Elements.size(); i++)
		{
			k.Elements[i] = Elements[row*C + i];
		}
		return k;
	}
	vMatrix<R, 1> getColoumn(int col)
	{
		vMatrix<C, 1> k;
		for (int i = 0; i < k.Elements.size(); i++)
		{
			k.Elements[i] = Elements[i*C + col];
		}
		return k;
	}

	void printMatrix()
	{
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				std::cout << Elements[i*C + j] << "\t";
			}
			std::cout<<std::endl;
		}
	}

	//ASSIGNMENT

	vMatrix<R, C> operator=(vMatrix<R, C>&A)
	{
		vMatrix<R, C> Result;
		for (int i = 0; i < A.Elements.size(); i++)
		{
			Result.Elements[i] = A.Elements[i];
		}
		return Result;
	}

	//ADDITION

	vMatrix<R, C> operator+(vMatrix<R, C>& A)
	{
		vMatrix<R,C> Result;
		for (int i = 0; i < A.Elements.size(); i++)
		{
			Result.Elements[i] = this->Elements[i] + A.Elements[i];
		}
		return Result;
	}

	vMatrix<R, C> operator+=(vMatrix<R, C>& A)
	{
		return this + A;
	}

	//SUBSTRACTION

	vMatrix<R, C> operator-(vMatrix<R, C>& A)
	{
		vMatrix<R, C> Result;
		for (int i = 0; i < A.Elements.size(); i++)
		{
			Result.Elements[i] = this->Elements[i] - A.Elements[i];
		}
		return Result;
	}

	vMatrix<R, C> operator-=(vMatrix<R, C>& A)
	{
		return this - A;
	}

	//MULTIPLY

	template < int C2 >
	vMatrix<R, C2> operator*(vMatrix<C, C2>& other) //mXn * pXq ... n==p . size = mXq
	{
		vMatrix<R, C2> Result;
		cout << "Matrix 1: " << R << "X" << C << ". Matrix 2: " << C << "X" << C2 << std::endl;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C2; j++)
			{
				float total = 0;
				for (int k = 0; k < C; k++)
				{
					total += (this->Elements[i * C + k] * other.Elements[k * C2 + j]);
				}
				Result.Elements[i*C2 + j] = total;
			}
		}
		return Result;
	}

	template < int C2 > 
	vMatrix<R, C2> operator*=(vMatrix<C, C2>& other) //mXn * pXq ... n==p . size = mXq
	{
		return this*other;
	}

	vMatrix<R, C> operator*(float scale)
	{
		vMatrix<R, C> Result;
		for (int i = 0; i < Elements.size();i++)
		{
			Result.Elements[i] = scale*Elements[i];
		}
	}

	//DETERMINATE
	template < int D >
	float det(vMatrix<D, D> &mat)
	{
		//OMG SO COMPLEX AND SO RECURSIVE!
	}

	//Transpose
	vMatrix<C, R> transpose()
	{
		vMatrix<C, R> Result;
		for (int i = 0; i < C; i++)
		{
			for (int j = 0; j < R; j++)
			{
				Result.Elements[i*R + j] = Elements[j*C + i];
			}
		}
		return Result;
	}

};
