#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lnode
{
  char *component;
  struct lnode *prev;
  struct lnode *next;

};

struct list
{
  struct lnode *head;
  size_t size;
};

struct list *new_list (void);
struct lnode *create_new_node (const char *);
struct lnode *push(struct list *, const char *);
struct lnode *append(struct list*, const char*);
struct lnode *getatindx(struct list*, int);
struct lnode *insert_front (struct list *, const char *);
struct lnode *getlst(struct list *);
void free_list (struct list *);
