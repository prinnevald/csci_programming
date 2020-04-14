from matrix import *
from vector import *
from rational import *

def test( ):
    print("test1")
    testMat1 = Matrix( Rational(1, 2), Rational(1, 3), Rational(-2, 7), Rational(2, 8) )
    testMat2 = Matrix( Rational(-1, 3), Rational(2, 7), Rational(2,5), Rational(-1,7) )
    print(testMat1 @ testMat2)

    print("test2")
    invMat = Matrix( Rational(1, 2), Rational(1, 3), Rational(-2, 7), Rational(2, 8) )
    print(invMat.inverse())
    
    print("test3")
    print((testMat1 @ testMat2) @ invMat)
    print(testMat1 @ ( testMat2 @ invMat ))
    
    print("test4")
    print((testMat1 + testMat2) @ invMat)
    print(testMat1 @ invMat + testMat2 @ invMat)
    
    print("test5")
    vec = Vector(1, 2)
    print(testMat1(testMat2(vec)))
    print((testMat1 @ testMat2)(vec))
    
    print("test6")
    print(testMat1.determinant() * testMat2.determinant())
    print((testMat1 @ testMat2).determinant())
    
    print("test7")
    print(invMat@invMat.inverse())
    print(invMat.inverse()@invMat)

test( )
