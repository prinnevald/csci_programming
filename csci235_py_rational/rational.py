# coded by prinnevald
# custom class for rational numbers
# dated 03/11/19

from numbers import *

def gcd( n1, n2 ):
    try:
        if n1 == 0 and n2 == 0 : raise ArithmeticError("gcd(0,0) does not exist")
        if n1 < n2 or n2 == 0: return gcdLooper(n2, n1)
        return gcdLooper(n2, n1%n2)
    except ArithmeticError as ae:
        print(ae)

def gcdLooper( n1, n2 ):
        if n2 == 0 : return abs(n1)
        elif n1 == 0 : return abs(n2)
        return gcdLooper(n2, n1%n2)

def lcm( n1, n2 ):
    return abs( n1 * n2 ) // gcd( n1, n2 )

def isRat( other ):
    if not isinstance( other, Rational ):
        other = Rational( other, 1 )
    return other

class Rational( Number ):
    
    def normalize( self ):
        if self.denom < 0:
            self.num, self.denom = -self.num, -self.denom
        com = gcd( self.num, self.denom )
        self.num, self.denom = self.num // com, self.denom // com
    
    def __init__( self, num, denom = 1 ):
        self.num, self.denom = num, denom
        self.normalize()

    def __repr__( self ):
        if self.denom == 1: return str(self.num // self.denom)
        else: return str(self.num) + "/" + str(self.denom)
    
    def __neg__( self ):
        return Rational(-self.num, self.denom)
    
    def __add__( self, other ):
        other = isRat( other )
        lcmLocal = lcm( self.denom, other.denom )
        numerator = self.num * lcmLocal // self.denom + other.num * lcmLocal // other.denom
        result = Rational( numerator, lcmLocal )
        return result
    
    def __sub__( self, other ):
        other = isRat( other )
        lcmLocal = lcm( self.denom, other.denom )
        numerator = self.num * lcmLocal // self.denom - other.num * lcmLocal // other.denom
        result = Rational( numerator, lcmLocal )
        return result
    
    def __radd__( self, other ):
        other = isRat( other )
        lcmLocal = lcm( self.denom, other.denom )
        numerator = other.num * lcmLocal // other.denom + self.num * lcmLocal // self.denom 
        result = Rational( numerator, lcmLocal )
        return result
    
    def __rsub__( self, other ):
        other = isRat( other )
        lcmLocal = lcm( self.denom, other.denom )
        numerator = other.num * lcmLocal // other.denom - self.num * lcmLocal // self.denom
        result = Rational( numerator, lcmLocal )
        return result
    
    def __mul__( self, other ):
        other = isRat( other )
        return Rational( self.num * other.num, self.denom * other.denom )
    
    def __truediv__( self, other ):
        other = isRat( other )
        return Rational( self.num * other.denom, self.denom * other.num )
    
    def __rmul__( self, other ):
        other = isRat( other )
        return Rational( self.num * other.num, self.denom * other.denom )
    
    def __rtruediv__( self, other ):
        other = isRat( other )
        return Rational( self.denom * other.num, self.num * other.denom )
    
    def __lt__( self, other ):
        other = isRat( other )
        return self.num / self.denom < other.num / other.denom
    
    def __gt__( self, other ):
        other = isRat( other )
        return self.num / self.denom > other.num / other.denom

    def __le__( self, other ):
        other = isRat( other )
        return self.num / self.denom <= other.num / other.denom
    
    def __ge__( self, other ):
        other = isRat( other )
        return self.num / self.denom >= other.num / other.denom
