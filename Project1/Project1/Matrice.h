#include<iostream>
#ifndef MATRICENMD_H
#define MATRICENMD_H

namespace MathLibrary {
	namespace MatriceNMD {
		template<class T, int N, int M> class MatriceNMD {
		public:
			MatriceNMD();
			MatriceNMD(T);
			MatriceNMD(const T[]);
			MatriceNMD(const MatriceNMD<T, N, M>&);
			//MatriceNMD(int, int);
			~MatriceNMD();
			int Get_Rows() const { return num_rows; };
			int Get_Columns() const { return num_columns; };
			T   Get_Value(int, int)const;
			void Set_Value(int, int, T);
			void operator=(const MatriceNMD<T, N, M>&);
			void operator()(const MatriceNMD<T, N, M>&);
			/*void operator+=(const MatriceNMD<T, N, M>&);
			void operator==(const MatriceNMD<T, N, M>&);
			void operator!=(const MatriceNMD<T, N, M>&);*/
			

		private:
			T mat[N][M];
			int num_rows = N;
			int num_columns = M;
		};
		
	};//namespace MatriceNMD
};//namespace MathLibrary

namespace MathLibrary {
	namespace MatriceNMD {

		template<class T, int N, int M>
		MatriceNMD<T, N, M> operator*(const MatriceNMD<T, N, M>& mat1, const MatriceNMD<T, N, M>& mat2) {
			int i, j, k;
			T sum;
			if (mat1.Get_Columns() != mat2.Get_Rows())
				return nullptr;
			MatriceNMD<T, N, M> mat3;
				i = 0;
			k = 0;
			while (i < mat3.Get_Rows())
			{
				while (k < mat3.Get_Columns())
				{
					sum = 0;
					for (j = 0; j < 3; j++)
					{
						sum += mat1.Get_Value(i, j)*mat2.Get_Value(j, k);
						cout << "SUM: " <<sum<<" = " <<mat1.Get_Value(i, j)<<" * "<< mat2.Get_Value(j, k)<< endl;
					}
					if (std::abs(sum) < 1.e-5)
						sum = 0;
						mat3.Set_Value(i, k, sum);
					k++;
				};
				i++;
				k = 0;
			};
			return mat3;
		};

		template<class T, int N, int M>
		void MatriceNMD<T, N, M>::operator()(const MatriceNMD<T, N, M>& mat) {
			for (int i = 0; i < mat.Get_Rows(); i++)
				for (int j = 0; j < mat.Get_Columns(); j++)
					this->mat[i][j] = mat.Get_Value(i, j);
		};

		template<class T, int N, int M>
		MatriceNMD<T, N, M>::MatriceNMD() {
			for (int i = 0; i < this->Get_Rows(); i++) {
				for (int j = 0; j < this->Get_Columns(); j++)
					this->mat[i][j] = (T)(i*M + i + j - 2);
			}
		}

		template<class T, int N, int M>
		MatriceNMD<T, N, M>::MatriceNMD(const T arr[]) {

			for (int i = 0; i < this->Get_Columns()*this->Get_Rows(); i++)
			{
				this->mat[i / this->Get_Columns()][i%this->Get_Columns()] = arr[i];
			}
		};

		template<class T, int N, int M>
		MatriceNMD<T, N, M>::MatriceNMD(T default) {
			for (int i = 0; i < num_rows; i++) {
				for (int j = 0; j < num_columns; j++)
				{
					if (i == j)
						this->mat[i][j] = default;
					else
						this->mat[i][j] = 0;//default*i-j;
				}
			}
		}

		template<class T, int N, int M>
		MatriceNMD<T, N, M>::MatriceNMD(const MatriceNMD<T, N, M>& mat1) {
			for (int i = 0; i < this->Get_Rows(); i++) {
				for (int j = 0; j < this->Get_Columns(); j++)
				{
					this->mat[i][j] = mat1.Get_Value(i, j);
					//cout << "TEST: " << this->mat[i][j] << " TEST2: " << mat1.Get_Value(i, j) << endl;
				}
			}
		};

		template<class T, int N, int M>
		MatriceNMD<T, N, M>::~MatriceNMD() {

		};

		template<class T, int N, int M>
		T MatriceNMD<T, N, M>::Get_Value(int row, int column) const {
			return mat[row][column];
		};

		template<class T,int N,int M>
		void MatriceNMD<T, N, M>::Set_Value(int row, int column, T value) {
			this->mat[row][column] = value;
		};
	
		template<class T, int N, int M>
		void MatriceNMD<T, N, M>::operator=(const MatriceNMD<T, N, M>& mat1) {
			for (int i = 0; i < num_rows; i++) {
				for (int j = 0; j < num_columns; j++)
				{
					this->mat[i][j] = mat1.Get_Value(i, j);
					//cout << "TEST: " << this->mat[i][j] << " TEST2: " << mat1.Get_Value(i, j) << endl;
				}
			}
		};

		template<class T, int N, int M>
		MatriceNMD<T, N, M> Inverse(const MatriceNMD<T, N, M>& mat) {
			T tempAbs = 0, temp=0, temp1=0;
			int tempRowIndex;
			MatriceNMD<T, N, M> retMat(mat);
			MatriceNMD<T, N, M> mat1(1.0f);

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					cout << "RETMAT: " << retMat.Get_Value(i, j) << endl;
			for(int i=0; i<retMat.Get_Rows(); i++)
				if (retMat.Get_Value(i, i) == 0) {
					for(int j=i; j<retMat.Get_Columns(); j++)
						if (std::abs(retMat.Get_Value(j, i)) > tempAbs) {
							tempAbs = retMat.Get_Value(j, i);
							tempRowIndex = j;
						}
					if (tempAbs == 0)
						return mat1;
					for (int k = 0; k < retMat.Get_Rows(); k++) {
						temp = retMat.Get_Value(i, k);
						retMat.Set_Value(i, k, retMat.Get_Value(tempRowIndex, k));
						retMat.Set_Value(tempRowIndex, k, temp);
						temp = mat1.Get_Value(i, k);
						mat1.Set_Value(i, k, mat1.Get_Value(tempRowIndex, k));
						mat1.Set_Value(tempRowIndex, k, temp);
					}
				}
			for(int j=0; j<retMat.Get_Columns(); j++)
				for (int i = 0; i < retMat.Get_Rows(); i++) {
					if (i != j && retMat.Get_Value(i, j) != 0)
					{
						float constante = retMat.Get_Value(i, j) / retMat.Get_Value(j, j);
						for (int k = 0; k < retMat.Get_Rows(); k++) {
							temp = retMat.Get_Value(i, k);
							temp -= constante*retMat.Get_Value(j, k);
							temp1 = mat1.Get_Value(i, k);
							temp1 -= constante*mat1.Get_Value(j, k);
							retMat.Set_Value(i, k, temp);
							mat1.Set_Value(i, k, temp1);
						}
						
					}
				}
			for (int i = 0; i < retMat.Get_Rows(); i++)
				for (int j = 0; j < retMat.Get_Columns(); j++)
					mat1.Set_Value(i, j, mat1.Get_Value(i, j) / retMat.Get_Value(i, i));
			return mat1;
		};
	};//namespace MatriceNMD
};//namespace MathLibrary

#endif

