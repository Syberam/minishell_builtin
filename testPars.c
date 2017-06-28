States {A, B, C, D, E, G, H, F, Cmd, Dead}
Transitions {
	T1 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789!@%^-_+=;:,.~/?{}[]"
	T2 = " "
	T3 = "'"
	T4 = "\""
	T5 = "\\"
	T6 = "/0"
	T7 = "`"
	T8 = ";#*<>|()&"
	T9 = "$"
}

A->T1 = W
A->T2 = A
A->T3 = D
A->T4 = B
A->T5 = G
A->T6 = F
A->T7 = Cmd
A->T8 = ???
A->T9 = ??? 

B->T1 = E
B->T2 = E
B->T3 = E
B->T4 = W
B->T5 = C
B->T6 = DEAD
B->T7 = Cmd
B->T8 = ???
B->T9 = ???

C->T1 = E
C->T2 = E
C->T3 = E
C->T4 = H
C->T5 = H
C->T6 = H
C->T7 = H
C->T8 = ???
C->T9 = ???

D->T1 = D
D->T2 = D
D->T3 = W
D->T4 = D
D->T5 = D
D->T6 = DEAD
D->T7 = D
D->T8 = ???
D->T9 = ???

E->T1 = E
E->T2 = E
E->T3 = E
E->T4 = W
E->T5 = C
E->T6 = DEAD
E->T7 = Cmd
E->T8 = ???
E->T9 = ???

G->T1 = W
G->T2 = W
G->T3 = W
G->T4 = W
G->T5 = W
G->T6 = W
G->T7 = W
G->T8 = ???
G->T9 = ???

H->T1 = E
H->T2 = E
H->T3 = E
H->T4 = W
H->T5 = C
H->T6 = DEAD
H->T7 = Cmd
H->T8 = ???
H->T9 = ???

F->T1 = F
F->T2 = F
F->T3 = F
F->T4 = F
F->T5 = F
F->T6 = F
F->T7 = F
F->T8 = ???
F->T9 = ???

Cmd->T1 = Cmd
Cmd->T2 = Cmd
Cmd->T3 = Cmd
Cmd->T4 = Cmd
Cmd->T5 = Cmd
Cmd->T6 = Cmd
Cmd->T7 = Cmd
Cmd->T8 = ???
Cmd->T9 = ???

DEAD->T1 = DEAD
DEAD->T2 = DEAD
DEAD->T3 = DEAD
DEAD->T4 = DEAD
DEAD->T5 = DEAD
DEAD->T6 = DEAD
DEAD->T7 = DEAD
DEAD->T8 = ???
DEAD->T9 = ??? 
