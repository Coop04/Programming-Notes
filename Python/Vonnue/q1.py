def nonIncSum(nums,k=3):
    # i = 0
    # j = 1
    # flag = 1
    # s = 0
    # while i<len(nums) and j<len(nums):
    #     # print("outside")
    #     # print(nums[i],nums[j],s)
    #     if j<len(nums) and nums[j]>nums[j-1]:
    #         while j<len(nums) and nums[j]>nums[j-1]:
    #             flag+=1
    #             j+=1
    #         if flag >= 3:
    #             i = j
    #             j = i+1
    #         else:
    #             s+=sum(nums[i:j])
    #         # print("inside if")
    #         # print(nums[i],nums[j],s)
    #     elif j<len(nums) and nums[j]==nums[j-1]:
    #         i = j
    #         j = i+1
    #         flag = 1
    #     else:
    #         flag = 1
    #         if j+1<len(nums) and nums[j]<=nums[j+1]:
    #             s+=nums[i]
    #             i = j
    #             j = i+1
    #         else:
    #         # print(j)
    #             while j<len(nums) and nums[j]<nums[j-1]:
    #                 flag+=1
    #                 j+=1
    #             s+=sum(nums[i:j])
    #             i=j
    #             j=i+1
    # # print(nums[i],nums[j],s)
    # return s
    n = len(nums)
    s = 0
    i = 0
    while i < n:
        start = i
        # Find the end of the current increasing run
        while i + 1 < n and nums[i+1] > nums[i]:
            i += 1
        
        # 'i' is now at the end of the sequence
        length = i - start + 1
        
        if length < 3:
            s += sum(nums[start:i+1])
            
        i += 1 # Move to the next number
    return s
            


l = [1,2,3,10,5,6,7,8,2,1]
l2 = [100, 1, 2, 3, 4]
l3 = [1, 2, 3, 5]
l4 = [5, 1, 2, 3, 10, 20]
l5 = [1, 2, 2, 3]

print(nonIncSum(l))
print(nonIncSum(l2))
print(nonIncSum(l3))
print(nonIncSum(l4))   
print(nonIncSum(l5))

