
#define COUNTRIES_AMOUNT 190

struct Country {
	char name[50];
	char capital[30];
};
void print_country(struct Country country) {
	printf("\nname: %s\ncapital: %s\n",country.name,country.capital);
}
int filter_countries(char* user_guess,struct Country list[COUNTRIES_AMOUNT],int length) {
	for (int i =0;i<length;++i) {
		char* country_name = list[i].name;
		if (strncmp(user_guess,country_name,strlen(country_name)) == 0) {
			/* replace element we need to delete with the last element of the array and decriment the length */
			printf("\nWell done, removing %s from list\n",country_name);
			print_country(list[i]);
			list[i] = list[length-1];
			--length;
		}
}
return length;
}

/* Define countries */
struct Country countries[COUNTRIES_AMOUNT] = {
        { "Afghanistan", "Kabul"},
        { "Albania", "Tirana"},
        { "Algeria", "Algiers"},
        { "Andorra", "Andorra la Vella"},
        { "Angola", "Luanda"},
        { "Antigua and Barbuda", "Saint John's"},
        { "Argentina", "Buenos Aires"},
        { "Armenia", "Yerevan"},
        { "Australia", "Canberra"},
        { "Austria", "Vienna"},
        { "Azerbaijan", "Baku"},
        { "Bahamas", "Nassau"},
        { "Bahrain", "Manama"},
        { "Bangladesh", "Dhaka"},
        { "Barbados", "Bridgetown"},
        { "Belarus", "Minsk"},
        { "Belgium", "Brussels"},
        { "Belize", "Belmopan"},
        { "Benin", "Porto-Novo"},
        { "Bhutan", "Thimphu"},
        { "Bolivia", "Sucre"},
        { "Bosnia and Herzegovina", "Sarajevo"},
        { "Botswana", "Gaborone"},
        { "Brazil", "Brasília"},
        { "Brunei", "Bandar Seri Begawan"},
        { "Bulgaria", "Sofia"},
        { "Burkina Faso", "Ouagadougou"},
        { "Burundi", "Gitega"},
        { "Côte d'Ivoire", "Yamoussoukro"},
        { "Cabo Verde", "Praia"},
        { "Cambodia", "Phnom Penh"},
        { "Cameroon", "Yaoundé"},
        { "Canada", "Ottawa"},
        { "Central African Republic", "Bangui"},
        { "Chad", "N'Djamena"},
        { "Chile", "Santiago"},
        { "China", "City of Victoria"},
        { "Colombia", "Bogotá"},
        { "Comoros", "Moroni"},
        { "Costa Rica", "San José"},
        { "Croatia", "Zagreb"},
        { "Cuba", "Havana"},
        { "Cyprus", "Nicosia"},
        { "Democratic Republic of the Congo", "Kinshasa"},
        { "Denmark", "Copenhagen"},
        { "Djibouti", "Djibouti"},
        { "Dominica", "Santo Domingo"},
        { "Dominican Republic", "Santo Domingo"},
        { "Ecuador", "Quito"},
        { "Egypt", "Cairo"},
        { "El Salvador", "San Salvador"},
        { "Equatorial Guinea", "Malabo"},
        { "Eritrea", "Asmara"},
        { "Estonia", "Tallinn"},
        { "Ethiopia", "Addis Ababa"},
        { "Fiji", "Suva"},
        { "Finland", "Helsinki"},
        { "France", "Paris"},
        { "Gabon", "Libreville"},
        { "Gambia", "Banjul"},
        { "Georgia", "King Edward Point"},
        { "Germany", "Berlin"},
        { "Ghana", "Accra"},
        { "Greece", "Athens"},
        { "Grenada", "St. George's"},
        { "Guatemala", "Guatemala City"},
        { "Guinea", "Malabo"},
        { "Guinea-Bissau", "Bissau"},
        { "Guyana", "Georgetown"},
        { "Haiti", "Port-au-Prince"},
        { "Holy See", "Vatican City"},
        { "Honduras", "Tegucigalpa"},
        { "Hungary", "Budapest"},
        { "Iceland", "Reykjavik"},
        { "India", "New Delhi"},
        { "Indonesia", "Jakarta"},
        { "Iran", "Tehran"},
        { "Iraq", "Baghdad"},
        { "Ireland", "Dublin"},
        { "Israel", "Jerusalem"},
        { "Italy", "Rome"},
        { "Jamaica", "Kingston"},
        { "Japan", "Tokyo"},
        { "Jordan", "Amman"},
        { "Kazakhstan", "Nur-Sultan"},
        { "Kenya", "Nairobi"},
        { "Kiribati", "South Tarawa"},
        { "Kuwait", "Kuwait City"},
        { "Kyrgyzstan", "Bishkek"},
        { "Laos", "Vientiane"},
        { "Latvia", "Riga"},
        { "Lebanon", "Beirut"},
        { "Lesotho", "Maseru"},
        { "Liberia", "Monrovia"},
        { "Libya", "Tripoli"},
        { "Liechtenstein", "Vaduz"},
        { "Lithuania", "Vilnius"},
        { "Luxembourg", "Luxembourg"},
        { "Madagascar", "Antananarivo"},
        { "Malawi", "Lilongwe"},
        { "Malaysia", "Kuala Lumpur"},
        { "Maldives", "Malé"},
        { "Mali", "Mogadishu"},
        { "Malta", "Valletta"},
        { "Marshall Islands", "Majuro"},
        { "Mauritania", "Nouakchott"},
        { "Mauritius", "Port Louis"},
        { "Mexico", "Mexico City"},
        { "Micronesia", "Palikir"},
        { "Moldova", "Chișinău"},
        { "Monaco", "Monaco"},
        { "Mongolia", "Ulan Bator"},
        { "Montenegro", "Podgorica"},
        { "Morocco", "Rabat"},
        { "Mozambique", "Maputo"},
        { "Namibia", "Windhoek"},
        { "Nauru", "Yaren"},
        { "Nepal", "Kathmandu"},
        { "Netherlands", "Amsterdam"},
        { "New Zealand", "Wellington"},
        { "Nicaragua", "Managua"},
        { "Niger", "Niamey"},
        { "Nigeria", "Abuja"},
        { "North Korea", "Pyongyang"},
        { "North Macedonia", "Skopje"},
        { "Norway", "Oslo"},
        { "Oman", "Bucharest"},
        { "Pakistan", "Islamabad"},
        { "Palau", "Ngerulmud"},
        { "Panama", "Panama City"},
        { "Papua New Guinea", "Port Moresby"},
        { "Paraguay", "Asunción"},
        { "Peru", "Lima"},
        { "Philippines", "Manila"},
        { "Poland", "Warsaw"},
        { "Portugal", "Lisbon"},
        { "Qatar", "Doha"},
        { "Romania", "Bucharest"},
        { "Russia", "Moscow"},
        { "Rwanda", "Kigali"},
        { "Saint Kitts and Nevis", "Basseterre"},
        { "Saint Lucia", "Castries"},
        { "Saint Vincent and the Grenadines", "Kingstown"},
        { "Samoa", "Pago Pago"},
        { "San Marino", "City of San Marino"},
        { "Sao Tome and Principe", "São Tomé"},
        { "Saudi Arabia", "Riyadh"},
        { "Senegal", "Dakar"},
        { "Serbia", "Belgrade"},
        { "Seychelles", "Victoria"},
        { "Sierra Leone", "Freetown"},
        { "Singapore", "Singapore"},
        { "Slovakia", "Bratislava"},
        { "Slovenia", "Ljubljana"},
        { "Solomon Islands", "Honiara"},
        { "Somalia", "Mogadishu"},
        { "South Africa", "Pretoria"},
        { "South Korea", "Seoul"},
        { "South Sudan", "Juba"},
        { "Spain", "Madrid"},
        { "Sri Lanka", "Sri Jayawardenepura Kotte"},
        { "Sudan", "Khartoum"},
        { "Suriname", "Paramaribo"},
        { "Sweden", "Stockholm"},
        { "Switzerland", "Bern"},
        { "Syria", "Damascus"},
        { "Tajikistan", "Dushanbe"},
        { "Tanzania", "Dodoma"},
        { "Thailand", "Bangkok"},
        { "Timor-Leste", "Dili"},
        { "Togo", "Lomé"},
        { "Tonga", "Nuku'alofa"},
        { "Trinidad and Tobago", "Port of Spain"},
        { "Tunisia", "Tunis"},
        { "Turkey", "Ankara"},
        { "Turkmenistan", "Ashgabat"},
        { "Tuvalu", "Funafuti"},
        { "Uganda", "Kampala"},
        { "Ukraine", "Kyiv"},
        { "United Arab Emirates", "Abu Dhabi"},
        { "United Kingdom", "London"},
        { "United States of America", "Washington, D.C."},
        { "Uruguay", "Montevideo"},
        { "Uzbekistan", "Tashkent"},
        { "Vanuatu", "Port Vila"},
        { "Venezuela", "Caracas"},
        { "Vietnam", "Hanoi"},
        { "Yemen", "Sana'a"},
        { "Zambia", "Lusaka"},
        { "Zimbabwe", "Harare"}
 };


void country_game() {
char user_input[100];
int length = sizeof(countries)/sizeof(countries[0]);
int og_length = sizeof(countries)/sizeof(countries[0]);
int length_after_filter;
while ( length != 0) {
	memset(user_input,'\0',sizeof(user_input));
	get_user_guess:
	printf("\nPlease type in a country name:\n");
	fgets(user_input,sizeof(user_input),stdin);
	length_after_filter = filter_countries(user_input,countries,length);
	if (length_after_filter == length) {
		printf(ANSI_COLOR_RED "\nNot a country\n" ANSI_COLOR_RESET);
		goto get_user_guess;
	}
	length = length_after_filter;
	printf("\nyou have done %d/%d\n",og_length-length,og_length);
}
	printf(ANSI_COLOR_GREEN "\nWell done you got all the countries!\n" ANSI_COLOR_RESET);


}

