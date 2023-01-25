#include "allclasses.hh"

void Palier :: Finale(Joueur J1) const {
    J1.setMessage("Case Finale : " +J1.getNom() +" est en finale !\n");
    J1.afficheMessage();
}

void Palier :: Quart(Joueur J1) const {
    J1.setMessage("Case Quart de Finale : " +J1.getNom() +" est en 1/4 de finale !\n");
    J1.afficheMessage();
}

void Palier :: Huitieme(Joueur J1) const {
    J1.setMessage("Case Huitieme de Finale : " +J1.getNom() +" est en 1/8 de finale !\n");
    J1.afficheMessage();
}

void Palier :: Demi(Joueur J1) const {
    J1.setMessage("Case Demi-Finale : " +J1.getNom() +" est en 1/2 finale !\n");
    J1.afficheMessage();
}

void Palier :: Poule(Joueur J1) const {
    J1.setMessage("Case Poules de qualification : " +J1.getNom() +" est en poule de qualification !\n");
    J1.afficheMessage();
}

void Palier :: affiche() const {
    std :: cout << getType() << std :: endl;
}