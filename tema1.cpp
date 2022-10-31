#include<iostream>
#include<vector>
#include<cstring>

class angajat {
private :
    std::string nume;
    int salariu;
    std::string CNP;
    int AniExperienta;
public :
    angajat(const std::string& nume,int salariu,const std::string& CNP,int AniExperienta)
    {
        this->nume = nume;
        this->salariu = salariu;
        this->CNP = CNP;
        this->AniExperienta = AniExperienta;
    }
    angajat(const angajat &other) : nume{other.nume} , salariu(other.salariu) , CNP(other.CNP) , AniExperienta(other.AniExperienta){
          //  std::cout << "Constructor de copiere" << std::endl;
        }
    angajat &operator=(const angajat &other)
        {
        nume = other.nume;
        salariu = other.salariu;
        CNP =other.CNP;
        AniExperienta = other.AniExperienta;
        return *this;
        };

    ~angajat()
    {
     ///   std::cout<<"Destructor";
    };

    friend std::ostream &operator<<(std::ostream& os, const angajat& ang)
    {
        os <<"Nume : "<< ang.nume<<std::endl<<"Salariu : "<<ang.salariu<<std::endl<<"CNP : "<<ang.CNP<<std::endl<<"Ani experienta : "<<ang.AniExperienta<<std::endl;
            return os;
    };
    int getAniExperienta() const {return AniExperienta;}

};

class magazin{
private :
    std::vector<angajat> ang;
    std::string adresa;
public :
    magazin(const std::vector<angajat> &ang , const std::string& adresa)
    {
        this->ang = ang;
        this->adresa = adresa;
    }
    friend std::ostream &operator<<(std::ostream& os, const magazin& mag)
    {
        os<< mag.ang[0]<<std::endl<<mag.ang[1]<<std::endl<<mag.ang[2]<< std::endl;
            return os;
    };

    void CautareVanzator(const magazin& mag,int x,std::vector<angajat>& v2)
    {
        for(int i=0; i<3; i++)
        {
            if(v2[i].getAniExperienta()>=x)
            std::cout<<mag.ang[i]<<std::endl;
        }
    }
};


class undita {
private :
    int lungime;
    std::string material;
    int stoc;
    int pret;
public :
    undita(int lungime, const std::string& material,int stoc,int pret)
    {
        this->lungime = lungime;
        this->material = material;
        this->stoc = stoc;
        this->pret = pret;
    }
    friend std::ostream &operator<<(std::ostream& os, const undita& und)
    {
        os <<"Lungime : "<< und.lungime<<" metri "<<std::endl<<"Material : "<<und.material<<std::endl<<"Stoc : "<<und.stoc<<std::endl<<"Pret : "<<und.pret<<" lei"<< std::endl;
            return os;
    };

    int getPret()
    const
    {
        return pret;
    }
    int getStoc()
    const
    {
        return stoc;
    }
     const std::string& getMaterial() const { return material; }
     int getLungime()
     const{ return lungime;}
};

class carlig {
private :
    int dimensiune;
    std::string culoare;
    int stoc;
    int pret;
public :
    carlig(int dimensiune , const std::string& culoare,int stoc,int pret)
    {
        this-> dimensiune = dimensiune;
        this-> culoare = culoare;
        this-> stoc = stoc;
        this-> pret = pret;
    }
    friend std::ostream &operator<<(std::ostream& os, const carlig& carr)
    {
        os <<"Dimensiune : "<<carr.dimensiune<<std::endl<<"Culoare : "<<carr.culoare<<std::endl<<"Stoc : "<<carr.stoc<<std::endl<<"Pret : "<<carr.pret<<" lei"<< std::endl;
            return os;
    };
    int getPret()
    const
    {
        return pret;
    }
    int getStoc()
    const
    {
        return stoc;
    }
     const std::string& getCuloare() const { return culoare; }
     int getDimensiune() const {return dimensiune;}
};

class mamaliga {
private :
    std::string culoare;
    std:: string aroma;
    int stoc;
    int pret;
public :
    mamaliga(const std::string& culoare, const std::string& aroma,int stoc,int pret)
    {
        this-> culoare = culoare;
        this-> aroma = aroma;
        this-> stoc = stoc;
        this-> pret = pret;
    }
    friend std::ostream &operator<<(std::ostream& os, const mamaliga& mam)
    {
        os <<"Culoare : "<<mam.culoare<<std::endl<<"Aroma : "<<mam.aroma<<std::endl<<"Stoc : "<<mam.stoc<<std::endl<<"Pret : "<<mam.pret<<" lei"<< std::endl;
            return os;
    };
    int getPret()
    const
    {
        return pret;
    }
    int getStoc()
    const
    {
        return stoc;
    }
     const std::string& getCuloare() const { return culoare; }
      const std::string& getAroma() const { return aroma; }
};

class inventar {
private :
    std::vector<undita> und;
    std::vector<carlig> carr;
    std::vector<mamaliga> mam;
public :
    inventar(const std::vector<undita> &und, const std::vector<carlig> &carr, const std::vector<mamaliga> &mam)
    {
        this-> und = und;
        this-> carr = carr;
        this-> mam = mam;
    }
    friend std::ostream &operator<<(std::ostream& os, const inventar& inv)
    {
        os<<"Undite : "<<std::endl<<"========"<<std::endl<< inv.und[0]<<std::endl<<inv.und[1]<<std::endl<<inv.und[2]<< std::endl<< std::endl;
        os<<"Carlige : "<<std::endl<<"========="<<std::endl<<std::endl<< inv.carr[0]<<std::endl<<inv.carr[1]<<std::endl<<inv.carr[2]<< std::endl<< std::endl;
        os<<"Mamaligi : "<<std::endl<<"=========="<<std::endl<<std::endl<< inv.mam[0]<<std::endl<<inv.mam[1]<<std::endl<<inv.mam[2]<< std::endl<< std::endl;
            return os;
    };

    void CalculInv(std::vector<undita>& v2,std::vector<carlig>& v3 , std::vector<mamaliga>& v4)
    {
    int x = 0;
    for(int i=0;i<3;i++)
    {
        x = x + v2[i].getStoc()*v2[i].getPret() + v3[i].getStoc()*v3[i].getPret() + v4[i].getStoc()*v4[i].getPret();
    }
    std::cout<<x<<" lei ";
    }

    void CreareMonturaIdeala(std::vector<undita>& v2,std::vector<carlig>& v3, std::vector<mamaliga>& v4)
    {
        std::cout<<"Montura ideala : " <<std::endl<<"================"<<std::endl<<std::endl;
        int maximund=0,maximcarr=0,maximmam=0,indiceund,indicecarr,indicemam;
        for(int i=0; i<3; i++)
        {
            if(v2[i].getPret()>maximund)
            {
                maximund=v2[i].getPret();
                indiceund = i;
            }
            if(v3[i].getPret()>maximcarr)
            {
                maximcarr=v3[i].getPret();
                indicecarr = i;
            }
            if(v4[i].getPret()>maximmam)
            {
                maximmam=v4[i].getPret();
                indicemam = i;
            }
        }
        std::cout<<"Undita ideala : "<<std::endl<<"Lungime : "<<
        v2[indiceund].getLungime()<<" metri "<<std::endl<<"Material : "<<v2[indiceund].getMaterial()<<std::endl<<std::endl<<
        "Carlig ideal : "<<std::endl<<" Dimensiune : "<<v3[indicecarr].getDimensiune()<<std::endl<<" Culoare : "<<v3[indicecarr].getCuloare()<<" "<<std::endl<<std::endl<<
        "Mamaliga ideala : "<<std::endl<<"Culoare : "<<v4[indicemam].getCuloare()<<std::endl<<"Aroma : "<<v4[indicemam].getAroma()<<std::endl;
    }
};

int main()
{
    angajat ang1 = angajat("Mihai",1700,"5020808255698",8);
    angajat ang2 = angajat("Horia",2000,"5020808144751",10);
  ///  angajat ang3 = ang2; // aici am apelat cc
    angajat ang3 = angajat("Vali",2500,"5632525144478",12);
  ///  ang3 = ang2; //Aici am apelat op=

    std::vector<angajat> v1;
    v1.push_back(ang1);
    v1.push_back(ang2);
    v1.push_back(ang3);

    magazin mag1 = magazin(v1,"Kogalniceanu 14");

    undita und1 = undita(3,"carbon",4,50);
    undita und2 = undita(5,"fibra de sticla",6,70);
    undita und3 = undita(4,"carbon 20T",10,20);

    std::vector<undita> v2;
    v2.push_back(und1);
    v2.push_back(und2);
    v2.push_back(und3);
    /// Am creat vectorul cu undite

    carlig carr1 = carlig(6,"rosu",50,20);
    carlig carr2 = carlig(8,"rosu",60,10);
    carlig carr3 = carlig(10,"albastru",70,40);

    std::vector<carlig> v3;
    v3.push_back(carr1);
    v3.push_back(carr2);
    v3.push_back(carr3);
    /// Am creat vectorul cu carlige

    mamaliga mam1 = mamaliga("galben","usturoi",10,50);
    mamaliga mam2 = mamaliga("galben","capsuna",10,60);
    mamaliga mam3 = mamaliga("rosu","pepene",15,70);

    std::vector<mamaliga> v4;
    v4.push_back(mam1);
    v4.push_back(mam2);
    v4.push_back(mam3);
    /// Am creat vectorul cu mamaligi

    inventar inv = inventar(v2,v3,v4); /// Am creat inventarul cu obiecte de vanzare


/*
    for(int i=1;i<4;i++)
    {
        std::cout<<"Angajatul "<<i<<" : "<<std::endl;
        std::cout<<v1[i-1];
        std::cout<<std::endl;
    }
    /// Afisez angajatii
    std::cout<<"============================"<<std::endl<<std::endl;
*/
 ///   std::cout<<mag1; // Afisez datele magazinului

/*
    for(int i=1;i<4;i++)
    {
        std::cout<<"Tipul "<<i<<" de undita : "<<std::endl;
        std::cout<<v2[i-1];
        std::cout<<std::endl;
    };
    std::cout<<"============================"<<std::endl<<std::endl;
    /// Afisez unditele
*/
   /// Aici nu e nimic
/*
    for(int i=1;i<4;i++)
    {
        std::cout<<"Tipul "<<i<<" de carlig : "<<std::endl;
        std::cout<<v3[i-1];
        std::cout<<std::endl;
    };
    std::cout<<"============================"<<std::endl<<std::endl;
    /// Afisez carligele
*/
    /// Aici nu e nimic

/*
    for(int i=1;i<4;i++)
    {
        std::cout<<"Tipul "<<i<<" de mamaliga : "<<std::endl;
        std::cout<<v4[i-1];
        std::cout<<std::endl;
    };
    std::cout<<"============================"<<std::endl<<std::endl;
    /// Afisez mamaligile
*/
    ///   std::cout<<inv; //Afisez inventarul magazinului

  ///  inv.CalculInv(v2,v3,v4);   // Functie membru care calculeaza valoarea totala a inventarului

    ///   inv.CreareMonturaIdeala(v2,v3,v4);  //Functie membru care realizeaza montura ideala

  ///  mag1.CautareVanzator(mag1,10,v1);   // FUnctie membru care cauta vanzatori cu anii de experienta pe care ii vreau eu
}
