#include <stdio.h>
#include <stdlib.h>
#include "depot.h"

void check_depot_size(Depot *depot){
	int cnt = depot_get_stack_count(depot);
	printf("The depot has %d stacks\n", cnt);
}

void add_product(Depot *depot, Product *product){
	depot_push(depot, product);
	printf("Added product #%d to the depot\n", product->serial_no);
}

int main() {
	Product products[] = {
            {1},
            {2},
            {3},
            {4},
            {5},
            {6},
			{7},
			{8}
    };

	Depot *depot = depot_create();
	check_depot_size(depot);

	add_product(depot, &products[0]);
	check_depot_size(depot);
	add_product(depot, &products[1]);
	check_depot_size(depot);
	add_product(depot, &products[2]);
	check_depot_size(depot);
	add_product(depot, &products[3]);
	check_depot_size(depot);
	add_product(depot, &products[4]);
	check_depot_size(depot);
	add_product(depot, &products[5]);
	check_depot_size(depot);
	add_product(depot, &products[6]);
	check_depot_size(depot);

	for (int i = 0; i < 8; i++){
		Product *product = depot_pop(depot);
		printf("In retrieval step %d we got product #%d\n", i+1, product->serial_no);
		check_depot_size(depot);
		if (i == 3){
			add_product(depot, &products[7]);
			check_depot_size(depot);
		}
	}	

	depot_delete(depot);
}
