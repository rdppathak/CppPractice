import copy

def get_unique_array(array):
	unique_array = []
	weight_sum = 0

	for i in xrange(len(array)):
		curr_arr = ''
		j=i
		while(j<len(array)):
			item = array[j]
			if item+'|' not in curr_arr:
				curr_arr += 
			else:
				break
			if curr_arr not in unique_array:
				unique_array.append(copy.deepcopy(curr_arr))
				weight_sum += len(curr_arr.replace('|'))
			j+=1
	return weight_sum


def main():
	lines = int(raw_input())
	for l in xrange(lines):
		array_size = int(raw_input())
		array = raw_input()
		array = [int(j) for j in array.split(" ")]
		print get_unique_array(array)

if __name__ == '__main__':
	main()