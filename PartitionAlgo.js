
const arr = [9,11,13,6,3,1,21,7,4,15,21,8,2,5,0,22,12,17,19];
var j = arr.length - 1;
function Demo(arr,p){
    let i = 0;
    // j = arr.length - 1;
    while(i < j){
        if(arr[i] >= p){
            let temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            if(arr[j] != p) j--;
        }else i++;
    }
}

Demo(arr,13);
for(let i=0;i<arr.length;i++) console.log(arr[i]);

console.log("******************");
