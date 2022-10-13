  for(pass=0;pass<nopass;pass++)
    {
        for(i=0;i<10;i++)
        {
            bc[i]=0;
        }

        for(i=0;i<n;i++)
        {
            rem=(a[i]/div)%10;
            bucket[rem][bc[rem]]=a[i];
            bc[rem]=bc[rem]+1;
        }
        i=0;
        for(k=0;k<10;k++)
        {
            for(j=0;j<bc[k];j++)
            {
                a[i]=bucket[k][j];
                i++;
            }
        }
        div=div*10;


    }    
