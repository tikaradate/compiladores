program exemplo75 (input, output);
var a, b: integer;
    m: boolean;
    procedure p(var c: integer; var d, e: integer);
    var k: integer;
    begin
        k := c + d + e;
        e := c + k;
        c := 3;
        p(c, d, e);
    end
begin
    a := 1;
    b := 2;
    write(a);
    p(a, b, b);
    read(a, b, b);
end.
