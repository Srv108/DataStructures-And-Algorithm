function Sort(arr) {
    for (let i = 0; i < arr.length - 1; i++) {
        for (let j = 0; j < arr.length - 1 - i; j++) {
            let x = arr[j].charCodeAt(0);   // Ascii value
            let y = arr[j+1].charCodeAt(0);  // Ascii value
            if (x > y) {
                let temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

let colors = ["red", "blue", "green", "yellow", "orange", "purple"];
console.log("Original array:", colors);
Sort(colors);
console.log("Sorted array:", colors);



// function Sort(arr) {
//     for (let i = 0; i < arr.length - 1; i++) {
//         for (let j = 0; j < arr.length - 1 - i; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 let temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
//     return arr;
// }

// let colors = ["red", "blue", "green", "yellow", "orange", "purple"];

console.log("Original array:", colors);
Sort(colors);
console.log("Sorted array:", colors);

let x = ("red" > "green");
console.log(x);