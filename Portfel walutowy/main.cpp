#include"menu.h"
#include"portfel.h"

int main() {

	portfel moj_portfel(1000, 0, 0, 0, 0);
	int zdarzenia = 0;
	menu<portfel>::MENU(moj_portfel);
}