#include "allclasses.hh"

void Map :: affichegrille(std::map <int,std :: string> map) const // affiche la grille de jeu de façon graphique dans la console
{ 
   
   int i=0;
   std :: cout << "\n";
   for(int a=0;a<12;a++){
    std :: cout << " ---";
   }
   std :: cout << "\n";
   for(int a=0;a<13;a++){
     if(a<=11){
        std :: cout << "| " << map[i] << " ";
        i++;
     }
    else{
        std :: cout << "|";
        }
   }
    std :: cout << "\n";
   for(int a=0;a<12;a++){
    std :: cout << " ---";
   }
    std :: cout << "\n";

   for(int b=0;b<7;b++){
        std :: cout << "                                            ";
        std :: cout << "| " << map[i] <<" |" << std :: endl;
        i++;
        if(b!=6){
            std :: cout << "                                             ";
            std :: cout << "---" << std :: endl;
        }
    }
    std :: cout << "                                            ";
    for(int a=0;a<12;a++){
        std :: cout << " ---";
    }
    std :: cout << "\n";
    std :: cout << "                                            ";
   for(int a=0;a<13;a++){
        std :: cout << "| " << map[i] << " ";
        i++;
   }
    std :: cout << "\n";
    std :: cout << "                                            ";
   for(int a=0;a<12;a++){
        std :: cout << " ---";
   }
    std :: cout << "\n";
    std :: cout << "\n";
    std :: cout << "\n";
}

void Map :: affiche() const{
    std :: cout << "Nombre de cases : " << getNbCase() << std :: endl; // affiche le nombre de cases
}