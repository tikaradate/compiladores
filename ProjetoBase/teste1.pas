program exemplo75 (input, output);
var a, b: integer;

begin
    a:= 0;

    if a = 0 then
    begin
        a := 1;
    end;

    while a < 2 do
    begin
        b:= 0;
        while b < 2 do
            b:= b+1;
        a:= a+1;
    end;
end.
