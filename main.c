#include <stdio.h>
#include <string.h>

#define MAX_USER 100

struct user {
	char name[15];
	char lastname[15];
	char number[11];
};

void print_menu() {
	printf("1) Add user\n");
	printf("2) List users\n");
	printf("3) Search user\n");
	printf("4) Quit\n");
}

void add_user(struct user* users, int* count_user) {
	if (*count_user >= MAX_USER) {
		printf("Error: phonebook is full\n");
		return;
	}

	char name_buf[15];
	char lastname_buf[15];
	char number_buf[11];

	printf("Input name(max 15 symbol): ");
	scanf("%s", name_buf);

	printf("Input last name(max 15 symbol): ");
	scanf("%s", lastname_buf);

	printf("Input number(max 11 symbol): ");
	scanf("%s", number_buf);

	strcpy(users[*count_user].name, name_buf);
	strcpy(users[*count_user].lastname, lastname_buf);
	strcpy(users[*count_user].number, number_buf);

	++(*count_user);
}

void print_users(struct user* users, int count_user) {
	for (int i = 0; i < count_user; ++i)
		printf("%s\t%s\t%s\n", users[i].name, users[i].lastname, users[i].number);
}

int search_user(struct user *users, int count_user) {
	if (count_user == 0) {
		printf("List users empty\t");
		return -1;
	}

	char name_buf[15];
	int count_collision = 0;

	printf("Input name for search(max 15 symbol): ");
	scanf("%s", name_buf);

	for (int i = 0; i < count_user; ++i) {
		if (strcmp(users[i].name, name_buf) == 0) {
			printf("%s\t%s\t%s\n", users[i].name,
						users[i].lastname,
						users[i].number);
			++count_collision;
		}
	}

	if (count_collision == 0)
		printf("User not found\n");

	return 0;
}

int delete_user(struct user *users, int count_user) {
	if (count_user == 0) {
		printf("List user empty\t");
		return -1;
	}

	char name_buf[15];
	int count_delete = 0;

	printf("Input name for delete(max 15 symbol): ");
	scanf("%s", name_buf);

	for (int i = 0; i < count_user; ++i) {
		if (strcmp(users[i].name, name_buf) == 0) {


			--count_user;			
		}
	}

	if (count_delete == 0)
		printf("User not found\n");

	return 0;	
}

int main() {
	struct user users[MAX_USER];
	int count_user = 0;
	int act;

	do {
		print_menu();

		printf("Input act: ");
		scanf("%d", &act);

		switch (act) {
			case 1:
				add_user(users, &count_user);
				break;
			case 2:
				print_users(users, count_user);
				break;
			case 3:
				search_user(users, count_user);
				break;
			case 4:
				printf("Bye\n");
				break;
			default:
				printf("Error: act not found\n");
				break;
		}
	} while (act != 4);

	return 0;
}
