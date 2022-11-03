else
    {
        printf("\n1.at begining\n2. at end\n3. at given position");
        printf("\nenter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head = head->next;
            temp->next = NULL;
            return head;
            break;
        case 2:

            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            return head;
        case 3:
            printf("\nEnter the position to Delete:");
            scanf("%d", &pos);
            if (pos == 1)
            {
                head = head->next;
                temp->next = NULL;
                return head;
            }
            else
            {
                for (i = 1; i < pos - 1; i++)
                {
                    temp = temp->next;
                }
                temp->next = temp->next->next;
                return head;
            }

        default:

            break;
        }