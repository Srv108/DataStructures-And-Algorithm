
const arr = [9,11,13,31,23,14,6,3,1,7,4,15,21,8,2,5,0,22,12,17,19];
function Demo(arr,st,en){
    if(st == en) return;
    let i = st;
    let j = en-1;
    let p = arr[st];
    while(i < j){
        if(arr[i] >= p){
            let temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            if(arr[j] != p) j--;
        }else i++;
    }
    Demo(arr,0,j);
    Demo(arr,j+1,en);
}

Demo(arr,0,arr.length);
for(let i=0;i<arr.length;i++) console.log(arr[i]);
console.log("******************");