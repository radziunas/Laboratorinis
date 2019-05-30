#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct mokiniai
{
     string vard;
     string pav;
     vector<double> nd;
     double vid;
     double med;
};

void rikiavimas(vector<int> paz, int n);

int main() {
    int testi=1;
    double sum=0, eg, gal, med;
    vector<mokiniai>mok;
    mokiniai laikinas;
    double t=1,i=0, z;

    while(testi==1)
    {
        cout<<"iveskite varda: ";
        cin>>laikinas.vard;
        cout<<endl;

      cout<<"iveskite pavarde: ";
      cin>>laikinas.pav;
      cout<<endl;
        laikinas.nd.clear();
        cout<<"iveskite namu darbu pazymi: "<<endl;;
        while (t!=0 && t>0 && t<11)
        {
            cin>>t;
            laikinas.nd.push_back(t);
            sum=sum+t;
        }
        laikinas.nd.erase(laikinas.nd.end()-1);
      sort(laikinas.nd.begin(), laikinas.nd.end());
      if(laikinas.nd.size()%2==0)
      med=(laikinas.nd[laikinas.nd.size()/2]+laikinas.nd[laikinas.nd.size()/2-1])/2;
      else
      med=laikinas.nd[laikinas.nd.size()/2-1];

      cout<<"iveskite egzamino pazymi: ";
      cin>>eg;
      cout<<endl;

      gal=(sum/(laikinas.nd.size()-1))*0.4+0.6*eg;
      laikinas.vid=gal;
      gal=med*0.4+0.6*eg;
      laikinas.med=gal;

      laikinas.nd.clear();

      mok.push_back(laikinas);

      sum=0;
      i++;
        cout<<"Ar norite testi? jei tai ptai spauskite 1"<<endl;
        cin>>testi;
        }

    cout<<setw(20)<<left<<"Vardas"<<setw(30)<<left<<"Pavarde"<<setw(20)<<left<<"Galutinis"<<setw(20)<<left<<"mediana"<<endl;
    cout.fill('-');
    cout.width(89);
    cout<<"-"<<endl;
    cout.fill(' ');
    for(int r=0;r<i;r++)
    {
      cout<<setw(20)<<left<<mok.at(r).vard<<setw(30)<<mok.at(r).pav<<setw(20)<<left<<setprecision(2)<<mok.at(r).vid<<setw(20)<<left<<mok.at(r).med<<endl;
    }
return 0;

}
