
#define ELEMENTS_AMOUNT 118

struct Element {
	char name[50];
	int atomic_number;
	float atomic_mass;
};
void print_element(struct Element element) {
	printf("\nname: %s\natomic number: %d\natomic mass: %f\n",element.name,element.atomic_number,element.atomic_mass);
}
int filter_elements(char* user_guess,struct Element list[ELEMENTS_AMOUNT],int length) {
	for (int i =0;i<length;++i) {
		char* element_name = list[i].name;
		if (strncmp(user_guess,element_name,strlen(element_name)) == 0) {
			/* replace element we need to delete with the last element of the array and decriment the length */
			printf("\nWell done, removing %s from list\n",element_name);
			print_element(list[i]);
			list[i] = list[length-1];
			--length;
		}
}
return length;
}

/* Define elements */
struct Element elements[118] = {
  {"Hydrogen", 1, 1.0079},
  {"Helium", 2, 4.00260},
  {"Lithium", 3, 6.941},
  {"Beryllium", 4, 9.01218},
  {"Boron", 5, 10.81},
  {"Carbon", 6, 12.011},
  {"Nitrogen", 7, 14.0067},
  {"Oxygen", 8, 15.9994},
  {"Fluorine", 9, 18.998403},
  {"Neon", 10, 20.179},
  {"Sodium", 11, 22.98977},
  {"Magnesium", 12, 24.305},
  {"Aluminum", 13, 26.98154},
  {"Silicon", 14, 28.0855},
  {"Phosphorus", 15, 30.97376},
  {"Sulfur", 16, 32.06},
  {"Chlorine", 17, 35.453},
  {"Potassium", 18, 39.0983},
  {"Argon", 19, 39.948},
  {"Calcium", 20, 40.08},
  {"Scandium", 21, 44.9559},
  {"Titanium", 22, 47.90},
  {"Vanadium", 23, 50.9415},
  {"Chromium", 24, 51.996},
  {"Manganese", 25, 54.9380},
  {"Iron", 26, 55.847},
  {"Cobalt", 27, 58.9332},
  {"Nickel", 28, 58.70},
  {"Copper", 29, 63.546},
  {"Zinc", 30, 65.38},
  {"Gallium", 31, 69.72},
  {"Germanium", 32, 72.59},
  {"Arsenic", 33, 74.9216},
  {"Selenium", 34, 78.96},
  {"Bromine", 35, 79.904},
  {"Krypton", 36, 83.80},
  {"Rubidium", 37, 85.4678},
  {"Strontium", 38, 87.62},
  {"Yttrium", 39, 88.9059},
  {"Zirconium", 40, 91.22},
  {"Niobium", 41, 92.9064},
  {"Molybdenum", 42, 95.94},
  {"Technetium", 43, 98},
  {"Ruthenium", 44, 101.07},
  {"Rhodium", 45, 102.9055},
  {"Palladium", 46, 106.4},
  {"Silver", 47, 107.868},
  {"Cadmium", 48, 112.41},
  {"Indium", 49, 114.82},
  {"Tin", 50, 118.69},
  {"Antimony", 51, 121.75},
  {"Iodine", 52, 126.9045},
  {"Tellurium", 53, 127.60},
  {"Xenon", 54, 131.30},
  {"Cesium", 55, 132.9054},
  {"Barium", 56, 137.33},
  {"Lanthanum", 57, 138.9055},
  {"Cerium", 58, 140.12},
  {"Praseodymium", 59, 140.9077},
  {"Neodymium", 60, 144.24},
  {"Promethium", 61, 145},
  {"Samarium", 62, 150.4},
  {"Europium", 63, 151.96},
  {"Gadolinium", 64, 157.25},
  {"Terbium", 65, 158.9254},
  {"Dysprosium", 66, 162.50},
  {"Holmium", 67, 164.9304},
  {"Erbium", 68, 167.26},
  {"Thulium", 69, 168.9342},
  {"Ytterbium", 70, 173.04},
  {"Lutetium", 71, 174.967},
  {"Hafnium", 72, 178.49},
  {"Tantalum", 73, 180.9479},
  {"Tungsten", 74, 183.85},
  {"Rhenium", 75, 186.207},
  {"Osmium", 76, 190.2},
  {"Iridium", 77, 192.22},
  {"Platinum", 78, 195.09},
  {"Gold", 79, 196.9665},
  {"Mercury", 80, 200.59},
  {"Thallium", 81, 204.37},
  {"Lead", 82, 207.2},
  {"Bismuth", 83, 208.9804},
  {"Polonium", 84, 209},
  {"Astatine", 85, 210},
  {"Radon", 86, 222},
  {"Francium", 87, 223},
  {"Radium", 88, 226.0254},
  {"Actinium", 89, 227.0278},
  {"Thorium", 90, 232.0381},
  {"Protactinium", 91, 231.0381},
  {"Uranium", 92, 238.029},
  {"Neptunium", 93, 237.0482},
  {"Plutonium", 94, 242},
  {"Americium", 95, 243},
  {"Curium", 96, 247},
  {"Berkelium", 97, 247},
  {"Californium", 98, 251},
  {"Einsteinium", 99, 252},
  {"Fermium", 100, 257},
  {"Mendelevium", 101, 258},
  {"Nobelium", 102, 259},
  {"Lawrencium", 103, 262},
  {"Rutherfordium", 104, 267},
  {"Dubnium", 105, 262},
  {"Seaborgium", 106, 269},
  {"Bohrium", 107, 264},
  {"Hassium", 108, 269},
  {"Meitnerium", 109, 278},
  {"Darmstadtium", 110, 281},
  {"Roentgenium", 111, 282},
  {"Copernicium", 112, 285},
  {"Nihonium", 113, 286},
  {"Flerovium", 114, 289},
  {"Moscovium", 115, 289},
  {"Livermorium", 116, 293},
  {"Tennessine", 117, 294},
  {"Oganesson", 118, 294}
 };


void elements_game() {
char user_input[100];
int length = sizeof(elements)/sizeof(elements[0]);
int length_after_filter;
while ( length != 0) {
	memset(user_input,'\0',sizeof(user_input));
	get_user_guess:
	printf("\nPlease type in a element name:\n");
	fgets(user_input,sizeof(user_input),stdin);
	length_after_filter = filter_elements(user_input,elements,length);
	if (length_after_filter == length) {
		printf(ANSI_COLOR_RED "\nNot an element\n" ANSI_COLOR_RESET);
		goto get_user_guess;
	}
	length = length_after_filter;
	for (int i =0;i<length;++i) {
	}
}
	printf(ANSI_COLOR_GREEN "\nWell done you got all the elements!\n" ANSI_COLOR_RESET);


}

