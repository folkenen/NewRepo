#include <iostream>
#include "VectorND.h"
#include "Matrice.h"
#include "Scene.h"

using namespace MathLibrary::VectorLibrary;
using namespace MathLibrary::MatriceNMD;
using namespace std;
using namespace custom_scene;


int main() {
	int arr[3] = { 1,2,3 };
	float arra[9] = {1, 2, 3 , 7.5, 2, 5 , 1.3, 2, 4 };
	VectorND<int, 3> foo;
	VectorND<int, 3> boo(arr);
	MatriceNMD<float, 3, 3> mat1(arra);
	MatriceNMD<float, 3, 3> mat2(5);
	MatriceNMD<float, 3, 3> fin(arra);
	MatriceNMD<float, 3, 3> inve;
	Scene scene;
	//fin = mat1 * mat2;
	inve = Inverse(mat1);
	fin = inve * mat1;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cout << "FIN: " << fin.Get_Value(i, j) << endl;
	for (int i = 0; i<3; i++)
		cout << foo.get_vector_index(i) << endl;
	for (int i = 0; i<3; i++)
		cout << boo.get_vector_index(i) << endl;
	foo += boo;
	//char t = (foo==boo);
	for (int i = 0; i<3; i++)
		cout << foo.get_vector_index(i) << endl;
	if (!(foo == boo))
		cout << "FALSE" << endl;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cout << "INVE: " << inve.Get_Value(i, j) << endl;
	scene.Scene_Init();
	cin.get();
	return 0;
}