
int nta(int n, int liczba, int baza = 10)
{
   int cyfra = liczba % baza;
   while (n > 0)
   {
      liczba /= baza;
      cyfra = liczba % baza;
      n--;
   }
   return cyfra;
}


nta(1, 187654, 1000);
