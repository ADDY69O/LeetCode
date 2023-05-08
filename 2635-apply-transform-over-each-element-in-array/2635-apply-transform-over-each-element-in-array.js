/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
  var newArr = new Array( arr.length);
    for(let i=0;i<arr.length;i++){
        newArr[i]= fn(arr[i],i);
    }
    
    return newArr;
};