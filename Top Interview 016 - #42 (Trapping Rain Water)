int trap(int* height, int heightSize){ //time complexity O(n), space complexity O(1)

    int left_ptr = 0, right_ptr = heightSize - 1; //traverse from left to right
    int left_max = 0, right_max = 0; //init max heights
    int water = 0; //water at current point will be determined by the minimum of the max heights from left and right subtracted by current height

    while (left_ptr < right_ptr) { //go towards center from both sides
        if (height[left_ptr] < height[right_ptr]) { //left height is the deciding factor now
            if (height[left_ptr] > left_max) {
                left_max = height[left_ptr]; //update max left height
            }
            else { //current height lower than max height on the left side
                water = water + left_max - height[left_ptr]; //diff. between max and current height
            }
            left_ptr++;
        }
        else { //right height is deciding factor
            if (height[right_ptr] > right_max) { //current height on the right greater than max height
                right_max = height[right_ptr];
            }
            else {
                water = water + right_max - height[right_ptr]; //add water trapped at this location
            }
            right_ptr--;
        }

    }
    return water; //total water trapped by all blocks

}
