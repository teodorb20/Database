#include "System.h"

int System::findMatrixId(std::vector<Matrix> vec, const char* m_name)
{
	for (int i = 0; i < vec.size(); i++) {
		if (strcmp(m_name, vec[i].name()) == 0)
			return i;
	}

	std::cout << "Table " << '"' << m_name << '"' << " not found." << std::endl;
	return -1;
}

void System::Help()
{
	std::cout << "add <rows> <cols> <name> - create a new table" << std::endl
		<< "import <FileName> - open a table from file" << std::endl
		<< "export <name> <FileName> - save table to a file" << std::endl
		<< "print <name> - print a table with this name" << std::endl
		<< "showtables - print all table names that are loaded" << std::endl
		<< "describe <name> - describe each column type" << std::endl;
}

System& System::i()
{
	static System table;
	return table;
}

void System::run()
{
	std::vector<Matrix> vec;
	char FileName[MAX_FILENAME_SIZE];
	char input[MAX_INPUT_SIZE];
	char m_name[MAX_NAME_SIZE];
	char m_column_type[MAX_TYPE_SIZE];
	char m_column_name[MAX_NAME_SIZE];
	int id;

	do {
		std::cout << ">> ";
		std::cin >> input;
		/*
		** The "add" function added new table
		*/
		if (strcmp(input, "add") == 0) {
			size_t m_rows, m_cols;
			std::cin >> m_rows >> m_cols >> m_name;
			vec.push_back(Matrix(m_rows, m_cols, m_name));
			std::cin >> vec.back();
			std::cout << "Table " << '"' << vec[vec.size() - 1].name() << '"' << " created." << std::endl;
		}
		/*
		** The "import" function open a table from file
		*/
		else if (strcmp(input, "import") == 0) {
			std::cin >> FileName;
			std::ifstream in(FileName, std::ios::in);
			if (!in) {
				std::cout << "Cannot open file!" << std::endl;
			}

			else {
				std::cout << "Loading file from " << FileName << std::endl;
				in >> m_name;
				in >> vec[vec.size() - 1];
				std::cout << "Successfully loaded!" << std::endl;
				std::cout << m_name;
				std::cout << std::endl;
				std::cout << vec[vec.size() - 1];
			}
			in.close();
		}
		/*
		** The "export"function save table to a file
		*/
		else if (strcmp(input, "export") == 0) {
			std::cin >> m_name;
			std::cin >> FileName;

			std::ofstream out(FileName, std::ios::out);
			if (!out) {
				std::cout << "Cannot open file!" << std::endl;
			}
			else {
				std::cout << "Save table to " << FileName << std::endl;
				out << m_name;
				out << std::endl;
				out << vec[vec.size() - 1];
				std::cout << "Successfully saved!" << std::endl;
			}
			out.close();
		}
		/*
		** The "print" function print table after we enter its name
		*/
		else if (strcmp(input, "print") == 0) {
			std::cin >> m_name;
			id = findMatrixId(vec, m_name);
			if (id != -1) {
				std::cout << vec[id];
			}
		}
		/*
		** The "showtables" function print all table names that are loaded
		*/
		else if (strcmp(input, "showtables") == 0) {
			id = findMatrixId(vec, m_name);
			if (id != -1) {
				for (int i = 0; i < vec.size(); i++) {
					std::cout << vec[i].name() << std::endl;
				}
			}
		}
		/*
		** The "describe" function describes each column type
		*/
		else if (strcmp(input, "describe") == 0) {
			size_t m_rows, m_cols;
			std::cin >> m_name;
			id = findMatrixId(vec, m_name);
			if (id != -1) {
				for (int i = 0; i < vec.size(); i++) {
					for (int j = 0; j < vec[vec.size() - 1].cols(); j++) {
						std::cout << "Column " << j << " is type int." << std::endl;
					}

				}
			}
		}
		else if (strcmp(input, "help") == 0) {
			Help();
		}
		else {
			std::cout << "Unknown command!" << std::endl;
		}

	}

	while (strcmp(input, "exit") != 0);
	std::cout << "Bye!" << std::endl;
}
