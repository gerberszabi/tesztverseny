#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    int i=0;
    int j=0;
    int db=0;
    string temp;

    ifstream fajl("valaszok.txt");

    while (!fajl.eof()) {
        getline(fajl,temp);
        db++;
    }
    db--;
    fajl.close();

    ifstream fajl2("valaszok.txt");

    string helyes;

    fajl2>>helyes;

    string azon[db];
    string valaszok[db];

    for (i=0; i <db; i++){
        fajl2>>azon[i];
        fajl2>>valaszok[i];
    }
    db--;

    cout<<"2. feladat: "<<db<<" versenyzo indult."<< endl;

    cout<<endl<<"3. feladat: "<< endl;

    cout<<"A versenyzo azonositoja: ";
    string beazon;
    cin>>beazon;

    int azon_i=1;

    for (i=0;i<db;i++)
    {
        if (beazon ==azon[i])
        {
                cout<<valaszok[i]<<" (a versenyzo valasza)"<<endl;
                azon_i=i;
        }
    }

    cout<<endl<<"4. feladat: "<< endl;

    cout<<helyes<<" (a helyes valasz)"<<endl;

    for (i=0;i<14;i++)
    {
        if (valaszok[azon_i].substr(i,1)==helyes.substr(i,1))
        {
            cout<<"+";
        }
        else
        {
            cout<<" ";

        }
    }

    cout<<" (a versenyzo helyes valaszai)"<<endl;

    cout<<"A feladat sorszáma: ";
    int sorszam =0;
    cin>>sorszam;
    sorszam--;

    double jo_db=0;
    for (i=0;i<db;i++)
    {
        if(helyes.substr(sorszam,1)==valaszok[i].substr(sorszam,1))
        {
            jo_db++;
        }
    }

    cout<<"A feladatra "<<jo_db<<"fo, a versenyzok "<<fixed<<setprecision(2)<<jo_db/db*100<<"%-a adott helyes valaszt"<<endl;


    cout<<endl<<"6. feladat: "<< endl;

    ofstream kifajl("pontok.txt");

    int pont=0;
    int pontok[db];
    for (i=0;i<db;i++)
    {
        kifajl<<azon[i];

        for (j=0;j<14;j++)
        {
            if(j<=4 and valaszok[i].substr(j,1)==helyes.substr(j,1))
            {
                pont+=3;
            }
            else if(j<=9 and valaszok[i].substr(j,1)==helyes.substr(j,1))
            {
                pont+=4;
            }
            else if(j<=12 and valaszok[i].substr(j,1)==helyes.substr(j,1))
            {
                pont+=5;
            }
            else if(j==13 and valaszok[i].substr(j,1)==helyes.substr(j,1))
            {
                pont+=6;
            }
        }

        kifajl<<" "<<pont<<endl;
        pontok[i]=pont;
        pont=0;
    }

/// -----------------------------------
    for (i=0; i<db;i++)
    {
        for(j=i+1;j<db;j++)
        {
            if (pontok[i]<pontok[j])
            {
                swap(pontok[i], pontok[j]);
                swap(azon[i], azon[j]);
            }
        }
    }

    int helyezes=1;

    for (i=0;i<db;i++)
    {
        if(pontok[i]==pontok[i+1])
        {
            cout<<helyezes<<". dij "<<"("<<pontok[i]<<") "<<azon[i]<<endl;
        }
        else
        {
            cout<<helyezes<<". dij "<<"("<<pontok[i]<<") "<<azon[i]<<endl;
            helyezes++;
        }
        if(helyezes>3)
        {
            break;
        }
    }

    return 0;
}

