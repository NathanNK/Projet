#include "allclasses.hh"

int Carte :: Evenement(Joueur J1,Joueur J2) const {
    srand(time(0)); // pour avoir un nombre aléatoire différent à chaque fois
    J1.setMessage("Case Evenement: ");
    J1.afficheMessage();
    int a = rand()%5; // nombre aléatoire entre 0 et 4
    if(a==0){
        J1.setMessage("Jour de chance pour " +J1.getNom()+" : Vous avancez d'1 case !\n"); // affiche le message
        J1.afficheMessage(); 
    }
    else if(a==1){
        J1.setMessage("Pas de chance pour " +J1.getNom()+" : Vous reculez de 2 cases !\n"); // affiche le message
        J1.afficheMessage();
    }
    else if(a==2){
        J1.setMessage(J1.getNom()+" : Vous reculez de 2 cases mais vous pouvez rejouer !\n"); // affiche le message
        J1.afficheMessage(); 
    }
    else if(a==3){
        J1.setMessage(J1.getNom()+" : Direction les 1/4 de finale , vous allez directement en 1/4 de finale !\n");
        J1.afficheMessage(); // affiche le message
        J1.setCase(15);
    }
    else if(a==4){
        J1.setMessage(J1.getNom()+" : Direction les 1/8 de finale , vous allez directement en 8ème de finale !\n");
        J1.afficheMessage(); // affiche le message
        J1.setCase(10); // change la case du joueur
    }
    return a; // retourne a pour savoir sur quelle evenement le joueur est tombé parmi les 5
}
 

int  Carte :: Chance(Joueur J1, Joueur J2) const {
    srand(time(0)); // pour avoir un nombre aléatoire différent à chaque fois
    J1.setMessage("Case Chance: ");
    J1.afficheMessage(); // affiche le message
    int a = rand()%3; // nombre aléatoire entre 0 et 2
    if(a==0){ // si a = 0
        J1.setMessage("Jour de chance pour " +J1.getNom()+" : Vous jouez 2 fois !\n");
        J1.afficheMessage(); // affiche le message
    }
    else if(a==1){
        J1.setMessage("Jour de chance pour " +J1.getNom()+" : Vous avancez de 3 cases !\n");
        J1.afficheMessage(); // affiche le message
    }
    else if(a==2){
        J1.setMessage("Jour de chance pour " +J1.getNom()+" : Vous avancez de 2 cases et vous pouvez rejouer une 2ème fois !\n");
        J1.afficheMessage(); // affiche le message
    }

    return a; // retourne a pour savoir sur quelle chance le joueur est tombé parmi les 3
}