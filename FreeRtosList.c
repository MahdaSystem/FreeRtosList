#include "FreeRtosList.h"

uint32_t FRL_GetItemByIndex(List_t* list, uint32_t index) {
  if(list == NULL)
    return 0;
  if(index >= list->uxNumberOfItems)
    return 0;
  ListItem_t* walkingListItem = list->xListEnd.pxNext;
  for(uint32_t inListItemWalker = 0; inListItemWalker < index; inListItemWalker++)
    walkingListItem = walkingListItem->pxNext;
  return walkingListItem->xItemValue;
}
void FRL_SetItemByIndex(List_t* list, uint32_t index, uint32_t value) {
  if(list == NULL)
    return;
  if(index >= list->uxNumberOfItems)
    return;
  ListItem_t* walkingListItem = list->xListEnd.pxNext;
  for(uint32_t inListItemWalker = 0; inListItemWalker < index; inListItemWalker++)
    walkingListItem = walkingListItem->pxNext;
  listSET_LIST_ITEM_VALUE(walkingListItem, value);
}
void FRL_SetItem(ListItem_t* listItem, uint32_t value) {
  if(listItem == NULL)
    return;
  listSET_LIST_ITEM_VALUE(listItem, value);
}
uint32_t FRL_GetItem(ListItem_t* listItem) {
  if(listItem == NULL)
    return 0;
  return listGET_LIST_ITEM_VALUE(listItem);
}
List_t* FRL_Create(void) {
  List_t* tempList = malloc(sizeof(List_t));
  if(tempList)
    vListInitialise(tempList);
  return tempList;
}
ListItem_t* FRL_CreateItem(void) {
  ListItem_t* tempListItem = malloc(sizeof(ListItem_t));
  if(tempListItem)
    vListInitialiseItem(tempListItem);
  return tempListItem;
}
ListItem_t* FRL_CreateItemWithValue(uint32_t itemValuePtr) {
  ListItem_t* tempListItem = malloc(sizeof(ListItem_t));
  if(tempListItem)
  {
    vListInitialiseItem(tempListItem);
    tempListItem->xItemValue = itemValuePtr;
  }
  return tempListItem;
}
void FRL_Insert(List_t* list, ListItem_t* listItem) {
  if(list == NULL)
    return;
  if(listItem == NULL)
    return;
  vListInsert(list, listItem);
}
bool FRL_IsEmpty(List_t* list) {
  if(list == NULL)
    return false;
  return listLIST_IS_EMPTY(list) ? true : false;
}
uint32_t FRL_Length(List_t* list) {
  if(list == NULL)
    return 0;
  uint32_t listLen = listCURRENT_LIST_LENGTH(list);
  return listLen;
}
void FRL_Remove(ListItem_t* listItem) {
  if(listItem == NULL)
    return;
  uxListRemove(listItem);
}
void FRL_RemoveAt(List_t* list, uint32_t index) {
  if(list == NULL)
    return;
  if(index >= list->uxNumberOfItems)
    return;
  ListItem_t* walkingListItem = list->xListEnd.pxNext;
  for(uint32_t inListItemWalker = 0; inListItemWalker < index; inListItemWalker++)
    walkingListItem = walkingListItem->pxNext;
  uxListRemove(walkingListItem);
}
void FRL_Dispose(List_t* list) {
  if(list == NULL)
    return;
  free(list);
}
void FRL_DisposeItem(ListItem_t* listItem) {
  if(listItem == NULL)
    return;
  free(listItem);
}

//static void Test_FreeRTOSList(void) {
//  printf("-----------------------------------\r\n");
//  printf("Test_FreeRTOSList\r\n");
//  List_t* list = FRL_Create();
//  ListItem_t* listItem1 = FRL_CreateItem();
//  ListItem_t* listItem2 = FRL_CreateItem();
//  ListItem_t* listItem3 = FRL_CreateItem();
//  
//  FRL_SetItem(listItem1, 10);
//  FRL_SetItem(listItem2, 20);
//  FRL_SetItem(listItem3, 30);
//  
//  printf("Is Empty = %s\r\n", FRL_IsEmpty(list) ? "Yes" : "No");
//  
//  FRL_Insert(list, listItem1);
//  printf("List Length = %u\r\n", FRL_Length(list));
//  FRL_Insert(list, listItem2);
//  printf("List Length = %u\r\n", FRL_Length(list));
//  FRL_Insert(list, listItem3);
//  printf("List Length = %u\r\n", FRL_Length(list));
// 
//  printf("Is Empty = %s\r\n", FRL_IsEmpty(list) ? "Yes" : "No");
//  
//  for(uint8_t tempItemCounter = 0; tempItemCounter < 5; tempItemCounter++)
//    printf("Item[%d] Value = %d\r\n", tempItemCounter, FRL_GetItemByIndex(list, tempItemCounter));
//  
//  for(uint8_t tempItemCounter = 0; tempItemCounter < 5; tempItemCounter++)
//    FRL_SetItemByIndex(list, tempItemCounter, tempItemCounter);
//  
//  for(uint8_t tempItemCounter = 0; tempItemCounter < 5; tempItemCounter++)
//    printf("Item[%d] Value = %d\r\n", tempItemCounter, FRL_GetItemByIndex(list, tempItemCounter));
//  
//  FRL_Remove(listItem1);
//  printf("List Length = %u\r\n", FRL_Length(list));
//  FRL_Remove(listItem2);
//  printf("List Length = %u\r\n", FRL_Length(list));
//  FRL_Remove(listItem3);
//  printf("List Length = %u\r\n", FRL_Length(list));
//  
//  printf("Is Empty = %s\r\n", FRL_IsEmpty(list) ? "Yes" : "No");
//  
//  FRL_Dispose(list);
//  FRL_DisposeItem(listItem1);
//  FRL_DisposeItem(listItem2);
//  FRL_DisposeItem(listItem3);

//  printf("-----------------------------------\r\n");
//}
