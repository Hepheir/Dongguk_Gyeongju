REM "compile.bat"의 내용
for %%n in (1) do gcc "필수.%%n.c" -o "필수.%%n.exe"
for %%n in (1,2) do gcc "선택.%%n.c" -o "선택.%%n.exe"