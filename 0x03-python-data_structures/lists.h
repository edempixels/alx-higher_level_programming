#ifndef LISTS_H
#define LISTS_H

void print_list_integer(int *my_list, size_t size);
int element_at(int *my_list, int idx);
void replace_in_list(int *my_list, int idx, int element);
void print_reversed_list_integer(int *my_list, size_t size);
int *new_in_list(int *my_list, int idx, int element);
void print_matrix_integer(int **matrix, size_t rows, size_t columns);


#endif /* LISTS_H */
