#include <iostream>
#include <cstdlib>
#include <math.h>
//#include <gsl/gsl_fit.h>

#define PI 3.14159265
using namespace std;


double random (const double min, const double max)
{
  return ((max - min) * rand()/(RAND_MAX) + min);
}

class Particule
{
private:
  double E;
  double Rp;
  double t0;
  double theta_sdp;
  double phi_sdp;
  double psi;

public:
  //Particule(int E, int R_p, int t0, int theta, int phi, int psi); //constructeur classe particule
  //Particule(int, int);
  Particule ();
  ~Particule();

  double get_E () const {return E;}
  double get_Rp () const {return Rp;}
  double get_theta_sdp () const {return theta_sdp;}
  double get_phi_sdp () const {return phi_sdp;}
  double get_psi () const {return psi;}

  void initialise ();
  void affiche();
};


Particule::Particule () :    // all set to 0 to start
  E (0.0),
  Rp (0.0),
  t0 (0.0),
  theta_sdp (0.0),
  phi_sdp (0.0),
  psi (0.0)
{}

Particule::~Particule()
{}

void Particule::initialise ()
{
  E = random (18.0, 21.0);       //10^18 till 10^21 Gev
  Rp = random (8, 12);           //8 till 12 km
  theta_sdp = random (90, 160);  //90 till 100 degree
  phi_sdp = random (60, 90);     //60 till 90 degree
  psi = random (80, 100);        //80 till 100 degree
}

void Particule::affiche()
{
  cout << "Particule: E	= " << E << endl;
  cout << "Particule: radius	= " << Rp << endl;
  cout << "Particule: t0	= " << t0 << endl;
  cout << "Particule: theta_SDP = " << theta_sdp << endl;
  cout << "Particule: phi_SDP	= " << phi_sdp << endl;
  cout << "Particule: psi	= " << psi << endl;
}



/*class Pixel
  {
  private:
  int signal[19][21];
  double t_i[];
  double theta_i[21];
  double phi_i[19];

  public:
  Pixel();
  ~Pixel();
  void affiche();

  double get_signal () const {return signal[19][21];}
  double get_t_i[] () const {return t_i[];}
  double get_theta_i () const {return theta_i;}
  double get_phi_i () const {return phi_i;}
  };

  Pixel::Pixel () :
  signal[19][21](0),
  t_i[](0.),
  theta_i[21](0.),
  phi_i[19](0.)
  {}




  Pixel::Pixel(double theta_i[], double phi_j[], int signal, double t_i)
  {g=theta_i[21]; h=phi_j[19]; k=signal; l=t_i;
  for (int j=1; j++; j<=22)
  {theta_i[21]=1.5*j;
  }
  for (int i=1; i++; i<=20)
  {phi_j[19]=60+1.5*(20-i);
  }
  }

  void Pixel::affiche()
  {for (int i=1; i++; i<=22)
  cout<<theta_i[i]<<endl;}

  Pixel::~Pixel()
  {}
*/

int main ()
{
  srand (time (0)); //graine pour generateur aleatoire

  Particule my_particule;
  my_particule.initialise ();
  my_particule.affiche ();

  const size_t nline = 20;
  const size_t nrow  = 22;

  bool signal[nline][nrow];
  for (size_t j = 0; j < nrow; ++j)
    for (size_t i = 0; i < nline; ++i)
      signal[i][j] = false;

  double t_i[22]={0.};
  double theta_i[22]={0.};
  double phi_i[20]={0.};
  double const c=2.99792458*pow(10.0, 5.0); //speed of light in km

  // Print camera (to be done in Camera class)
  cout << "Camera View:" << endl;
  cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
  for (size_t j = 0; j < nrow; ++j)
    {
      cout << endl;
      cout << "|";
      for (size_t i = 0; i < nline; ++i)
        {
          if (signal[i][j])
            cout << " o ";
          else
            cout << "   ";
        }
      cout << "|";
    }
  cout << endl;
  cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
  cout << endl;

  for (int j=0; j<=21; j++) {
    theta_i[j]=1.5*j;
    //cout<<"theta:"<<theta_i[j]<<endl;
    t_i[j]=-(my_particule.get_Rp()/c)*(tan(PI/2.-my_particule.get_psi())-tan(PI-my_particule.get_psi()-1.5*j));	//an Klammern () nach get_... Funktion denken!!!
    //cout<<"t_i:"<<t_i[j]<<endl;
    for (int i=0; i<=19; i++) {
      phi_i[i]=60.+1.5*(20.-i);
      const double dummy = 1.5*j - ((60.+1.5*(20.-i))-my_particule.get_phi_sdp())/tan(PI/180.*my_particule.get_theta_sdp());
      //			if(1.5*j-((60.+1.5*(20.-i))-my_particule.get_phi_sdp())/tan(PI/180.*my_particule.get_theta_sdp())==0.)
      if(fabs (dummy) < 1.5) signal[i][j] = true;
      else                   signal[i][j] = false;
      //cout<<"signal:"<<signal[i][j]<<endl;
    }
    //cout<<"phi_i:"<<phi_i[j]<<endl;
  }

  // Print camera (to be done in Camera class)
  cout << "Camera View After:" << endl;
  cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
  for (size_t j = 0; j < nrow; ++j)
    {
      cout << endl;
      cout << "|";
      for (size_t i = 0; i < nline; ++i)
        {
          if (signal[i][j])
            cout << " o ";
          else
            cout << "   ";
        }
      cout << "|";
    }
  cout << endl;
  cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
  cout << endl;

  // //linear Regression
  //  int n=22;
  //  double c0, c1, cov00, cov01, cov11, sumsq;
  //  gsl_fit_linear (theta_i, 1, phi_i, 1, n, &c0, &c1, &cov00, &cov01, &cov11, &sumsq);


  return 0;
}
