import logic
open tactic (renaming id->id_tac)

definition id {A : Type} (a : A) := a

definition simple {A : Prop} : tactic
:= unfold id; assumption

theorem tst {A B : Prop} (H1 : A) (H2 : B) : id A
:= by simple

check tst
