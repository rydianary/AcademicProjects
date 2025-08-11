#include<iostream>

template<typename T>
class container{
	public: 
		explicit container(const T &arg); 
		T increase();
	
	private: T element;
};

template<typename T>
container::container(const T &arg)
	: element(arg){
	}
