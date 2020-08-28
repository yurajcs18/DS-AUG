#include&lt;stdio.h&gt;
#include&lt;conio.h&gt;
#include&lt;process.h&gt;
#define QUE_SIZE 5
int item,front=0,rear=-1,q[10];
void insertrear()
{
if(rear==QUE_SIZE-1)
{
printf(&quot;queue overflow\n&quot;);
return;
}
rear=rear+1;
q[rear]=item;
}
int deletefront()
{
if(front&gt;rear) return -1;
return q[front++];
}
void displayQ()
{
int i;
if(front&gt;rear)
{
printf(&quot;queue is empty\n&quot;);
return;
}
printf(&quot;Contents of queue \n&quot;);
for(i=front;i&lt;=rear;i++)
{
printf(&quot;%d\n&quot;,q[i]);
}
}


void main()
{
int choice;
clrscr();
for(;;)
{
printf(&quot;\n1:insertrear\n2:deletefront\n3:display\n4:exit\n&quot;);
printf(&quot;enter the choice\n&quot;);
scanf(&quot;%d&quot;,&amp;choice);
switch(choice)
{
case 1:printf(&quot;enter the item to be inserted\n&quot;);
scanf(&quot;%d&quot;,&amp;item);
insertrear();
break;
case 2:item=deletefront();
if(item==-1)
printf(&quot;queue is empty\n&quot;);
else
printf(&quot;item deleted =%d\n&quot;,item);
break;
case 3:displayQ();
break;
default:exit(0);
}
}
getch();
}