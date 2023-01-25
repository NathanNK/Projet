#include "allclasses.hh"

Rules :: Rules (std :: string rules) {
    this->rules = rules;
}

void Rules :: afficherules () const {
    std :: cout << rules <<  std :: endl;
}