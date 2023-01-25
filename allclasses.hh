#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <time.h>

class Rules{ // classe qui contient les règles du jeu
    public:
        Rules(std::string rules); // constructeur
        void afficherules() const; // affiche les règles du jeu
        std::string getRules() const {return rules;} // retourne les règles du jeu
    private:
        std::string rules; // règles du jeu
};

class Joueur{ // classe qui contient les informations du joueur

    static int CartonJauneJ1;
    static int CartonJauneJ2;

    public:
        Joueur(std::string nom,  int case_actuelle): nom_joueur(nom),case_joueur(case_actuelle){} // constructeur
        virtual void affiche() const; // affiche les informations du joueur avec l'utilisation du virtual
        std :: string getNom() const {return nom_joueur;} // retourne le nom du joueur
        int getCase() const {return case_joueur;} // retourne la case du joueur
        int victoire() const; // retourne 1 si le joueur a gagné
        void setCase(int case_actuelle) {case_joueur = case_actuelle;}  // modifie la case du joueur
        int action(std :: map <int,std :: string> map,Joueur J2,Joueur J1,int cpt); // realise l'action de la case
        void setMessage( std :: string message) {this->message = message;} // modifie le message du joueur
        void afficheMessage() const {std::cout << message;} // affiche le message du joueur
        int getCartonJauneJ1() const {return CartonJauneJ1;} // retourne le nombre de carton jaune du joueur 1
        int getCartonJauneJ2() const {return CartonJauneJ2;} // retourne le nombre de carton jaune du joueur 2

    private:
        std::string nom_joueur; // nom du joueur
        int case_joueur; // case du joueur
        std :: string message; // message du joueur

};

class Equipe : public Joueur{ // classe qui contient les informations de l'équipe
    public:
        Equipe(std::string nom, int case_actuelle, int nb_joueur,std::string nom_pays): Joueur(nom, case_actuelle), nb_joueur(nb_joueur),pays(nom_pays){} // constructeur
        void affiche() const; // affiche les informations de l'équipe
        int getNbJoueur() const {return nb_joueur;} // retourne le nombre de joueur de l'équipe
        std::string getPays() const {return pays;} // retourne le nom du pays de l'équipe
        int operator==(const Equipe& J) const { // surcharge de l'opérateur ==
            if (this->getNom() == J.getNom()){
                return 1;
            }
            else{
                return 0;
            }
        }

        int operator=(const Equipe& J1) const { // surcharge de l'opérateur =
            if (this->getPays() == J1.getPays()){
                return 1;
            }
            else{
                return 0;
            }
        } 

    private:
        int nb_joueur; // nombre de joueur de l'équipe
        std::string pays; // nom du pays de l'équipe
};

class Jeu { // classe qui contient les informations du jeu

    public:
        Jeu(); // constructeur
        int Jouer(std::list<Joueur> listeJoueur,std::string J1_pays,std::string J2_pays) const; // fonction qui permet de jouer
        std :: map <int,std :: string> getMap() const {return map;} // retourne la map du jeu
    private:
        std::map <int,std :: string> map; // map du jeu
};

class Carte { // classe qui contient les informations des cartes
    public:
        Carte(std::string action):action(action){} // constructeur
        std::string getAction() const {return action;} // retourne l'action de la carte
        int Chance(Joueur J1,Joueur J2) const; // fonction qui permet de jouer une carte chance
        int Evenement(Joueur J1,Joueur J2) const; // fonction qui permet de jouer une carte evenement
    private:
        std::string action; // action de la carte
};

class Map{ // classe qui contient les informations de la map
    public:
        Map(int nb_case): nb_case(nb_case){} // constructeur
        void affichegrille(std::map <int,std :: string> map) const; // affiche la map
        int getNbCase() const {return nb_case;} // retourne le nombre de case de la map
        virtual void affiche() const; // affiche les informations de la map avec l'utilisation du virtual
    private:
        int nb_case; // nombre de case de la map
};

class Case : public Map{ // classe qui contient les informations des cases
    public:
        Case(int nb_case,std::string nom_case): Map(nb_case),nom_case(nom_case){} // constructeur
        void affiche() const; // affiche les informations de la case
        std::string getNomCase() const {return nom_case;} // retourne le nom de la case
    private:
        std::string nom_case; // nom de la case
};

class Palier : public Case{ // classe qui contient les informations des paliers
    public:
        Palier(int nb_case,std::string nom_case, std::string type): Case(nb_case ,nom_case), type_case(type){}
        void Poule(Joueur J1) const; // Le joueur J1 est au palier des poules
        void Huitieme(Joueur J1) const; // Le joueur J1 est au palier des huitiemes
        void Quart(Joueur J1) const; // Le joueur J1 est au palier des quarts
        void Demi(Joueur J1) const; // Le joueur J1 est au palier des demi
        void Finale(Joueur J1) const; // Le joueur J1 est au palier des finales
        std::string getType() const {return type_case;} // retourne le type de la case
        void affiche() const; // affiche les informations du palier
    private:
        std::string type_case;
};

class PetiteCase : public Case{ // classe qui contient les informations des petites cases ---> Petite Case = Cases qui ne sont pas des paliers
    public:
        PetiteCase(int nb_case,std::string nom_case, std::string type): Case(nb_case,nom_case), type_case(type){} // constructeur
        void affiche() const; // affiche les informations de la petite case
        std::string getType() const {return type_case;} // retourne le type de la petite case
        void Depart(Joueur J1) const; // Le joueur J1 est sur la petite case depart
        void Rien(Joueur J1) const; // Le joueur J1 est sur la petite case rien
        void Elimination(Joueur J1) const; // Le joueur J1 est sur la petite case elimination
        void CartonJaune(Joueur J1) const; // Le joueur J1 est sur la petite case carton jaune
        void CartonRouge(Joueur J1) const; // Le joueur J1 est sur la petite case carton rouge
        void HorsJeu(Joueur J1) const; // Le joueur J1 est sur la petite case hors jeu
    private:
        std ::string type_case; // type de la petite case
};






	
