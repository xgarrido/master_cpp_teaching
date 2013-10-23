#include<iostream>
#include<fstream>
#include<string>
#include<Carre.hpp>

//using namespace std;

Carre::Carre()
{
  int i,j;
  for (i=0; i<=3 ; i++)
    {
      for (j=0; j<=3 ; j++)
	{
	  n[i][j] = 0;
	}
    }
  return;
} 

Carre::~Carre()
{
  return;
} 

void Carre::Initialise_Carre()
{
  int i,j;
  for (i=0; i<=3 ; i++)
    {
      for (j=0; j<=3 ; j++)
	{
	  n[i][j] = 0;
	}
    }
  return;
} 

void Carre::PutCarre(int no_ligne, int no_colonne, int valeur)
{
  int no_lig_dec,no_col_dec;  

  if (no_ligne<=3 && no_colonne <=3)
    {
      std::cout<<" affectation n["<<(no_ligne)<<"]["<<(no_colonne)<<"] = "<<valeur<<std::endl;
      //      std::cout<<" avant n[1][0] : "<<n[1][0]<<std::endl;
      n[no_ligne][no_colonne] = valeur;
      //std::cout<<" apres n[1][0] : "<<n[1][0]<<std::endl;
    }

}

void Carre::AfficheCarre()
{
  int i,j;
  /*  for (i=0; i<=2 ; i++)
    {
      for (j=0; j<=2 ; j++)
	{
	  
	  std::cout<<" Element du carre : ligne "<<(i+1)<<" colonne "<<(j+1)<<" valeur "<<n[i][j]<<std::endl;
	}
	} */
  for (i=1; i<=3; i++)
    {
  std::cout<<n[i][1]<<"|"<<n[i][2]<<"|"<<n[i][3]<<std::endl;
    }



}

int Carre::Somme_Ligne(int no_ligne)
{
  int somme;
  int i;
  if (no_ligne <= 3)
    {
      somme = 0;
      for (i=1 ; i<=3 ; i++)
	{
	  somme += n[no_ligne][i];
	}

      std::cout<<" somme ligne "<<no_ligne<<" = "<<somme<<std::endl;      

    }
  else
    {
      somme = -1;
    }
  return somme;
}
int Carre::Somme_Colonne(int no_colonne)
{
  int somme;
  int i;

  if (no_colonne <= 3)
    {
      somme = 0;
      for (i=1 ; i<=3 ; i++)
	{
	  somme += n[i][no_colonne];
	}

      std::cout<<" somme colonne "<<no_colonne<<" = "<<somme<<std::endl;      

    }
  else
    {
      somme = -1;
    }
  return somme;
}
int Carre::Test_Meme_Entier()
{
  int i,j,i2,j2;
  int itest; 

  itest = 0;

  //  cout<<" debut itest "<<endl;
  for (i=1; i<=3; i++)
    {
      for (j=1; j<=3; j++)
	{
	  for (i2=1; i2<=3; i2++)
	    {
	      for (j2=1; j2<=3; j2++)
		{
		  //		  std::cout<<" i "<<i<<" j "<<j<<" i2 "<<i2<<" j2 "<<j2<<std::endl;
		  if (n[i][j] == n[i2][j2] && (i != i2 || j != j2))
		    {
		      itest = 1;
		      return itest;
		    }  
		    
		}    
	    }  
	}
    }
  return itest;
  
}
void Carre::Determination_Cases_vides()
{
  int i,j;
  int compt;
  int nbis[4][4];

  //  std::cout<<" dans Determination_Cases_vides n[3][2] "<<n[3][2]<<std::endl;
  //std::cout<<" dans Determination_Cases_vides n[3][3] "<<n[3][3]<<std::endl;

  for (i=1; i<=3; i++)
    {
      for (j=1; j<=3; j++)
	{
	  nbis[i][j] = n[i][j];
	}
    }  

  //std::cout<<" dans routine n[2][3] "<<n[2][3]<<std::endl;

  compt=0;
  for (i=1; i<=3; i++)
    {
      for (j=1; j<=3; j++)
	{
	  //          std::cout<<" i "<<i<<" j "<<j<<" nbis[i][j] "<<nbis[i][j]<<std::endl;
	  // std::cout<<" dans Determination_Cases_vides n[2][3] "<<n[2][3]<<" nbis[2][3] "<<nbis[2][3]<<std::endl;
	  if (nbis[i][j] == 0)
	    {
	      //  std::cout<<" nbis[i][j] nul compt "<<compt<<std::endl;
	      compt++;
	      ligne_vide[compt] = i;
	      colonne_vide[compt] = j;
	    }
	}
    }


  // std::cout<<" juste avant fin routine n[2][3] "<<n[2][3]<<std::endl;
  n_vide = compt;
  std::cout<<" fin routine n_vide "<<n_vide<<std::endl;

  for (i=1; i<=3; i++)
    {
      for (j=1; j<=3; j++)
	{
	  n[i][j] = nbis[i][j];
	}
    }  

  std::cout<<" apres fin routine n_vide "<<n_vide<<std::endl;
  // std::cout<<" fin routine n[2][3] "<<n[2][3]<<std::endl;
}
void Carre::Determination_Valeurs_interdites()
{
  int i,j;
  int compt;
  int nbis[4][4];

  for (i=1; i<=3; i++)
    {
      for (j=1; j<=3; j++)
	{
	  nbis[i][j] = n[i][j];
	  // std::cout<<" i "<<i<<" j "<<j<<" n[i][j] "<<n[i][j]<<std::endl;
	}
    }  

  compt=0;
  for (i=1; i<=3; i++)
    {
      for (j=1; j<=3; j++)
	{
	  // std::cout<<" i "<<i<<" j "<<j<<" nbis[i][j] "<<nbis[i][j]<<std::endl;
	  if (nbis[i][j] !=0)
	    {
	      compt++;
	      valeur_interdite[compt] = nbis[i][j];
	    }
	}
    }
  n_valeur_interdite = compt;

  /*  for (i=1; i<=3; i++)
    {
      for (j=1; j<=3; j++)
	{
	  n[i][j] = nbis[i][j];
	}
	}  */

}

void Carre::Determination_Valeurs_autorisees()
{
  int k,l,itest;
  int compt;
  int nbis;
  int aux[10];

  /* nbis = n_valeur_interdite;
  for (l=1; l<=n_valeur_interdite; l++)
    {
      aux[l] = valeur_interdite[l];
      } */
	

    compt=0;
  for (k=1; k<=9; k++)
    {
        itest = 0;
        // std::cout<<" routine autorisee k "<<k<<std::endl;
	for (l=1; l<=n_valeur_interdite; l++)
	{
	   if (k == valeur_interdite[l]) itest=1;
	  } 
        // std::cout<<" itest "<<itest<<std::endl;
       if (itest == 0) 
	{
	  compt++;
	  valeur_autorisee[compt] = k;
	  } 
	} 

  /* for (k=1; k<=n_vide; k++)
    {
      std::cout<<" k "<<k<<" valeur autorisee "<<valeur_autorisee[k]<<std::endl;
      } */

  /* n_valeur_interdite = nbis;
   for (l=1; l<=nbis; l++)
    {
      valeur_interdite[l] = aux[l];
      } */
 
}
