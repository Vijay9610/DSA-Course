#include <stdio.h>
int main(){
    //! General syntax <data_type> <array_name>[size];
    // Create an integer array
    int nums[10];

    // Taking input from user
    for(int i=0; i<10; i++){
        scanf("%d", &nums[i]);
    }

    // Print even array elements
    for(int i=0; i<10; i++){
        if(nums[i] % 2 == 0)
            printf("%d ", nums[i]);
    }
    return 0;
}