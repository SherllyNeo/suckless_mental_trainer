
#define STATES_AMOUNT 50

struct State {
	char name[50];
	char capital[30];
};
void print_state(struct State state) {
	printf("\nname: %s\ncapital: %s\n",state.name,state.capital);
}
int filter_states(char* user_guess,struct State list[STATES_AMOUNT],int length) {
	for (int i =0;i<length;++i) {
		char* state_name = list[i].name;
		if (strncmp(user_guess,state_name,strlen(state_name)) == 0) {
			/* replace element we need to delete with the last element of the array and decriment the length */
			printf("\nWell done, removing %s from list\n",state_name);
			print_state(list[i]);
			list[i] = list[length-1];
			--length;
		}
}
return length;
}

/* Define states */
struct State states[STATES_AMOUNT] = {
{ "Alabama", "Montgomery"},
        { "Alaska", "Juneau"},
        { "Arizona", "Phoenix"},
        { "Arkansas", "Little Rock"},
        { "California", "Sacramento"},
        { "Colorado", "Denver"},
        { "Connecticut", "Hartford"},
        { "Delaware", "Dover"},
        { "Florida", "Tallahassee"},
        { "Georgia", "Atlanta"},
        { "Hawaii", "Honolulu"},
        { "Idaho", "Boise"},
        { "Illinois", "Springfield"},
        { "Indiana", "Indianapolis"},
        { "Iowa", "Des Moines"},
        { "Kansas", "Topeka"},
        { "Kentucky", "Frankfort"},
        { "Louisiana", "Baton Rouge"},
        { "Maine", "Augusta"},
        { "Maryland", "Annapolis"},
        { "Massachusettes", "Boston"},
        { "Michigan", "Lansing"},
        { "Minnesota", "Saint Paul"},
        { "Mississippi", "Jackson"},
        { "Missouri", "Jefferson State"},
        { "Montana", "Helena"},
        { "Nebraska", "Lincoln"},
        { "Nevada", "Carson State"},
        { "New Hampshire", "Concord"},
        { "New Jersey", "Trenton"},
        { "New Mexico", "Santa Fe"},
        { "New York", "Albany"},
        { "North Carolina", "Raleigh"},
        { "North Dakota", "Bismarck"},
        { "Ohio", "Columbus"},
        { "Oklahoma", "Oklahoma State"},
        { "Oregon", "Salem"},
        { "Pennsylvania", "Harrisburg"},
        { "Rhode Island", "Providence"},
        { "South Carolina", "Columbia"},
        { "South Dakota", "Pierre"},
        { "Tennessee", "Nashville"},
        { "Texas", "Austin"},
        { "Utah", "Salt Lake State"},
        { "Vermont", "Montpelier"},
        { "Virginia", "Richmond"},
        { "Washington", "Olympia"},
        { "West Virginia", "Charleston"},
        { "Wisconsin", "Madison"},
        { "Wyoming", "Cheyenne"},
 };


void state_game() {
char user_input[100];
int length = sizeof(states)/sizeof(states[0]);
int length_after_filter;
while ( length != 0) {
	memset(user_input,'\0',sizeof(user_input));
	get_user_guess:
	printf("\nPlease type in a state name:\n");
	fgets(user_input,sizeof(user_input),stdin);
	length_after_filter = filter_states(user_input,states,length);
	if (length_after_filter == length) {
		printf(ANSI_COLOR_RED "\nNot a state\n" ANSI_COLOR_RESET);
		goto get_user_guess;
	}
	length = length_after_filter;
	for (int i =0;i<length;++i) {
	}
}
	printf(ANSI_COLOR_GREEN "\nWell done you got all the states!\n" ANSI_COLOR_RESET);


}

