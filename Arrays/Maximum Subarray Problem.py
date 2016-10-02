'''input
'''
#theta(nlgn)
# Divide and Conquer approach
# def find_max_crossing_subarray(A, low, mid, high):
# 	left_sum =-1e9
# 	sums =0
# 	max_left =0
# 	max_right =0
# 	for i in xrange(mid, low, -1):
# 		sums +=A[i];
# 		if sums > left_sum:
# 			left_sum =sums
# 			max_left =i
# 	right_sum =-1e9
# 	sums =0
# 	for i in xrange(mid+1, high):
# 		sums +=A[i];
# 		if sums > right_sum:
# 			right_sum =sums
# 			max_right =i
# 	return (max_left, max_right, left_sum + right_sum)

# def Find_Maximum_Subarray(A, low, high):
# 	if high == low:
# 		return (low, high, A[low])
# 	else:
# 		mid =(low+high)/2
# 		left_low, left_high, left_sum =Find_Maximum_Subarray(A, low, mid)
# 		right_low, right_high, right_sum =Find_Maximum_Subarray(A, mid+1, high)
# 		cross_low, cross_high, cross_sum =find_max_crossing_subarray(A, low, mid, high)
# 		if left_sum>=right_sum and left_sum>=cross_sum:
# 			return (left_low, left_high, left_sum)
# 		elif right_sum>=left_sum and right_sum>=cross_sum:
# 			return (right_low, right_high, right_sum)
# 		else:
# 			return (cross_low, cross_high, cross_sum)

# theta(n^2)
# Brute-Force
# def Find_Maximum_Subarray(A, low, high):
# 	max_sum =-1e9
# 	for i in xrange(low, high):
# 		sums =0
# 		for j in xrange(i, high):
# 			sums += A[j]
# 			if(sums > max_sum):
# 				max_sum =sums
# 				max_left =i
# 				max_right =j
# 	return (max_left, max_right, max_sum)

# theta(n)
# Kadane Algorithm
def Find_Maximum_Subarray(A, low, high):
	max_sum =sums =A[0]
	for i in xrange(low, high):
		if (A[i])<(A[i]+sums):
			sums =A[i]+sums
		else:
			sums =A[i]
			max_left =i
		if sums>max_sum:
			max_right =i
			max_sum =sums
	return (max_left, max_right, max_sum)

A =[13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]
i, j, max_sum =Find_Maximum_Subarray(A, 0, len(A)-1)
print i+1, j+1, max_sum
