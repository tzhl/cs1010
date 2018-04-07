// CS1010 Programming Methodology
// Problem Set 1 Exercise #22: packing.c
//
// <Replace this with a short program description>
//
//
// Tee Zhen Lee   A0170711R

#include <stdio.h>


int area_used(int tray_size[],int slab_size[]);


int main(void) {

	int size_tray[2],size_slab[2], unused_area;

	printf("Enter size of tray: ");
	scanf("%d%d", &size_tray[0], &size_tray[1]);

	printf("Enter size of slab: ");
	scanf("%d%d", &size_slab[0], &size_slab[1]);

	unused_area = size_tray[0] * size_tray[1] - area_used( size_tray, size_slab);

	printf("Minimum unused area = %d\n", unused_area);

	return 0;
}

int area_used(int tray_size[],int slab_size[])
{
	int area=0, temp, orient=0;

	//check the 2 orientation of slab, potrait and landscape
	//the maximum area covered by slab is returned
	while(orient<2)   
	{

		temp = ( tray_size[0] / slab_size[orient % 2] )* slab_size[orient % 2];
		temp *= ( tray_size[1] / slab_size[(orient + 1) % 2] )* slab_size[(orient + 1) % 2];

		if (temp>area)
			area=temp;

		orient ++;
	}
	return area;
}

