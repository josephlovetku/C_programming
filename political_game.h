/* Headers of political_game.cpp 
 *
 * Enumerate instances of the Two Party Election Game by random sampling 
 * Each party has two candidates. 
 * 
 * The program can check if there is any instance with no pure Nash equilibrium
 * and also compute the worst price of anarchy (PoA) among the instances.
 *
 * Author: Joseph Chuang-Chieh Lin
 * Email: josephcclin@gmail.com
 * Date: 27 November, 2019 (Ver.1), 4 July 2021 (Ver.2)
 */
#ifndef _POLITICAL_GAME_H_
#define _POLITICAL_GAME_H_

using namespace std;

class Candidate { 
friend void SetExpUti(Candidate &, Candidate &);
friend void SetExpUti(Candidate &, Candidate &, std::string type);
public:
	Candidate () { init_uti(); }
	Candidate (int ut1, int ut2): utSup(ut1), utOpp(ut2) {}
	void init_uti();
	void set_uti(int, int, int);
	int get_sup();
	int get_opp();
    	int uti_sum();
	double get_expUti();
	double get_expSW();
	static constexpr int utUB = 1000;
private:
	int utSup;
	int utOpp;
	double expUti;  // expected payoff
    double expSW; // expected social welfare
}; 

struct Party {
	Candidate cand1, cand2;
	void reOrder();
};

struct Game { 
	Party A, B;
	bool egoismCheck(Party &, Party &);
};

bool checkNE(vector<vector<double>> & SocialWelfare); 
double PoA(vector<vector<double>> &SocialWelfare); 
std::tuple<int, int, double> maxSocWel(vector<vector<double>> &maxSocialWelfare); 
std::tuple<int, int, double> worstPNE(vector<vector<double>> &SocialWelfare); 

#endif
