set var=1
echo off 
:loop
	echo ������%var%��
	set /a var+=1
	rand.exe>data.in
	P1255.exe<data.in>my.out
 	::�Լ���Ϊ�������exe
	test.exe<data.in>std.out
	::�Ƚ�
	fc my.out std.out
	if not errorlevel 1 goto loop
pause
goto loop