/*Copyright(c) 2014 The Paradox Game Converters Project

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE. */


#ifndef EU4COUNTRY_H_
#define EU4COUNTRY_H_



#include "EU4Army.h"
#include "..\Color.h"
#include "..\Date.h"

class EU4Province;
class EU4Relations;
class EU4Loan;
class EU4Leader;


class EU4Country
{
	public:
		EU4Country(Object* obj);

		// Some countries are created by EU4 as placeholders to be filled as the game 
		// progresses (colonial nations in particular). This method returns true if
		// this country is one of these unused countries.
		bool isUnusedCountry() const;

		// Add any additional information available from the specified country file.
		void readFromCommonCountry(const string& fileName, Object*);

		void setLocalisationName(const string& language, const string& name);
		void setLocalisationAdjective(const string& language, const string& adjective);

		void						addProvince(EU4Province*);
		void						addCore(EU4Province*);
		bool						hasModifier(string) const;
		int						hasNationalIdea(string) const;
		bool						hasFlag(string) const ;
		void						resolveRegimentTypes(const RegimentTypeMap& map);
		int						getManufactoryCount() const;
		double					inflationAdjust(double input) const;
		double					getBadboyLimit() const;
		void						eatCountry(EU4Country* target);

		string						getTag()										const { return tag; };
		vector<EU4Province*>		getProvinces()								const { return provinces; };
		vector<EU4Province*>		getCores()									const { return cores; };
		int							getCapital()								const { return capital; };
		int							getNationalFocus()						const { return nationalFocus; };
		string						getTechGroup()								const { return techGroup; };
		string						getPrimaryCulture()						const { return primaryCulture; };
		vector<string>				getAcceptedCultures()					const { return acceptedCultures; };
		string						getCulturalUnion()						const { return culturalUnion; };
		string						getReligion()								const { return religion; };
		double						getScore()									const { return score; };
		double						getCulture()								const { return culture; };
		double						getArmyTradition()						const { return armyTradition; };
		double						getNavyTradition()						const { return navyTradition; };
		double						getStability()								const { return stability; };
		double						getAdmTech()								const { return admTech; };
		double						getDipTech()								const { return dipTech; };
		double						getMilTech()								const { return milTech; };
		double						getEstimatedMonthlyIncome()			const { return estMonthlyIncome; };
		double						getArmyInvestment()						const { return armyInvestment; };
		double						getNavyInvestment()						const { return navyInvestment; };
		double						getCommerceInvestment()					const { return commerceInvestment; };
		double						getIndustryInvestment()					const { return industryInvestment; };
		double						getCultureInvestment()					const { return cultureInvestment; };
		bool							getPossibleDaimyo()						const { return possibleDaimyo; };
		string						getGovernment()							const { return government; };
		vector<EU4Relations*>	getRelations()								const { return relations; };
		vector<EU4Army*>			getArmies()									const { return armies; };
		date							getLastBankrupt()							const { return last_bankrupt; };
		vector<EU4Loan*>			getLoans()									const { return loans; };
		double						getDiplomats()								const { return diplomats; };
		double						getBadboy()									const { return badboy; };
		vector<EU4Leader*>		getLeaders()								const { return leaders; };

		double						getTreasury()								const	{ return inflationAdjust(treasury); };

		string getName() const { return name; }
		string getName(const string& language) const;
		string getAdjective(const string& language) const;
		Color getColor() const { return color; }

	private:
		void							checkIdea(const Object*, const string);
		void							clearProvinces();
		void							clearCores();

		string						tag;
		vector<EU4Province*>		provinces;
		vector<EU4Province*>		cores;
		int							capital;
		int							nationalFocus;
		string						techGroup;
		string						primaryCulture;
		vector<string>				acceptedCultures;
		string						culturalUnion;
		string						religion;
		double						score;
		double						culture;
		double						armyTradition;
		double						navyTradition;
		double						stability;
		double						admTech;
		double						dipTech;
		double						milTech;
		double						estMonthlyIncome;
		double						armyInvestment;
		double						navyInvestment;
		double						commerceInvestment;
		double						industryInvestment;
		double						cultureInvestment;
		map<string, bool>			flags;
		map<string, bool>			modifiers;
		bool							possibleDaimyo;
		vector<EU4Leader*>		leaders;
		string						government;
		vector<EU4Relations*>	relations;
		vector<EU4Army*>			armies; // and navies...
		map<string, int>			nationalIdeas;
		double						treasury;
		date							last_bankrupt;
		vector<EU4Loan*>			loans;
		double						diplomats;
		double						badboy;

		double						legitimacy;
		double						inflation;

		string name;
		string adjective;
		Color color;

		// Localisation attributes
		map<string, string> namesByLanguage;
		map<string, string> adjectivesByLanguage;
};


#endif // EU4COUNTRY_H_