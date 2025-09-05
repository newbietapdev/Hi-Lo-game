#ifndef RANDOM_MT_H
#define RANDOM_MT_H //mersenne twisted pseudo_random number generator
#include <random> //for std::19937 and std::seed_seq
#include <chrono> //for system clock and std::random_device
namespace Random
{
	//inline keyword with purpose prevent ODR (one_definition_rule) violation for add this header more than one files
	std::random_device rd{};
	inline std::mt19937 generate() //seeding
	{
		//static_cast with purpose cast to 32bit unsigned int
		//because system clock has 64bit that's a reason ss should be cast to 32bit unsigned int
		std::seed_seq ss{ static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
			rd(), rd(), rd(), rd(), rd() }; //5times rd for random_device 5 times
		return std::mt19937{ ss }; //std::mt19937 return a value, conversely std::seed_seq none
	}
	inline std::mt19937 mt{generate()}; //mt has already seeded with generate() intializer above
	//create random number generator with uniform distribution
	inline int get(int min, int max) 
	{
		return std::uniform_int_distribution{ min, max }(mt); //(mt) for generator above seeded with system clock and std::random_device 5 times
	}

	// Generate a random value between [min, max] (inclusive)
	// * min and max must have the same type
	// * return value has same type as min and max
	// * Supported types:
	// *    short, int, long, long long
	// *    unsigned short, unsigned int, unsigned long, or unsigned long long
	// Sample call: Random::get(1L, 6L);             // returns long
	// Sample call: Random::get(1u, 6u);             // returns unsigned int
	template <typename T>
	T get(T min, T max)
	{
		return std::uniform_int_distribution<T>{min, max}(mt);
	}

	// Generate a random value between [min, max] (inclusive)
	// * min and max can have different types
		// * return type must be explicitly specified as a template argument
	// * min and max will be converted to the return type
	// Sample call: Random::get<std::size_t>(0, 6);  // returns std::size_t
	// Sample call: Random::get<std::size_t>(0, 6u); // returns std::size_t
	// Sample call: Random::get<std::int>(0, 6u);    // returns int
	template <typename R, typename S, typename T>
	R get(S min, T max)
	{
		return get<R>(static_cast<R>(min), static_cast<R>(max));
	}
}


#endif
