#ifndef carre
#define carre


class Carre
{
private:

public:
  int n[4][4];
  int n_vide;
  int ligne_vide[10];
  int colonne_vide[10];
  int n_valeur_interdite;
  int valeur_interdite[10];
  int valeur_autorisee[10];
  int interdit[4][4][10];
  int n_interdit[4][4];

  Carre();
  ~Carre();
  void Initialise_Carre();
  void PutCarre(int no_ligne, int no_colonne, int valeur);
  void AfficheCarre();
  int Somme_Ligne(int no_ligne);
  int Somme_Colonne(int no_colonne);
  int Test_Meme_Entier();
  void Determination_Cases_vides();  
  void Determination_Valeurs_interdites();  
  void Determination_Valeurs_autorisees();  

};
#endif
