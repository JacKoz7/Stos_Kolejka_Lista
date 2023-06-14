int func(kolejka *k)
{
    int nieparzyste = 0;
    kolejka *k_kopia;
    
    while(isEmpty(k) != 1)
    {
        int obecna_wartosc = first(k);
        push(k_kopia, pop(k));
        
        if (obecna_wartosc % 2 != 0)
        {
            nieparzyste++;
        }
    }
    while(isEmpty(k_kopia) != 1)
    {
        push(k, pop(k_kopia));
    }
    return nieparzyste;
}
