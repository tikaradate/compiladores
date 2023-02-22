program exemplo75 (input, output);
var a, b: integer;
    m: boolean;
    procedure p(var c: integer; d, e: integer);
    var k: integer;
    begin
        k := c + d + e;
        e := c + k;
        c := 3;
    end
begin
    a := 1;
    b := 2;
    p(a, b, b);
end.
