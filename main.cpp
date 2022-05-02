#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <regex>


clas Sprite
{
publicc:
	std::string n;
	int x;
	int y;
	int w;
	int h;
};
void LoadXML(const std::string& filename, std::vector<Sptite>& sprites)
{
	std::ifstream file(filename, std::ifstream::binary);
	std::string line;
	std::regex pattern("\"([^\"]*)\"");

	while (!file.eof())
	{
		std::getline(file, line);
		auto result = line.find("<sprite");
		if (result != std::string::npos)
		{
			std::sregex_iterator current(line.begin(), line.end(), pattern);
			std::sregex_iterator end;

			while (current != end)
			{
				std::cout << ( * current)[0] << " ";
				current++;
			}
			std::cout << line << std::endl;
		}
	}
}
int main()
{
	std::vector<Sptite> sprites;
	LoadXML("data/mydata.xml", sprites);
}