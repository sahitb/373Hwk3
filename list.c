#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
    assert(head != NULL);
    assert(new_element != NULL);
    
    list_t* curr = head;
    
    // If new_element is the new head
    if (curr->index > new_element->index) {
        new_element->next = head;
        head = new_element;
        return head;
    }
    
    while (1) {
        // Check that not at the end of the list
        if (curr->next != NULL) {
            list_t* nextel = curr->next;
            // Reached the point where to insert new_element
            if (nextel->index > new_element->index) {
                curr->next = new_element;
                new_element->next = nextel;
                return head;
            // Not yet reached the point where to insert new_element
            } else {
                curr = curr->next;
            }
        // If reached the end of the list
        } else {
            curr->next = new_element;
            new_element->next = NULL;
            return head;
        }
    }
    return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
    assert(head != NULL);
    
    // If list is only one element long
    list_t* curr = head;
    if (curr->next == NULL) {
        return head;
    }
    
    // Declare variables to be used
    list_t* nextel = NULL;
    list_t* prevel = NULL;
    while (curr != NULL) {
        // Store the next element
        nextel = curr->next;
        // Reverse the direction of the pointer
        curr->next = prevel;
        
        // Increment to next element in the list
        prevel = curr;
        curr = nextel;
    }
    
    head = prevel;
    
    return head;
}

