Program OutputLines(output);

procedure fun1(); forward;

procedure fun2();
begin
    fun1();
    write(0);
end;

procedure fun1();
    procedure inside(); forward;
    procedure test();
    begin
        write(1);
        inside();
    end;
    procedure inside();
    begin
        write(2);
    end;
begin
    test();
    write(3);
end;

begin
    fun2();
end.
