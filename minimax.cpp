#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void ispisiPolje(vector<char> &polje){
  for (int i = 0; i < 9; ++i){
    cout << polje[i] << " ";
    if (i % 3 == 2) cout << "\n";
  }
  cout << "\n";
}

int eval(vector<char> &polje){
  for (int i = 0; i < 9; i+=3){
    if (polje[i] != '-' && polje[i] == polje[i+1] && polje[i] == polje[i+2]) return polje[i] == 'X' ? 1 : -1;
  }
  for (int i = 0; i < 9; ++i){
    if (polje[i] != '-' && polje[i] == polje[i+3] && polje[i] == polje[i+6]) return polje[i] == 'X' ? 1 : -1;
  }
  if (polje[0] != '-' && polje[0] == polje[4] && polje[0] == polje[8]) return polje[0] == 'X' ? 1 : -1;
  if (polje[2] != '-' && polje[2] == polje[4] && polje[2] == polje[6]) return polje[2] == 'X' ? 1 : -1;
  return 0;
}

int minimax(vector<char> &polje, bool max_igrac, int alpha=-2, int beta=2){
  int vrijednost = eval(polje);
  if (vrijednost == 1 || vrijednost == -1) return vrijednost;
  if (vrijednost == 0 && count(polje.begin(), polje.end(), '-') == 0) return 0;
  if (max_igrac){
    for (int i = 0; i < 9; ++i){
      if (polje[i] == '-'){
        polje[i] = 'X';
        alpha = max(alpha, minimax(polje, false, alpha, beta));
        polje[i] = '-';
        if (alpha >= beta) break;
      }
    }
    return alpha;
  }
  else{
    for (int i = 0; i < 9; ++i){
      if (polje[i] == '-'){
        polje[i] = 'O';
        beta = min(beta, minimax(polje, true, alpha, beta));
        polje[i] = '-';
        if (alpha >= beta) break;
      }
    }
    return beta;
  }
}

int najboljiPotez(vector<char> &polje, char znak){
  int trenutna_vrijednost, pozicija = -1;
  bool max_igrac;
  (znak == 'X') ? max_igrac = false : max_igrac = true;
  (znak == 'X') ? trenutna_vrijednost = -2 : trenutna_vrijednost = 2;
  for (int i = 0; i < 9; ++i){
    if (polje[i] == '-'){
      polje[i] = znak;
      int vrijednost = minimax(polje, max_igrac);
      polje[i] = '-';
      if (znak == 'X' && vrijednost > trenutna_vrijednost){
        trenutna_vrijednost = vrijednost;
        pozicija = i;
      }
      else if (znak == 'O' && vrijednost < trenutna_vrijednost){
        trenutna_vrijednost = vrijednost;
        pozicija = i;
      }
    }
  }
  return pozicija;
}

bool krajIgre(vector<char> &polje, int &vrijednost){
  int trenutna_vrijednost = eval(polje);
  if (trenutna_vrijednost == 1 || trenutna_vrijednost == -1){
    vrijednost = trenutna_vrijednost;
    return true;
  }
  if (trenutna_vrijednost == 0 && count(polje.begin(), polje.end(), '-') == 0){
    vrijednost = 0;
    return true;
  }
  return false;
}

int main(){
  vector<char> polje(9, '-');
  int vrijednost, pozicija;
  char znak_igraca, znak_racunala;
  cout << "Odaberite krizic(X) ili kruzic(O): ";
  cin >> znak_igraca;
  (znak_igraca == 'X') ? znak_racunala = 'O' : znak_racunala = 'X';
  while(!krajIgre(polje, vrijednost)){
    if (znak_igraca == 'X'){
      ispisiPolje(polje);
      cout << "Na potezu igrac O: ";
      pozicija = najboljiPotez(polje, 'O');
      cout << pozicija << "\n";
      polje[pozicija] = 'O';
      if (krajIgre(polje, vrijednost)) break;
      
      ispisiPolje(polje);
      cout << "Na potezu igrac X: ";
      cin >> pozicija;
      polje[pozicija] = 'X';
      if (krajIgre(polje, vrijednost)) break;
    }
    else{
      ispisiPolje(polje);
      cout << "Na potezu igrac O: ";
      cin >> pozicija;
      polje[pozicija] = 'O';
      if (krajIgre(polje, vrijednost)) break;

      ispisiPolje(polje);
      cout << "Na potezu igrac X: ";
      pozicija = najboljiPotez(polje, 'X');
      cout << pozicija << "\n";
      polje[pozicija] = 'X';
      if (krajIgre(polje, vrijednost)) break;
    }
  }
  ispisiPolje(polje);
  if(vrijednost == 0) cout << "Nerijeseno." << "\n";
  else cout << "Pobijedio je " << (vrijednost == 1 ? 'X' : 'O') << "\n";
  return 0;
}
