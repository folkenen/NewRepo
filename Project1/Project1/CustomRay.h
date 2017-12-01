#pragma once
#define DLLExport __declspec(dllexport)
#define default_length 3
namespace custom_ray {
	namespace math_library {

		template<class T> class DLLExport vector_operations
		{
		private: T* vector;
				 int length;
		public:
			vector_operations();
			vector_operations(int length, int values[]);
			~vector_operations();
			void operator+=(const vector_operations<T>&);
			bool operator==(const vector_operations<T>&);
			bool operator!=(const vector_operations<T>&);
			int    operator[](int);
			T get_vector_index(int)const;
			int get_length()const;

		};
	}; //namespace math_library
}; //namesapce custom_ray

namespace custom_ray {
	namespace math_library {
		template<class T> vector_operations<T>::vector_operations()
		{
			this->length = default_length;
			vector = new int[length];
			for (int i = 0; i < length; i++)
				vector[i] = i;
		}

		template<class T> vector_operations<T>::vector_operations(int length, int values[]) {
			this->length = length;
			this->vector = new int[length];
			for (int i = 0; i < length; i++)
				this->vector[i] = values[i];
		}

		template<class T> vector_operations<T>::~vector_operations() {
			delete[] this->vector;
		}

		template<class T> T vector_operations<T>::get_vector_index(int i) const {
			return this->vector[i];
		}

		template<class T> int vector_operations<T>::get_length() const {
			return this->length;
		}

		template<class T> void vector_operations<T>::operator+=(const vector_operations<T>& v_operations) {
			if (this->length == v_operations.get_length())
				for (int i = 0; i < this->length; i++)
					this->vector[i] = this->vector[i] + v_operations.get_vector_index(i);
		}

		template<class T> bool vector_operations<T>::operator==(const vector_operations<T>& v_operations) {
			bool result = true;
			int i = 0;
			if (!(this->length == v_operations.get_length()))
				return !result;
			else
				while (i < this->length && result)
				{
					if (this->vector[i] != v_operations.get_vector_index(i))
						result = !result;
					i++;
				}
			return result;
		}

		template<class T> bool vector_operations<T>::operator!=(const vector_operations<T>& v_operations) {
			return !(*this == v_operations);
		}

		template<class T> int vector_operations<T>::operator[](int i) {
			return get_vector_index(i);
		}

	}//namespace math_library
} //namesapce custom_ray


