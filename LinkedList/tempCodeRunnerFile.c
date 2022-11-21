while(temp!=NULL)
	{
		printf("%d*X^%d+",temp->coef,temp->exp);
		temp=temp->next;
	}