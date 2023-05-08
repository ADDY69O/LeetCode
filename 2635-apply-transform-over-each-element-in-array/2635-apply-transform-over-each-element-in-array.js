/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
  var newArr = [];
   arr.forEach((item,index)=>{
       newArr.push(fn(item,index));
   })
    return newArr;
};