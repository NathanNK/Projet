#include "allclasses.hh"
// SFML quand c'est surligner en rouge quickJeu 


Jeu :: Jeu()
{
    map = {{0,"S"}, {1,"N"}, {2,"J"}, {3,"C"}, {4,"E"}, 
          {5,"P"}, {6,"C"}, {7,"E"}, {8,"J"}, {9,"N"}, 
          {10,"8"}, {11,"R"}, {12,"E"}, {13,"N"}, {14,"C"},
          {15,"Q"}, {16,"N"}, {17,"J"}, {18,"B"}, {19,"C"},
          {20,"D"}, {21,"B"}, {22,"N"}, {23,"N"}, {24,"H"},
          {25,"F"},{26,"R"}, {27,"N"}, {28,"B"}, {29,"E"}, 
          {30,"V"}}; 
    // represente la map du jeu contenant toutes les cases dont chaque case est associée à un caractère signifiant son type
}

int Jeu :: Jouer(std::list<Joueur> listeJoueur,std::string J1_pays,std::string J2_pays) const 
{   srand(time(0)); // initialisation de rand
    Rules donnees("\nP : Poule , 8 : 1/8 de finale, Q : Quart de finale , D : Demi finale , F : Finale , V : Victoire\nN : No thing ( Rien ),B : Bye ( Elimination ) , E : Evenement\nS : Start ( Début ) , C : Chance , H : Hors jeu , J : Carton jaune , R : Carton rouge\n");
    int lancede=0; // variable qui permet de savoir si le joueur a lancé le dé ou non
    Map mapjeu(31); // création de la map du jeu
    std::map <int,std :: string> map_en_cours; // map qui va être affichée à chaque tour
    map_en_cours = map; // on initialise la map qui va être affichée à chaque tour avec la map du jeu
    mapjeu.affichegrille(map_en_cours); // affichage de la map du jeu
    int cpt=0; // variable qui permet de savoir si c'est le tour du joueur 1 ou du joueur 2
    int rejouer; // variable qui permet de savoir si le joueur veut rejouer ou non
    Joueur J1 = listeJoueur.front(); // on récupère le premier joueur de la liste
    Joueur J2 = listeJoueur.back(); // on récupère le dernier joueur de la liste
    while((J1.victoire() == 0)&&(J2.victoire() == 0)) // tant que l'un des deux joueurs n'a pas gagné
    {
      lancede=0; // on remet la variable à 0 pour que le joueur puisse relancer le dé
      while((lancede==0)&&(cpt%2==0)){ // tant que le joueur n'a pas lancé le dé et que c'est le tour du joueur 1
        if(cpt%2==0){ // si c'est le tour du joueur 1
            std::cout << J1.getNom()+ ", Veuillez lancer le dé (O : O majuscule ) "; // on demande au joueur 1 de lancer le dé
            std::string reponse; // variable qui va contenir la réponse du joueur 1
            std::cin >> reponse;  // on récupère la réponse du joueur 1
            if (reponse == "O") // si la réponse du joueur 1 est O
            {   donnees.afficherules(); // on affiche les règles du jeu
                int de = rand()%3 +1 ; // on génère un nombre aléatoire entre 1 et 3
                J1.setCase(J1.getCase() + de); // on avance le joueur 1 de de cases
                std::cout << "\n"+J1.getNom()+",votre dé est tombé sur " << de << " !" << std::endl; // on affiche le résultat du dé
                std::cout << "\nVous avançez de " << de << " cases" << " !" << std::endl; // on affiche le nombre de cases que le joueur 1 a avancé
                std::cout << "\nVous êtes sur la case " << J1.getCase() << " ! "; // on affiche la case sur laquelle le joueur 1 est
                int cpt1 = J1.action(map,J2,J1,cpt); // en fonction de la case sur laquelle le joueur 1 est, on lance l'action correspondante
                cpt=cpt1; // on met à jour le compteur
                int case_joueurJ1 = J1.getCase(); // on récupère la case sur laquelle se trouve le joueur 1
                int case_joueurJ2 = J2.getCase();   // on récupère la case sur laquelle se trouve le joueur 2
                map_en_cours = map; // on met à jour la map qui va être affichée à chaque tour
                map_en_cours[case_joueurJ1]="*";  // on met à jour la map qui va être affichée avec le symbole du joueur 1
                map_en_cours[case_joueurJ2]="-";  // on met à jour la map qui va être affichée avec le symbole du joueur 2
                mapjeu.affichegrille(map_en_cours); // on affiche la map
                lancede=1; // on met à jour la variable qui permet de savoir si le joueur a lancé le dé ou non
                cpt++; // on met à jour le compteur
                if(J1.victoire()==1) // si le joueur 1 a gagné
                {
                    std::cout << J1.getNom() + " et son equipe " + J1_pays +")" << " a gagné la coupe du monde !\n" << std::endl;
                    std :: cout << "Voulez vous rejouer ? (1 : Oui , 0 : Non) "; // on demande au joueur s'il veut rejouer
                    std :: cin >> rejouer; // on récupère la réponse du joueur
                    return rejouer; // on retourne la réponse du joueur
                }
            }
        }   
        else
            {
                std::cout << "Veuillez répondre par O " << std::endl; // si la réponse du joueur 1 n'est pas O, on lui demande de répondre par O
                lancede=0;
            }
      }
        lancede=0;
          while((lancede==0)&&(cpt%2==1)){ // si le joueur 2 n'a pas lancé le dé et que c'est son tour
            if(cpt%2==1){ // si c'est le tour du joueur 2
                std::cout << J2.getNom()+ ", Veuillez lancer le dé (O : O majuscule ) "; // on demande au joueur 2 de lancer le dé
                std::string reponse; // variable qui va contenir la réponse du joueur 2
                std::cin >> reponse; // on récupère la réponse du joueur 2
                if (reponse == "O")   // si la réponse du joueur 2 est O
                {   donnees.afficherules(); // on affiche les règles du jeu
                    int de = rand()%3 + 1; // on génère un nombre aléatoire entre 1 et 3
                    J2.setCase(J2.getCase() + de); // on avance le joueur 2 de de cases
                    std::cout << "\nVotre dé est tombé sur " << de << " !" << std::endl; // on affiche le résultat du dé
                    std::cout << "\nVous êtes sur la case " << J2.getCase() << " ! "; // on affiche la case sur laquelle le joueur 2 est
                    int cpt1 = J2.action(map,J1,J2,cpt); // en fonction de la case sur laquelle le joueur 2 est, on lance l'action correspondante
                    cpt=cpt1; // on met à jour le compteur
                    int case_joueurJ1 = J1.getCase(); // on récupère la case sur laquelle se trouve le joueur 1
                    int case_joueurJ2 = J2.getCase(); // on récupère la case sur laquelle se trouve le joueur 2
                    map_en_cours = map; // on met à jour la map qui va être affichée à chaque tour
                    map_en_cours[case_joueurJ1]="*";  // on met à jour la map qui va être affichée avec le symbole du joueur 1
                    map_en_cours[case_joueurJ2]="-";  // on met à jour la map qui va être affichée avec le symbole du joueur 2
                    mapjeu.affichegrille(map_en_cours); // on affiche la map
                    lancede=1; // on met à jour la variable qui permet de savoir si le joueur a lancé le dé ou non
                    cpt++; // on met à jour le compteur
                    if(J2.victoire()==1) // si le joueur 2 a gagné
                    {
                        std::cout << J2.getNom() + " et son equipe " + J2_pays +"" << " a gagné la coupe du monde !\n" << std::endl; // on affiche le nom du joueur 2 et son équipe
                        std :: cout << "Voulez vous rejouer ? (1 : Oui , 0 : Non) "; // on demande au joueur s'il veut rejouer
                        std :: cin >> rejouer;  // on récupère la réponse du joueur
                        return rejouer; // on retourne la réponse du joueur
                    }
                }
                else
                {
                    std::cout << "Veuillez répondre par O " << std::endl; // si la réponse du joueur 2 n'est pas O, on lui demande de répondre par O
                    lancede=0; // on met à jour la variable qui permet de savoir si le joueur a lancé le dé ou non
                }
            }
      }
    }
    return rejouer; // on retourne la réponse du joueur pour savoir s'il veut rejouer ou non
} 