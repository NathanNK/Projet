#include "allclasses.hh"

void PetiteCase :: Depart(Joueur J1) const {
    J1.setMessage("Case Départ : " +J1.getNom() +" est à la case départ !\n");
    J1.afficheMessage(); // affiche le message
}
void PetiteCase :: Rien(Joueur J1) const {
    J1.setMessage("Case Rien : " +J1.getNom() +", vous êtes sur une case neutre !\n");
    J1.afficheMessage(); // affiche le message
}

void PetiteCase :: CartonJaune(Joueur J1) const {
    J1.setMessage("Case Carton Jaune : " +J1.getNom() +" reçoit un carton jaune ! Attention !\n");
    J1.afficheMessage(); // affiche le message
}

void PetiteCase :: CartonRouge(Joueur J1) const {
    J1.setCase(J1.getCase()-2); // recule de 2 cases
    J1.setMessage("Case Carton Rouge : " +J1.getNom() +" reçoit un carton rouge ! Vos reculez de 2 cases !\n");
    J1.afficheMessage(); // affiche le message
}

void PetiteCase :: Elimination(Joueur J1) const {
    J1.setCase(0); // retourne à la case départ
    J1.setMessage("Case Elimination : "+J1.getNom() +" est éliminé ! Retour à la case départ !\n");
    J1.afficheMessage(); // affiche le message
}

void PetiteCase :: HorsJeu(Joueur J1) const {
    J1.setCase(J1.getCase()-1); // recule d'une case
    J1.setMessage("Case Hors-Jeu : " +J1.getNom()+" est hors-jeu ! Veuillez reculer d'une case !\n");
    J1.afficheMessage(); // affiche le message
}

void PetiteCase :: affiche() const{ // affiche le type de la case
    std :: cout << getType() << std :: endl;
}