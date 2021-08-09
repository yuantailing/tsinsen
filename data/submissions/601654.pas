var n:longint;
 s,k:real;
begin
 s:=0;
 n:=0;
 read(k);
 while s<=k do
 begin
  n:=n+1;
  s:=s+1/n;
 end;
 write(n);
end.
