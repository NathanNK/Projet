#include "allclasses.hh"

void Equipe :: affiche() const{
    std :: cout << "Nom de l'équipe : " << getPays() << std :: endl;
    std :: cout << "Numéro de l'équipe : " << getNbJoueur() << std :: endl;
}

