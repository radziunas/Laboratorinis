#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

void rikiavimas(int paz[], int n);

int main() {

    string vard[100], pav[100];
    int nd[100], eg[100], n, m, ndlaik[100], sum=0;
    double gal[100], med[100];

    cout<<"iveskite studentu skaiciu: ";
    cin>>n;
    cout<<endl;
    for(int i=0;i<n;i++)
    {
      cout<<"iveskite varda: ";
      cin>>vard[i];
      cout<<endl;

      cout<<"iveskite pavarde: ";
      cin>>pav[i];
      cout<<endl;

      cout<<"iveskite gautu pazymiu kieki: ";
      cin>>m;
      cout<<endl;

      cout<<"iveskite namu darbu pazymi: "<<endl;
      for(int j=0;j<m;j++)
      {
        cin>>ndlaik[j];
        sum=sum+ndlaik[j];
      }
      rikiavimas(ndlaik,m);
      cout<<endl;

      if(m%2==0)
      med[i]=(ndlaik[m/2]+ndlaik[m/2-1])/2;
      else
      med[i]=ndlaik[m/2];


      cout<<"iveskite egzamino pazymi: ";
      cin>>eg[i];
      cout<<endl;

      gal[i]=(sum*1.0)/(m*1.0)*0.4+0.6*eg[i]*1.0;
    }
    cout<<setw(20)<<left<<"Vardas"<<setw(30)<<left<<"Pavarde"<<setw(20)<<left<<"Galutinis"<<setw(20)<<left<<"mediana"<<endl;
    cout.fill('-');
    cout.width(89);
    cout<<"-"<<endl;
    cout.fill(' ');
    for(int i=0;i<n;i++)
    {
      cout<<setw(20)<<left<<vard[i]<<setw(30)<<left<<pav[i]<<setw(20)<<left<<setprecision(2)<<gal[i]<<setw(20)<<left<<med[i]<<endl;
    }
return 0;

}

void rikiavimas(int paz[], int n)
{
  int laik, nuo;
  for(int i=0;i<n-1;i++)
  {
    nuo=i;
    for(int j=i+1;j<n;j++)
    {
      if(paz[j]<paz[nuo])
      nuo=j;
    }
    laik=paz[nuo];
    paz[nuo]=paz[i];
    paz[i]=laik;
  }
}
