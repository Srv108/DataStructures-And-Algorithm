arr = [-7,-5,-3,-2,0,1,4,6,7,8];
// arr = [7,-5,12,-2,0,10,4,16,7,8];

arr.sort((x,y) => x - y);
console.log(arr);


let i = 0, j = arr.length -1;
let n = arr.length;
let ans = [n];
let k = n-1;
while( i <= j){
    let a = arr[i] * arr[i];
    let b = arr[j] * arr[j];
    if(a < b) {
        ans[k] = b;
        k--;
        j--;
    }
    else{
        ans[k] = a;
        k--;
        i++;
    }

}
console.log("Ans : ");
console.log(ans);