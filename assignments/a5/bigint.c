/*
 * Shervin Zare
 * 169064750
 * Assignment 5
 * October 22 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"

BIGINT bigint(char *p) {
  BIGINT bn = {0};
  if (p == NULL) 
    return bn;
  else if (!(*p >= '0' && *p <= '9')) {// not begin with digits 
    return bn;
  }
  else if (*p == '0' && *(p+1) == '\0') {// just "0"
    dll_insert_end(&bn, dll_node(*p -'0'));
    return bn;
  }  
  else { 
    while (*p) {
      if (*p >= '0' && *p <= '9' ){
        dll_insert_end(&bn, dll_node(*p -'0'));
      } else {
        dll_clean(&bn);
        break;
      }
      p++;
    }
    return bn;
  }
}

BIGINT bigint_add(BIGINT op1, BIGINT op2) {
    BIGINT sum = {0};
    NODE *p1 = op1.end;
    NODE *p2 = op2.end;
    int carry = 0, a, b, s;

    while (p1 || p2) {
        a = (p1 ? p1->data : 0);
        b = (p2 ? p2->data : 0);
        
        s = a + b + carry;
        carry = s / 10;
        s = s % 10;

        dll_insert_start(&sum, dll_node(s));

        if (p1) p1 = p1->prev;
        if (p2) p2 = p2->prev;
    }

    if (carry == 1) {
        dll_insert_start(&sum, dll_node(1));
    }

    return sum;
}

BIGINT bigint_fibonacci(int n) {
    BIGINT f1 = bigint("0");
    BIGINT f2 = bigint("1");
    BIGINT temp;

    if (n == 0) return f1;
    if (n == 1) return f2;

    for (int i = 2; i <= n; i++) {
        temp = bigint_add(f1, f2);
        dll_clean(&f1);
        f1 = f2;
        f2 = temp;
    }

    dll_clean(&f1);
    return f2;
}
