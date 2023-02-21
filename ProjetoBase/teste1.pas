program exemplo75 (input, output);
var a, b: integer;
    m: boolean;
    procedure p(c: integer; d: integer);
    var k: integer;
    begin
        k := c + d;
        print(k);
    end
begin
    a := 1;
    b := 2;
    p(a, b);
end.
