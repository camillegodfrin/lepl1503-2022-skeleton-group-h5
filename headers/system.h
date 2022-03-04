#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdint.h>

typedef struct
{
    // TODO
} system_t;

/**
 *
 * Add two vectors in a Galois Field 256
 * @param symbol_1: the first symbol to add
 * @param symbol_2: the second symbol to add
 * @param symbol_size: size of the two symbols (of the same size!)
 * @return: a new vector of `symbol_size` byte containing the result of symbol_1 + symbol_2 in GF(256)
 */
uint8_t *gf256_add_two_vectors(uint8_t *symbol_1, uint8_t *symbol_2, uint32_t symbol_size);

/**
 *
 * Add two vectors in a Galois Field 256 where the second vector is scaled
 * @param symbol_1: the first symbol to add
 * @param symbol_2: the second symbol to add (the scaled one)
 * @param coef: the coefficient of the scaling
 * @param symbol_size: size of the two symbols (of the same size!)
 * @return: a new vector of `symbol_size` byte containing the result of symbol_1 + symbol_2 * coef in GF(256)
 */
uint8_t *gf256_add_two_vectors_scaled(uint8_t *symbol_1, uint8_t *symbol_2, uint8_t coef, uint32_t symbol_size);

/**
 *
 * Divide a vector in a Galois Field 25§ by a coefficient
 * @param symbol: the symbol to add
 * @param coef: the dividing coefficient
 * @param symbol_size: size of the two symbols (of the same size!)
 * @return: a new vector of `symbol_size` byte containing the result of symbol_1 / coef
 */
uint8_t *gf256_divide_vector_scaled(uint8_t *symbol, uint8_t coef, uint32_t symbol_size);

/**
 *
 * Resolve the linear system Ax=b in a Galois Field 256. The result is stored in the independent terms after the resolution
 * @param A: matrix of coefficients
 * @param b: independent terms
 * @param symbol_size: size of the independent terms
 * @param system_size: the size of the system (i.e., number of rows/columns)
 */
void gf256_gaussian_elimination(uint8_t **A, uint8_t **b, uint32_t symbol_size, uint32_t system_size);

/**
 *
 * Generate all coefficients for a block
 * @param seed: the seed to generate the coefficients
 * @param nss: number of source symbols in a block
 * @param nrs: number of repair symbols in a block
 * @return: a nss * nrs array of coefficients
 */
uint8_t **gen_coef(uint32_t seed, uint32_t nss, uint32_t nrs);

#endif /* SYSTEM_H */