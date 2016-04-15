#ifndef _Vector
#define _Vector


#include <string.h>
#define uint unsigned int


template <class TYPE>
class Vector{
private:
	TYPE *buffer=nullptr;
	uint capacity = 10;
	uint num_elements = 0;


public:
	Vector(){
		buffer = new TYPE[capacity];

	};

	Vector(const Vector& My_Vector){ //copy constructor
	
	capacity:My_Vector.capacity;
	num_elements:My_Vector.num_elements;
	buffer = new TYPE[My_Vector.capacity];

		for (uint i = 0; i < num_elements; i++){
			buffer[i] = My_Vector.buffer[i];
		}

	};

	~Vector(){

		delete[] buffer;
	};

	 TYPE operator[](uint index) const
	{
		assert( index < num_elements); //if index > num_elements = runtime error
		return vector[index];
	 };
	 TYPE &operator[](const uint &index) 
	{
		assert(index < num_elements); //if index > num_elements = runtime error
		return vector[index];
	 };


	uint Get_Capacity()const{

		return capacity;

	};

	void push_back(const TYPE &element)
	{
		TYPE*temp = nullptr;

		if (capacity == num_elements){
			capacity *= 2;
			temp = new TYPE[capacity];

			for (uint i = 0; i < num_elements; i++){

				temp[i] = buffer[i];
			}
			delete[] buffer;
			buffer = temp;



		}
		buffer[num_elements++] = element;

	};


	void push_front(const TYPE &element)
	{

		TYPE*temp = nullptr;
		if (capacity == num_elements){

			capacity *= 2;
			temp = new TYPE[capacity];

			uint y = 1;
			for (uint i = 0; i < num_elements; i++){

				temp[y++] = buffer[i];
			}
			delete[] buffer;

			buffer = new TYPE[capacity];
			temp[0] = element;
			buffer = temp;
		}

		else{
			TYPE * temp;
			temp = buffer;
			int y = num_elements - 1;

			for (int i = num_elements; i>0; i--)
			{
				buffer[i] = temp[y--];
			}
			buffer[0] = element;
		}num_elements++;
	};

	bool pop_back(TYPE & value){

		if (num_elements > 0){
			num_elements--;
			value = buffer[num_elements];
			return true;
		}
		else return false;

	}


	bool empty() const{


		return buffer[0] == '\0';

	}

	void clear(){
		buffer[0] = NULL;
		num_elements = 0;
	}


	}














};


#endif




/*
Vector<Room*> rooms;
rooms.Push_back(new Room("nombre","descripcion")
*/






																/*Entity -------->  Vector<Entity*> my_entities
																 
																 
																 
																 Heredan




				(Rooms _____________________________Player______________________Exit_________________Item________)
	
															
															

				enum{
				Type Player
				Type Room
				Type Exit
				...}



				String::Tokenize("____");

				tiene que devolver un vector de Strings   Vector<String>


				a__b__c__d






				Vector <string> tokens;			constructor de strings
				player_input.Tokenize(" ",tokens);






																*/


/*que valores recibe
 es constante?
 que retorna*/
