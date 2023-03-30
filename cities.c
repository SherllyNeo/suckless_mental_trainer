
#define CITIES_AMOUNT 74

struct City {
	char name[50];
	char creation_date[30];
};
void print_city(struct City city) {
	printf("\nname: %s\nfounded: %s\n",city.name,city.creation_date);
}
int filter_cities(char* user_guess,struct City list[CITIES_AMOUNT],int length) {
	for (int i =0;i<length;++i) {
		char* city_name = list[i].name;
		if (strncmp(user_guess,city_name,strlen(city_name)) == 0) {
			/* replace element we need to delete with the last element of the array and decriment the length */
			printf("\nWell done, removing %s from list\n",city_name);
			print_city(list[i]);
			list[i] = list[length-1];
			--length;
		}
}
return length;
}

/* Define cities */
struct City cities[CITIES_AMOUNT] = {
	{ "Aberdeen", "1891"},
        { "Armagh", "1994"},
        { "Bangor (County Down)", "2022"},
        { "Bangor (Gwynedd)", "time immemorial"},
        { "Bath", "1090"},
        { "Belfast", "1888"},
        { "Birmingham", "1889"},
        { "Bradford", "1897"},
        { "Brighton & Hove", "2001"},
        { "Bristol", "1542"},
        { "Cambridge", "1951"},
        { "Canterbury", "time immemorial"},
        { "Cardiff", "1905"},
        { "Carlisle", "1133"},
        { "Chelmsford", "2012"},
        { "Chester", "1541"},
        { "Chichester", "1075"},
        { "Colchester", "2022"},
        { "Coventry", "1102"},
        { "Derby", "1977"},
        { "Derry", "1604"},
        { "Doncaster", "2022"},
        { "Dundee", "1889"},
        { "Dunfermline", "2022"},
        { "Durham", "time immemorial"},
        { "Edinburgh", "18th Century"},
        { "Ely", "1109"},
        { "Exeter", "time immemorial"},
        { "Glasgow", "18th Century"},
        { "Gloucester", "1541"},
        { "Hereford", "time immemorial"},
        { "Inverness", "2001"},
        { "Kingston Upon Hull", "1897"},
        { "Lancaster", "1937"},
        { "Leeds", "1893"},
        { "Leicester", "1919"},
        { "Lichfield", "time immemorial"},
        { "Lincoln", "1072"},
        { "Lisburn", "2002"},
        { "Liverpool", "1880"},
        { "London", "time immemorial"},
        { "Manchester", "1853"},
        { "Milton Keynes", "2022"},
        { "Newcastle Upon Tyne", "1882"},
        { "Newport", "2002"},
        { "Norwich", "1094"},
        { "Nottingham", "1897"},
        { "Oxford", "1542"},
        { "Perth", "2012"},
        { "Peterborough", "1541"},
        { "Plymouth", "1928"},
        { "Portsmouth", "1926"},
        { "Preston", "2002"},
        { "Ripon", "1865"},
        { "Salford", "1926"},
        { "Salisbury", "1227"},
        { "Sheffield", "1893"},
        { "Southampton", "1964"},
        { "Southend-on-Sea", "2022"},
        { "St Asaph", "2012"},
        { "St Davids", "1994"},
        { "Stirling", "2002"},
        { "Stoke-on-Trent", "1925"},
        { "Sunderland", "1992"},
        { "Swansea", "1969"},
        { "Truro", "1877"},
        { "Wakefield", "1888"},
        { "Wells", "time immemorial"},
        { "Westminster", "1540"},
        { "Winchester", "time immemorial"},
        { "Wolverhampton", "2001"},
        { "Worcester", "time immemorial"},
        { "Wrexham", "2022"},
        { "York", "time immemorial"},
 };


void city_game() {
char user_input[100];
int length = sizeof(cities)/sizeof(cities[0]);
int length_after_filter;
while ( length != 0) {
	memset(user_input,'\0',sizeof(user_input));
	get_user_guess:
	printf("\nPlease type in a city name:\n");
	fgets(user_input,sizeof(user_input),stdin);
	length_after_filter = filter_cities(user_input,cities,length);
	if (length_after_filter == length) {
		printf(ANSI_COLOR_RED "\nNot a city\n" ANSI_COLOR_RESET);
		goto get_user_guess;
	}
	length = length_after_filter;
	for (int i =0;i<length;++i) {
	}
}
	printf(ANSI_COLOR_GREEN "\nWell done you got all the cities!\n" ANSI_COLOR_RESET);


}

