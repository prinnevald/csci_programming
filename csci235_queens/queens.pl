dist(X,Y,Z) :- (X - Y) =< 0, Z is (Y - X).
dist(X,Y,Z) :- (Y - X) < 0, Z is (X - Y).
                
canstrike( q(X,_), q(X,_) ).
canstrike( q(_,Y), q(_,Y) ).
canstrike( q(X1,Y1), q(X2,Y2) ) :- dist(Y1, Y2, Z), dist(X1, X2, Z).

betw(L,U,X) :- L =< U, X is L.
betw(L,U,X) :- L < U, betw(L+1,U,X).

cannotstrike( [], q(_,_) ).
cannotstrike( L, q(X,Y) ) :- [H|T] = L, not(canstrike(H, q(X,Y))),
                                        cannotstrike(T, q(X,Y)).

queens(0, _, A, A).
queens(I, N, P1, P2) :- I > 0, NewI is I-1,
                        queens(NewI, N, P1, NewP),
                        betw(1, N, X), betw(1, N, Y), 
                        cannotstrike(NewP, q(X,Y)),
                        P2 = [q(X,Y) | NewP].
