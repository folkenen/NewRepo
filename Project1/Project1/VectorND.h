#ifndef VECTORND_H
#define VECTORND_H

namespace MathLibrary {
	namespace VectorLibrary {

#define default_length 3

		template<class T, int N > class VectorND
		{
		public:
			VectorND();
			VectorND(const int[]);
			~VectorND();
			void operator+=(const VectorND<T, N>&);
			bool operator==(const VectorND<T, N>&);
			bool operator!=(const VectorND<T, N>&);
			int    operator[](int);
			T get_vector_index(int)const;
			void set_vector_index(int, T);
			int get_length()const;

		private: T vector[N];
				 int length;

		};
	}; //namespace VectorLibrary
}; //namesapce MathLibrary

namespace MathLibrary {
	namespace VectorLibrary {

		template<class T, int N>
		VectorND<T, N>::VectorND()
		{
			this->length = N;
			for (int i = 0; i < length; i++)
				vector[i] = i;
		}

		template<class T, int N>
		VectorND<T, N>::VectorND(const int values[]) {
			this->length = N;
			for (int i = 0; i < length; i++)
				this->vector[i] = values[i];
		}

		template<class T, int N>
		VectorND<T, N>::~VectorND() {
		}

		template<class T, int N>
		T VectorND<T, N>::get_vector_index(int i) const {
			return this->vector[i];
		}

		template<class T, int N>
		void VectorND<T, N>::set_vector_index(int i, T v) {
			this->vector[i] = v;
		}

		template<class T, int N>
		int VectorND<T, N>::get_length() const {
			return this->length;
		}

		template<class T, int N>
		void VectorND<T, N>::operator+=(const VectorND<T, N>& v_operations) {
			if (this->get_length() == v_operations.get_length())
				for (int i = 0; i < this->length; i++)
					this->set_vector_index(i, this->get_vector_index(i) + v_operations.get_vector_index(i));
		}

		template<class T, int N>
		bool VectorND<T, N>::operator==(const VectorND<T, N>& v_operations) {
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

		template<class T, int N>
		bool VectorND<T, N>::operator!=(const VectorND<T, N>& v_operations) {
			return !(*this == v_operations);
		}

		template<class T, int N>
		int VectorND<T, N>::operator[](int i) {
			return get_vector_index(i);
		}

	}//namespace MathLibrary
} //namesapce VectorLibrary

#endif
