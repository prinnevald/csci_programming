
#include "queue.h"

void queue::ensure_capacity( size_t c ) 
{
   if( current_capacity < c )
   {
      // New capacity will be the greater of c and
      // 2 * current_capacity. 

      if( c < 2 * current_capacity )
         c = 2 * current_capacity;

      if( c < 8 ) 
         c = 8;
 
      double* newdata = new double[c];
      for( size_t s = 0; s < current_size; ++ s )
      {
         newdata[s] = data[ begin ];
         begin = next( begin );
      }

      current_capacity = c;
      begin = 0;
      end = current_size;

      delete[] data;
      data = newdata;
   }
}


void queue::printfields( std::ostream& out ) const
{
   out << "   current_size =     " << current_size << "\n";
   out << "   current_capacity = " << current_capacity << "\n";
   out << "   begin =            " << begin << "\n";
   out << "   end =              " << end << "\n";
}

void queue::checkinvariant( ) const 
{

   if( current_capacity == 0 )
   {
      std::cout << "current capacity == 0\n";
      printfields( std::cout ); 
      std::abort( );
   }

   if( begin >= current_capacity ) 
   {
      std::cout << "begin >= current_capacity\n";
      printfields( std::cout ); 
      std::abort( );
   }

   if( end >= current_capacity )
   {
      std::cout << "end >= current_capacity\n";
      printfields( std::cout ); 
      std::abort( );
   }

   if( current_size > current_capacity )
   {
      std::cout << "current_size > current_capacity\n";
      printfields( std::cout ); 
      std::abort( );
   }

   if( ( begin + current_size ) % current_capacity != end )
   {
      std::cout << 
         "distance between begin and end does not fit to current_size\n";
      printfields( std::cout );  
      std::abort( );
   }
}


queue::queue( ):
	data{new double[8]},
	current_size{0},
	current_capacity{8},
	begin{0},
	end{0}
{}

queue::queue( const queue& q ):
	current_size{q.current_size},
	current_capacity{q.current_capacity},
	begin{q.begin},
	end{q.end},
	data{new double[current_capacity]}
{	

	//end = q.end;
		
	for(size_t count = 0; count < current_capacity; ++count){
		data[count] = q.data[count];
	}
}

queue::~queue( ){
	delete[] data;
}

const queue& queue::operator = ( const queue& q ){

	current_size = q.current_size;
	//std::cout<<"size "<<current_size<<std::endl;
	//std::cout<<"q.size "<<q.current_size<<std::endl;
	begin = q.begin;
	end = q.end;
	
	if(current_capacity != q.current_capacity){
		current_capacity = q.current_capacity;
		delete[] data;
		data = new double[current_capacity];
	}
	
	for(size_t count = 0; count < current_capacity; ++count){
		data[count] = q.data[count];
	}

	return q;

}	
	

queue::queue( std::initializer_list<double> init ):
	current_size{init.size()},
	current_capacity{current_size},
	data{new double[current_capacity]},
	begin{0},
	end{current_size}
{
	//std::cout<<init.size()<<std::endl;
	//ensure_capacity(init.size());
	
	size_t count = 0;

	for(double copy: init){
		data[count] = copy;
		++count;
	}

}

void queue::push( double d ){
	ensure_capacity( current_size + 1 );
	data[end] = d;
	end = next(end);
	++current_size;
}  

void queue::pop( ){
	begin = next(begin);
	--current_size;
}

void queue::clear( ){
	begin = 0;
	end = 0;
	current_size = 0;
}

double queue::peek( ) const{
	return data[begin];
}

// It's a present for you:

std::ostream& operator << ( std::ostream& out, const queue& q )
{
	out << "[";
	size_t i = q. begin; 
	for( size_t s = 0; s < q. size( ); ++ s )
	{
	if(s) out << ", ";
	else out << " ";
      out << q. data[i];

      i = q.next(i); 
   }
   out << " ]";
   return out;
}

