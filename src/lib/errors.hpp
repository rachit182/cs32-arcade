#ifndef ERRORS_HPP
#define ERRORS_HPP

#include <exception>


class Collision: public std::exception{

};
class LevelOver: public std::exception{

};

#endif //ERRORS_HPP