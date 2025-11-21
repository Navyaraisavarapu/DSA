#define min(a,b) ((a>b)?b:a)    //this is neccessary..
int trap(int* height, int heightSize){
    int max1 = 0;
    //create left array so that we find the maximum element on its left...
    int left[heightSize];
    // Scan every element from left to right...
    for(int i = 0; i < heightSize; i++) { 
        // Find maximum element on its left...
        if(max1 < height[i]) {
            max1 = height[i];
        }
        left[i] = max1;
    }
        
    int max2 = 0;
    //create right array so that we find the maximum element on its right...
    int right[heightSize];
    // Scan every element from right to left...
    for(int i = heightSize-1; i >= 0; i--) {
        // Find maximum element on its left...
        if(max2 < height[i]) {
            max2 = height[i];
        }
        right[i] = max2;
    }
        
    // To store the maximum water that can be stored..
    int trap = 0;
    // Scan and Calculate maximum trapped water...
    for(int i = 0; i  < heightSize; i++) {
        trap += min(left[i], right[i]) - height[i];
    }
    return trap;        //return the amount..
}