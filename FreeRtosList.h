#ifndef __FREERTOSLIST_H
#define __FREERTOSLIST_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "freertos.h"
#include "list.h"

uint32_t FRL_GetItemByIndex(List_t* list, uint32_t index);
void FRL_SetItemByIndex(List_t* list, uint32_t index, uint32_t value);
void FRL_SetItem(ListItem_t* listItem, uint32_t value);
uint32_t FRL_GetItem(ListItem_t* listItem);
List_t* FRL_Create(void);
ListItem_t* FRL_CreateItem(void);
ListItem_t* FRL_CreateItemWithValue(uint32_t itemValuePtr);
void FRL_Insert(List_t* list, ListItem_t* listItem);
bool FRL_IsEmpty(List_t* list);
uint32_t FRL_Length(List_t* list);
void FRL_Remove(ListItem_t* listItem);
void FRL_RemoveAt(List_t* list, uint32_t index);
void FRL_Dispose(List_t* list);
void FRL_DisposeItem(ListItem_t* listItem);

#endif /* __FREERTOSLIST_H */
