#pragma once

#pragma once
#include <vector>
#include <string>
#include <iostream>

class AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string) = 0;
};

