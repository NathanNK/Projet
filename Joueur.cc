#include "allclasses.hh"

int Joueur::CartonJauneJ1=0;
int Joueur::CartonJauneJ2=0;

int Joueur :: victoire() const //Fonction qui permet de savoir si le joueur a gagné ou non
{
    if (case_joueur >= 30)  //Si le joueur est sur la case 30 ou plus, il a gagné
    {
        return 1;  //On retourne 1
    }
    else
    {
        return 0; //Sinon on retourne 0
    }
}

int Joueur :: action(std :: map <int,std :: string> map,Joueur J2,Joueur J1,int cpt){
    
    if(map[case_joueur]=="J"){ //Si la case est un carton jaune
        if(cpt%2==0){ //Si le joueur est le joueur 1
            CartonJauneJ1++; //On incrémente le nombre de carton jaune du joueur 1
            PetiteCase CartonJaune(31,"CartonJaune","PetiteCase"); //On crée un objet CartonJaune
            CartonJaune.CartonJaune(*this); //On affiche le message correspondant à la case
            if(CartonJauneJ1==2){ //Si le joueur a deux cartons jaunes
                CartonJauneJ1=0; //On remet le nombre de cartons jaunes à 0
                std :: cout << "\nVous avez deux cartons jaunes ! Carton Rouge -> Vous reculez de 2 cases !" << std :: endl; // Le joueur prend un carton rouge
                this->setCase(this->getCase()-2); // Suite à son carton rouge, le joueur recule de 2 cases
        }
        else if(cpt%2==1){ //Si le joueur est le joueur 2
            CartonJauneJ2++; //On incrémente le nombre de carton jaune du joueur 2
            PetiteCase CartonJaune(31,"CartonJaune","PetiteCase"); //On crée un objet CartonJaune
            CartonJaune.CartonJaune(*this); //On affiche le message correspondant à la case
            if(CartonJauneJ2==2){ //Si le joueur a deux cartons jaunes
                CartonJauneJ2=0; //On remet le nombre de cartons jaunes à 0
                std :: cout << "\nVous avez deux cartons jaunes ! Carton Rouge -> Vous reculez de 2 cases !" << std :: endl; // Le joueur prend un carton rouge
                this->setCase(this->getCase()-2); // Suite à son carton rouge, le joueur recule de 2 cases
            }
        }

      }
    }
    else if(map[case_joueur]=="R"){ //Si la case est un carton rouge
        this->setCase(this->getCase()-2); //Le joueur recule de 2 cases
        PetiteCase CartonRouge(31,"CartonRouge","PetiteCase"); //On crée un objet CartonRouge
        CartonRouge.CartonRouge(*this);     //On affiche le message correspondant à la case
    }
    else if(map[case_joueur]=="B"){ //Si la case est eliminatoire
        this->setCase(0);  //Le joueur retourne au depart
        PetiteCase Elimination(31,"Elimination","PetiteCase"); //On crée un objet Elimination
        Elimination.Elimination(*this); //On affiche le message correspondant à la case
    }
    else if(map[case_joueur]=="H"){ //Si la case est hors jeu
        this->setCase(getCase()-1); //Le joueur recule d'une case
        PetiteCase HorsJeu(31,"HorsJeu","PetiteCase"); //On crée un objet HorsJeu
        HorsJeu.HorsJeu(*this); //On affiche le message correspondant à la case
    }
    else if(map[case_joueur]=="S"){ //Si la case est la case depart
        PetiteCase Depart(31,"Depart","PetiteCase"); //On crée un objet Depart
        Depart.Depart(*this); //On affiche le message correspondant à la case
    }
    else if(map[case_joueur]=="N"){ //Si la case est la case rien
        PetiteCase Rien(31,"Rien","PetiteCase"); //On crée un objet Rien
        Rien.Rien(*this); //On affiche le message correspondant à la case
    }
    else if(map[case_joueur]=="D"){ //Si la case est la case demi-finale
        Palier Demi(31,"Demi","Palier"); //On crée un objet Demi
        Demi.Demi(*this); //On affiche le message correspondant à la case
    }
    else if(map[case_joueur]=="P"){ //Si la case est la case poule
        Palier Poule(31,"Poule","Palier"); //On crée un objet Poule
        Poule.Poule(*this); //On affiche le message correspondant à la case
    }
    else if(map[case_joueur]=="8"){ //Si la case est la case huitieme
        Palier Huitieme(31,"Huitieme","Palier");     //On crée un objet Huitieme
        Huitieme.Huitieme(*this); //On affiche le message correspondant à la case
    }
    else if(map[case_joueur]=="Q"){ //Si la case est la case quart
        Palier Quart(31,"Quart","Palier"); //On crée un objet Quart
        Quart.Quart(*this); //On affiche le message correspondant à la case
    }
    else if(map[case_joueur]=="F"){ //Si la case est la case finale
        Palier Finale(31,"Finale","Palier"); //On crée un objet Finale
        Finale.Finale(*this);   //On affiche le message correspondant à la case
    }
    else if(map[case_joueur]=="E"){ //Si la case est la case evenement
        Carte Evenement("Evenement"); //On crée un objet Evenement
        int a = Evenement.Evenement(*this,J2); //On lance la fonction Evenement
        if(a==0){ //Si la fonction Evenement renvoie 0
            this->setCase(this->getCase()+1); //Le joueur avance d'une case
        }
        else if(a==1){ //Si la fonction Evenement renvoie 1
            this->setCase(this->getCase()-2); //Le joueur recule de deux cases
        }
        else if(a==2){ //Si la fonction Evenement renvoie 2
            this->setCase(this->getCase()-2); //Le joueur recule de deux cases et il peut rejouer
            cpt++; //On incrémente cpt car il peut rejouer
        }
        else if(a==3){
            this->setCase(15); //Le joueur avance à la case 15 soit la case Quart de finale
        }
        else if(a==4){
            this->setCase(10); //Le joueur avance à la case 10 soit la case Huitieme de finale
        }
    }
    else if(map[case_joueur]=="C"){ //Si la case est la case chance
        Carte Chance("Chance"); //On crée un objet Chance
        int a = Chance.Chance(*this,J2); //On lance la fonction Chance
        if(a==0){ //Si la fonction Chance renvoie 0
            cpt++; //On incrémente cpt car le joueur peut rejouer
        }
        else if(a==1){ //Si la fonction Chance renvoie 1
            this->setCase(this->getCase()+3); //Le joueur avance de trois cases
        }
        else if(a==2){ // Si la fonction Chance renvoie 2
           this->setCase(this->getCase()+2); //Le joueur avance de deux cases
           cpt++; //On incrémente cpt car le joueur peut rejouer
        }
      }
    return cpt;
}

void Joueur :: affiche() const
{
    std :: cout << "Joueur : " << nom_joueur  << std :: endl; //On affiche le nom du joueur
    std :: cout << "Case : " << case_joueur << std :: endl; //On affiche la case du joueur
}
