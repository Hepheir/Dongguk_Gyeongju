FOR %%x IN (*.py) DO (
  echo echo on > %%x.bat
  echo cd sources\chap14 >> %%x.bat
  echo python %%x >> %%x.bat
  echo pause >> %%x.bat
)
