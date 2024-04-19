#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
main()
{
int fd,sin_size,p1,p2,i;
char buf[50];
struct sockaddr_in server,client;
printf("Enter the source and destination port no\n");
scanf("%d%d",&p1,&p2);
if((fd=socket(AF_INET,SOCK_DGRAM,0))==-1)
{
printf("socket error");
exit(-1);
}
bzero(&server,sizeof(server));
bzero(&client,sizeof(client));
client.sin_family=AF_INET;
server.sin_family=AF_INET;
server.sin_port=htons(p1);
client.sin_port=htons(p2);
server.sin_addr.s_addr=htonl(INADDR_ANY);
client.sin_addr.s_addr=htonl(INADDR_ANY);
if(bind(fd,(struct sockaddr*)&server,sizeof(server))==-1)
{
printf("bind error\n");
exit(-1);
}
sin_size=sizeof(client);
while(1)
{
if(!fork())
while(1)
{
recvfrom(fd,buf,100,0,(struct sockaddr*)&client,&sin_size);
printf("%s\n",buf);
break;
}
else
while(1)

{
scanf("%s",buf);
sendto(fd,buf,100,0,(struct sockaddr*)&client,sin_size);
break;
}
if(strcmp(buf,"EXIT")==0)
break;
}
close(fd);
return 0;
}
