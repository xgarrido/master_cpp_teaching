#include<iostream>
#include<fstream>
#include<string>
#include<Carre.hpp>

using namespace std;

void Affect_carre(Carre c[4][4]);
int Test_carre_ligne(Carre c1, Carre c2, Carre c3);
int Test_carre_colonne(Carre c1, Carre c2, Carre c3);
int Test_carre_ligne_vide(Carre c1, Carre c2, Carre c3);
int Test_carre_colonne_vide(Carre c1, Carre c2, Carre c3);

void Affect_carre(Carre c[4][4])
{
  int i,j,k,nvaleur,valeur;
  int iaux,jaux,valeuraux;
  //  ifstream InputFile;

  // InputFile.open("sud_in");

  for (i=1; i<=3 ; i++)
    //for (i=1; i<=1 ; i++)
    {
      for (j=1; j<=3; j++)
      // for (j=1; j<=1; j++)
	{
	  cout<<" Carre de ligne "<<i<<" de colonne "<<j<<endl;
	  cout<<" Nombre de valeurs a affecter? "<<endl;
	  cin>>nvaleur;
	  for (k=1; k<=nvaleur ;k++)
	    {
	      cout<<" Ligne? "<<endl;
	      cin>>iaux;
	      cout<<" Colonne? "<<endl;
	      cin>>jaux;
	      cout<<" Valeur? "<<endl;
	      cin>>valeuraux;
	      c[i][j].PutCarre(iaux,jaux,valeuraux);
	  cout<<" c[1][1].n[1][1] "<<c[1][1].n[1][1]<<endl;
	  cout<<" c[1][1].n[1][2] "<<c[1][1].n[1][2]<<endl;
	  cout<<" c[1][1].n[1][3] "<<c[1][1].n[1][3]<<endl;
	  cout<<" c[1][1].n[2][1] "<<c[1][1].n[2][1]<<endl;
	  cout<<" c[1][1].n[2][2] "<<c[1][1].n[2][2]<<endl;
	  cout<<" c[1][1].n[2][3] "<<c[1][1].n[2][3]<<endl;
	  cout<<" c[1][1].n[3][1] "<<c[1][1].n[3][1]<<endl;
	  cout<<" c[1][1].n[3][2] "<<c[1][1].n[3][2]<<endl;
	  cout<<" c[1][1].n[3][3] "<<c[1][1].n[3][3]<<endl;
	      
	      } 
	}
    }

}

int Test_carre_ligne_vide(Carre c1, Carre c2, Carre c3)
{
  //test si les carres c1,c2,c3 ont des memes elements pour les cases vides
  // dans une ligne
  //itest = 0 si jamais le meme element
  //itest = 1 si le meme element est la dans une meme ligne pour c1,c2,c3
  int i,j,k;
  int ncas1,ncas2,ncas3;
  int no_ligne1,no_ligne2,no_colonne1,no_colonne2;
  int itest;

  ncas1 = c1.n_vide;
  ncas2 = c2.n_vide;
  ncas3 = c3.n_vide;


  //cout<<" routine test_ligne_vide... "<<endl;
  //cout<<" ncas1 "<<ncas1<<" ncas2 "<<ncas2<<" ncas3 "<<ncas3<<endl;
  
  itest = 0;

  for (i=1; i<= ncas1; i++)
    {
      for (j=1; j<= ncas2; j++)
	{
	  no_ligne1 = c1.ligne_vide[i];
	  no_colonne1 = c1.colonne_vide[i];
	  no_ligne2 = c2.ligne_vide[j];
	  no_colonne2 = c2.colonne_vide[j];
	    
	  if ((no_ligne1 == no_ligne2) && (c1.n[no_ligne1][no_colonne1] == c2.n[no_ligne2][no_colonne2]))
	    {
	      itest = 1;
	      return itest;
	    }
	}
    }

  for (i=1; i<= ncas1; i++)
    {
      for (k=1; k<= ncas3; k++)
	{
	  no_ligne1 = c1.ligne_vide[i];
	  no_colonne1 = c1.colonne_vide[i];
	  no_ligne2 = c3.ligne_vide[k];
	  no_colonne2 = c3.colonne_vide[k];
	    
	  if ((no_ligne1 == no_ligne2) && (c1.n[no_ligne1][no_colonne1] == c3.n[no_ligne2][no_colonne2]))
	    {
	      itest = 1;
	      return itest;
	    }
	}
    }

  for (j=1; j<= ncas2; j++)
    {
      for (k=1; k<= ncas3; k++)
	{
	  no_ligne1 = c2.ligne_vide[j];
	  no_colonne1 = c2.colonne_vide[j];
	  no_ligne2 = c3.ligne_vide[k];
	  no_colonne2 = c3.colonne_vide[k];
	    
	  if ((no_ligne1 == no_ligne2) && (c2.n[no_ligne1][no_colonne1] == c3.n[no_ligne2][no_colonne2]))
	    {
	      itest = 1;
	      return itest;
	    }
	}
    }

  return itest;
}

int Test_carre_colonne_vide(Carre c1, Carre c2, Carre c3)
{
  //test si les carres c1,c2,c3 ont des memes elements pour les cases vides
  // dans une colonne
  //itest = 0 si jamais le meme element
  //itest = 1 si le meme element est la dans une meme ligne pour c1,c2,c3
  int i,j,k;
  int ncas1,ncas2,ncas3;
  int no_ligne1,no_ligne2,no_colonne1,no_colonne2;
  int itest;

  ncas1 = c1.n_vide;
  ncas2 = c2.n_vide;
  ncas3 = c3.n_vide;

  itest = 0;

  for (i=1; i<= ncas1; i++)
    {
      for (j=1; j<= ncas2; j++)
	{
	  no_ligne1 = c1.ligne_vide[i];
	  no_colonne1 = c1.colonne_vide[i];
	  no_ligne2 = c2.ligne_vide[j];
	  no_colonne2 = c2.colonne_vide[j];
	    
	  if ((no_colonne1 == no_colonne2) && (c1.n[no_ligne1][no_colonne1] == c2.n[no_ligne2][no_colonne2]))
	    {
	      itest = 1;
	      return itest;
	    }
	}
    }

  for (i=1; i<= ncas1; i++)
    {
      for (k=1; k<= ncas3; k++)
	{
	  no_ligne1 = c1.ligne_vide[i];
	  no_colonne1 = c1.colonne_vide[i];
	  no_ligne2 = c3.ligne_vide[k];
	  no_colonne2 = c3.colonne_vide[k];
	    
	  if ((no_colonne1 == no_colonne2) && (c1.n[no_ligne1][no_colonne1] == c3.n[no_ligne2][no_colonne2]))
	    {
	      itest = 1;
	      return itest;
	    }
	}
    }

  for (j=1; j<= ncas2; j++)
    {
      for (k=1; k<= ncas3; k++)
	{
	  no_ligne1 = c2.ligne_vide[j];
	  no_colonne1 = c2.colonne_vide[j];
	  no_ligne2 = c3.ligne_vide[k];
	  no_colonne2 = c3.colonne_vide[k];
	    
	  if ((no_colonne1 == no_colonne2) && (c2.n[no_ligne1][no_colonne1] == c3.n[no_ligne2][no_colonne2]))
	    {
	      itest = 1;
	      return itest;
	    }
	}
    }

  return itest;
}

int Test_carre_ligne(Carre c1, Carre c2, Carre c3)
{
  //test si les carres c1,c2,c3 ont des memes elements dans une ligne
  //itest = 0 si jamais le meme element
  //itest = 1 si le meme element est la dans une meme ligne pour c1,c2,c3
  int i,j,j2;
  int itest;
  
  itest = 0;
  for (i=1; i<=3; i++) //test sur la ligne i
    {
     for (j=1; j<=3; j++)
       {
	 for (j2=1; j2<=3; j2++)
	   {
             if ((c2.n[i][j2] != c1.n[i][j]) || (c3.n[i][j2] != c1.n[i][j]) || (c3.n[i][j2] != c1.n[i][j]))
	       {
		 itest = 1;
		 return itest;
	       }
	  } 
       }
    }
  return itest;
}

int Test_carre_colonne(Carre c1, Carre c2, Carre c3)
{
  //test si les carres c1,c2,c3 ont des memes elements dans une colonne
  //itest = 0 si jamais le meme element
  //itest = 1 si le meme element est la dans une meme colonne pour c1,c2,c3
  int i,j,i2;
  int itest;
  
  itest = 0;
  for (j=1; j<=3; i++) //test sur la ligne j
    {
     for (i=1; i<=3; j++)
       {
	 for (i2=1; i2<=3; i2++)
	   {
             if ((c2.n[i2][j] != c1.n[i][j]) || (c3.n[i2][j] != c1.n[i][j]) || (c3.n[i2][j] != c1.n[i][j]))
	       {
		 itest = 1;
		 return itest;
	       }
	  } 
       }
    }
  return itest;
}

int main()
{
  Carre c[4][4];
  Carre caux;
  Carre Solution[4][4][280];
  int Nombre_Solution[4][4],Test_Solution[4][4][280];
  int i,j,i2,j2,k,l,itest,itag;
  int n_vid;
  int no1[100],no2[100],no3[100],no4[100];
  int i1,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14,i15,i16,i17,i18,i19;
  int i20,i21,i22,i23,i24,i25,i26,i27,i28,i29;
  int i30,i31,i32,i33,i34,i35,i36,i37,i38,i39;
  int i40,i41,i42,i43,i44,i45,i46,i47,i48,i49;
  int i50,i51,i52,i53,i54,i55,i56,i57,i58,i59;
  int i60,i61,i62,i63,i64,i65,i66,i67,i68,i69;
  int i70,i71,i72,i73,i74,i75,i76,i77,i78,i79;
  int j3,ncompt;
  int valeur_interdite[100][20],n_valeur_interdite[100];
  int no_ligne,no_colonne,inter[10],m,ncompt2,npos;
  int combi[100000][10],n_int;
  //  int deja_test_ligne2[200][200][200];

    for (i=1; i<=3; i++)
    {
      for (j=1; j<=3; j++)
	{
	  c[i][j].Initialise_Carre();
	}
	}  

 // Affectation des valeurs pre-remplies
  Affect_carre(c);

  cout<<" test carre c[1][1] "<<itest<<endl;
    for (i=1; i<=3; i++)
    {
      for (j=1; j<=3; j++)
        {
          cout<<" Affichage du carre "<<i<<","<<j<<endl;
          c[i][j].AfficheCarre();
        }
	}  

    cin>>i;
  //  cout<<" avant test_meme_entier "<<endl;

  //  itest = (c[1][1]).Test_Meme_Entier();

  //On liste les cases vides pour pouvoir faire des boucles dessus
    cout<<" Creation des tableaux des cases vides... "<<endl;  
    cout<<" Creation des tableaux des valeurs interdites pour le carre... "<<endl;  
    cout<<" Creation des tableaux des valeurs autorisees pour le carre... "<<endl;  
    cout<<" test c[1][1].n[3][2] "<<c[1][1].n[3][2]<<endl;
    cout<<" test c[1][1].n[3][3] "<<c[1][1].n[3][3]<<endl;

    for (i2=1; i2<=3; i2++)
    //  for (i2=1; i2<=1; i2++)
      {
	for (j2=1; j2<=3; j2++)
	  //for (j2=1; j2<=1; j2++)
	  {
	    //cout<<" avant c[1][1].n[2][3] "<<c[1][1].n[2][3]<<endl;
	    c[i2][j2].Determination_Cases_vides();
	    //cout<<" apres c[1][1].n[2][3] "<<c[1][1].n[2][3]<<endl;
	    c[i2][j2].Determination_Valeurs_interdites();
	    c[i2][j2].Determination_Valeurs_autorisees();
	    cout<<"***** Carre "<<i2<<","<<j2<<" : "<<endl;
	    /* cout<<" n_vide "<<c[i2][j2].n_vide<<endl;
             for (k=1; k<=c[i2][j2].n_vide; k++)
             {
	     cout<<" ligne_vide "<<(c[i2][j2].ligne_vide[k])<<" colonne_vide "<<(c[i2][j2].colonne_vide[k])<<endl; 
	     } */
	    /* cout<<" n_valeur_interdite "<<c[i2][j2].n_valeur_interdite<<endl;
            for (k=1; k<=c[i2][j2].n_valeur_interdite; k++)
             {
	        cout<<" valeur_interdite "<<(c[i2][j2].valeur_interdite[k])<<endl;
		} */
            cout<<" n_vide "<<c[i2][j2].n_vide<<endl;
            for (k=1; k<=c[i2][j2].n_vide; k++)
             {
	       cout<<" valeur_autorisee "<<(c[i2][j2].valeur_autorisee[k])<<endl;
              }
	  }
      }

    cout<<" Determination des valeurs interdites pour une case d un carre a cause d autres carres "<<endl;

         for (i2=1; i2<=3; i2++)
	   //for (i2=1; i2<=1; i2++)
      {
		 for (j2=1; j2<=3; j2++)
		   //for (j2=1; j2<=1; j2++)
	  {
	    cout<<" Nombre de cases vides "<<c[i2][j2].n_vide<<endl;
	    for (k=1; k<=c[i2][j2].n_vide; k++) // boucle sur les cases
	   //   vides du carre i2,j2
	      {
		// cin>>ncompt;
		// cout<<" case vide k= "<<k<<endl;
		no_ligne = c[i2][j2].ligne_vide[k];
		no_colonne = c[i2][j2].colonne_vide[k];
		ncompt = 0;
		 // on regarde les autres carres sur la meme "ligne"
		for (j3=1; j3<=3; j3++)
		  {
		    if (j3 != j2)
		      {
			//cout<<" carre de colonne j3 "<<j3<<endl;
			for (j=1; j<=3; j++)
			  {
			    //cout<<" colonne j "<<j<<" no_ligne "<<no_ligne<<" valeur "<<c[i2][j3].n[no_ligne][j]<<endl;
			    if (c[i2][j3].n[no_ligne][j] != 0)
			      {
				itest = 0;
				// cout<<" nombre interdits "<<c[i2][j2].n_valeur_interdite<<endl;
				for (l=1; l<=(c[i2][j2].n_valeur_interdite); l++)
				  {
				    // cout<<" valeur interdite l "<<l<<" c[i2][j2].valeur_interdite[l] "<<c[i2][j2].valeur_interdite[l]<<endl;
				    if (c[i2][j3].n[no_ligne][j] == c[i2][j2].valeur_interdite[l]) itest = 1;
				  }
				//cout<<" itest "<<itest<<endl;
				if (itest == 0) {
				  ncompt++;
				  // c[i2][j2].interdit[no_ligne][no_colonne][ncompt] = c[i2][j3].n[no_ligne][j];
				  inter[ncompt] = c[i2][j3].n[no_ligne][j];
				  //cout<<" ajoute a la liste des interdits "<<endl; 
				  //cout<<" inter[ncompt] "<<inter[ncompt]<<endl;
				}
			      }
			  }
		  }
		  }
		 // on regarde les autres carres sur la meme "colonne"
		for (i3=1; i3<=3; i3++)
		  {
		    if (i3 != i2)
		      {
			//cout<<" carre de ligne i3 "<<i3<<endl;
			for (i=1; i<=3; i++)
			  {
			    //cout<<" ligne i  "<<i<<" no_colonne "<<no_colonne<<" valeur "<<c[i3][j2].n[i][no_colonne]<<endl;
			    if (c[i3][j2].n[i][no_colonne] != 0)
			      {
				itest = 0;
				// cout<<" nombre d interdits "<<c[i2][j2].n_valeur_interdite<<endl;
				for (l=1; l<=(c[i2][j2].n_valeur_interdite); l++)
				  {
				    // cout<<" l "<<l<<" c[i2][j2].valeur_interdite[l] "<<c[i2][j2].valeur_interdite[l]<<endl;
				    if (c[i3][j2].n[i][no_colonne] == c[i2][j2].valeur_interdite[l]) itest = 1;
				  }
				//cout<<" itest "<<itest<<endl;
				if (itest == 0) {
				  ncompt++;
				  // c[i2][j2].interdit[no_ligne][no_colonne][ncompt] = c[i3][j2].n[i][no_colonne];
				  inter[ncompt] = c[i3][j2].n[i][no_colonne];
				  //cout<<" ajoute a la liste des interdits "<<endl; 				  
				  //cout<<" inter[ncompt] "<<inter[ncompt]<<endl;
				}
			      }
			  }
		  }
		  }
		    ncompt2 = 0;
		    for (l=1; l<= ncompt; l++)
		      {
			//cout<<" l= "<<l<<" inter[l] "<<inter[l]<<endl;
			itest = 0;
			for (m=1; m<= (l-1); m++)
			  {
			    if (inter[l] == inter[m]) itest = 1;
			  }
			if (itest == 0)	
			  {
			    ncompt2++;
			    c[i2][j2].interdit[no_ligne][no_colonne][ncompt2] = inter[l];
			  }
		      }
		    c[i2][j2].n_interdit[no_ligne][no_colonne] = ncompt2;
		    cout<<" c[i2][j2].n_interdit[no_ligne][no_colonne] "<<c[i2][j2].n_interdit[no_ligne][no_colonne]<<endl;
		for (l=1; l<= c[i2][j2].n_interdit[no_ligne][no_colonne]; l++)
		  {
		    cout<<" l= "<<l<<" c[i2][j2].interdit[no_ligne][no_colonne][ncompt] "<<c[i2][j2].interdit[no_ligne][no_colonne][l]<<endl;
		  }
		//cout<<" Fin de l iteration sur k "<<k<<endl;
	      } //boucle sur k
	  } //boucle sur j2
      } //boucle sur i2

	 cout<<" Recherche des solutions carre par carre..."<<endl;
	 
	 for (i2=1; i2<=3; i2++)
	   //for (i2=1; i2<=1; i2++)
	   {
	     for (j2=1; j2<=3; j2++)
	       //for (j2=1; j2<=1; j2++)
	       {
		 cout<<"######### Carre "<<i2<<","<<j2<<"###############"<<endl;
		 //ncompt = 0; //compteur du nombre de solutions
		 npos = c[i2][j2].n_vide;
		 if (npos == 1) 
		   {
		     ncompt = 0;
		     for (i11=1; i11<=npos; i11++)//affectation 1ere case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[1];
			 no_colonne = c[i2][j2].colonne_vide[1];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i11] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (itest == 0)
			   {
          			    ncompt++;
			 no_ligne = c[i2][j2].ligne_vide[1];
			 no_colonne = c[i2][j2].colonne_vide[1];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i11];
			 for (l=1; l<=3; l++)
			   {
			     for (m=1; m<=3; m++)
			       {
				 Solution[i2][j2][ncompt].n[l][m] = c[i2][j2].n[l][m];
				 Test_Solution[i2][j2][ncompt] = 1;
			       }
			   }
			 Solution[i2][j2][ncompt].n_vide = c[i2][j2].n_vide;

			 for (l=1; l<=c[i2][j2].n_vide; l++)
			   {
			     Solution[i2][j2][ncompt].ligne_vide[l] = c[i2][j2].ligne_vide[l];
			     Solution[i2][j2][ncompt].colonne_vide[l] = c[i2][j2].colonne_vide[l];
			   }

			 cout<<" ************ Solution "<<ncompt<<endl;			 
          c[i2][j2].AfficheCarre();
			  } //test itest=0
			   } // boucle sur i11
		   }
		 else if (npos == 2)
		   {
		     ncompt = 0;
		     for (i11=1; i11<=npos; i11++)//affectation 1ere case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[1];
			 no_colonne = c[i2][j2].colonne_vide[1];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i11] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (itest == 0)
			   {
		         for (i12=1; i12<=npos; i12++)//affectation 1ere case vide
		          {
			 no_ligne = c[i2][j2].ligne_vide[2];
			 no_colonne = c[i2][j2].colonne_vide[2];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i12] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (itest == 0)
			   {
			    if (i11 != i12) 
			      {
          			    ncompt++;
			 no_ligne = c[i2][j2].ligne_vide[1];
			 no_colonne = c[i2][j2].colonne_vide[1];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i11];
			 no_ligne = c[i2][j2].ligne_vide[2];
			 no_colonne = c[i2][j2].colonne_vide[2];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i12];
			 for (l=1; l<=3; l++)
			   {
			     for (m=1; m<=3; m++)
			       {
				 Solution[i2][j2][ncompt].n[l][m] = c[i2][j2].n[l][m];
				 Test_Solution[i2][j2][ncompt] = 1;
			       }
			   }
			 Solution[i2][j2][ncompt].n_vide = c[i2][j2].n_vide;

			 for (l=1; l<=c[i2][j2].n_vide; l++)
			   {
			     Solution[i2][j2][ncompt].ligne_vide[l] = c[i2][j2].ligne_vide[l];
			     Solution[i2][j2][ncompt].colonne_vide[l] = c[i2][j2].colonne_vide[l];
			   }

			 cout<<" ************ Solution "<<ncompt<<endl;			 
          c[i2][j2].AfficheCarre();
			      } // test sur i11
			   }
			  } //boucle sur i12
			   }
			   } // boucle sur i11
		   
		   } // test npos=2
		 else if (npos == 3) //3 cases vides, 3 possibilites
		   {
		     ncompt = 0;
		     for (i11=1; i11<=npos; i11++)//affectation 1ere case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[1];
			 no_colonne = c[i2][j2].colonne_vide[1];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 //cout<<" i11 : n_int "<<n_int<<endl;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     //  			     cout<<" k "<<k<<" c[i2][j2].interdit[no_ligne][no_colonne][k] "<<c[i2][j2].interdit[no_ligne][no_colonne][k]<<endl;
			     if (c[i2][j2].valeur_autorisee[i11] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (itest == 0)
			   {
		     for (i12=1; i12<=npos; i12++)//affectation 2eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[2];
			 no_colonne = c[i2][j2].colonne_vide[2];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 //cout<<" i12 : n_int "<<n_int<<endl;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     //    cout<<" k "<<k<<" c[i2][j2].interdit[no_ligne][no_colonne][k] "<<c[i2][j2].interdit[no_ligne][no_colonne][k]<<endl;
			     if (c[i2][j2].valeur_autorisee[i12] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i12 == i11) itest = 1;
			 if (itest == 0)
			   {
		     for (i13=1; i13<=npos; i13++)//affectation 3eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[3];
			 no_colonne = c[i2][j2].colonne_vide[3];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i13] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i13 == i11 || i13 == i12) itest = 1;
			 if (itest == 0)
			   {
          			    ncompt++;
			 no_ligne = c[i2][j2].ligne_vide[1];
			 no_colonne = c[i2][j2].colonne_vide[1];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i11];
			 no_ligne = c[i2][j2].ligne_vide[2];
			 no_colonne = c[i2][j2].colonne_vide[2];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i12];
			 no_ligne = c[i2][j2].ligne_vide[3];
			 no_colonne = c[i2][j2].colonne_vide[3];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i13];

			 for (l=1; l<=3; l++)
			   {
			     for (m=1; m<=3; m++)
			       {
				 Solution[i2][j2][ncompt].n[l][m] = c[i2][j2].n[l][m];
				 Test_Solution[i2][j2][ncompt] = 1;
			       }
			   }
			 Solution[i2][j2][ncompt].n_vide = c[i2][j2].n_vide;

			 for (l=1; l<=c[i2][j2].n_vide; l++)
			   {
			     Solution[i2][j2][ncompt].ligne_vide[l] = c[i2][j2].ligne_vide[l];
			     Solution[i2][j2][ncompt].colonne_vide[l] = c[i2][j2].colonne_vide[l];
			   }

			 cout<<" ************ Solution "<<ncompt<<endl;			 
          c[i2][j2].AfficheCarre();
	  
			   }// test itest=0
		       }//boucle i13
			 
			   }// test itest = 0
		       } //boucle i12
			   } // test itest = 0
		       } // boucle i11
		   }
		 else if (npos == 4) //4 cases vides, 4 possibilites
		   {
		     ncompt = 0;
		     for (i11=1; i11<=npos; i11++)//affectation 1ere case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[1];
			 no_colonne = c[i2][j2].colonne_vide[1];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 //cout<<" i11 : n_int "<<n_int<<endl;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     //  			     cout<<" k "<<k<<" c[i2][j2].interdit[no_ligne][no_colonne][k] "<<c[i2][j2].interdit[no_ligne][no_colonne][k]<<endl;
			     if (c[i2][j2].valeur_autorisee[i11] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (itest == 0)
			   {
		     for (i12=1; i12<=npos; i12++)//affectation 2eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[2];
			 no_colonne = c[i2][j2].colonne_vide[2];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 //cout<<" i12 : n_int "<<n_int<<endl;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     //    cout<<" k "<<k<<" c[i2][j2].interdit[no_ligne][no_colonne][k] "<<c[i2][j2].interdit[no_ligne][no_colonne][k]<<endl;
			     if (c[i2][j2].valeur_autorisee[i12] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i12 == i11) itest = 1;
			 if (itest == 0)
			   {
		     for (i13=1; i13<=npos; i13++)//affectation 3eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[3];
			 no_colonne = c[i2][j2].colonne_vide[3];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i13] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i13 == i11 || i13 == i12) itest = 1;
			 if (itest == 0)
			   {
		     for (i14=1; i14<=npos; i14++)//affectation 4eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[4];
			 no_colonne = c[i2][j2].colonne_vide[4];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i14] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i14 == i11 || i14 == i12 || i14==i13) itest = 1;
			 if (itest == 0)
			   {
          			    ncompt++;
			 no_ligne = c[i2][j2].ligne_vide[1];
			 no_colonne = c[i2][j2].colonne_vide[1];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i11];
			 no_ligne = c[i2][j2].ligne_vide[2];
			 no_colonne = c[i2][j2].colonne_vide[2];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i12];
			 no_ligne = c[i2][j2].ligne_vide[3];
			 no_colonne = c[i2][j2].colonne_vide[3];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i13];
			 no_ligne = c[i2][j2].ligne_vide[4];
			 no_colonne = c[i2][j2].colonne_vide[4];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i14];

			 for (l=1; l<=3; l++)
			   {
			     for (m=1; m<=3; m++)
			       {
				 Solution[i2][j2][ncompt].n[l][m] = c[i2][j2].n[l][m];
				 Test_Solution[i2][j2][ncompt] = 1;
			       }
			   }
			 Solution[i2][j2][ncompt].n_vide = c[i2][j2].n_vide;

			 for (l=1; l<=c[i2][j2].n_vide; l++)
			   {
			     Solution[i2][j2][ncompt].ligne_vide[l] = c[i2][j2].ligne_vide[l];
			     Solution[i2][j2][ncompt].colonne_vide[l] = c[i2][j2].colonne_vide[l];
			   }

			 cout<<" ************ Solution "<<ncompt<<endl;			 
          c[i2][j2].AfficheCarre();
	  
			   }//test itest=0
		       }//boucle i14
			   }// test itest=0
		       }//boucle i13
			 
			   }// test itest = 0
		       } //boucle i12
			   } // test itest = 0
		       } // boucle i11
		   }
		 else if (npos == 5) //5 cases vides, 5 possibilites
		   {
		     ncompt = 0;
		     for (i11=1; i11<=npos; i11++)//affectation 1ere case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[1];
			 no_colonne = c[i2][j2].colonne_vide[1];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 //cout<<" i11 : n_int "<<n_int<<endl;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     //  			     cout<<" k "<<k<<" c[i2][j2].interdit[no_ligne][no_colonne][k] "<<c[i2][j2].interdit[no_ligne][no_colonne][k]<<endl;
			     if (c[i2][j2].valeur_autorisee[i11] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (itest == 0)
			   {
		     for (i12=1; i12<=npos; i12++)//affectation 2eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[2];
			 no_colonne = c[i2][j2].colonne_vide[2];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 //cout<<" i12 : n_int "<<n_int<<endl;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     //    cout<<" k "<<k<<" c[i2][j2].interdit[no_ligne][no_colonne][k] "<<c[i2][j2].interdit[no_ligne][no_colonne][k]<<endl;
			     if (c[i2][j2].valeur_autorisee[i12] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i12 == i11) itest = 1;
			 if (itest == 0)
			   {
		     for (i13=1; i13<=npos; i13++)//affectation 3eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[3];
			 no_colonne = c[i2][j2].colonne_vide[3];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i13] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i13 == i11 || i13 == i12) itest = 1;
			 if (itest == 0)
			   {
		     for (i14=1; i14<=npos; i14++)//affectation 4eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[4];
			 no_colonne = c[i2][j2].colonne_vide[4];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i14] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i14 == i11 || i14 == i12 || i14==i13) itest = 1;
			 if (itest == 0)
			   {
		     for (i15=1; i15<=npos; i15++)//affectation 4eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[5];
			 no_colonne = c[i2][j2].colonne_vide[5];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i15] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i15 == i11 || i15 == i12 || i15==i13 || i15==i14) itest = 1;
			 if (itest == 0)
			   {
          			    ncompt++;
			 no_ligne = c[i2][j2].ligne_vide[1];
			 no_colonne = c[i2][j2].colonne_vide[1];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i11];
			 no_ligne = c[i2][j2].ligne_vide[2];
			 no_colonne = c[i2][j2].colonne_vide[2];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i12];
			 no_ligne = c[i2][j2].ligne_vide[3];
			 no_colonne = c[i2][j2].colonne_vide[3];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i13];
			 no_ligne = c[i2][j2].ligne_vide[4];
			 no_colonne = c[i2][j2].colonne_vide[4];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i14];
			 no_ligne = c[i2][j2].ligne_vide[5];
			 no_colonne = c[i2][j2].colonne_vide[5];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i15];

			 for (l=1; l<=3; l++)
			   {
			     for (m=1; m<=3; m++)
			       {
				 Solution[i2][j2][ncompt].n[l][m] = c[i2][j2].n[l][m];
				 Test_Solution[i2][j2][ncompt] = 1;
			       }
			   }
			 Solution[i2][j2][ncompt].n_vide = c[i2][j2].n_vide;

			 for (l=1; l<=c[i2][j2].n_vide; l++)
			   {
			     Solution[i2][j2][ncompt].ligne_vide[l] = c[i2][j2].ligne_vide[l];
			     Solution[i2][j2][ncompt].colonne_vide[l] = c[i2][j2].colonne_vide[l];
			   }

			 cout<<" ************ Solution "<<ncompt<<endl;			 
          c[i2][j2].AfficheCarre();
	  
			   }
		       }//boucle i15
			   }//test itest=0
		       }//boucle i14
			   }// test itest=0
		       }//boucle i13
			 
			   }// test itest = 0
		       } //boucle i12
			   } // test itest = 0
		       } // boucle i11

		   }
		 else if (npos == 6) //6 cases vides, 6 possibilites
		   {
		     ncompt = 0;
		     for (i11=1; i11<=npos; i11++)//affectation 1ere case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[1];
			 no_colonne = c[i2][j2].colonne_vide[1];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i11] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (itest==0)
			   {
		     for (i12=1; i12<=npos; i12++)//affectation 2eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[2];
			 no_colonne = c[i2][j2].colonne_vide[2];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i12] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i12 == i11) itest=1;
			 if (itest==0)
			   {
		     for (i13=1; i13<=npos; i13++)//affectation 3eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[3];
			 no_colonne = c[i2][j2].colonne_vide[3];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i13] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i13 == i11 || i13 == i12) itest=1;
			 if (itest==0)
			   {
		     for (i14=1; i14<=npos; i14++)//affectation 4eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[4];
			 no_colonne = c[i2][j2].colonne_vide[4];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i14] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i14 == i11 || i14 == i12 || i14 == i13) itest=1;
			 if (itest==0)
			   {
		     for (i15=1; i15<=npos; i15++)//affectation 4eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[5];
			 no_colonne = c[i2][j2].colonne_vide[5];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i15] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i15 == i11 || i15 == i12 || i15 == i13 || i15 == i14) itest=1;
			 if (itest==0)
			   {
		     for (i16=1; i16<=npos; i16++)//affectation 4eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[6];
			 no_colonne = c[i2][j2].colonne_vide[6];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i16] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i16 == i11 || i16 == i12 || i16 == i13 || i16 == i14 || i16 == i15) itest=1;
			 if (itest==0)
			   {
          			    ncompt++;
			 no_ligne = c[i2][j2].ligne_vide[1];
			 no_colonne = c[i2][j2].colonne_vide[1];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i11];
			 no_ligne = c[i2][j2].ligne_vide[2];
			 no_colonne = c[i2][j2].colonne_vide[2];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i12];
			 no_ligne = c[i2][j2].ligne_vide[3];
			 no_colonne = c[i2][j2].colonne_vide[3];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i13];
			 no_ligne = c[i2][j2].ligne_vide[4];
			 no_colonne = c[i2][j2].colonne_vide[4];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i14];
			 no_ligne = c[i2][j2].ligne_vide[5];
			 no_colonne = c[i2][j2].colonne_vide[5];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i15];
			 no_ligne = c[i2][j2].ligne_vide[6];
			 no_colonne = c[i2][j2].colonne_vide[6];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i16];

			 for (l=1; l<=3; l++)
			   {
			     for (m=1; m<=3; m++)
			       {
				 Solution[i2][j2][ncompt].n[l][m] = c[i2][j2].n[l][m];
				 Test_Solution[i2][j2][ncompt] = 1;
			       }
			   }
			 Solution[i2][j2][ncompt].n_vide = c[i2][j2].n_vide;

			 for (l=1; l<=c[i2][j2].n_vide; l++)
			   {
			     Solution[i2][j2][ncompt].ligne_vide[l] = c[i2][j2].ligne_vide[l];
			     Solution[i2][j2][ncompt].colonne_vide[l] = c[i2][j2].colonne_vide[l];
			   }

			 cout<<" ************ Solution "<<ncompt<<endl;			 
          c[i2][j2].AfficheCarre();
			   }//test itest = 0
		       }//boucle i16
			   }// test itest = 0
		       }//boucle i15
			   }//test itest = 0
		       }//boucle i14 
			   }//test itest = 0
		       }//boucle i13
			   }//test itest = 0
		       }//boucle i12
			   }//test itest = 0
		       }//boucle i11
		   }
		 else if (npos == 7) //7 cases vides, 7 possibilites
		   {
		     ncompt = 0;
		     for (i11=1; i11<=npos; i11++)//affectation 1ere case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[1];
			 no_colonne = c[i2][j2].colonne_vide[1];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i11] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (itest == 0)
			   {
		     for (i12=1; i12<=npos; i12++)//affectation 2eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[2];
			 no_colonne = c[i2][j2].colonne_vide[2];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i12] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i12 == i11) itest =1;
			 if (itest == 0)
			   {
		     for (i13=1; i13<=npos; i13++)//affectation 3eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[3];
			 no_colonne = c[i2][j2].colonne_vide[3];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i13] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i13 == i11 || i13 == i12) itest =1;
			 if (itest == 0)
			   {
		     for (i14=1; i14<=npos; i14++)//affectation 4eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[4];
			 no_colonne = c[i2][j2].colonne_vide[4];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i14] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i14 == i11 || i14 == i12 || i14 == i13) itest =1;
			 if (itest == 0)
			   {
		     for (i15=1; i15<=npos; i15++)//affectation 4eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[5];
			 no_colonne = c[i2][j2].colonne_vide[5];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i15] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i15 == i11 || i15 == i12 || i15 == i13 || i15 == i14) itest =1;
			 if (itest == 0)
			   {
		     for (i16=1; i16<=npos; i16++)//affectation 4eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[6];
			 no_colonne = c[i2][j2].colonne_vide[6];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i16] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i16 == i11 || i16 == i12 || i16 == i13 || i16 == i14 || i16==i15) itest =1;
			 if (itest == 0)
			   {
		     for (i17=1; i17<=npos; i17++)//affectation 4eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[7];
			 no_colonne = c[i2][j2].colonne_vide[7];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i17] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i17 == i11 || i17 == i12 || i17 == i13 || i17 == i14 || i17==i15 || i17==i16) itest =1;
			 if (itest == 0)
			   {
          			    ncompt++;
			 no_ligne = c[i2][j2].ligne_vide[1];
			 no_colonne = c[i2][j2].colonne_vide[1];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i11];
			 no_ligne = c[i2][j2].ligne_vide[2];
			 no_colonne = c[i2][j2].colonne_vide[2];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i12];
			 no_ligne = c[i2][j2].ligne_vide[3];
			 no_colonne = c[i2][j2].colonne_vide[3];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i13];
			 no_ligne = c[i2][j2].ligne_vide[4];
			 no_colonne = c[i2][j2].colonne_vide[4];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i14];
			 no_ligne = c[i2][j2].ligne_vide[5];
			 no_colonne = c[i2][j2].colonne_vide[5];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i15];
			 no_ligne = c[i2][j2].ligne_vide[6];
			 no_colonne = c[i2][j2].colonne_vide[6];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i16];
			 no_ligne = c[i2][j2].ligne_vide[7];
			 no_colonne = c[i2][j2].colonne_vide[7];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i17];

			 for (l=1; l<=3; l++)
			   {
			     for (m=1; m<=3; m++)
			       {
				 Solution[i2][j2][ncompt].n[l][m] = c[i2][j2].n[l][m];
				 Test_Solution[i2][j2][ncompt] = 1;
			       }
			   }
			 Solution[i2][j2][ncompt].n_vide = c[i2][j2].n_vide;

			 for (l=1; l<=c[i2][j2].n_vide; l++)
			   {
			     Solution[i2][j2][ncompt].ligne_vide[l] = c[i2][j2].ligne_vide[l];
			     Solution[i2][j2][ncompt].colonne_vide[l] = c[i2][j2].colonne_vide[l];
			   }

			 cout<<" ************ Solution "<<ncompt<<endl;			 
          c[i2][j2].AfficheCarre();
			   }//test itest=0
		       }//boucle i17
			   }//test itest=0
		       }//boucle i16
			   }//test itest=0
		       }//boucle i15
			   }//test itest=0
		       }//boucle i14
			   }//test itest=0
		       }//boucle i13
			   }//test itest=0
		       }//boucle i12
			   }//test itest=0
		       }//boucle i11
		   }
		 else if (npos == 8) //8 cases vides, 8 possibilites
		   {
		     ncompt = 0;
		     for (i11=1; i11<=npos; i11++)//affectation 1ere case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[1];
			 no_colonne = c[i2][j2].colonne_vide[1];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i11] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (itest == 0)
			   {
		     for (i12=1; i12<=npos; i12++)//affectation 2eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[2];
			 no_colonne = c[i2][j2].colonne_vide[2];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i12] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i12 == i11) itest =1;
			 if (itest == 0)
			   {
		     for (i13=1; i13<=npos; i13++)//affectation 3eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[3];
			 no_colonne = c[i2][j2].colonne_vide[3];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i13] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i13 == i11 || i13 == i12) itest =1;
			 if (itest == 0)
			   {
		     for (i14=1; i14<=npos; i14++)//affectation 4eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[4];
			 no_colonne = c[i2][j2].colonne_vide[4];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i14] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i14 == i11 || i14 == i12 || i14 == i13) itest =1;
			 if (itest == 0)
			   {
		     for (i15=1; i15<=npos; i15++)//affectation 4eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[5];
			 no_colonne = c[i2][j2].colonne_vide[5];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i15] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i15 == i11 || i15 == i12 || i15 == i13 || i15 == i14) itest =1;
			 if (itest == 0)
			   {
		     for (i16=1; i16<=npos; i16++)//affectation 4eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[6];
			 no_colonne = c[i2][j2].colonne_vide[6];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i16] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i16 == i11 || i16 == i12 || i16 == i13 || i16 == i14 || i16==i15) itest =1;
			 if (itest == 0)
			   {
		     for (i17=1; i17<=npos; i17++)//affectation 4eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[7];
			 no_colonne = c[i2][j2].colonne_vide[7];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i17] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i17 == i11 || i17 == i12 || i17 == i13 || i17 == i14 || i17==i15 || i17==i16) itest =1;
			 if (itest == 0)
			   {
		     for (i18=1; i18<=npos; i18++)//affectation 4eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[8];
			 no_colonne = c[i2][j2].colonne_vide[8];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i18] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i18 == i11 || i18 == i12 || i18 == i13 || i18 == i14 || i18==i15 || i18==i16 || i18==i17) itest =1;
			 if (itest == 0)
			   {
          			    ncompt++;
			 no_ligne = c[i2][j2].ligne_vide[1];
			 no_colonne = c[i2][j2].colonne_vide[1];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i11];
			 no_ligne = c[i2][j2].ligne_vide[2];
			 no_colonne = c[i2][j2].colonne_vide[2];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i12];
			 no_ligne = c[i2][j2].ligne_vide[3];
			 no_colonne = c[i2][j2].colonne_vide[3];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i13];
			 no_ligne = c[i2][j2].ligne_vide[4];
			 no_colonne = c[i2][j2].colonne_vide[4];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i14];
			 no_ligne = c[i2][j2].ligne_vide[5];
			 no_colonne = c[i2][j2].colonne_vide[5];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i15];
			 no_ligne = c[i2][j2].ligne_vide[6];
			 no_colonne = c[i2][j2].colonne_vide[6];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i16];
			 no_ligne = c[i2][j2].ligne_vide[7];
			 no_colonne = c[i2][j2].colonne_vide[7];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i17];
			 no_ligne = c[i2][j2].ligne_vide[8];
			 no_colonne = c[i2][j2].colonne_vide[8];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i18];

			 for (l=1; l<=3; l++)
			   {
			     for (m=1; m<=3; m++)
			       {
				 Solution[i2][j2][ncompt].n[l][m] = c[i2][j2].n[l][m];
				 Test_Solution[i2][j2][ncompt] = 1;
			       }
			   }
			 Solution[i2][j2][ncompt].n_vide = c[i2][j2].n_vide;

			 for (l=1; l<=c[i2][j2].n_vide; l++)
			   {
			     Solution[i2][j2][ncompt].ligne_vide[l] = c[i2][j2].ligne_vide[l];
			     Solution[i2][j2][ncompt].colonne_vide[l] = c[i2][j2].colonne_vide[l];
			   }

			 cout<<" ************ Solution "<<ncompt<<endl;			 
          c[i2][j2].AfficheCarre();
			   }//test itest=0
		       }//boucle i18
			   }//test itest=0
		       }//boucle i17
			   }//test itest=0
		       }//boucle i16
			   }//test itest=0
		       }//boucle i15
			   }//test itest=0
		       }//boucle i14
			   }//test itest=0
		       }//boucle i13
			   }//test itest=0
		       }//boucle i12
			   }//test itest=0
		       }//boucle i11
		   }
		 else if (npos == 9) //9 cases vides, 9 possibilites
		   {
		     ncompt = 0;
		     for (i11=1; i11<=npos; i11++)//affectation 1ere case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[1];
			 no_colonne = c[i2][j2].colonne_vide[1];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i11] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (itest == 0)
			   {
		     for (i12=1; i12<=npos; i12++)//affectation 2eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[2];
			 no_colonne = c[i2][j2].colonne_vide[2];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i12] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i12 == i11) itest =1;
			 if (itest == 0)
			   {
		     for (i13=1; i13<=npos; i13++)//affectation 3eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[3];
			 no_colonne = c[i2][j2].colonne_vide[3];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i13] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i13 == i11 || i13 == i12) itest =1;
			 if (itest == 0)
			   {
		     for (i14=1; i14<=npos; i14++)//affectation 4eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[4];
			 no_colonne = c[i2][j2].colonne_vide[4];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i14] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i14 == i11 || i14 == i12 || i14 == i13) itest =1;
			 if (itest == 0)
			   {
		     for (i15=1; i15<=npos; i15++)//affectation 4eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[5];
			 no_colonne = c[i2][j2].colonne_vide[5];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i15] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i15 == i11 || i15 == i12 || i15 == i13 || i15 == i14) itest =1;
			 if (itest == 0)
			   {
		     for (i16=1; i16<=npos; i16++)//affectation 4eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[6];
			 no_colonne = c[i2][j2].colonne_vide[6];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i16] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i16 == i11 || i16 == i12 || i16 == i13 || i16 == i14 || i16==i15) itest =1;
			 if (itest == 0)
			   {
		     for (i17=1; i17<=npos; i17++)//affectation 4eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[7];
			 no_colonne = c[i2][j2].colonne_vide[7];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i17] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i17 == i11 || i17 == i12 || i17 == i13 || i17 == i14 || i17==i15 || i17==i16) itest =1;
			 if (itest == 0)
			   {
		     for (i18=1; i18<=npos; i18++)//affectation 4eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[8];
			 no_colonne = c[i2][j2].colonne_vide[8];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i18] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i18 == i11 || i18 == i12 || i18 == i13 || i18 == i14 || i18==i15 || i18==i16 || i18==i17) itest =1;
			 if (itest == 0)
			   {
		     for (i19=1; i19<=npos; i19++)//affectation 4eme case vide
		       {
			 no_ligne = c[i2][j2].ligne_vide[9];
			 no_colonne = c[i2][j2].colonne_vide[9];
			 n_int = c[i2][j2].n_interdit[no_ligne][no_colonne];
			 itest = 0;
			 for (k=1; k<=n_int; k++) //on exclut les interdits
			   {
			     if (c[i2][j2].valeur_autorisee[i19] ==  c[i2][j2].interdit[no_ligne][no_colonne][k]) itest = 1;
			   }  
			 if (i19 == i11 || i19 == i12 || i19 == i13 || i19 == i14 || i19==i15 || i19==i16 || i19==i17 || i19==i18) itest =1;
			 if (itest == 0)
			   {
          			    ncompt++;
			 no_ligne = c[i2][j2].ligne_vide[1];
			 no_colonne = c[i2][j2].colonne_vide[1];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i11];
			 no_ligne = c[i2][j2].ligne_vide[2];
			 no_colonne = c[i2][j2].colonne_vide[2];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i12];
			 no_ligne = c[i2][j2].ligne_vide[3];
			 no_colonne = c[i2][j2].colonne_vide[3];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i13];
			 no_ligne = c[i2][j2].ligne_vide[4];
			 no_colonne = c[i2][j2].colonne_vide[4];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i14];
			 no_ligne = c[i2][j2].ligne_vide[5];
			 no_colonne = c[i2][j2].colonne_vide[5];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i15];
			 no_ligne = c[i2][j2].ligne_vide[6];
			 no_colonne = c[i2][j2].colonne_vide[6];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i16];
			 no_ligne = c[i2][j2].ligne_vide[7];
			 no_colonne = c[i2][j2].colonne_vide[7];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i17];
			 no_ligne = c[i2][j2].ligne_vide[8];
			 no_colonne = c[i2][j2].colonne_vide[8];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i18];
			 no_ligne = c[i2][j2].ligne_vide[9];
			 no_colonne = c[i2][j2].colonne_vide[9];	
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[i19];

			 for (l=1; l<=3; l++)
			   {
			     for (m=1; m<=3; m++)
			       {
				 Solution[i2][j2][ncompt].n[l][m] = c[i2][j2].n[l][m];
				 Test_Solution[i2][j2][ncompt] = 1;
			       }
			   }
			 Solution[i2][j2][ncompt].n_vide = c[i2][j2].n_vide;

			 for (l=1; l<=c[i2][j2].n_vide; l++)
			   {
			     Solution[i2][j2][ncompt].ligne_vide[l] = c[i2][j2].ligne_vide[l];
			     Solution[i2][j2][ncompt].colonne_vide[l] = c[i2][j2].colonne_vide[l];
			   }

			 cout<<" ************ Solution "<<ncompt<<endl;			 
          c[i2][j2].AfficheCarre();
			   }//test itest=0
		       }//boucle i19
			   }//test itest=0
		       }//boucle i18
			   }//test itest=0
		       }//boucle i17
			   }//test itest=0
		       }//boucle i16
			   }//test itest=0
		       }//boucle i15
			   }//test itest=0
		       }//boucle i14
			   }//test itest=0
		       }//boucle i13
			   }//test itest=0
		       }//boucle i12
			   }//test itest=0
		       }//boucle i11
		   }
		 /* for (k=1; k<=c[i2][j2].n_vide; k++) //boucle cases vides
		   {
		     no_ligne = c[i2][j2].ligne_vide[k];
		     no_colonne = c[i2][j2].colonne_vide[k];
		     for (l=1; l<=c[i2][j2].n_vide; l++) //boucle valeur autori
		       {
			 c[i2][j2].n[no_ligne][no_colonne] = c[i2][j2].valeur_autorisee[l];
			 //ncompt++;
			 //Copy(c[i2][j2],solution1[ncompt]);
		       }
		       } */
		 
		 Nombre_Solution[i2][j2] = ncompt;
	       } //boucle sur j2
	   } //boucle sur i2


	 cout<<" Recherche de solutions globales "<<endl;

	 ncompt = 0;
	 for (i11=1; i11<=Nombre_Solution[1][1]; i11++)
	   // for (i11=2; i11<=2; i11++)
	   {
	     if (Test_Solution[1][1][i11] == 1)
	       {
		 //cout<<" solution 11 no "<<i11<<endl;
		 //       Solution[1][1][i11].AfficheCarre();
		 for (i12=1; i12<=Nombre_Solution[1][2]; i12++)
			//for (i12=15; i12<=15; i12++)
	   {
	     if (Test_Solution[1][2][i12] == 1)
	       {
		 //cout<<" solution 12 no "<<i12<<endl;
		 //       Solution[1][2][i12].AfficheCarre();
		 for (i13=1; i13<=Nombre_Solution[1][3]; i13++)
		   //for (i13=87; i13<=87; i13++)
	   {
	     if (Test_Solution[1][3][i13] == 1)
	       {
		 //cout<<" solution 13 no "<<i13<<endl;
		 //       Solution[1][3][i13].AfficheCarre();
		itest = Test_carre_ligne_vide(Solution[1][1][i11],Solution[1][2][i12],Solution[1][3][i13]);
		//cout<<" itest "<<itest<<endl;
		//return i2;
		//cin>>ncompt;
		   if (itest == 0)
		     {
		 for (i14=1; i14<=Nombre_Solution[2][1]; i14++)
		       //for (i14=5; i14<=Nombre_Solution[2][1]; i14++)
	   {
	     if (Test_Solution[2][1][i14] == 1)
	       {
		 for (i15=1; i15<=Nombre_Solution[2][2]; i15++)
	   {
	     if (Test_Solution[2][2][i15] == 1)
	       {
		 for (i16=1; i16<=Nombre_Solution[2][3]; i16++)
	   {
	     if (Test_Solution[2][3][i16] == 1)
	       {
		 //if (deja_test_ligne2[i14][i15][i16] != 1 && deja_test_ligne2[i14][i15][i16] != 2 )
		 //  {
		itest = Test_carre_ligne_vide(Solution[2][1][i14],Solution[2][2][i15],Solution[2][3][i16]);
		// deja_test_ligne2[i14][i15][i16] = itest + 1;
		//   }
		//else
		//  {
		//    itest = deja_test_ligne2[i14][i15][i16] - 1;
		//  }
		if (itest == 0)
		  {
		    for (i17=1; i17<=Nombre_Solution[3][1]; i17++)
		      //for (i17=30; i17<=30; i17++)
	   {
	     if (Test_Solution[3][1][i17] == 1)
	       {
		 itest = Test_carre_colonne_vide(Solution[1][1][i11],Solution[2][1][i14],Solution[3][1][i17]);
		if (itest == 0)
		  {
		    for (i18=1; i18<=Nombre_Solution[3][2]; i18++)
		    //for (i18=1; i18<=1; i18++)
	   {
	     if (Test_Solution[3][2][i18] == 1)
	       {
		 itest = Test_carre_colonne_vide(Solution[1][2][i12],Solution[2][2][i15],Solution[3][2][i18]);
		if (itest == 0)
		  {
		   for (i19=1; i19<=Nombre_Solution[3][3]; i19++)
		    //for (i19=48; i19<=48; i19++)
	   {
	     if (Test_Solution[3][3][i19] == 1)
	       {
		itest = Test_carre_ligne_vide(Solution[3][1][i17],Solution[3][2][i18],Solution[3][3][i19]);
		if (itest == 0)
		  {
		itest = Test_carre_colonne_vide(Solution[1][3][i13],Solution[2][3][i16],Solution[3][3][i19]);
		if (itest == 0)
		  {
		       ncompt++;
		       cout<<" ######### SOLUTION GLOBALE "<<ncompt<<" ######## "<<endl;
		       //cout<<" i11 "<<i11<<" i12 "<<i12<<" i13 "<<i13<<" i14 "<<i14<<" i15 "<<i15<<" i16 "<<i16<<" i17 "<<i17<<" i18 "<<i18<<" i19 "<<i19<<endl;
		       cout<<" ***** Carre 1,1 *****"<<endl;
		       Solution[1][1][i11].AfficheCarre();
		       cout<<" ***** Carre 1,2 *****"<<endl;
		       Solution[1][2][i12].AfficheCarre();
		       cout<<" ***** Carre 1,3 *****"<<endl;
		       Solution[1][3][i13].AfficheCarre();
		       cout<<" ***** Carre 2,1 *****"<<endl;
		       Solution[2][1][i14].AfficheCarre();
		       cout<<" ***** Carre 2,2 *****"<<endl;
		       Solution[2][2][i15].AfficheCarre();
		       cout<<" ***** Carre 2,3 *****"<<endl;
		       Solution[2][3][i16].AfficheCarre();
		       cout<<" ***** Carre 3,1 *****"<<endl;
		       Solution[3][1][i17].AfficheCarre();
		       cout<<" ***** Carre 3,2 *****"<<endl;
		       Solution[3][2][i18].AfficheCarre();
		       cout<<" ***** Carre 3,3 *****"<<endl;
		       Solution[3][3][i19].AfficheCarre();
		    
		  }// test colonne 3
		  }// test ligne 3
	       }// test_solution 3 3
	   }//boucle i19
		  }// test colonne 2
	       }// test_solution 3 2
	   }//boucle i18
		  }//test colonne 1
	       }// test_solution 3 1
	   }//boucle i17
		  }// test ligne 2
	       }// test_solution 2 3
	   }//boucle i16
	       }// test_solution 2 2
	   }//boucle i15
	       }// test_solution 2 1
	   }//boucle i14
		       //ncompt++;
		       //cout<<" ######### SOLUTION GLOBALE "<<ncompt<<" ######## "<<endl;
		       // Solution[1][1][i11].AfficheCarre();
		       // Solution[1][2][i12].AfficheCarre();
		       // Solution[1][3][i13].AfficheCarre();

		     }// test ligne 1 

	       }// test solution 1 3
	   }//boucle i13
		 
	       }// test solution 1 2
	   }//boucle i12
	       }// test_solution 1 1
	   }//boucle i11
	 

    return i2;

    cin>>i2;
	  /* n_vid = 0;
     for (i=1; i<=3; i++)
    {
      for (j=1; j<=3; j++)
	{
	  for (i2=1; i2<=3; i2++)
	  {
	    for (j2=1; j2<=3; j2++)
	    {
	      if (c[i][j].n[i2][j2] == 0)
	      {
		n_vid++;
		no1[n_vid] = i;
		no2[n_vid] = j;
		no3[n_vid] = i2;
		no4[n_vid] = j2;
		cout<<" case vide "<<n_vid<<" no1 "<<no1[n_vid]<<" no2 "<<no2[n_vid]<<" no3 "<<no3[n_vid]<<" no4 "<<no4[n_vid]<<endl;
	      }
	    }
	  }    
	 }
	 }  */


     cout<<" Creation des listes interdites pour les cases vides..."<<endl;
     //on liste les possibilites interdites pour les cases vides
     for (k=1; k<=n_vid; k++)
       {
	 cout<<"*** case vide "<<k<<" no1 "<<no1[k]<<" no2 "<<no2[k]<<" no3 "<<no3[k]<<" no4 "<<no4[k]<<endl;
	 l = 0;
	 //cases du meme carre
	 for (i=1; i<=3; i++)
	   {
	     for (j=1; j<=3; j++)
	       {
		 //	 cout<<" test case meme carre : i "<<i<<" j "<<j<<endl;
		 if (((i != no3[k]) || (j != no4[k])) && (c[no1[k]][no2[k]].n[i][j] != 0 ))
	   {
	     //cout<<" la valeur "<<c[no1[k]][no2[k]].n[i][j]<<" doit etre rejetee "<<endl;
	     l++;
	     valeur_interdite[k][l] = c[no1[k]][no2[k]].n[i][j];
	   }
	     }
	   }
         cin>>itest;
         //cases d'un autre carre (meme ligne)
	 for (j2=1; j2<=3; j2++)
	   {
	     if (j2 != no2[k])
	       {
		 for (j=1; j<=3; j++)
		   {
		     if (c[no1[k]][j2].n[no3[k]][j] != 0)
		       {
			 l++;
			 valeur_interdite[k][l] = c[no1[k]][j2].n[no3[k]][j];
		       }
		   }
	       }
	   }
         //cases d'un autre carre (meme colonne)
	 for (i2=1; i2<=3; i2++)
	   {
	     if (i2 != no1[k])
	       {
		 for (i=1; i<=3; i++)
		   {
		     if (c[i2][no2[k]].n[i][no4[k]] != 0)
		       {
			 l++;
			 valeur_interdite[k][l] = c[i2][no2[k]].n[i][no4[k]];
		       }
		   }
	       }
	   }

         n_valeur_interdite[k] = l;
       }
   
     for (k=1; k<=n_vid; k++)
       {
	 cout<<"***** Case vide : carre "<<no1[k]<<","<<no2[k]<<" : case "<<no3[k]<<","<<no4[k]<<endl;
	 for (l=1; l<=n_valeur_interdite[k]; l++)
	   {
	     cout<<" Valeur_interdite "<<valeur_interdite[k][l]<<endl;
	   }
       

       }
	 
     //On boucle sur les cases vides pour trouver la solution
        for (i1=1; i1<=9; i1++)
          {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[1]; l++)
	      {
		if (i1 == valeur_interdite[1][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    cout<<" Boucle sur i1 "<<i1<<endl;
	    c[no1[1]][no2[1]].n[no3[1]][no4[1]] = i1;
	    for (i2=1; i2<=9; i2++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[2]; l++)
	      {
		if (i2 == valeur_interdite[2][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    cout<<" Boucle sur i2 "<<i2<<endl;
	    c[no1[2]][no2[2]].n[no3[2]][no4[2]] = i2;
	    for (i3=1; i3<=9; i3++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[3]; l++)
	      {
		if (i3 == valeur_interdite[3][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    cout<<" Boucle sur i3 "<<i3<<endl;
	    c[no1[3]][no2[3]].n[no3[3]][no4[3]] = i3;
	    for (i4=1; i4<=9; i4++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[4]; l++)
	      {
		if (i4 == valeur_interdite[4][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    cout<<" Boucle sur i4 "<<i4<<endl;
	    c[no1[4]][no2[4]].n[no3[4]][no4[4]] = i4;
	    for (i5=1; i5<=9; i5++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[5]; l++)
	      {
		if (i5 == valeur_interdite[5][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    cout<<" Boucle sur i5 "<<i5<<endl;
	    c[no1[5]][no2[5]].n[no3[5]][no4[5]] = i5;
	    for (i6=1; i6<=9; i6++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[6]; l++)
	      {
		if (i6 == valeur_interdite[6][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    cout<<" Boucle sur i6 "<<i6<<endl;
	    c[no1[6]][no2[6]].n[no3[6]][no4[6]] = i6;
	    for (i7=1; i7<=9; i7++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[7]; l++)
	      {
		if (i7 == valeur_interdite[7][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[7]][no2[7]].n[no3[7]][no4[7]] = i7;
	    for (i8=1; i8<=9; i8++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[8]; l++)
	      {
		if (i8 == valeur_interdite[8][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[8]][no2[8]].n[no3[8]][no4[8]] = i8;
	    for (i9=1; i9<=9; i9++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[9]; l++)
	      {
		if (i9 == valeur_interdite[9][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[9]][no2[9]].n[no3[9]][no4[9]] = i9;
	    for (i10=1; i10<=9; i10++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[10]; l++)
	      {
		if (i10 == valeur_interdite[10][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[10]][no2[10]].n[no3[10]][no4[10]] = i10;
	    for (i11=1; i11<=9; i11++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[11]; l++)
	      {
		if (i11 == valeur_interdite[11][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[11]][no2[11]].n[no3[11]][no4[11]] = i11;
	    for (i12=1; i12<=9; i12++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[12]; l++)
	      {
		if (i12 == valeur_interdite[12][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[12]][no2[12]].n[no3[12]][no4[12]] = i12;
	    for (i13=1; i13<=9; i13++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[13]; l++)
	      {
		if (i13 == valeur_interdite[13][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[13]][no2[13]].n[no3[13]][no4[13]] = i13;
	    for (i14=1; i14<=9; i14++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[14]; l++)
	      {
		if (i14 == valeur_interdite[14][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[14]][no2[14]].n[no3[14]][no4[14]] = i14;
	    for (i15=1; i15<=9; i15++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[15]; l++)
	      {
		if (i15 == valeur_interdite[15][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[15]][no2[15]].n[no3[15]][no4[15]] = i15;
	    for (i16=1; i16<=9; i16++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[16]; l++)
	      {
		if (i16 == valeur_interdite[16][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[16]][no2[16]].n[no3[16]][no4[16]] = i16;
	    for (i17=1; i17<=9; i17++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[17]; l++)
	      {
		if (i17 == valeur_interdite[17][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[17]][no2[17]].n[no3[17]][no4[17]] = i17;
	    for (i18=1; i18<=9; i18++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[18]; l++)
	      {
		if (i18 == valeur_interdite[18][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[18]][no2[18]].n[no3[18]][no4[18]] = i18;
	    for (i19=1; i19<=9; i19++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[19]; l++)
	      {
		if (i19 == valeur_interdite[19][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[19]][no2[19]].n[no3[19]][no4[19]] = i19;
	    for (i20=1; i20<=9; i20++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[20]; l++)
	      {
		if (i20 == valeur_interdite[20][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[20]][no2[20]].n[no3[20]][no4[20]] = i20;
	    for (i21=1; i21<=9; i21++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[21]; l++)
	      {
		if (i21 == valeur_interdite[21][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[21]][no2[21]].n[no3[21]][no4[21]] = i21;
	    for (i22=1; i22<=9; i22++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[22]; l++)
	      {
		if (i22 == valeur_interdite[22][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[22]][no2[22]].n[no3[22]][no4[22]] = i22;
	    for (i23=1; i23<=9; i23++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[23]; l++)
	      {
		if (i23 == valeur_interdite[23][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[23]][no2[23]].n[no3[23]][no4[23]] = i23;
	    for (i24=1; i24<=9; i24++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[24]; l++)
	      {
		if (i24 == valeur_interdite[24][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[24]][no2[24]].n[no3[24]][no4[24]] = i24;
	    for (i25=1; i25<=9; i25++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[25]; l++)
	      {
		if (i25 == valeur_interdite[25][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[25]][no2[25]].n[no3[25]][no4[25]] = i25;
	    for (i26=1; i26<=9; i26++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[26]; l++)
	      {
		if (i26 == valeur_interdite[26][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[26]][no2[26]].n[no3[26]][no4[26]] = i26;
	    for (i27=1; i27<=9; i27++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[27]; l++)
	      {
		if (i27 == valeur_interdite[27][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[27]][no2[27]].n[no3[27]][no4[27]] = i27;
	    for (i28=1; i28<=9; i28++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[28]; l++)
	      {
		if (i28 == valeur_interdite[28][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[28]][no2[28]].n[no3[28]][no4[28]] = i28;
	    for (i29=1; i29<=9; i29++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[29]; l++)
	      {
		if (i29 == valeur_interdite[29][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[29]][no2[29]].n[no3[29]][no4[29]] = i29;
	    for (i30=1; i30<=9; i30++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[30]; l++)
	      {
		if (i30 == valeur_interdite[30][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[30]][no2[30]].n[no3[30]][no4[30]] = i30;
	    for (i31=1; i31<=9; i31++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[31]; l++)
	      {
		if (i31 == valeur_interdite[31][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[31]][no2[31]].n[no3[31]][no4[31]] = i31;
	    for (i32=1; i32<=9; i32++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[32]; l++)
	      {
		if (i32 == valeur_interdite[32][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[32]][no2[32]].n[no3[32]][no4[32]] = i32;
	    for (i33=1; i33<=9; i33++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[33]; l++)
	      {
		if (i33 == valeur_interdite[33][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[33]][no2[33]].n[no3[33]][no4[33]] = i33;
	    for (i34=1; i34<=9; i34++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[34]; l++)
	      {
		if (i34 == valeur_interdite[34][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[34]][no2[34]].n[no3[34]][no4[34]] = i34;
	    for (i35=1; i35<=9; i35++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[35]; l++)
	      {
		if (i35 == valeur_interdite[35][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[35]][no2[35]].n[no3[35]][no4[35]] = i35;
	    for (i36=1; i36<=9; i36++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[36]; l++)
	      {
		if (i36 == valeur_interdite[36][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[36]][no2[36]].n[no3[36]][no4[36]] = i36;
	    for (i37=1; i37<=9; i37++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[37]; l++)
	      {
		if (i37 == valeur_interdite[37][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[37]][no2[37]].n[no3[37]][no4[37]] = i37;
	    for (i38=1; i38<=9; i38++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[38]; l++)
	      {
		if (i38 == valeur_interdite[38][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[38]][no2[38]].n[no3[38]][no4[38]] = i38;
	    for (i39=1; i39<=9; i39++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[39]; l++)
	      {
		if (i39 == valeur_interdite[39][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[39]][no2[39]].n[no3[39]][no4[39]] = i39;
	    for (i40=1; i40<=9; i40++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[40]; l++)
	      {
		if (i40 == valeur_interdite[40][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[40]][no2[40]].n[no3[40]][no4[40]] = i40;
	    for (i41=1; i41<=9; i41++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[41]; l++)
	      {
		if (i41 == valeur_interdite[41][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[41]][no2[41]].n[no3[41]][no4[41]] = i41;
	    for (i42=1; i42<=9; i42++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[42]; l++)
	      {
		if (i42 == valeur_interdite[42][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[42]][no2[42]].n[no3[42]][no4[42]] = i42;
	    for (i43=1; i43<=9; i43++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[43]; l++)
	      {
		if (i43 == valeur_interdite[43][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[43]][no2[43]].n[no3[43]][no4[43]] = i43;
	    for (i44=1; i44<=9; i44++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[44]; l++)
	      {
		if (i44 == valeur_interdite[44][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[44]][no2[44]].n[no3[44]][no4[44]] = i44;
	    for (i45=1; i45<=9; i45++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[45]; l++)
	      {
		if (i45 == valeur_interdite[45][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[45]][no2[45]].n[no3[45]][no4[45]] = i45;
	    for (i46=1; i46<=9; i46++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[46]; l++)
	      {
		if (i46 == valeur_interdite[46][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[46]][no2[46]].n[no3[46]][no4[46]] = i46;
	    for (i47=1; i47<=9; i47++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[47]; l++)
	      {
		if (i47 == valeur_interdite[47][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[47]][no2[47]].n[no3[47]][no4[47]] = i47;
	    for (i48=1; i48<=9; i48++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[48]; l++)
	      {
		if (i48 == valeur_interdite[48][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[48]][no2[48]].n[no3[48]][no4[48]] = i48;
	    for (i49=1; i49<=9; i49++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[49]; l++)
	      {
		if (i49 == valeur_interdite[49][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[49]][no2[49]].n[no3[49]][no4[49]] = i49;
	    for (i50=1; i50<=9; i50++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[50]; l++)
	      {
		if (i50 == valeur_interdite[50][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[50]][no2[50]].n[no3[50]][no4[50]] = i50;
	    for (i51=1; i51<=9; i51++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[51]; l++)
	      {
		if (i51 == valeur_interdite[51][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[51]][no2[51]].n[no3[51]][no4[51]] = i51;
	    for (i52=1; i52<=9; i52++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[52]; l++)
	      {
		if (i52 == valeur_interdite[52][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[52]][no2[52]].n[no3[52]][no4[52]] = i52;
	    for (i53=1; i53<=9; i53++)
	      {
	    itag = 0;
	    for (l=1; l<=n_valeur_interdite[53]; l++)
	      {
		if (i53 == valeur_interdite[53][l]) itag = 1;
	      }
	    if (itag == 0)
	      {
	    c[no1[53]][no2[53]].n[no3[53]][no4[53]] = i53;
	    for (i=1; i<=3;i++)
	      {
		for (j=1; j<=3; j++)
		  {
		    if ((c[i][j].Test_Meme_Entier()) == 1) goto fin;
		  }
	      }
	    for (i=1; i<=3; i++)
	      {
		if ((Test_carre_ligne(c[i][1],c[i][2],c[i][3])) == 1) goto fin;
		}	
	    for (j=1; j<=3; j++)
	      {
		if ((Test_carre_ligne(c[1][j],c[2][j],c[3][j])) == 1) goto fin;
		}	
	    cout<<" ###################### Solution "<<endl;
	    for (i=1; i<=3; i++)
	      for (j=1; j<=3; j++)
		{
		  cout<<" ***** Carre "<<i<<","<<j<<endl;
		  c[i][j].AfficheCarre();
		}

	      fin:itest=0;
	      } // test itag(53)
	      } //i53
	      } // test itag(52)
	      } //i52
	      } // test itag(51)
	      } //i51
	      } // test itag(50)
	      } //i50
	      } // test itag(49)
	      } //i49
	      } // test itag(48)
	      } //i48
	      } // test itag(47)
	      } //i47
	      } // test itag(46)
	      } //i46
	      } // test itag(45)
	      } //i45
	      } // test itag(44)
	      } //i44
	      } // test itag(43)
	      } //i43
	      } // test itag(42)
	      } //i42
	      } // test itag(41)
	      } //i41
	      } // test itag(40)
	      } //i40
	      } // test itag(39)
	      } //i39
	      } // test itag(38)
	      } //i38
	      } // test itag(37)
	      } //i37
	      } // test itag(36)
	      } //i36
	      } // test itag(35)
	      } //i35
	      } // test itag(34)
	      } //i34
	      } // test itag(33)
	      } //i33
	      } // test itag(32)
	      } //i32
	      } // test itag(31)
	      } //i31
	      } // test itag(30)
	      } //i30 
	      } // test itag(29)
	      } //i29
	      } // test itag(28)
	      } //i28
	      } // test itag(27)
	      } //i27
	      } // test itag(26)
	      } //i26
	      } // test itag(25)
	      } //i25
	      } // test itag(24)
	      } //i24
	      } // test itag(23)
	      } //i23
	      } // test itag(22)
	      } //i22
	      } // test itag(21)
	      } //i21 
	      } // test itag(20)
	      } //i20
	      } // test itag(19)
	      } //i19
	      } // test itag(18)
	      } //i18
	      } // test itag(17)
	      } //i17
	      } // test itag(16)
	      } //i16
	      } // test itag(15)
	      } //i15
	      } // test itag(14)
	      } //i14
	      } // test itag(13)
	      } //i13
	      } // test itag(12)
	      } //i12
	      } // test itag(11)
	      } //i11
	      } // test itag(10)
	      } //i10
	      } // test itag(9)
	      } //i9
	      } // test itag(8)
	      } //i8
	      } // test itag(7)
	      } //i7
	      } // test itag(6)
	      } //i6 
	      } // test itag(5)
	      } //i5
	      } // test itag(4)
	      } //i4
	      } // test itag(3)
	      } //i3
	      } // test itag(2)
	  } //i2
	      } // test itag(1)
} //i1


}
