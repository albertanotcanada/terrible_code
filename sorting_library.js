// Array we'll sort
my_arr = [100, 3, 6, 7, 50]

function sleepSort(arr) {
	for (let n of arr) {
	// Print item n after n seconds. 
	setTimeout(() => console.log(n, n))
  }
}
