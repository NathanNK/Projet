// Let Catch provide main():
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../allclasses.hh"
#include <iostream>
#include <string>
#include <vector>
#include <list>

TEST_CASE("Création joueurs et Equipes ") // Test de création de joueurs et d'équipes
{
  Joueur J1("Ronaldo", 0); //On crée un joueur
  Joueur J2("Messi", 0);  //On crée un joueur 
  Equipe E1("Zidane",0,11,"France"); //On crée une équipe
  Equipe E2("Iniesta",0,11,"Espagne"); //On crée une équipe

  REQUIRE(J1.getNom() == "Ronaldo"); //On vérifie que le nom du joueur est bien Ronaldo
  REQUIRE(J2.getNom() == "Messi"); //On vérifie que le nom du joueur est bien Messi
  REQUIRE(E1.getPays() == "France"); //On vérifie que le pays de l'équipe est bien France
  REQUIRE(E2.getPays() == "Espagne"); //On vérifie que le pays de l'équipe est bien Espagne

  std::cout << " --------------Joueur et Equipe -----------------" << std::endl;

}

TEST_CASE("2: Joueur et Petites Cases ") // Test de création de joueurs et de petites cases avec leurs effets
{
  Joueur J1("Ronaldo", 5); //On crée un joueur
  PetiteCase CartonJaune(31,"CartonJaune","PetiteCase"); //On crée un objet CartonJaune
  CartonJaune.CartonJaune(J1); //On applique la méthode CartonJaune à J1 donc il ne peut plus avancer
  REQUIRE(J1.getCase()== 5); //On vérifie que J1 n'a pas avancé
  REQUIRE(CartonJaune.getNbCase()==31);  //On vérifie que le nombre de cases est bien 31
  REQUIRE(CartonJaune.getType()=="PetiteCase"); //On vérifie que le type est bien PetiteCase

  std::cout << " --------------Joueur et Evenement -----------------" << std::endl;
}

TEST_CASE("3: Joueur et Victoire")  // Test de création de joueurs et de victoires
{
  Joueur J1("Ronaldo", 32); //On crée un joueur
  Joueur J2("Messi", 4); //On crée un joueur
  REQUIRE(J1.victoire() == 1); //On vérifie que J1 a gagné
  REQUIRE(J2.victoire() == 0); //On vérifie que J2 n'a pas gagné

  std::cout << " --------------Joueur et Victoires -----------------" << std::endl;
}


