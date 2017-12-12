#include "Matrice.h"
#include "VectorND.h"

using namespace MathLibrary::VectorLibrary;
using namespace MathLibrary::MatriceNMD;

#ifndef TRANSFORM_H
#define TRANSFORM_H

template<class T,int N>
void VectorTranslation(VectorND<T, N>& vec, const VectorND<T, N> vec2)
{
	for (int i = 0; i < vec.get_length(); i++)
		vec.set_vector_index(i, vec.get_vector_index(i) + vec2.get_vector_index(i));
}

template<class T, int N, int M>
VectorND<T, N> VectorRotation(VectorND<T, N>& vec, const MatriceNMD<T, N, M> matr) {
	int sum = 0;
	VectorND<T, N> resV;
	for (int i = 0; i < matr.Get_Rows() < i++)
	{
		for (int j = 0; j < matr.Get_Columns() < j++)
			sum += matr.Get_Value(i, j) * vec.get_vector_index(j);
		resV.set_vector_index(i, sum);
		sum = 0;
	}

	return resV;
}

#endif