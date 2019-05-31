#include "isvedimas.h"

void isvedimas(vector<mokiniai> &mok)
{
    string duomenys = "mokiniai.txt";
    int sum=0, egz;
	double vid, med;
	mokiniai laikinas;
try {

    std::ifstream in;
    in.open ("mokiniai.txt");
		if(!in)
        throw (std::runtime_error("failas neegzistuoja"));
		string eilute;
		getline(in, eilute);
		while (!in.eof())
		{
			in>>laikinas.vard>>laikinas.pav;
			laikinas.nd.clear();
			for(int i=0, paz; i<5; i++)
            {
                in>>paz;
                laikinas.nd.push_back(paz);
            }
            in>>egz;
            sum=0;
			for (int i : laikinas.nd)
				sum += i;
			vid=sum*1.0/(laikinas.nd.size());
			vid=vid*0.4+egz*0.6;
			laikinas.nd.push_back(egz);
			sort(laikinas.nd.begin(), laikinas.nd.end());
			if (laikinas.nd.size() % 2 == 0)
			{
                med=(laikinas.nd[laikinas.nd.size()/2]+laikinas.nd[laikinas.nd.size()/2-1])/2;
			}
			mok.push_back(laikinas); // i lentele idedam temp
		}
            in.close();
        }
            catch(const std::runtime_error &e1)
        {
            cout<<"klaida: "<<e1.what()<<endl;
            terminate();
        }
}
void failai(vector<mokiniai>&lentele)
{
    vector<mokiniai>moksliukai;
	vector<mokiniai>nemoksliukai;
    int sum = 0, egz;
	double vid, med;
	mokiniai laikinas;
          chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    string numeris;
    string txt={".txt"};
    string a[15]="Vardas";
    string b[15]="Pavarde";
    int k=1;
    for(int i=1; i<6; i++)
    {
        k=k*10;
        ofstream file;
        file.open (std::to_string(i) + ".txt");
            file <<"Vardas Pavarde ND1 ND2 ND3 ND4 ND5 EGZ" <<endl;
            for(int j=1; j<=k; j++)
                file << a[i]<<j<<" "<<b[i]<<j<<" "<<rand() % 10 + 1<<" "<<rand() % 10 + 1<<" "<<rand() % 10 + 1<<" "<<rand() % 10 + 1<<" "<<rand() % 10 + 1<<" "<<rand() % 10 + 1<<"\n";
                file.close();
    }
                cout<<"iveskite failo numeri nuo 1 iki 5 kuri noretumete surusiuoti (1 - 10 zmoniu .... 5 - 100000 zmoniu) ";
                cin>>numeris;
                numeris+=txt;
                ifstream in (numeris);
                string eilute;
                getline (in, eilute);
                while (!in.eof())
            {
			in>>laikinas.vard>>laikinas.pav;
			laikinas.nd.clear();
			for(int i=0, temp_paz; i<5; i++)
            {
                in>>temp_paz;
                laikinas.nd.push_back(temp_paz);
            }
            in>>egz;
            sum=0;
			for (int i : laikinas.nd)
				sum+=i;
			vid=sum*1.0/(laikinas.nd.size());
			laikinas.vid =vid*0.4+egz*0.6;
			if(laikinas.vid>=5)
                moksliukai.push_back(laikinas);
			else
                nemoksliukai.push_back(laikinas);
            }
            in.close();
            ofstream out("galvociai.txt");
            out << setw(15) << left << "Vardas " << setw(15) << left << "Pavarde " << setw(20) << right << "Galutinis (Vid.) " << endl;
            out.fill('-');
            out.width(50);
            out << "-" << endl;
            out.fill(' ');
            for (mokiniai duomenys : moksliukai)
                out << setw(15) << left << duomenys.vard << setw(15) << left << duomenys.pav << setw(20) << right << setprecision(3) << duomenys.vid << endl;
            out.close();
            ofstream out2("nuskriaustukai.txt");
            out2 << setw(15) << left << "Vardas " << setw(15) << left << "Pavarde " << setw(20) << right << "Galutinis (Vid.) " << endl;
            out2.fill('-');
            out2.width(50);
            out2 << "-" << endl;
            out2.fill(' ');
            for (mokiniai duomenys : nemoksliukai)
                out2 << setw(15) << left << duomenys.vard << setw(15) << left << duomenys.pav << setw(20) << right << setprecision(3) << duomenys.vid << endl;
            out2.close();
            chrono::steady_clock::time_point end=chrono::steady_clock::now();
            cout << "Jusu programa dirbo " << chrono::duration_cast<chrono::seconds>(end - begin).count() <<" sekundziu"<<endl;

}
