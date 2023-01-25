#include "allclasses.hh"

int main(){
    int jouer=1;
    while(jouer==1){
        Jeu jeu;
        Rules regle("\nBienvenue dans 'The World Cup Board Game' .Ce jeu est un jeu de société se jouant à 2 joueurs.Ci-dessous,vous trouverez une map du jeu.\nChaque case représente une action. Le but du jeu est d'arriver le premier sur la case Victoire (V) mais cela ne sera pas si facile.\nVous lancerez chacun votre tour un dé aléatoirement pour avancer sur la map.\nSur cette map, se passeront de nombreux évenements avant la victoire !\nLe joueur n°1 sera représenté par une étoile '*' sur la map et le joueur n°2 sera représenté par un trait '-'.\nSi vous ne voyez votre symbole sur map à un moment du jeu, pas de panique !\nCela veut sûrement dire que vous êtes à la même case que votre adversaire et qu'il cache donc votre symbole !\nBonne Chance !!!\n");
        regle.afficherules();
        int a=1;
        int b=1;
        std::string J1_pays="Vide";
        std::string J2_pays="Vide";
        std::string J1_nom="Vide";
        std::string J2_nom="Vide";
        Joueur Joueur1(J1_nom,0);
        Joueur Joueur2(J2_nom,0);
        std::list<Joueur> listeJoueur;
        while((a==1)||(b==1)){
            std :: cout << "\nLes 2 joueurs doivent avoir des noms et des pays différents ! Sinon, ils devront rentrer leurs noms et pays à nouveau !\n";
            std :: cout << "\nJoueur 1, veuillez entrer votre nom : ";
            std::cin >> J1_nom;
            std :: cout << "\nJoueur 1, veuillez entrer votre pays : ";
            std::cin >> J1_pays;
            std :: cout << "\nJoueur 2, veuillez entrer votre nom : ";
            std::cin >> J2_nom;
            std :: cout << "\nJoueur 2, veuillez entrer votre pays : ";
            std::cin >> J2_pays;
            Joueur Joueur1(J1_nom,0);
            Joueur Joueur2(J2_nom,0);
            Equipe Equipe1(J1_nom,Joueur1.getCase(),11,J1_pays);
            Equipe Equipe2(J2_nom,Joueur2.getCase(),11,J2_pays);
            a = Equipe1==Equipe2;
            b = Equipe1=Equipe2;
            listeJoueur.push_back(Joueur1);
            listeJoueur.push_back(Joueur2);
        }
            std :: cout << "\nLe match oppose : " << J1_pays << " VS " << J2_pays << " ! Que le partie commence !\n" << std :: endl;
            jouer = jeu.Jouer(listeJoueur,J1_pays,J2_pays);  
    }

    std :: cout << "\nMerci d'avoir joué à 'The World Cup Board Game' ! A bientôt ! " << std :: endl;
    return 0; 
}