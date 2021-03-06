#include <stdio.h>

int getLargest(int smallest[]) 
{
    int index = 0, i;
    for (i = 0; i<3; i++) {
        if (smallest[i] > smallest[index]) {
            index = i;
        }
    }
    return index;
}

int main() {
    int n, smallest[3], a[1024], i, j, found_smallest;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for (i=0; i<3; i++) {
        smallest[i] = a[i];
    }
    for (i=3; i<n; i++) {
        found_smallest = 0;
        for (j=0; j<3; j++) {
            if (a[i] < smallest[j]) {
                found_smallest = 1;
                break;
            }
        }
        if (found_smallest) {
            smallest[getLargest(smallest)] = a[i];
        }
    }
    printf("\n%d\n", smallest[getLargest(smallest)]);
}
