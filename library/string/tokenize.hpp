#ifndef TOKENIZE_HPP
#define TOKENIZE_HPP

#include <algorithm>
#include <regex>
#include <string>
#include <vector>

std::vector<std::string> tokenize(const std::string& input, const std::regex& pattern = std::regex{R"([\\s|\\h|,]+)"})
{
	std::vector<std::string> tokens{std::sregex_token_iterator{input.begin(), input.end(), pattern, -1}, {}};
	tokens.erase(std::remove_if(tokens.begin(), tokens.end(), [](const std::string& token) -> bool
	{ return token.size() == 0; }), tokens.end());
	return tokens;
}

#endif