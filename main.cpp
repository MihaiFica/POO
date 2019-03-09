#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
ifstream f("in.txt");
ofstream g("out.txt");

 class NumarComplex{                               //clasa numar complex
   float real;
   float imag;
 public:
     friend ostream& operator<<(ostream&, const NumarComplex&);                   //supraincarcare operatorului <<
     friend istream& operator>>(istream&, NumarComplex&);                         //supraincarcare operatorului >>
     friend NumarComplex Suma(NumarComplex&, const NumarComplex&);                //functie ce calculeaza suma dintre doua numere complexe
     friend NumarComplex Produs(NumarComplex&, const NumarComplex&);              //functie ce calculeaza produsul dintre doua numere complexe
     float ModulNrComplex()                                                       //functie ce calculeaza modulul unui nr complex
     {
        float modul;
        modul = sqrt(real * real + imag * imag);
        return modul;
     }
     NumarComplex operator+(const NumarComplex& a)                                //supraincarcare operatorului + pentru a aduna nr complexe 
     {
      NumarComplex nr;
      nr.real = real + a.real;
      nr.imag = imag + a.imag;
      return  nr;
     }
     NumarComplex operator*(const NumarComplex& a)                               //supraincarcarea operatorului * pentru a inmulti nr complexe
     {
         NumarComplex b;
         b.real = (real*a.real) - (imag * a.imag);
         b.imag = (real*a.imag) + (imag * a.real);
         return b;
     }
     NumarComplex CitireNrComplex(int k)                                        //citirea unui nr complex de la tastatura/fisier
     {
         NumarComplex t;
         if(k == 1)
         {
            cin >> t;
         }
         else
         {
            f >> t;
         }
         return t;
     }

};
NumarComplex Suma(NumarComplex& a, const NumarComplex& b)                        //functie ce calculeaza suma dintre doua numere complexe
{
    NumarComplex c;
    c = a + b;
    return c;
}
NumarComplex Produs(NumarComplex& a, const NumarComplex& b)                      //functie ce calculeaza produsul dintre doua numere complexe
{
    NumarComplex c;
    c = a * b;
    return c;
}
istream& operator>>(istream& in, NumarComplex& num)                             //supraincarcare operatorului >>  pentru a citi un nr complex        
{
 in >> num.real;
 in >> num.imag;
 return in;
}
 ostream& operator<<(ostream& out, const NumarComplex& num)                     //supraincarcare operatorului << pentru a afisa un nr complex
{
 if(num.imag > 0)
 {
 out << num.real << "+" << num.imag<<"i";
 }
  else
    if(num.imag == 0)
        {
         out << num.real;
        }
        else
         if(num.imag < 0)
        {
            out << num.real << num.imag <<"i";
        }
 return out;
}


class VectoriDeCoplecsi                                          // clasa pentru vectori de nr complexe
{
  NumarComplex h[100];
  float p[100];
  int n;
  public:
    friend class NumarComplex;
    friend istream& operator>>(istream&, VectoriDeCoplecsi&);            //supraincarcare operatorului >>
    friend ostream& operator<<(ostream&, VectoriDeCoplecsi&);            //supraincarcare operatorului <<
    int CitireNrElemente(int j)                                          //citirea unui vector de nr complexe de la tastatura/fisier
    {
       if(j == 1)
       {

          cin >> n;
       }
       else
        if(j == 2)
       {
           f >> n;
       }
       return n;
    }
    void CalculModuleVector(int n, int k)                               //calculul modulelor unui vector de nr complexe
    {
       for(int i = 1; i <= n; i++)
       {
           p[i] = h[i].ModulNrComplex();
           if(k == 1)
           {
           cout << p[i] << endl;
           }
           else
            if(k == 2)
           {
            g << p[i] << endl;
           }
       }
    }
   NumarComplex SumaElemVector(int n)                                //suma elementelor unui vector de nr complexe
   {
       NumarComplex suma;
       suma = h[1];
       for(int i = 2 ;i <= n; i++)
       {
           suma = Suma(suma, h[i]);
       }
       return suma;
   }
   void SortareVector(int n)                                         //sortarea unui vector de numere complexe dupa modulele elementelor
   {
    NumarComplex aux;
    for (int i = 1; i <= n-1; i++)
        {
        for (int j = i + 1; j <= n; j++)
             {
                if (p[i] > p[j])
                {
                        aux = h[i];
                        h[i] = h[j];
                        h[j] = aux;
                }
             }
        }
   }
   NumarComplex operator *(VectoriDeCoplecsi& b)                     //supraincarcare operator *pentru a face produsul scalar dintre 2 vectori
   {
       NumarComplex c;
       c = Produs(h[1], b.h[1]);
       for(int i = 2; i <= n; i++)
       {
           c = Suma(c, Produs(b.h[i],h[i]));
       }
       return c;
   }
};
istream& operator>>(istream& in, VectoriDeCoplecsi& num)          //supraincarcare operatorului >> pentru a citi un vector de complecsi
{
    for(int i = 1; i <= num.n; i++)
    {
        in >> num.h[i];
    }
    return  in;
}
ostream& operator<<(ostream& out, VectoriDeCoplecsi& num)        //supraincarcare operatorului << pentru a afisa un vecotor de complecsi
{

    for(int i = 1;i <= num.n; i++)
    {
        out << num.h[i] << endl;
    }
    return out;
}
 void meniu()                                                    //meniul
 {
     int k = 0;
     int r = 0, n, m;
     NumarComplex c, d, suma1, suma2, suma;
     VectoriDeCoplecsi l, o;
     while(1)
     {
        if(k == 0)
        {
          cout << "Alegeti metoda prin care se citesc informatiile : " << endl;               //citire fisier/consola
          cout << "1.Citire si afisare in consola" << endl;
          cout << "2.Citire si afisare din fisier" << endl;
          cin >> k;
        }
         else
            if(k == 1)
               {
             switch(r)
             {
                 case 0:
                     cout << "Alegeti una dintre variantele urmatoare : " << endl;
                     cout << "1.Suma dintre doua numere complexe. " << endl;
                     cout << "2.Produsul dintre doua numere complexe. " << endl;
                     cout << "3.Aflarea modulului unui numar complex. " << endl;
                     cout << "4.Aflarea vectorului de module. " << endl;                                 //meniu secundar consola
                     cout << "5.Sortarea unui vector in functie de vectorul de module. " << endl;
                     cout << "6.Suma elementelor unui vector de numere complexe. " << endl;
                     cout << "7.Produsul scalar dintre doi vectori de numere complexe. " << endl;
                     cout << "8.Revenire la meniul principal. " << endl;
                     cin >> r;
                    break;
                 case 1:
                     cout << "Dati doua numere complexe:" << endl;
                     cin >> c;
                     cin >> d;
                     suma = Suma(c, d);                                                                      
                     cout << "Suma dintre numarul " << c <<" si numarul " << d << " este " << suma << endl;
                     cout << "Pentru a reveni la meniul anterior apasati 0." << endl;
                     cin >> r;
                     cout << endl;
                     break;
                 case 2:
                      cout << "Dati doua numere complexe:" << endl;
                      cin >> c;
                      cin >> d;
                      cout << "Produsul dintre numarul " << c << " si numarul " << d << " este " << Produs(c, d)<<endl;
                      cout << "Pentru a reveni la meniul anterior apasati 0." << endl;
                      cin >> r;
                      cout << endl;
                      break;
                 case 3:
                      cout << "Dati un numar complex :" << endl;
                      cin >> c;
                      cout << "Modulul numarului " << c << " este " << c.ModulNrComplex() << endl;
                      cout << "Pentru a reveni la meniul anterior apasati 0." << endl;
                      cin >> r;
                      cout << endl;
                      break;
                 case 4:
                      cout << "Dati numarul de elemente pentru un vector de numere complexe" << endl;
                      n = l.CitireNrElemente(k);
                      cout << "Dati elementele vectorului(perechi de cate 2): " << endl;
                      cin >> l;
                      cout << "Se afiseaza elementele vecoturului : " << endl;
                      cout << l;
                      cout << "Se afiseaza vectorul de module : " << endl;
                      l.CalculModuleVector(n, k);
                      cout << "Pentru a reveni la meniul anterior apasati 0." << endl;
                      cin >> r;
                      break;
                 case 5:
                      cout << "Dati numarul de elemente pentru un vector de numere complexe" << endl;
                      n = l.CitireNrElemente(k);
                      cout << "Dati elementele vectorului(perechi de cate 2): " << endl;
                      cin >> l;
                      cout << "Se afiseaza elementele vecoturului : " << endl;
                      cout << l;
                      cout << "Se afiseaza vectorul de module : " << endl;
                      l.CalculModuleVector(n,k);
                      cout << "Se afiseaza vectorul sortat in functie de modul : " << endl;
                      l.SortareVector(n);
                      cout << l;
                      cout << "Pentru a reveni la meniul anterior apasati 0." << endl;
                      cin >> r;
                      break;
                 case 6:
                      cout << "Dati numarul de elemente pentru un vector de numere complexe" << endl;
                      n = l.CitireNrElemente(k);
                      cout << "Dati elementele vectorului(perechi de cate 2): " << endl;
                      cin >> l;
                      cout << "Se afiseaza elementele vecoturului : " << endl;
                      cout << l;
                      cout << "Suma elementelor din vector este : ";
                      suma = l.SumaElemVector(n);
                      cout << suma << endl;
                      cout << "Pentru a reveni la meniul anterior apasati 0." << endl;
                      cin >> r;
                      break;
                 case 7:
                      cout << "Dati numarul de elemente pentru primul vector de numere complexe" << endl;
                      n = l.CitireNrElemente(k);
                      cout << "Dati elementele vectorului 1 (perechi de cate 2): " << endl;
                      cin >> l;
                      cout << "Dati numarul de elemente pentru al doilea  vector de numere complexe" << endl;
                      m = o.CitireNrElemente(k);
                      cout << "Dati elementele vectorului 2 (perechi de cate 2): " << endl;
                      cin >> o;
                      if(m == n)
                      {
                      cout << "Produsul scalar intre cei doi vectori este : " << l * o << endl;
                      }
                      else
                      {
                      cout << "Produsul scalar nu se poate calcula dearece vectorii au lungimi diferite.";
                      }
                      cout << "Pentru a reveni la meniul anterior apasati 0." << endl;
                      cin >> r;
                      break;
                 case 8:
                      k = 0;
                      break;
                 default:
                    cout << "Numarul nu se afla printre variante.Apasati un numar de la 1 la 8" << endl;
                    cin >> r;
                    break;
        }

                }
                else
                    if(k == 2)
                    {
                         f >> c >> d;
                         g << "Suma dintre numarul " << c << " si numarul " << d << " este " << Suma(c, d) << endl;
                         g << "Produsul dintre numarul " << c << " si numarul " << d << " este " << Produs(c, d) << endl;
                         g << "Modulul numarului " << c <<" este " << c.ModulNrComplex() << endl;
                         g << "Modulul numarului " << d << " este " << d.ModulNrComplex() << endl;
                         n = l.CitireNrElemente(k);
                         f >> l;
                         g << "Se afiseaza elementele vecoturului 1 : " << endl;                                                //afisare in fisier
                         g << l;
                         g << "Se afiseaza vectorul de module : " << endl;
                         l.CalculModuleVector(n, k);
                         g << "Se afiseaza vectorul sortat in functie de modul : "<<endl;
                         l.SortareVector(n);
                         g << l;
                         g << "Suma elementelor din vector este : ";
                         suma1 = l.SumaElemVector(n);
                         g << suma1 << endl;
                         m = o.CitireNrElemente(k);
                         f >> o;
                         g << "Se afiseaza elementele vecoturului 2 : " << endl;
                         g << o;
                         g << "Se afiseaza vectorul de module : " << endl;
                         o.CalculModuleVector(m, k);
                         g << "Se afiseaza vectorul sortat in functie de modul : " << endl;
                         o.SortareVector(m);
                         g << o;
                         g << "Suma elementelor din vector este : ";
                         suma2 = o.SumaElemVector(m);
                         g << suma2 << endl;
                         if(m == n)
                         {
                         g << "Produsul scalar intre cei doi vectori este : ";
                         g << l*o;
                         }
                         else
                         g << "Produsul scalar nu se poate calcula deoarece vectorii au lungimi diferite.";
                         break;
                    }
     }
 }
int main()
{
    meniu();
    f.close();
    g.close();
    return 0;
}
