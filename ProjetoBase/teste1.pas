program exemplo75 (input, output);
var a, b: integer;
    m: boolean;
    procedure p(c: integer; d, e: integer);
    var k: integer;
    begin
        k := c + d + e;
        e := c + k;
    end
begin
    a := 1;
    b := 2;
    p(a, b, b);
end.
