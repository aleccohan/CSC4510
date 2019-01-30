-- Ada Add Correct Numbers
with Text_IO;
with Gnat.IO; use Gnat.IO;
procedure addCorrect is
	I : Integer;
	J : Integer;
	K : Integer;
begin 
	Put_Line ("Enter 2 Numbers to add: ");
	Get (I);
	Get (J);
	K := I + J;
	Put (I);
	Put (" + ");
	Put (J);
	Put (" = ");
	Put (K);
	New_Line;
end addCorrect;