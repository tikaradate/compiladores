
O que eu fiz:
   - Adicionei um novo campo na struct procedure.
   - Fatorei a procedure.
   - Empilhei o proc e os parametros.
   - Chequei se estava em forward na hora de ler um cabeçalho
   - No atribuicao_proc eu coloquei caso for algo de forward
   - Chamei o rotulo certo na chamada no meio do bloco
   - Mais algumas coisas mas não anotei certinho aqui, a maior parte é para estar comentada
   - SUMÁRIO: 
      - 1 parece feita, 
      - 2 parcialmente, não fiz o desempilhar após um bloco
      - 3 não acho que foi feita, mas apesar disso os testes do professor funcionam

Sucessos:
    Compila dum jeito decente? E também funciona nos testes do prof ainda

Problemas:
- Precisa de flag pra falar que estamos lendo dum forward?
- Não sei muito o que fazer quando achar a implementação original: continuo usando a pilha de forwards ou "transfiro de volta"?
    Por alguma razão parece apenas funcionar, tirando algum rótulo ou outro que está mais do que deveria, eu acho.

- Esse tipo de estrutura me bugou um pouco
        procedure p; forward;
        procedure h; forward;

        procedure g();
        begin
            p();
        end;
        procedure h();
        begin
        end;
        procedure p();
        begin
        end;


# Ideia Geral

1) Quando achar um procedimento com forward.
    Empilhe numa pilha própria (pilha_forward) o procedimento e os parametros
    Aumente o número de forwards correntes

2) Num bloco de procedimento normal
    Empilhe a quantidade de forward correntes em 'pilha_qt_forward' e repita 1)
    A cada chamada de procedimento(regra 19), procure se o procedure está na pilha
        Se sim, use seu cabeçalho para chamar corretamente
        Se não, deu errado
    No fim do procedimento, veja na pilha_forward se os forwards correntes foram 
    ativados
        Se sim, tudo deu certo, desempilhe a quantidade anterior para uso dos níveis léxicos abaixo
        Se não, deu errado

3) Ao encontrar sua definição
    Cheque se está na pilha de forwards
    Cheque se a assinatura é a mesma(precisamos mesmo?)
    Bote na pilha normal
    Marque como visitado na pilha de forwards
