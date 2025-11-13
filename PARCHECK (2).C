/*
       PARENTHESIS CHECKER
---------------------------------------------------------------------

      INFIX = "({a+b} * [c-d])"

	   3
	   2
	   1  '{' <- top   '}'
	   0  '('

	      top=-1
*/

   #include<stdio.h>
   #include<string.h>
   #include<conio.h>

     char stk[30];
     int top = -1;

    void PUSH(char ch)
    {
	top++;
	stk[top] = ch;
    }

    char POP()
    {
	if(top != -1)
	{
	    return stk[top--];
	}
    }

   void main()
   {
      char infix[100];
      int i, flag=1;

	clrscr();

      printf("\n\n Enter infix expression : ");
	   gets(infix);

      for(i=0 ; i<strlen(infix) ; i++)
      {
	  if(infix[i]=='(' || infix[i] == '[' || infix[i] == '{')
	  {
	      PUSH(infix[i]);
	  }
	  else
	  {
	       if(infix[i] == ')')
	       {
		  if(POP() != '(')
		  {
		      flag = 2;
		      break;
		  }
	       }
	       if(infix[i] == ']')
	       {
		  if(POP() != '[')
		  {
		      flag = 2;
		      break;
		  }
	       }
	       if(infix[i] == '}')
	       {
		  if(POP() != '{')
		  {
		      flag = 2;
		      break;
		  }
	       }
	  }
      }

      if(flag == 1 && top == -1)
      {
	  printf("\n\n VALID INFIX EXPRESSION ");
      }
      else
      {
	  printf("\n\n INVALID INFIX EXPRESSION ");
      }

	getch();
   }

























