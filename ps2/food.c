// CS1010E Programming Methodology
// Problem Set 2 Exercise #30: food.c
//
// <Replace this with a short program description>
//
//
// <Replace this with your name>

#include <stdio.h>

void best_combination(int budget, int ff_cost, int hf_cost,
		int *final_ff_num, int *final_hf_num);

int main(void) {

   int budget,ff_cost,hf_cost,final_ff_num,final_hf_num;
	printf("Enter budget: $");
   scanf("%d",&budget);
	printf("Enter fast-food cost per meal: $");
	scanf("%d",&ff_cost);
	printf("Enter health-food cost per meal: $");
   scanf("%d",&hf_cost);

   best_combination(budget,ff_cost,hf_cost,&final_ff_num,&final_hf_num);
	printf("Number of fast-food meals = %d\n",final_ff_num);
	printf("Number of health-food meals = %d\n",final_hf_num);

	return 0;
}

// <Replace this with a short function description>
void best_combination(int budget, int ff_cost, int hf_cost,
		int *final_ff_num, int *final_hf_num) {

   int i,j,rem_budget,min_rem=budget;
   for(i=budget/hf_cost;i>=0;i--)
   {
      rem_budget=budget-i*hf_cost;
      for(j=rem_budget/ff_cost;j>=0;j--)
      {
         rem_budget-=j*ff_cost;
      
         if(rem_budget<min_rem)
         {
            min_rem=rem_budget;
            *final_hf_num=i;
            *final_ff_num=j;
         }
         rem_budget=budget-i*hf_cost;

      }
   }
}

