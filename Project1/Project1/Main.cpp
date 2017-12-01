#include <iostream>
#include "CustomRay.h"
#include "Scene.h"

using namespace custom_ray::math_library;
using namespace std;
using namespace custom_scene;


int main() {
	int arr[3] = { 1,2,3 };
	vector_operations<int> foo;
	vector_operations<int> boo(3, arr);
	Scene scene;

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
	scene.Scene_Init();
	cin.get();
	return 0;
}