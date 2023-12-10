#include <iostream>
#include <string>

#include "middle_str.h"

int main() {
	bool stop = false;
	int x = 0, y = 0;
	while (!stop) {
		std::string line, p1;
		std::getline(std::cin, line);

		if (line == "000") {
			stop = true;
		}
		else {

			int step = 0;
			bool isFirstPart = true;
			for (int i = 0; line[i] != '\0'; i++) {
				char c = line[i];
				if (c == ' ') {
					isFirstPart = false;
				}
				else {
					if (isFirstPart)
						p1 += c;
					else
						step = step * 10 + charToInt(c);
				}
			}
			if (p1 == "North") y += step;
			else if (p1 == "South") y -= step;
			else if (p1 == "East") x += step;
			else if (p1 == "West") x -= step;
		}
	}

	std::cout << x << " " << y;

	return 0;
}
