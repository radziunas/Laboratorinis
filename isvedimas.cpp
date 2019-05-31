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
