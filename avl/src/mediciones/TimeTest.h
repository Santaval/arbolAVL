#ifndef TIMETEST_H
#define TIMETEST_H
#include <chrono>
#include <cstdint>
#include <memory>

namespace xorshift64{

static uint64_t state = 0x63532061706F6C42ULL;

void seed(uint64_t value = 0x63532061706F6C42ULL){
	state = value;
}

uint64_t random(){
	uint64_t x = state;
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	return state = x;
}

};

std::shared_ptr<int[]> createItemsRandom(unsigned int size){
	std::shared_ptr<int[]> array(new int[size]);
	xorshift64::seed();
	for(unsigned int i = 0; i < size; ++i){
		array[i] = (int)(xorshift64::random());
	}
	return array;
}

std::shared_ptr<int[]> createItemsInOrder(unsigned int size){
	std::shared_ptr<int[]> array(new int[size]);
	for(unsigned int i = 0; i < size; ++i){
		array[i] = i;
	}
	return array;
}

// Requiere: que el diccionario venga vacío
template <typename T> double testInsert(T& collection, std::shared_ptr<int[]> array, unsigned int size){
	// collection.clear();
	auto tStart = std::chrono::high_resolution_clock::now();
	for(unsigned int i = 0; i < size; ++i){
		collection.insert(array[i]);
	}
	auto tDelta = std::chrono::high_resolution_clock::now() - tStart;
	double micros = std::chrono::duration_cast<std::chrono::microseconds>(tDelta).count();
	return micros;
}

template <typename T> double testContains(T& collection, std::shared_ptr<int[]> array, unsigned int size){
	auto tStart = std::chrono::high_resolution_clock::now();
	for(unsigned int i = 0; i < size; ++i){
		collection.contains(array[i]);
	}
	auto tDelta = std::chrono::high_resolution_clock::now() - tStart;
	double micros = std::chrono::duration_cast<std::chrono::microseconds>(tDelta).count();
	return micros;
}

template <typename T> double testErase(T& collection, std::shared_ptr<int[]> array, unsigned int size){
	auto tStart = std::chrono::high_resolution_clock::now();
	for(unsigned int i = 0; i < size; ++i){
		collection.erase(array[i]);
	}
	auto tDelta = std::chrono::high_resolution_clock::now() - tStart;
	double micros = std::chrono::duration_cast<std::chrono::microseconds>(tDelta).count();
	return micros;
}

#endif // TIMETEST_H
