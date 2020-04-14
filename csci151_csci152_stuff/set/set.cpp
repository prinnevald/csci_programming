
// Lab Exercise 4.

#include "set.h"

bool set::equal( const std::string& s1, const std::string& s2 ){
	if(s1.size() != s2.size())	
		return false;
	size_t temp = s1.size();
	for(size_t i = 0; i < temp; i++){
		if(tolower(s1[i]) != tolower(s2[i]))
			return false;	
	}
	return true;
}

bool set::contains( const std::string& el ) const{
	for( auto p = data.begin( ); p != data.end( ); ++ p ){
		if(equal(*p, el))
			return true;
	}	
	return false;
}

bool set::insert( const std::string& el ){
	if(!contains(el)){
		data.push_back(el);	
		return true;
	} 
	return false; 
}

size_t set::insert( const set& s ){
	size_t amount = 0;
	for( auto p = s. begin( ); p != s. end( ); ++ p ){
		amount += insert(*p);
	}
	return amount;
}

bool set::remove( const std::string& el ){

	if(!contains(el))
		return false;

	for( auto p = data. begin( ); p != data. end( ); ++ p ){
		if (equal(*p, el)){
			std::iter_swap(data.end()-1, p);
			data.pop_back();
			return true;
		}
	}

	return false;
}

size_t set::remove( const set& s ){
	size_t amount = 0;
	for( auto p = s. begin( ); p != s. end( ); ++ p ){
		amount += remove(*p);
	}
	return amount;
}

std::ostream& operator << ( std::ostream& out, const set& data ){
	out << "{";
	for (auto i = data.begin(); i != data.end(); ++i){
    		if( i != data. begin( )){
			out << ",";
		}
		out << " " << *i;
	}
	out << " }";
	return out;
}

bool subset( const set& s1, const set& s2 ){
	size_t amount = 0;	
	for(auto val : s1){
		amount += s2.contains(val);
	}
	return amount == s2.size();
}

