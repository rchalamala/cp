#include "../tasks/FRemovingLeaves.cpp"
#include <ctime>
#include <iostream>
#include <sstream>
#include <vector>

namespace JHelper
{
	struct Test
	{
		std::string input;
		std::string output;
		bool active;
		bool has_output;
	};

	bool check(std::string expected, std::string actual)
	{
		while (!expected.empty() && isspace(*--expected.end()))
			expected.erase(--expected.end());
		while (!actual.empty() && isspace(*--actual.end()))
			actual.erase(--actual.end());
		return expected == actual;
	}
}

int main()
{
    string blue = "\x1B[34m";
    string green = "\x1B[32m";
    string red = "\x1B[31m";
    string yellow = "\x1B[33m";
    string original = "\033[0m";
	std::vector<JHelper::Test> tests{{"4\n8 3\n1 2\n1 5\n7 6\n6 8\n3 1\n6 4\n6 1\n10 3\n1 2\n1 10\n2 3\n1 5\n1 6\n2 4\n7 10\n10 9\n8 10\n7 2\n3 1\n4 5\n3 6\n7 4\n1 2\n1 4\n5 1\n1 2\n2 3\n4 3\n5 3\n", "2\n3\n3\n4\n", true, true},};
	int testID = 0;
	bool allOK = true;
	std::cerr << std::fixed;
	long double maxTime = 0.0L;
	for (const JHelper::Test& test : tests)
	{
		std::cerr << blue << "Test #" << ++testID << original << std::endl;
		std::cerr << blue << "Input:" << std::endl << original << test.input << std::endl;
		std::cerr << blue << "Expected output:" << std::endl << original << (test.has_output ? test.output : yellow + "N/A" + original) << std::endl;
		if (test.active)
		{
			std::istringstream in(test.input);
			std::ostringstream out;
			std::clock_t start = std::clock();
			FRemovingLeaves solver;
		    int n;
in >> n;
for(int i = 0; i < n; ++i) {
	solver.solve(in, out);
}

			std::clock_t finish = std::clock();
			long double currentTime = (finish - start) / CLOCKS_PER_SEC;
			maxTime = std::max(currentTime, maxTime);
			std::cerr << blue << "Actual output:" << std::endl << original << out.str() << std::endl;
			if (test.has_output)
			{
				bool result = JHelper::check(test.output, out.str());
				allOK &= result;
				std::cerr << blue << "Result: " << original << (result ? green + "OK" : red + "Wrong answer") << original << std::endl;
			}
			std::cerr << blue << "Time: " << currentTime << original << std::endl;
		}
		else std::cerr << yellow << "SKIPPED" << original << std::endl;
		std::cerr << std::endl;
	}
	std::cerr << (allOK ? green + "All OK" : red + "Some cases failed") << original << std::endl;
	std::cerr << "Maximal time: " << maxTime << "s." << original << std::endl;
}