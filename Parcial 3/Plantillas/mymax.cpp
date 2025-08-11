#include<iostream>
//3 differente parameters in a function
template<typename R,typename T,typename U>
R max(T a, U b){
	return a<b? b:a;
}

int main(){
	//return data type
	double d=max<double>(5.5, 2);
	char i = max<char, char, char>('a','b');
	std::cout<<d<<std::endl;
	std::cout<<i<<std::endl;
	return 0;
}
