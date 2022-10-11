#Tower of hanoi in python

def towerOfHanoi(N , source, destination, auxiliary):
	if N==1:
		print("Move disk 1 from source",source,"to destination",destination)
		return
	towerOfHanoi(N-1, source, auxiliary, destination)
	print("Move disk",N,"from source",source,"to destination",destination)
	towerOfHanoi(N-1, auxiliary, destination, source)
