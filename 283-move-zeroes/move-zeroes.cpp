class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for(int j=0; j<n-1; j++){                 
            for(int i=j+1; i<n; i++){        
                if (nums[j]==0){              
                    if (nums[i]==0){          
                        continue;     
                    }
                    else{
                        swap(nums[j],nums[i]); 
                        break;
                    }
                }
            }
        }
    }
};