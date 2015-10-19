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

	vMatrix<R, C> operator+(vMatrix<R, C>& A)
	{
		vMatrix<R,C> Result;
		for (int i = 0; i < A.Elements.size(); i++)
		{
			Result.Elements[i] = this->Elements[i] + A.Elements[i];
		}
		return Result;
	}

	vMatrix<R, C> operator=(vMatrix<R, C>&A)
	{
		vMatrix<R, C> Result;
		for (int i = 0; i < A.Elements.size(); i++)
		{
			Result.Elements[i] = A.Elements[i];
		}
		return Result;
	}
};
