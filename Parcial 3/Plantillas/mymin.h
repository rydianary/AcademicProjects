#include<iostream>
template <typename T>
T min(T p1, T p2){
	p1<p2?p1:p2;
}

template<typename T>
T min(T p1, T p2, T p3){
	if(min(p1,p2)<p3)
		return(p1,p2);
	else
		return p3;
}
