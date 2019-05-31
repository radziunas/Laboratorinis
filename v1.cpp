#include "mano.h"
#include "isvedimas.h"

using namespace std;

bool rusiavimas (mokiniai a, mokiniai b)
{
    return a.vard < b.vard;
}


void rikiavimas(vector<int> paz, int n);

int main() {
    int testi=1, failo;
    double sum=0, eg, gal, med;
    vector<mokiniai>mok;
    mokiniai laikinas;
    double t=1, z=0;
    string duomenys="mokiniai.txt";

    cout<<"Ar norite duomenis ivesti (spauskite 1) ar nuskaityti is failo (spauskite 2)";
    cin>>failo;
    if(failo==1)
    {
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

            gal=(sum/(laikinas.nd.size()))*0.4+0.6*eg;
            laikinas.vid=gal;
            gal=med*0.4+0.6*eg;
            laikinas.med=gal;

            laikinas.nd.clear();

            mok.push_back(laikinas);

            sum=0;
            z++;
            cout<<"Ar norite testi? jei tai ptai spauskite 1"<<endl;
            cin>>testi;
            }




    }
        else
        {
            ifstream in;
            in.open(duomenys);
            string eilute;
            getline(in, eilute);
            while(!in.eof())
            {
                    in>>laikinas.vard>>laikinas.pav;
                    laikinas.nd.clear();
                    for(int i=0, ndlaik; i<5;i++)
                    {
                            in>>ndlaik;
                            sum=sum+ndlaik;
                            laikinas.nd.push_back(ndlaik);
                    }
                    in>>eg;
                    laikinas.vid=sum/(laikinas.nd.size());
                    if(laikinas.nd.size()%2==0)
                            med=(laikinas.nd[laikinas.nd.size()/2]+laikinas.nd[laikinas.nd.size()/2-1])/2;
                    else
                            med=laikinas.nd[laikinas.nd.size()/2-1];

                    gal=(sum/(laikinas.nd.size()))*0.4+0.6*eg;
                    laikinas.vid=gal;
                    gal=med*0.4+0.6*eg;
                    laikinas.med=gal;

                    laikinas.nd.clear();

                    mok.push_back(laikinas);

                    sum=0;
                    z++;

                 }
                 in.close();
        }
    }

    sort(mok.begin(), mok.end(), rusiavimas);
    cout<<setw(20)<<left<<"Vardas"<<setw(30)<<left<<"Pavarde"<<setw(20)<<left<<"Galutinis"<<setw(20)<<left<<"mediana"<<endl;
    cout.fill('-');
    cout.width(89);
    cout<<"-"<<endl;
    cout.fill(' ');
    for(int r=0;r<z;r++)
    {
      cout<<setw(20)<<left<<mok.at(r).vard<<setw(30)<<mok.at(r).pav<<setw(20)<<left<<setprecision(2)<<mok.at(r).vid<<setw(20)<<left<<mok.at(r).med<<endl;
    }
return 0;

}
