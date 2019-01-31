-- Ada Add Correct Numbers
-- Name: Matthew Olker and Alec Cohan
-- Date: 1-22-2019
-- Class: CSC-4510
-- Location: molker/csc4510/P1/Source
-- This program takes in two integer inputs and returns the value of their sum
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