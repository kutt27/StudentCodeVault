#include <stdio.h>

struct poly{
	int coef;
	int exp;
} p1[10], p2[10], p3[10];

void poly_add();
void poly_multi();
void display(struct poly p[], int);

void main(){
	int n, m, i;
	printf("\nEnter the number of terms for the 1st expression: ");
	scanf("%d",&n);
	printf("\nEnter the number of terms for the 2nd expression: ");
	scanf("%d",&m);
	printf("\nEnter Coefficient and Exponent of the 1 st expression\n")
	for (int i = 0; i < n; ++i) {
		printf("\n%d term",i+1);
		printf("Coefficient: ");
		scanf("%d",&p1[i].coef);
		printf("Exponent: ");
		scanf("%d",&p1[i].exp);
	}
	printf("\nEnter Coefficient and Exponent of the 2 nd expression\n")
	for (int i = 0; i < m; ++i) {
		printf("\n%d term",i+1);
		printf("Coefficient: ");
		scanf("%d",&p2[i].coef);
		printf("Exponent: ");
		scanf("%d",&p2[i].exp);
	}
	printf("\n1st expression");
	display(p1, n);
	printf("\n2nd expression");
	display(p2, m);
	printf("\nAddition result");
	poly_add(p1, p2, n, m);
	printf("\nMultiplication result");
	poly_add(p1, p2, n, m);
}

void display(struct ploy p[], int size){
	for (int i = 0; i < size; ++i) {
		printf("%dx^%d",p[i].coef, p[i].exp);
		if(i < size - 1){
			printf(" + ");
		}
	}
	printf("\n");
}

void poly_add(struct poly p1[], struct poly p2[], int n, int m){
	int i = int j = int k = 0;
	while(i < n && j < m){
		if(p1[i].exp == p2[j].exp){
			p3[k].coef = p1[i].coef + p2[j].coef;
			p3[k].exp = p1[i].exp;
			i++, j++, k++;
		}
		else if(p1[i].exp > p2[j].exp){
			p3[k].coef = p1[i].coef;
			p3[k].exp = p1[i].exp;
			i++, k++;
		}
		else{
			p3[k].coef = p2[j].coef;
			p3[k].exp = p2[j].exp;
			j++, k++;
		}
	}
	while(i < n){
		p3[k].coef = p1[i].coef;
		p3[k].exp = p1[i].exp;
		i++, k++;
	}
	while(j < m){
		p3[k].coef = p2[j].coef;
		p3[k].exp = p2[j].exp;
		j++, k++;
	}
	display(p3, k);
}

void poly_multi(struct poly p1[], struct poly p2[], int n, int m){
	int flag, e, c, h, k = 0;
	for(int i = 0; i < n; i++){
		for (int j = 0; j < m; ++j){
			flag = 0;
			c = p1[i].coef * p2[j].coef;
			e = p1[i].exp + p2[j].exp;
			for(h = 0; h < k; h++){
				if(p3[h].exp == e){
					p3[h].coef = p3[h].ceof + c;
					flag = 1;
				}
			}
			if(flag == 0){
				p3[k].ceof = c;
				p3[k].exp = e;
				k++;
			}
		}
	}
	display(p3, k);
}