#pragma once
#include "util.h"

template <typename N > 	
struct list 
{
			N val ;
			list* next ;
};


template <typename T>
class Fifo 
{
	public :
		Fifo () ;
		~Fifo () ;
		int size () ;
		bool empty () ;
		T   out () ;
		Fifo<T>& in (T    ) ;
		 operator bool  () ;


	
	private:
	
		list<T> * head ;
		int _size ;


		 

};
 
/***Functions class Fifo *******/
template <typename T>
  Fifo<T>::Fifo (  ) :head(NULL),_size (0) 
{
	

}
template <typename T>
  Fifo<T>::~Fifo (  )  
{
	list<T> * temp = head ;
	while( temp)
	{
	temp = temp->next;
	delete head ;
	head= temp ;

	}
	_size =0;

}
template <typename T>
  Fifo<T>::  operator bool (  )  
{
	if ( head )
		return true ;
	else
		return false ;

}


template <typename T>
Fifo<T> & Fifo<T>::in ( T value ) 
{
	list<T> * temp = new list <T> ;
	temp->val = value ;
	temp->next=NULL;
	if(head)
	{	
		list<T> * tp  = head ;
		while ( tp->next )		
			tp=tp->next ;
		tp->next=  temp; 
		
	}
	else
	{
		head = temp;
		  
	}
	 _size ++ ;
 	return *this ;

}

template <typename T>
int Fifo<T>::size (   ) 
{
return _size ;
}

template <typename T>
bool Fifo<T>::empty (  ) 
{
	if(_size) return true ;
	else return false ;
}

template <typename T>
T   Fifo<T>::out () 
{
	if( _size == 0 ) 
		throw  *this  ;
	
	 	list<T> *  tp = head ;
 		T val = tp->val ;
		--_size ;
		head = head->next;
		delete tp ;
	 
	
	return val ;
}








