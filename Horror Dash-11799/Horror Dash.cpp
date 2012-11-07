      #include<stdio.h>
      #include<stdlib.h>
      #include<string.h>
      #include<math.h>


      int main()
      {
      	int i,j,TestCase,NumberOfCreature,CreatureSpeed,ClownSpeed;
      	scanf("%d",&TestCase);
      	for(i=1;i<=TestCase;i++)
      	{
      	      ClownSpeed=0;
      		scanf("%d",&NumberOfCreature);
      		for(j=1;j<=NumberOfCreature;j++)
      		{
      			scanf("%d",&CreatureSpeed);
      			if(CreatureSpeed>ClownSpeed)ClownSpeed=CreatureSpeed;
      		}
      		printf("Case %d: %d\n",i,ClownSpeed);
      	}
      	return 0;
      }
