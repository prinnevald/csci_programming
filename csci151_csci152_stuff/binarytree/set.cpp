
#include "set.h"

void print( std::ostream& out, const treenode* n, size_t indent )
{

   for( size_t i = 0; i != indent; ++ i )
      out << "|  "; 
   if(n)
   {
      out << ( n -> val ) << "\n";
      print( out, n -> left, indent + 1 );
      print( out, n -> right, indent + 1 ); 
   }
   else
      out << "#\n"; 
}


void checksorted( 
          treenode* n, 
          const std::string* lowerbound, 
          const std::string* upperbound )
{
   while(n) 
   {
      if( lowerbound && !before( *lowerbound, n -> val ))
      {
         std::cout << "value " << ( n -> val );
         std::cout << " is not above lower bound " << *lowerbound << "\n";
         std::abort( );
      }

      if( upperbound && !before( n -> val, *upperbound ))
      {
         std::cout << "value " << ( n -> val );
         std::cout << "is not below upperbound " << *upperbound << "\n";
         std::abort( );
      }

      checksorted( n -> left, lowerbound, &( n -> val ));
      lowerbound = & ( n -> val );
      n = n -> right;
   }
} 


// Used by copy constructor and assignment:

void writecopy( treenode** to, treenode* from )
{
   while( from )
   {
      *to = new treenode{ from -> val };

      writecopy( & (*to) -> left, from -> left );
      to = & (*to) -> right;
      from = from -> right;
   }
}

// Used by destructor:

void deallocate( treenode* n )
{
   while(n)
   {
      deallocate( n -> left );
      treenode* bye = n;
      n = n -> right;
      delete bye;
   }
}



size_t log2( size_t s ){	//lookup
	if((s == 0) || (s == 1)) return 0;
	return 1 + log2(s/2);
}

// From previous task:

bool equal( const std::string& s1, const std::string& s2 ){
	if(s1.size() != s2.size())	
		return false;
	size_t temp = s1.size();
	for(size_t i = 0; i < temp; i++){
		if(tolower(s1[i]) != tolower(s2[i]))
			return false;	
	}
	return true;
}

// Must be written for task 5(part 2) :

bool before( const std::string& s1, const std::string& s2 ){
	size_t temp;
	if(s1.size()<s2.size())
		temp = s1.size();
	else 
		temp = s2.size();
	for(size_t i = 0; i < temp; i++){
		if(tolower(s1[i]) < tolower(s2[i]))
			return true;
		else if (tolower(s1[i]) > tolower(s2[i]))
			return false;
	}
	return false;
}


const treenode* find( const treenode* n, const std::string& el ){
	if(n == nullptr) return n;
	else if(equal(n->val, el)) return n;
	else if(before(el, n->val)) return find(n->left, el);
	else return find(n->right, el);
}
   // Write this one first.

treenode** find( treenode** n, const std::string& el ){
	if(*n == nullptr) return n;
	else if(equal((*n)->val, el)) return n;
	else if(before(el, (*n)->val)) return find(&((*n)->left), el);
	else return find(&((*n)->right), el);	
}
   // Modify the other find into this one, also have a look at
   // stackscan4.pdf

// Insert n at the right most position in into: 

void rightinsert( treenode** into, treenode* n ){
	while(*into != nullptr){
		into = &((*into) -> right);
	}
	(*into) = n;
}

size_t size( const treenode* n ){
	if(n == NULL) return 0;
	return 1 + size(n->left) + size(n->right);
}

size_t height( const treenode* n ){
	//return log2(size(n));	//assuming we have balanced tree...
	if(n == nullptr) return 0;	
	size_t left = height(n->left);
	size_t right = height(n->right);
	
	if(left>=right)
		return left+1;
	else
		return right+1;

}
 
bool set::insert( const std::string& el ){
	
	if(contains(el)) return false;

	treenode** val = find(&tr, el);
	*val = new treenode(el);
	return true;
}

bool set::contains( const std::string& el ) const 
{
   return find( tr, el ) != nullptr; 
}


bool set::remove( const std::string& el ){
	
	treenode** val = find(&tr, el);

	if(*val == nullptr) return false;

	//No children
	if((*val)->left == nullptr && (*val)->right == nullptr) { 		
		delete *val;
		*val = nullptr;
		return true;
	}
	//Case 2: One child 
	else if((*val)->left == nullptr) {
		treenode* temp = *val;
		*val = (*val)->right;
		delete temp;
		return true;
	}
	else if((*val)->right == nullptr) {
		treenode* temp = *val;
		*val = (*val)->left;
		delete temp;
		return true;
	}
	//Two children
	treenode* temp = *val;
	rightinsert(&((*val)->left), (*val)->right);
	(*val)->right = nullptr;
	(*val) = (*val)->left;
	delete temp;
	return true;
}

void set::checksorted( ) const
{
   ::checksorted( tr, nullptr, nullptr );
      // :: are needed because the other checksorted is not in the class. 
}


std::ostream& set::print( size_t indent, std::ostream& out ) const
{
   ::print( out, tr, indent );
   return out;
}


