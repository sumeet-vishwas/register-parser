#include "../include/utils.h"
#include <cctype>
#include <vector>
#include <string>
#include <iostream>

namespace Utils
{

    std::string_view trim(std::string_view sv)
    {

        while (!sv.empty() && std::isspace(static_cast<unsigned char>(sv.front())))
        {
            sv.remove_prefix(1);
        }

        while (!sv.empty() && std::isspace(static_cast<unsigned char>(sv.back())))
        {
            sv.remove_prefix(1);
        }

        return sv;
    }

    std::vector<std::string_view> split(std::string_view sv, const char spliter)
    {
        std::vector<std::string_view> tokens;
        sv = trim(sv);

        std::cout << "--call split" << std::endl;

        while (!sv.empty())
        {
            if (sv.front() == '"')
            {
                // find closing quote
                size_t end = sv.find('"', 1);
                if (end == std::string_view::npos)
                    end = sv.size() - 1;

                std::string_view token = sv.substr(1, end - 1);
                tokens.push_back(token);

                sv.remove_prefix(end + 1);
            }
            else
            {
                size_t pos = sv.find(spliter);

                if (pos == std::string_view::npos)
                {
                    tokens.push_back(sv);
                    break;
                }

                std::string_view token = trim(sv.substr(0, pos));

                if (!token.empty())
                {
                    tokens.push_back(token);
                }

                //std::cout << "-- sv : " << sv << std::endl;
                sv.remove_prefix(pos + 1);
                sv = trim(sv);
            }
        }

        return tokens;
    }

}
