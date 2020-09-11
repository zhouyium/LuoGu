set var=1
echo off 
:loop
	echo 已运行%var%次
	set /a var+=1
	rand.exe>data.in
	P1255.exe<data.in>my.out
 	::自己认为的正解的exe
	test.exe<data.in>std.out
	::比较
	fc my.out std.out
	if not errorlevel 1 goto loop
pause
goto loop