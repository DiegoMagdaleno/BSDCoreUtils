#include "linked_strings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list *
new_list (void)
{
  struct list *tmp = malloc (sizeof tmp);
  if (!tmp)
    {
      return NULL;
    };

  tmp->head = NULL;
  tmp->size = 0;

  return tmp;
}

struct lnode *
create_new_node (const char *component)
{
  struct lnode *new_node = NULL;

  if (!component)
    {
      return NULL;
    }

  new_node = malloc (sizeof (*new_node));
  if (!new_node)
    {
      return NULL;
    }

  if (!(new_node->component = malloc (strlen (component) + 1)))
    {
      free (new_node);
      return NULL;
    }

  strcpy (new_node->component, component);
  new_node->next = NULL;

  return new_node;
}

struct lnode *
push (struct list *our_list, const char *component)
{
  struct lnode *new_node = create_new_node (component);

  new_node->next = our_list->head;
  new_node->prev = NULL;

  if (our_list->head != NULL)
    {
      our_list->head->prev = new_node;
    }

  our_list->head = new_node;
  return new_node;
}

struct lnode *
append (struct list *our_list, const char *component)
{
  struct lnode *new_node = create_new_node (component);

  struct lnode *last = our_list->head;

  new_node->next = NULL;

  if (our_list->head == NULL)
    {
      new_node->prev = NULL;
      our_list->head = new_node;
      return NULL;
    }

  while (last->next != NULL)
    {
      last = last->next;
    }

  last->next = new_node;
  new_node->prev = last;

  return new_node;
}

struct lnode *
getatindx (struct list *our_list, int index)
{
  struct lnode *current = our_list->head;
  int count = 0;
  while (current != NULL)
    {
      if (count == index)
        {
          return (current);
        }
      count++;
      current = current->next;
    }

  return NULL;
}

struct lnode*
getlst(struct list *our_list) {
  struct lnode *current = our_list->head;
  while(current->next != NULL) {
    current = current->next;
  }
  return (current);
}

void
free_list (struct list *our_list)
{
  struct lnode *current = our_list->head;
  while (current)
    {
      struct lnode *to_free = current;
      current = current->next;
      free (to_free->component);
      free (to_free);
    }

  free (our_list);
}
