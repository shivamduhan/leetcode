int maxArea(int* height, int heightSize){
    int left = 0, right = heightSize - 1;
    int maxarea = 0;
    while (left < right) {
        int container_height = height[left] < height[right] ? height[left] : height[right];
        int area = container_height * (right - left); //area of current container, right is bigger than left
        if (area > maxarea) {
            maxarea = area; //update max area if needed
        }
        if (height[left] < height[right]) { //gotta find a larger area
            left++; //left wall shorter, move it. area is limited by shorter wall, try to find a higher wall.
        }
        else {
            right--; //right wall shorter, move it
        }
    }
    return maxarea; //right and left pointers have meet and we have checked all wall heights
}

//time complexity is O(n) and space complexity is O(1)
