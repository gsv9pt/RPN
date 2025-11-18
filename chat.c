#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>


int main() {
	char *me = getenv("USER");puts(me);
	char buffer[4096];
	snprintf(buffer, 4096, "/p/%s/mailbox/%s.chat",
                "cso1",
                me);

	FILE *inbox = fopen(buffer, "r");

 if(inbox == NULL){
      puts("No Messages");
 }
 else
 {
  char Inbox[4096];
  size_t got = fread(Inbox, sizeof(char), 4096, inbox);
  puts(Inbox);
  truncate(buffer, 0);

 }
char RecID[4096];
char Outbox[4096];
puts("Who would you want to send this to?");
char *recID = fgets(RecID, 4096, stdin);
recID[strcspn(recID, "\n")] = '\0';
snprintf(Outbox, 4096, "/p/%s/mailbox/%s.chat",
    "cso1",
    recID
);

FILE *outbox = fopen(Outbox, "a");

char Message[4096];
puts("What is your message");
char *message = fgets(Message, 4096, stdin);
message[strcspn(message, "\n")] = '\0';

fprintf(outbox, "%s: %s\n", me, Message);

chmod(Outbox, 0666);

fclose(outbox);

}


