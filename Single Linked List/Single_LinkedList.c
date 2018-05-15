#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int studentID;
	int studentGrade;
	struct Node* next;
};

struct Node* SLL_insert(struct Node* head, struct Node* studentNode){
	printf("->Adding node to List.");
	struct Node* ptr = NULL;
	struct Node* current = head;

	while(current != NULL)
	{	
		if(studentNode->studentID < current->studentID)
		break;
		ptr = current;
		current = current->next;
	}
	if(ptr == NULL){ 
		studentNode->next = head;
		head = studentNode;
	}
	else
	{ 
		ptr->next = studentNode;
		studentNode->next = current;
	}
	return head;
}

int main(int argc, char *argv[])
{		
	if(argc = argc-1)
	{
		int count=0; double averageGrade;
		int i; int studentId; int grade;int loopC; 	int j, newID;		
		struct Node* head = NULL;	
		struct Node* studentNode;
		
		for (i=0; i<argc; ++i){
			FILE *ifp1 = fopen(argv[i], "r");
			if (ifp1 != NULL)
			{
				while (fscanf(ifp1, "%d,%d", &studentId, &grade) == 2){
					if(feof(ifp1))
					break;
					count++;
					studentNode=(struct Node*)malloc(sizeof(struct Node));
					studentNode->studentID = studentId;
					studentNode->studentGrade = grade;
					studentNode->next = NULL;
					head = SLL_insert(head, studentNode); 
					loopC = count/3;
			}
			fclose(ifp1);
			}
		}
		struct Node* current = head;
		FILE *ifp2 = fopen(argv[4], "w");

		while(current != NULL)
		{
			double totalGrade = 0;
			newID = current->studentID;		
			for(j=0; j<loopC; j++){
				totalGrade += current->studentGrade;
				current = current->next;
			}
			averageGrade = (totalGrade/3.0);
			fprintf(ifp2, "%d,%.0lf\n",newID, averageGrade); 
		}
		fclose(ifp2);
	}
	else
	{
		printf("Please run the calculator with 4 parameters.");
		exit(0);
	}
	return 0;
}
